// Exercicio 1

const alunos = [
    { nome: "Liedson", notas: [20, 17, 19] },
    { nome: "Maria", notas: [10, 10, 10] },
    { nome: "João", notas: [15, 15, 15] },
    { nome: "Ana", notas: [18, 18, 18] },
];

function calcularMedia(nota) {
    let t = nota.length;
    let s = nota.reduce((a, b) => a + b);
    return (s / t).toFixed(2);
}

function classi(media){
    if (media >= 16) {
        return "Excelente";
    } else if (media >= 10) {
        return "Aprovado";
    } else {
        return "Reprovado";
    }
}

function imprimir() {
    console.log("Exercicio 1:\n------------------------\n");
    alunos.forEach(aluno => {
        console.log("Nome: " +  + calcularMedia(aluno.notas) + " classificacao: " + classi(calcularMedia(aluno.notas)));
    });

    console.log("\n------------------------\n");
}
// ----------------------------------------------------------

// Exercicio 2

let num = [-2, 5, 0, -1, 3, 8, -4];

function separarNegativo(vetor) {
    valorPositivo = vetor.filter(v => v > 0)
    return valorPositivo;
}

function multiplicar(vetor) {
    aux = vetor.map(v => v * 2)
    return aux;
}

function pares(vetor) {
    valorPares = vetor.filter(v => v % 2 === 0)
    return valorPares;
}

function somar(vetor) {
    return vetor.reduce((a, b) => a + b);
}

function imprimir2() {

    sem_Negas = separarNegativo(num);
    multiplicado = multiplicar(sem_Negas);
    Vpares = pares(multiplicado);
    soma = somar(Vpares);

    console.log("Exercicio 2:\n------------------------\n");
    console.log("Vetor original: " + num);

    console.log("Vetor sem negativos: " + sem_Negas);
    console.log("Vetor n*2 :" + multiplicado);
    console.log("Vetor com os pares: " + Vpares);
    console.log("Soma dos elementos: " + soma);

    console.log("\n------------------------\n");
}
// ------------------------------------------------------------

// Exercicio 3
const users = {
    usarname: "Liedson",
    password: "1234"
};

/*const cmd = require('readline');
const lerCmd = cmd.createInterface({
    input: process.stdin,
    output : process.stdout
});*/

let btn = document.getElementById('btn');

btn.addEventListener('click', imprimir3);

/*function ler() {
    lerCmd.question("Seu Utilizador: ", (utilizador) => {
    
        user = utilizador;

        lerCmd.question("Sua senha: ", (senha) => {
            pass = senha;
        })
        lerCmd.close();
    });
}*/

function validar(user, pass) {
    if (user === users.usarname && pass === users.password)
        return true;
    else
        return false;
}

function imprimir3() {

    let pass = document.getElementById('p').value;
    let user = document.getElementById('u').value;
    
    console.log("Exercicio 3:\n------------------------\n");
    
    //ler();
    const token = validar(user, pass);

    if (token) {
        console.log("Login Valido");
        alert("Login Valido");
    } else {
        console.log("Login Invalido");
        alert("Login Invalido");
    }
    console.log("\n------------------------\n");

}

// -------------------------------------------------------------

// exercicio 4 ---------------------------------

function imprimirN(num) {
    for (let i = 0; i < num; i++){
        if (i % 2 === 0)
            console.log(i + " e par");
        else
            console.log(i + " e impar");

        console.log("\n--------------------------------------\n");
    }
}

// -------------------------------------------------------------

// exercicio 5 ---------------------------------



// -------------------------------------------------------------


// exercicio 6 ---------------------------------

const pessoa = {
    nome: "Liesdon",
    idade: 20
}

function arrow(Pessoa) {
    return ("Nome: " + Pessoa.nome + " de idade: " + Pessoa.idade);
}

// -------------------------------------------------------------


// exercicio 7 ---------------------------------
Vnotas = [10, 11, 8, 9, 18, 20]

function contar(notas) {
    let valorescontados = {}
    let p = 0;
    let n = 0;

    for (let i = 0; i < notas.length; i++) {
        if (notas[i] >= 10)
            p++;
        else
            n++
    }

    valorescontados.positivos = p;
    valorescontados.negativos = n;

    return valorescontados;

}

// -------------------------------------------------------------


// exercicio 8 ---------------------------------


// -------------------------------------------------------------

// saidas
imprimir();
imprimir2();