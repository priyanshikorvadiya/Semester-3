import React, { useState } from 'react'
import C from './C'

function B({ name , setName}) {

    const [input , setInput] = useState("");
  return (
    <>
      <input type="text" onChange={(e) => setInput(e.target.value)}></input>

      <button onClick={() => setName(input)}> 
        Set Name
      </button>

      <C name = {name}/>
    </>
  )
}

export default B
