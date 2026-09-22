import React from 'react'
import { BrowserRouter, Routes, Route } from 'react-router-dom'
import './App.css'

import Layout from './Layout'
import Home from './Home'

import Hello from './Lab 14/Hello'
import HelloWorld from './Lab 14/HelloClass'

import Header from './Lab 15/Header'
import Footer from './Lab 15/Footer'

import ClickButton from './Lab 16/Events'
import IsDisplay from './Lab 16/IsDisplay'
import Props from './Lab 16/Props'

import Faculties from './Lab 17/Faculties'
import Fruits from './Lab 17/Fruits'
import Students from './Lab 17/Students'

import MainLayout from './Lab 18/MainLayout'
import LabApp from './Lab 18/18-a/LabApp'
import LabAppB from './Lab 18/18-b/LabApp'
import LabAppC from './Lab 18/18-c/LabApp'

import LoginApp from './Lab 19/LoginApp'

import LabLayout from './Lab 20/LabLayout'
import Lab20Home from './Home'
import About from './Lab 20/About'
import Contact from './Lab 20/Contact'
import Services from './Lab 20/Services'

import Count from './Lab 21/Count'
import NameChange from './Lab 21/NameChange'

import SimpleCalc from './Lab 22/SimpleCalc'
import SciCalc from './Lab 22/SciCalc'

import Product from './Lab 23/Product'
import Student from './Lab 23/Student'
import Faculty from './Lab 23/Faculty'


function Lab14() {
  return (
    <>
      <Hello />
      <hr />
      <HelloWorld />
    </>
  )
}

function Lab15() {
  return (
    <>
      <Header />
      <hr />
      <Footer />
    </>
  )
}

function Lab16() {
  return (
    <>
      <ClickButton />
      <hr />
      <IsDisplay />
      <hr />
      <Props name='Shreena' age='18'/>
    </>
  )
}

function Lab17() {
  return (
    <>
      <Faculties />
      <hr />
      <Fruits />
      <hr />
      <Students />
      <hr />
     
    </>
  )
}

function Lab18(){
  return(
    <>
      <MainLayout />
    </>
  )
}

function Lab19(){
  return(
    <>
      <LoginApp/>
    </>
  )
}

function Lab21() {
  return (
    <>
      <Count />
      <hr />
      <NameChange />
    </>
  )
}

function Lab22(){
  return(
    <>
      <SimpleCalc/>
      <hr/>
      <SciCalc/>
    </>
  )
}

function Lab23(){
  return(
    <>
      <Product/>
      <hr/>
      <Student/>
      <hr/>
      <Faculty/>
    </>
  )
}

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Layout />}>
          <Route index element={<Home />} />
          
          <Route path="lab14" element={<Lab14 />} />
          <Route path="lab15" element={<Lab15 />} />
          <Route path="lab16" element={<Lab16 />} />
          <Route path="lab17" element={<Lab17 />} />

          <Route path="lab18" element={<MainLayout />}>
            <Route path="18-a" element={<LabApp/>}></Route>
            <Route path="18-b" element={<LabAppB/>}></Route>
            <Route path="18-c" element={<LabAppC/>}></Route>
          </Route>

          <Route path="lab19" element={<Lab19 />} />

          <Route path="lab20" element={<LabLayout />}>
            <Route index element={<Lab20Home />} />
            <Route path="home" element={<Lab20Home />} />
            <Route path="about" element={<About />} />
            <Route path="services" element={<Services />} />
            <Route path="contact" element={<Contact />} />
          </Route>

          <Route path="lab21" element={<Lab21 />} />

          <Route path="lab22" element={<Lab22 />} />

          <Route path="lab23" element={<Lab23 />} />
        </Route>
      </Routes>
    </BrowserRouter>
  )
}

export default App