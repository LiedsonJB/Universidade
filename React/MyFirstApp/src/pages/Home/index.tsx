import {} from 'react'
import './style.css'
import Teste from "./../../assets/react.svg"

function Home() {

  const users = [{

    id: "123",
    name: "teste",
    email: "teste@gmail.com"

  }]


  return (
    <div className='container'>
      <form action="">
        <h1>Cadastra Utilizadores</h1>

        <input type='text' name='nome' />
        <input type='number' name='idade' />
        <input type='email' name='email' />

        <button type='button'>Cadastrar</button>        

      </form>

      <div>
        <p>Nome: </p>
        <p>Idade </p>
        <p>Email: </p>
      </div>

      <button>
        <img src={Teste}/>        
      </button>

    </div>
  )
}

export default Home