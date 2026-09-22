import React, { useState } from 'react'
import A from './A'

function LabApp() {

    const [name, setName] = useState('Priyanshi');
  return (
    <div>
      <A name = { name } setName={ setName }/>
    </div>
  )
}

export default LabApp
