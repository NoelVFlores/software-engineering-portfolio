import { useEffect, useState } from 'react';
import { useParams } from 'react-router-dom';

function SubmitResume() {
  const { jobId } = useParams();
  const [job, setJob] = useState(null);
  const [name, setName] = useState('');
  const [resumeText, setResumeText] = useState('');
  const [message, setMessage] = useState('');

  useEffect(() => {
    fetch(`/api/record/${jobId}`)
      .then(res => res.json())
      .then(setJob)
      .catch(err => console.error("Failed to load job", err));
  }, [jobId]);

  const handleSubmit = async (e) => {
    e.preventDefault();
    const token = localStorage.getItem("token");
    setMessage("Submitting resume...");

    const res = await fetch('/api/record', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
        'Authorization': `Bearer ${token}`,
      },
      body: JSON.stringify({
        name,
        position: job?.jobTitle,
        level: resumeText,
        type: "resume",
        positionId: jobId,
      })
    });

    if (res.ok) {
      setMessage("✅ Resume submitted successfully!");
      setName('');
      setResumeText('');
    } else {
      setMessage("❌ Failed to submit resume.");
    }
  };

  if (!job) return <p>Loading job details...</p>;

  return (
    <div style={{ maxWidth: '600px', margin: '0 auto' }}>
      <h2>Submit Resume for {job.jobTitle}</h2>
      <form
        onSubmit={handleSubmit}
        style={{
          display: 'flex',
          flexDirection: 'column',
          alignItems: 'flex-start',
          gap: '1rem',
          marginTop: '1rem'
        }}
      >
        <label style={{ width: '100%' }}>
          <span style={{ display: 'block', marginBottom: '0.25rem' }}>Name</span>
          <input
            name="name"
            value={name}
            onChange={(e) => setName(e.target.value)}
            required
            style={{
              width: '100%',
              padding: '0.5rem',
              fontSize: '1rem',
              boxSizing: 'border-box',
            }}
          />
        </label>

        <label style={{ width: '100%' }}>
          <span style={{ display: 'block', marginBottom: '0.25rem' }}>Resume</span>
          <textarea
            name="resume"
            value={resumeText}
            onChange={(e) => setResumeText(e.target.value)}
            placeholder="Paste your resume text here..."
            rows={6}
            required
            style={{
              width: '100%',
              padding: '0.5rem',
              fontSize: '1rem',
              boxSizing: 'border-box',
            }}
          />
        </label>

        <button
          type="submit"
          style={{
            alignSelf: 'stretch',
            padding: '0.75rem',
            fontWeight: 'bold',
            fontSize: '1rem',
            background: '#f0f0f0',
            border: '1px solid #ccc',
            cursor: 'pointer',
          }}
        >
          Submit Resume
        </button>

        {message && (
          <p style={{ marginTop: '0.5rem', color: message.includes('✅') ? 'green' : 'red' }}>
            {message}
          </p>
        )}
      </form>
    </div>
  );
}

export default SubmitResume;
