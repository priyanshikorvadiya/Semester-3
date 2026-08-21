import React from 'react'

function Faculties() {
  let fac = ["Bala Sir", "Deep Sir", "Jadeja Sir", "Dhvanik Sir"];
  return (
    <>
        <h2>Faculties List</h2>
        {fac.map((i)=>(
            <p>{i}</p>
            )
        )}
    </>
  )
}

export default Faculties