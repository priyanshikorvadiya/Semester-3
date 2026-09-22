import React from 'react'
import { Link, Outlet } from 'react-router-dom'

function LabLayout() {
  return (
    <div>
      <nav>
        <Link to="/lab20/home">Home</Link> | {" "}
        <Link to="/lab20/about">About</Link> | {" "}
        <Link to="/lab20/services">Services</Link> | {" "}
        <Link to="/lab20/contact">Contact</Link>
      </nav>

      <Outlet />
    </div>
  )
}

export default LabLayout