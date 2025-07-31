import { useEffect } from 'react';

function Login() {
  const redirectUri = import.meta.env.VITE_NGROK_URL;
  const clientId = "2gtpp9dpvhei5aqle405jhuo2e"; // 🔁 Replace with your actual App Client ID
  const domain = "us-east-2tn5vlff4q.auth.us-east-2.amazoncognito.com"; // 🔁 Replace if different

  const loginUrl = `https://${domain}/login?client_id=${clientId}&response_type=code&scope=email+openid+profile&redirect_uri=${encodeURIComponent(redirectUri)}`;

  useEffect(() => {
    const urlParams = new URLSearchParams(window.location.search);
    const code = urlParams.get("code");

    if (code) {
      console.log("🔁 Received code from Cognito:", code);

      fetch(`https://${domain}/oauth2/token`, {
        method: "POST",
        headers: {
          "Content-Type": "application/x-www-form-urlencoded",
        },
        body: new URLSearchParams({
          grant_type: "authorization_code",
          client_id: clientId,
          code,
          redirect_uri: redirectUri,
        }),
      })
        .then((res) => res.json())
        .then((data) => {
          console.log("🧾 Token exchange response:", data);

          if (data.id_token) {
            console.log("✅ ID token received. Storing token...");
            localStorage.setItem("token", data.id_token);
            window.history.replaceState({}, document.title, "/");
            window.location.reload();
          } else {
            console.error("❌ Token exchange failed. No id_token in response.", data);
          }
        })
        .catch((err) => {
          console.error("❌ Error during token exchange:", err);
        });
    } else {
      console.log("⏳ No code in URL. Waiting for login...");
    }
  }, []);

  const handleLogin = () => {
    console.log("🔐 Redirecting to Cognito login...");
    window.location.href = loginUrl;
  };

  return (
    <div>
      <h2>Login</h2>
      <button onClick={handleLogin}>Login with AWS Cognito</button>
    </div>
  );
}

export default Login;
