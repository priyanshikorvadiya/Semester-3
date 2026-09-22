import React from 'react';
import E from './E';

function D({ name }) {
  return (
    <div style={{ border: '1px solid #aaa', padding: '8px', margin: '8px' }}>
      <h4>Component D</h4>
      <E name={name} />
    </div>
  );
}

export default D;