import React from 'react';
import { Outlet, Link } from 'react-router-dom';

function Layout() {
  return (
    <div className="layout-container">
     
      <nav className="navbar">
        <Link to="/" className="nav-link">Home</Link> | {"    "}
        <Link to="/Lab14" className="nav-link">Lab 14</Link> | {"    "}
        <Link to="/Lab15" className="nav-link">Lab 15</Link> | {"    "}
        <Link to="/Lab16" className="nav-link">Lab 16</Link> | {"    "}
        <Link to="/Lab17" className="nav-link">Lab 17</Link> | {"    "}
        <Link to="/Lab18" className="nav-link">Lab 18</Link> | {"    "}
        <Link to="/Lab19" className="nav-link">Lab 19</Link> | {"    "}
        <Link to="/Lab20" className="nav-link">Lab 20</Link> | {"    "}
        <Link to="/Lab21" className="nav-link">Lab 21</Link> | {"    "}
        <Link to="/Lab22" className="nav-link">Lab 22</Link> | {"    "}
        <Link to="/Lab23" className="nav-link">Lab 23</Link>
      </nav>

      <main className="content-container">
        <Outlet />
      </main>
    </div>
  );
}

export default Layout;