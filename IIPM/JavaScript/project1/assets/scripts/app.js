
let resultado = 0;
let meuResultado;
function lerInput(){
    const valorDigitado = parseInt(userInput.value);
    return valorDigitado;
}

function adicionar(){
    const valorLido = lerInput();
    meuResultado = document.getElementById('current-result').innerText;
    resultado = resultado + valorLido;
    const descri = `somar ${meuResultado} com  ${valorLido}`
    outputResult(resultado, descri);
}
function subtrair(){
    const valorLido = lerInput();
    meuResultado = document.getElementById('current-result').innerText;
    resultado = resultado - valorLido;
    const descri = `Subtrair ${meuResultado} com - ${valorLido}`
    outputResult(resultado, descri);
}
function multipicar(){
    const valorLido = lerInput();
    meuResultado = document.getElementById('current-result').innerText;
    resultado = resultado * valorLido;
    const descri = `Multiplicar ${meuResultado} com * ${valorLido}`
    outputResult(resultado, descri);
}
function dividir(){
    const valorLido = lerInput();
    meuResultado = document.getElementById('current-result').innerText;
    if(valorLido === 0){
        alert("Erro ao dividir o numero " + meuResultado + " por zero");
        return null;
    }
    
    resultado = resultado * valorLido;
    const descri = `Dividir ${meuResultado} com  ${valorLido}`
    outputResult(resultado, descri);
}

addBtn.addEventListener('click', adicionar);
subtractBtn.addEventListener('click',subtrair);
multiplyBtn.addEventListener('click',multipicar);
divideBtn.addEventListener('click',dividir);