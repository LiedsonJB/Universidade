const express = require('express');
const cors = require('cors');    // utilizar mais de uma porta

const app = express(); 

app.use(cors()); // utilizar mais portas

// endpoint do front-end requesicao 
app.get('/back.js', (req, res) => {
    console.log("conectado com frontend")
    res.send("backend responde: Ola Liedson");
});

//servidor rodando na porta 3000
app.listen(3000, () => {
    console.log("Servidor rodando na porta 3000");
});