import React from 'react'
import { Link, Outlet } from 'react-router-dom'

function MainLayout() {
  return (
    <div>

        <nav>
            <Link to="/Lab18/18-a"> 18 - a</Link> | {"    "}
            <Link to="/Lab18/18-b"> 18 - b</Link> | {"    "}
            <Link to="/Lab18/18-c"> 18 - c</Link>
        </nav>
      <Outlet/>
    </div>
  )
}

export default MainLayout
