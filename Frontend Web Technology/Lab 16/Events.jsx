import React from 'react'

function ClickButton() {
  const handleClick = () =>{
    alert("Button was clicked!");
  }

  return(
    <button onClick={handleClick}>Click me</button>
  )
}

export default ClickButton
