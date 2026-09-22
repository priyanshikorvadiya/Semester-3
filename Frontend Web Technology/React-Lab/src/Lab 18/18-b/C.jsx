import React from 'react';
import D from './D';

function C({ name }) {
  return (
    <div style={{ border: '1px solid #aaa', padding: '8px', margin: '8px' }}>
      <h4>Component C</h4>
      <D name={name} />
    </div>
  );
}

export default C;