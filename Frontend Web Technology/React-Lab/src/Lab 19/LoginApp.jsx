import React, { useState } from "react";

// --- Leaf Component (Receives props drilled through 2 parent levels) ---
function UserBadge({ user, onLogout }) {
  return (
    <div style={{ border: "1px dashed #555", padding: "12px", borderRadius: "6px" }}>
      <h4>User Badge Component</h4>
      <p>Logged in as: <strong>{user.name}</strong> ({user.email})</p>
      <button onClick={onLogout}>Log Out</button>
    </div>
  );
}

// --- Middle Component 2 (Passes props down to UserBadge) ---
function UserProfile({ user, onLogout }) {
  return (
    <div style={{ border: "1px solid #777", padding: "16px", margin: "10px 0", borderRadius: "8px" }}>
      <h3>User Profile Component</h3>
      <p>Passing props down further to UserBadge...</p>
      <UserBadge user={user} onLogout={onLogout} />
    </div>
  );
}

// --- Middle Component 1 (Passes props down to UserProfile) ---
function Dashboard({ user, onLogout }) {
  return (
    <div style={{ border: "2px solid #333", padding: "20px", margin: "10px 0", borderRadius: "8px" }}>
      <h2>Dashboard Component</h2>
      <p>Welcome to your workspace.</p>
      <UserProfile user={user} onLogout={onLogout} />
    </div>
  );
}

// --- Login Form Component ---
function LoginForm({ onLogin }) {
  const [username, setUsername] = useState("");
  const [email, setEmail] = useState("");

  const handleSubmit = (e) => {
    e.preventDefault();
    if (!username.trim() || !email.trim()) {
      alert("Please enter both username and email.");
      return;
    }
    onLogin({ name: username, email: email });
  };

  return (
    <form onSubmit={handleSubmit} style={{ border: "1px solid #ccc", padding: "20px", maxWidth: "300px" }}>
      <h3>Log In</h3>
      <div style={{ marginBottom: "10px" }}>
        <label>Username:</label>
        <br />
        <input
          type="text"
          value={username}
          onChange={(e) => setUsername(e.target.value)}
          required
        />
      </div>
      <div style={{ marginBottom: "10px" }}>
        <label>Email:</label>
        <br />
        <input
          type="email"
          value={email}
          onChange={(e) => setEmail(e.target.value)}
          required
        />
      </div>
      <button type="submit">Log In</button>
    </form>
  );
}

// --- Root Component (State Owner) ---
export default function LoginApp() {
  const [currentUser, setCurrentUser] = useState(null);

  const handleLogin = (userData) => {
    setCurrentUser(userData);
  };

  const handleLogout = () => {
    setCurrentUser(null);
  };

  return (
    <div style={{ fontFamily: "sans-serif", padding: "20px" }}>
      <h1>React App (Prop Drilling Demo)</h1>

      {!currentUser ? (
        <LoginForm onLogin={handleLogin} />
      ) : (
        /* Prop drilling happens here: passing user and onLogout down the chain */
        <Dashboard user={currentUser} onLogout={handleLogout} />
      )}
    </div>
  );
}