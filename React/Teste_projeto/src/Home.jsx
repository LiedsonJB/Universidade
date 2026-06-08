import { useState } from 'react'
import { Link, } from 'react-router-dom'
import './App.css'


function Home({ apartamentos, setApartamentos }) {
  const [titulo, setTitulo] = useState("")
  const [descricao, setDescricao] = useState("")

  const submeter = () => {
    if (!titulo.trim() || !descricao.trim()) {
      alert("Campos vazios")
      return
    }
    setApartamentos([...apartamentos, { titulo, descricao }])
    setTitulo("")
    setDescricao("")
  }

  return (
    <>
      <section id="center">
        <input name='titulo'
          type="text"
          placeholder="Nome do Apartamento"
          value={titulo}
          onChange={(e) => setTitulo(e.target.value)}
        />
        <textarea name='descricao' 
          placeholder="Descrição"
          value={descricao}
          onChange={(e) => setDescricao(e.target.value)}
        />
        <button onClick={submeter} type='button' id='btn'>Submeter</button>
      </section>

      <section id="footer">
        {apartamentos.length === 0 ? (
          <p>Sem elementos</p>
        ) : (
          apartamentos.map((dados, index) => (
           <div key={index} id='views'>
              <p>{dados.titulo}</p>
             
              <Link to="/outro" state={{ dados }}>Ver descrição</Link>
            </div>
          ))
        )}
      </section>
    </>
  )
}

export default Home
