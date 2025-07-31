import { useState } from 'react';

function PostJob() {
  const [formData, setFormData] = useState({
    jobTitle: '',
    position: '',
    employmentType: '',
    salaryAmount: '',
    payUnit: '',
  });

  const [message, setMessage] = useState('');
  const [loading, setLoading] = useState(false);

  const handleChange = (e) => {
    const { name, value } = e.target;
    setFormData(prev => ({ ...prev, [name]: value }));
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    setLoading(true);
    setMessage('');

    const { jobTitle, position, employmentType, salaryAmount, payUnit } = formData;
    const token = localStorage.getItem("token");

    const response = await fetch('/api/record', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
        Authorization: `Bearer ${token}`,
      },
      body: JSON.stringify({
        jobTitle,
        position,
        employmentType,
        salaryAmount,
        payUnit
      }),
    });

    setLoading(false);

    if (response.ok) {
      setMessage('✅ Job posted successfully!');
      setFormData({
        jobTitle: '',
        position: '',
        employmentType: '',
        salaryAmount: '',
        payUnit: '',
      });
    } else {
      setMessage('❌ Failed to post job.');
    }
  };

  return (
    <div style={{ maxWidth: '600px', margin: '0 auto' }}>
      <h2>Post a Job</h2>

      {loading && (
        <p style={{ color: 'gray', marginBottom: '1rem' }}>Submitting...</p>
      )}

      {!loading && message && (
        <p style={{ color: message.includes('✅') ? 'green' : 'red', marginBottom: '1rem' }}>
          {message}
        </p>
      )}

      <form
        onSubmit={handleSubmit}
        style={{
          display: 'flex',
          flexDirection: 'column',
          gap: '1rem',
        }}
      >
        <input
          name="jobTitle"
          placeholder="Job Title"
          value={formData.jobTitle}
          onChange={handleChange}
          required
          style={{ padding: '0.5rem', fontSize: '1rem' }}
        />
        <input
          name="position"
          placeholder="Position"
          value={formData.position}
          onChange={handleChange}
          required
          style={{ padding: '0.5rem', fontSize: '1rem' }}
        />
        <select
          name="employmentType"
          value={formData.employmentType}
          onChange={handleChange}
          required
          style={{ padding: '0.5rem', fontSize: '1rem' }}
        >
          <option value="">Select Employment Type</option>
          <option value="Full-Time">Full-Time</option>
          <option value="Part-Time">Part-Time</option>
        </select>
        <input
          name="salaryAmount"
          type="number"
          placeholder="Salary Amount"
          value={formData.salaryAmount}
          onChange={handleChange}
          required
          style={{ padding: '0.5rem', fontSize: '1rem' }}
        />
        <select
          name="payUnit"
          value={formData.payUnit}
          onChange={handleChange}
          required
          style={{ padding: '0.5rem', fontSize: '1rem' }}
        >
          <option value="">Select Pay Unit</option>
          <option value="per hour">per hour</option>
          <option value="per year">per year</option>
        </select>

        <button
          type="submit"
          disabled={loading}
          style={{
            padding: '0.75rem',
            fontSize: '1rem',
            fontWeight: 'bold',
            background: '#f0f0f0',
            border: '1px solid #ccc',
            cursor: loading ? 'not-allowed' : 'pointer',
          }}
        >
          Submit
        </button>
      </form>
    </div>
  );
}

export default PostJob;
