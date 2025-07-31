import { Routes, Route, Link, Navigate } from 'react-router-dom';
import Home from './pages/Home';
import Login from './pages/Login';
import PostJob from './pages/PostJob';
import SubmitResume from './pages/SubmitResume';
import Applications from './pages/Applications';
import { useEffect, useState } from 'react';

function App() {
  const [isAdmin, setIsAdmin] = useState(false);
  const [isLoggedIn, setIsLoggedIn] = useState(false);

  // ✅ Handle token exchange from Cognito ?code=... redirect
  useEffect(() => {
    const urlParams = new URLSearchParams(window.location.search);
    const code = urlParams.get("code");

    if (code) {
      console.log("🔁 Received code from Cognito:", code);

      fetch("https://us-east-2tn5vlff4q.auth.us-east-2.amazoncognito.com/oauth2/token", {
        method: "POST",
        headers: {
          "Content-Type": "application/x-www-form-urlencoded",
        },
        body: new URLSearchParams({
          grant_type: "authorization_code",
          client_id: "2gtpp9dpvhei5aqle405jhuo2e",
          code,
          redirect_uri: import.meta.env.VITE_NGROK_URL,
        }),
      })
        .then((res) => res.json())
        .then((data) => {
          console.log("🧾 Token exchange response:", data);
          if (data.id_token) {
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

  // ✅ Load login info from token
  useEffect(() => {
    const token = localStorage.getItem('token');
    if (token) {
      try {
        const payload = JSON.parse(atob(token.split('.')[1]));
        const isAdmin = payload['cognito:groups']?.includes('admin');
        setIsLoggedIn(true);
        setIsAdmin(isAdmin);
      } catch (err) {
        console.error('Failed to parse token:', err);
      }
    }
  }, []);

  return (
    <div style={{ maxWidth: '900px', margin: '0 auto', fontFamily: 'sans-serif' }}>
      {/* Header */}
      <header
        style={{
          display: 'flex',
          justifyContent: 'space-between',
          alignItems: 'center',
          padding: '1rem 0',
          borderBottom: '1px solid #ccc',
          marginBottom: '2rem',
        }}
      >
        <h1 style={{ margin: 0 }}>Job Board</h1>
        <nav>
          <Link to="/" style={{ marginRight: '1rem' }}>Home</Link>
          <Link to="/login" style={{ marginRight: '1rem' }}>Login</Link>
          {isAdmin && <Link to="/post-job">Post Job</Link>}
        </nav>
      </header>

      {/* Routes */}
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/login" element={<Login />} />
        <Route path="/post-job" element={isAdmin ? <PostJob /> : <Navigate to="/" replace />} />
        <Route path="/apply/:jobId" element={<SubmitResume />} />
        <Route path="/applications/:jobId" element={isAdmin ? <Applications /> : <Navigate to="/" replace />} />
      </Routes>
    </div>
  );
}

export default App;
