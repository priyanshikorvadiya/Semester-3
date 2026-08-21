import React from 'react'

function Fruits() {
  let fruits = ["Mango", "Strawberry"];
  return (
    <>
        <h2>Fruits List</h2>
        {fruits.map((i)=>(
            <p>{i}</p>
            )
        )}
    </>
  )
}

export default Fruits