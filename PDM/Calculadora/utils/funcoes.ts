import { Alert } from 'react-native';

let status = true;

const getValores = (newValor: string, valor: string, setValor: (v: string) => void, ) => {
  const ultimoValor = valor.at(-1);
  const operadores = ['*', '/', '+', '-',];

  if ((newValor === ultimoValor) && operadores.includes(newValor))
    return;

  if (valor === '' && newValor === '%')
    return;

  if (((newValor === '/') || (newValor === '*')) && valor === '') {
    setValor('0' + newValor)
    return;
  }

  if(operadores.includes(ultimoValor ||  '') && newValor === '%'){
    Alert.alert(`nao e possivel  ${newValor} depois de uma operacao`)
    return
  }

  if (operadores.includes(newValor)) {

    if (operadores.includes(ultimoValor || '')) {

      setValor(valor.slice(0, -1) + newValor);

      return;
    }

    status = true;
    setValor(valor + newValor);

    return;
  }

  if (newValor === '.') {
    if (status) {

      status = false;
      setValor(valor + newValor);

    } else {

      return;
    }

    return;
  }

  setValor(valor + newValor);
};

const AC = (setValor: (v: string) => void) => {
  status = true;
  setValor('');
};

const del = (valor: string, setValor: (v: string) => void) => {

  valor = valor.slice(0, -1);

  const partes = valor.split(/[+\-*/%]/);
  const ultimoNumero = partes[partes.length - 1];

  if (ultimoNumero.includes('.')) {
    status = false;
  } else {
    status = true;
  }

  setValor(valor);
}


const calcularResultado = (valor: string, setResultado: (v: string) => void) => {
  if (valor === '') {
    setResultado('');
    return;
  }

  try {
    let newValor = valor;

    while (/[+\-*/.]$/.test(newValor)) {
      newValor = newValor.slice(0, -1);
    }

    // caso de remover o sinal no final e nao houver mais nenhum valor 
    if (newValor === '') 
      return;

    // tratar da % subtituindo por n*(1/100)
    let aux = newValor.replace(/(\d+\.?\d*)%/g, "($1/100)");

    // eslint-disable-next-line no-new-func
    const res = new Function(`return ${aux}`)();

    // evitar divisao por 0
    if (!isFinite(res)) {
      setResultado("Erro"); 
      return;
    }

    if (res !== undefined) {

      const resultadoFinal = parseFloat(res.toFixed(5)).toString();
      setResultado(resultadoFinal);
    }
  } catch (e) {
    
    console.log(e)
    Alert.alert("Opps ocorreu um erro")
    
  }

};


const getResultado = (valor: string, setValor: (v: string) => void, resultado: string) => {

  setValor(resultado)
  
}

export { getValores, AC, del, getResultado, calcularResultado };
