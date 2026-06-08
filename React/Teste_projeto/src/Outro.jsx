import { useLocation, Link } from "react-router-dom"

function Outro() {
  const location = useLocation()
  const dados = location.state?.dados

  return (
    <>
      <h1>Apartamento: {dados?.titulo}</h1>
      <p>Descrição: {dados?.descricao}</p>
      <Link to="/">Voltar</Link>
    </>
  )
}

export default Outro
