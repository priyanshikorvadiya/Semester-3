import React from 'react';
import C from './C';

function B({ inputValue, setName, name }) {
  const handleClick = () => {
    setName(inputValue);
  };

  return (
    <div style={{ border: '1px solid #aaa', padding: '8px', margin: '8px' }}>
      <h4>Component B</h4>
      <button onClick={handleClick}>Set Name from Component A</button>
      <C name={name} />
    </div>
  );
}

export default B;