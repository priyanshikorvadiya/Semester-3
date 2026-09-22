import React from 'react';

function UserProfile({ user, onLogout }) {
  return (
    <div>
      <h3>Login Successful</h3>
      <p>Welcome, {user.username}!</p>
      <button onClick={onLogout}>Logout</button>
    </div>
  );
}

export default UserProfile;