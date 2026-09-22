import React from 'react';
import LoginForm from './LoginForm';
import UserProfile from './UserProfile';

function AuthContent({ isAuthenticated, user, onLogin, onLogout, error }) {
  return (
    <div>
      {isAuthenticated ? (
        <UserProfile user={user} onLogout={onLogout} />
      ) : (
        <LoginForm onLogin={onLogin} error={error} />
      )}
    </div>
  );
}

export default AuthContent;