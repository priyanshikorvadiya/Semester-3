import React, { useState } from 'react';

export default function Calc() {
  const [display, setDisplay] = useState('0');

  const handleClick = (val) => {
    setDisplay((prev) => (prev === '0' ? val : prev + val));
  };

  const handleClear = () => setDisplay('0');

  const handleCalculate = () => {
    try {
      setDisplay(String(Function(`'use strict'; return (${display})`)()));
    } catch {
      setDisplay('Error');
    }
  };

  return (
    <div style={{ width: 200, margin: '20px auto', textAlign: 'center' }}>
      <div style={{ border: '1px solid #ccc', padding: 10, fontSize: 20, marginBottom: 10 }}>
        {display}
      </div>
      <div style={{ display: 'grid', gridTemplateColumns: 'repeat(4, 1fr)', gap: 5 }}>
        <button onClick={handleClear} style={{ gridColumn: 'span 3' }}>C</button>
        <button onClick={() => handleClick('/')}>/</button>
        
        {['7', '8', '9'].map((n) => <button key={n} onClick={() => handleClick(n)}>{n}</button>)}
        <button onClick={() => handleClick('*')}>*</button>
        
        {['4', '5', '6'].map((n) => <button key={n} onClick={() => handleClick(n)}>{n}</button>)}
        <button onClick={() => handleClick('-')}>-</button>
        
        {['1', '2', '3'].map((n) => <button key={n} onClick={() => handleClick(n)}>{n}</button>)}
        <button onClick={() => handleClick('+')}>+</button>
        
        <button onClick={() => handleClick('0')} style={{ gridColumn: 'span 2' }}>0</button>
        <button onClick={() => handleClick('.')}>.</button>
        <button onClick={handleCalculate}>=</button>
      </div>
    </div>
  );
}