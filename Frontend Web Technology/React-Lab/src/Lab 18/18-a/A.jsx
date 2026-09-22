import React from 'react'
import B from './B'

function A({name , setName}) {
  return (
    <div>
      <B name = { name } setName={ setName }/>
    </div>
  )
}

export default A
