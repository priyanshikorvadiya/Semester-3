import React, { useState } from 'react';
import AuthContainer from './AuthContainer';

function Lab18C() {
  const [isAuthenticated, setIsAuthenticated] = useState(false);
  const [user, setUser] = useState(null);
  const [error, setError] = useState('');

  const handleLogin = (username, password) => {
    if (username === 'admin' && password === 'admin123') {
      setIsAuthenticated(true);
      setUser({ username });
      setError('');
    } else {
      setError('Invalid username or password!');
    }
  };

  const handleLogout = () => {
    setIsAuthenticated(false);
    setUser(null);
    setError('');
  };

  return (
    <div>
      <h2>Lab 18 - Part C</h2>
      <AuthContainer
        isAuthenticated={isAuthenticated}
        user={user}
        onLogin={handleLogin}
        onLogout={handleLogout}
        error={error}
      />
    </div>
  );
}

export default Lab18C;