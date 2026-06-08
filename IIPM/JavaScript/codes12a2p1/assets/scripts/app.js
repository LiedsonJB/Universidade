const valorDefeito = 0;
let resultadoCorrente = valorDefeito;

let listaRegistos = [];

function getUserNumberInput() {
  return parseInt(userInput.value);
}

function criarEmostrarOutput(operador, resultadoAntesCalc, numCalculado) {
  const descriCalculo = `${resultadoAntesCalc} ${operador} ${numCalculado}`;
  outputResult(resultadoCorrente, descriCalculo);
}

function escreverRegisto(operador,
  resultadoAnt,
  operando,
  resultado
){

  const entradaRegisto = {
    operador: operador,
    resultadoAnt: resultadoAnt,
    numero: operando,
    resultado: resultado
  }
  listaRegistos.push(entradaRegisto);
  console.log(listaRegistos);
}

const realizarCalculo = (operador)=>{
  if(operador === "Adicionar"){

    const valorDigitado = getUserNumberInput();
    const resultIni = resultadoCorrente;
    resultadoCorrente += valorDigitado;
    criarEmostrarOutput('+', resultIni, valorDigitado);
    escreverRegisto("Adicao", resultIni, valorDigitado,resultadoCorrente);

  }else if(operador === "Subtrair"){

    const valorDigitado = getUserNumberInput();
    const resultIni = resultadoCorrente;
    resultadoCorrente -= valorDigitado;
    criarEmostrarOutput('-', resultIni, valorDigitado);
    escreverRegisto("Subtracao", resultIni, valorDigitado, resultadoCorrente);

  }else if(operador === "Multiplicacao"){

    const valorDigitado = getUserNumberInput();
    const resultIni = resultadoCorrente;
    resultadoCorrente *= valorDigitado;
    criarEmostrarOutput('*', resultIni, valorDigitado);
    escreverRegisto("Multiplicacao", resultIni, valorDigitado,resultadoCorrente);
    
  }else if(operador === "dividir"){

    const valorDigitado = getUserNumberInput();
    const resultIni = resultadoCorrente;
    resultadoCorrente /= valorDigitado;
    criarEmostrarOutput('/', resultIni, valorDigitado);
    escreverRegisto("divisao", resultIni, valorDigitado,resultadoCorrente);

  }else{

  }
}

function adicionar() {
  realizarCalculo('Adicionar');

  /*const valorDigitado = getUserNumberInput();
  const resultIni = resultadoCorrente;
  resultadoCorrente += valorDigitado;
  criarEmostrarOutput('+', resultIni, valorDigitado);
  escreverRegisto("Adicao", resultIni, valorDigitado,resultadoCorrente);*/
}

function subtrair() {
  realizarCalculo('Subtrair');

  /*const valorDigitado = getUserNumberInput();
  const resultIni = resultadoCorrente;
  resultadoCorrente -= valorDigitado;
  criarEmostrarOutput('-', resultIni, valorDigitado);
  escreverRegisto("Subtracao", resultIni, valorDigitado, resultadoCorrente);*/
}

function multiplicar() {
  realizarCalculo('Multiplicacao');

  /*const valorDigitado = getUserNumberInput();
  const resultIni = resultadoCorrente;
  resultadoCorrente *= valorDigitado;
  criarEmostrarOutput('*', resultIni, valorDigitado);
  escreverRegisto("Multiplicacao", resultIni, valorDigitado,resultadoCorrente);*/
}

function dividir() {
  realizarCalculo('dividir');

  /*const valorDigitado = getUserNumberInput();
  const resultIni = resultadoCorrente;
  resultadoCorrente /= valorDigitado;
  criarEmostrarOutput('/', resultIni, valorDigitado);
  escreverRegisto("divisao", resultIni, valorDigitado,resultadoCorrente);*/
}

//addBtn.addEventListener('click', adicionar())
addBtn.addEventListener('click', adicionar);
subtractBtn.addEventListener('click', subtrair);
multiplyBtn.addEventListener('click', multiplicar);
divideBtn.addEventListener('click', dividir);

