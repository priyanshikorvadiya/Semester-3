import React, { useState } from 'react';

export default function SciCalc() {
  const [display, setDisplay] = useState('0');

  const handleClick = (val) => {
    setDisplay((prev) => (prev === '0' ? val : prev + val));
  };

  const handleClear = () => setDisplay('0');

  const handleCalculate = () => {
    try {
      // Replaces common scientific tokens with standard JS Math equivalents
      let expr = display
        .replace(/sin\(/g, 'Math.sin(')
        .replace(/cos\(/g, 'Math.cos(')
        .replace(/tan\(/g, 'Math.tan(')
        .replace(/log\(/g, 'Math.log10(')
        .replace(/ln\(/g, 'Math.log(')
        .replace(/sqrt\(/g, 'Math.sqrt(')
        .replace(/pi/g, 'Math.PI')
        .replace(/\^/g, '**');

      const result = Function(`'use strict'; return (${expr})`)();
      setDisplay(String(Number(result.toFixed(8))));
    } catch {
      setDisplay('Error');
    }
  };

  return (
    <div style={{ width: 340, margin: '20px auto', textAlign: 'center' }}>
      <div style={{ border: '1px solid #ccc', padding: 10, fontSize: 20, marginBottom: 10, minHeight: 28, wordWrap: 'break-word' }}>
        {display}
      </div>

      <div style={{ display: 'grid', gridTemplateColumns: 'repeat(5, 1fr)', gap: 5 }}>
        {/* Row 1 */}
        <button onClick={() => handleClick('sin(')}>sin</button>
        <button onClick={() => handleClick('cos(')}>cos</button>
        <button onClick={() => handleClick('tan(')}>tan</button>
        <button onClick={() => handleClick('(')}>(</button>
        <button onClick={() => handleClick(')')}>)</button>

        {/* Row 2 */}
        <button onClick={() => handleClick('sqrt(')}>√</button>
        <button onClick={() => handleClick('^')}>^</button>
        <button onClick={() => handleClick('log(')}>log</button>
        <button onClick={() => handleClick('ln(')}>ln</button>
        <button onClick={() => handleClick('pi')}>π</button>

        {/* Row 3 */}
        <button onClick={handleClear} style={{ gridColumn: 'span 4' }}>C</button>
        <button onClick={() => handleClick('/')}>/</button>

        {/* Row 4 */}
        {['7', '8', '9'].map((n) => <button key={n} onClick={() => handleClick(n)}>{n}</button>)}
        <button onClick={() => handleClick('*')}>*</button>
        <button onClick={() => handleClick('-')}>-</button>

        {/* Row 5 */}
        {['4', '5', '6'].map((n) => <button key={n} onClick={() => handleClick(n)}>{n}</button>)}
        <button onClick={() => handleClick('+')}>+</button>
        <button onClick={() => handleClick('.')}>.</button>

        {/* Row 6 */}
        {['1', '2', '3'].map((n) => <button key={n} onClick={() => handleClick(n)}>{n}</button>)}
        <button onClick={() => handleClick('0')}>0</button>
        <button onClick={handleCalculate}>=</button>
      </div>
    </div>
  );
}