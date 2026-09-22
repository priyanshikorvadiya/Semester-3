import React, { useState } from 'react';
import A from './A';

function Lab18B() {
  const [name, setName] = useState('Initial Name');

  return (
    <div>
      <A name={name} setName={setName} />
    </div>
  );
}

export default Lab18B;