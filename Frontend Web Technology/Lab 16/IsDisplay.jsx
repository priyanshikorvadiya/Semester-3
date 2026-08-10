import React from 'react'
export default function DisplayElement() {
  const isDisplay = true;

  return (
    <div>
      {isDisplay ? <h3>Visible</h3> : <h3>Invisible!</h3>}
    </div>
  );
}
