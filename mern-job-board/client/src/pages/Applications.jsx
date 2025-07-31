import { useEffect, useState } from 'react';
import { useParams } from 'react-router-dom';

function Applications() {
  const { jobId } = useParams();
  const [resumes, setResumes] = useState([]);

  useEffect(() => {
    fetch('/api/record')
      .then(res => res.json())
      .then(data => {
        const filtered = data.filter(
          item => item.type === 'resume' && String(item.positionId) === String(jobId)
        );
        setResumes(filtered);
      });
  }, [jobId]);

  return (
    <div>
      <h2>Applications for Job ID: {jobId}</h2>
      {resumes.length === 0 ? (
        <p>No applications yet.</p>
      ) : (
        <ul>
          {resumes.map((resume, index) => (
            <li key={index}>
              <strong>Name:</strong> {resume.name}<br />
              <strong>Position:</strong> {resume.position}<br />
              <strong>Resume:</strong> {resume.level}
            </li>
          ))}
        </ul>
      )}
    </div>
  );
}

export default Applications;
