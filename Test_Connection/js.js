btn = document.getElementById('btn').addEventListener('click', conectar);


async function conectar(params) {      
 
    try {
        const resposta = await fetch('http://localhost:3000/back.js'); //requesicao com o backend
        const txt = await resposta.text();

        alert("Backend respondeu");
        console.log("Backende =>: ", txt); // mostrar a resposta do backend
    
    } catch (error){        //caso de erro na coneccao
        console.log(error);
    }
}