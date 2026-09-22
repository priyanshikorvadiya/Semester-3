import React from 'react';

function F({ name }) {
  return (
    <div style={{ border: '1px solid #aaa', padding: '8px', margin: '8px' }}>
      <h4>Component F</h4>
      <p>State from App: <strong>{name}</strong></p>
    </div>
  );
}

export default F;