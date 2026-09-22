import {React, useEffect, useState} from 'react'

function NameChange() {
  const [count, setCount] = useState(0)
  const [name, setName] = useState("abc")

//   useEffect(() => {
//     console.log("I run on initial mount AND every re-render")
//   })

//   useEffect(() => {
//     console.log("I run ONLY once when the component mounts")
//   }, [])

  useEffect(() => {
    console.log("I run on mount and whenever 'count' changes")
  }, [count])
  
  return (
    <>
       <h1>Count : {count}</h1>
       <button onClick={() => setCount(count + 1)}>Click</button>
       <h1>Name : {name}</h1>
       <button onClick={() => setName("xyz")}>Click</button>
    </>
  )
}

export default NameChange