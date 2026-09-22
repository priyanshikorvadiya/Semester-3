import React, { useState } from 'react';
import B from './B';

function A({ name, setName }) {
  const [localInput, setLocalInput] = useState('');

  return (
    <div style={{ border: '1px solid #aaa', padding: '8px', margin: '8px' }}>
      <h4>Component A</h4>
      <input
        type="text"
        placeholder="Enter name in A"
        value={localInput}
        onChange={(e) => setLocalInput(e.target.value)}
      />
      <B inputValue={localInput} setName={setName} name={name} />
    </div>
  );
}

export default A;