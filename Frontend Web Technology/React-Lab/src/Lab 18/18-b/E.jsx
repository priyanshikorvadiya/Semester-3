import React from 'react';
import F from './F';

function E({ name }) {
  return (
    <div style={{ border: '1px solid #aaa', padding: '8px', margin: '8px' }}>
      <h4>Component E</h4>
      <F name={name} />
    </div>
  );
}

export default E;