import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import './index.css'
import App from './App.jsx'
import Hello from './Lab 14/Hello'
import HelloClass from './Lab 14/HelloClass'
import Events from './Lab 16/Events.jsx'

createRoot(document.getElementById('root')).render(
  <StrictMode>
    <App />

    {/* <Hello/>
    <HelloClass/> */}
    
  </StrictMode>,
)
