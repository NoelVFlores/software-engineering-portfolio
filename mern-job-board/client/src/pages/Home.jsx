import { useEffect, useState } from 'react';
import { Link } from 'react-router-dom';

function Home() {
  const [jobs, setJobs] = useState([]);
  const [userName, setUserName] = useState('');
  const [userRole, setUserRole] = useState('');
  const [isLoggedIn, setIsLoggedIn] = useState(false);

  // Load jobs
  useEffect(() => {
    fetch('/api/record')
      .then(res => res.json())
      .then(data => {
        const filtered = data.filter(item => !item.type || item.type === 'job');
        setJobs(filtered);
      });
  }, []);

  // Decode token and set login info
  useEffect(() => {
    const token = localStorage.getItem('token');
    if (token) {
      try {
        const payload = JSON.parse(atob(token.split('.')[1]));
        console.log('Decoded token payload:', payload);

        const name = payload['cognito:username'] || payload['email'] || 'User';
        const groups = payload['cognito:groups'] || [];
        const isAdmin = groups.includes('admin');

        setUserName(name);
        setUserRole(isAdmin ? 'Admin' : 'User');
        setIsLoggedIn(true);
      } catch (err) {
        console.error('Failed to decode token:', err);
      }
    }
  }, []);

  return (
    <div style={{ maxWidth: '700px', margin: '0 auto' }}>
      {userName && (
        <p>
          Welcome, <strong>{userName}</strong>! Role: <strong>{userRole}</strong>
        </p>
      )}

      <h2>Job Listings</h2>
      {!isLoggedIn && <p>Login to begin applying.</p>}

      <ul style={{ listStyleType: 'none', padding: 0 }}>
        {jobs.map((job, index) => (
          <li
            key={index}
            style={{
              borderBottom: '1px solid #ccc',
              padding: '1rem 0',
              marginBottom: '1rem',
            }}
          >
            <p style={{ margin: 0 }}>
              <strong>{job.jobTitle}</strong> - {job.position}
            </p>
            <p style={{ margin: '0.5rem 0' }}>
              Type: {job.employmentType} | Salary: ${Number(job.salaryAmount).toLocaleString()} {job.payUnit}
            </p>
            <div style={{ marginTop: '0.5rem' }}>
              {isLoggedIn && (
                <Link to={`/apply/${job._id}`} style={{ marginRight: '1rem' }}>
                  Apply
                </Link>
              )}
              {userRole === 'Admin' && (
                <Link to={`/applications/${job._id}`}>View Applications</Link>
              )}
            </div>
          </li>
        ))}
      </ul>
    </div>
  );
}

export default Home;
