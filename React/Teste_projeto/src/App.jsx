import { useState } from "react"
import { Routes, Route } from "react-router-dom"
import Home from "./Home"
import './App.css'
import Outro from "./Outro"

function App() {
  const [apartamentos, setApartamentos] = useState([])

  return (
    <Routes>
      <Route
        path="/"
        element={<Home apartamentos={apartamentos} setApartamentos={setApartamentos} />}
      />
      <Route
        path="/outro"
        element={<Outro />}
      />
    </Routes>
  )
}

export default App
