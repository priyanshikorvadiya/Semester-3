import React from 'react';
import AuthContent from './AuthContent';

function AuthContainer({ isAuthenticated, user, onLogin, onLogout, error }) {
  return (
    <div>
      <AuthContent
        isAuthenticated={isAuthenticated}
        user={user}
        onLogin={onLogin}
        onLogout={onLogout}
        error={error}
      />
    </div>
  );
}

export default AuthContainer;