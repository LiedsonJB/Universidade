let BaseDados = [];
let Lixeira = [];
const btn = document.getElementById('btn');
const show = document.getElementById('show');

function criar_JSON(nome, number) {
    // Criando o objeto de forma simples
    return {
        name: nome,
        number: number
    };
}

function ler_Campos() {
    const nome = document.getElementById('name').value;
    const number = document.getElementById('number').value;
    // Retornamos como um array para desestruturar depois
    return [nome, number];
}

function imprimir() {
    // Verificamos se o array está vazio
    if (BaseDados.length === 0) {
        show.innerHTML = "<p>OBS: Sem utilizadores</p>";
        return;
    }

    // Usamos map para gerar a lista e join para transformar em string
    const html = BaseDados.map(user => `
        <p>
            Nome do user: ${user.name}<br>
            Seu número: ${user.number}<br>
            ------------------------------
        </p>
    `).join('');

    show.innerHTML = html;
}

function eliminarU(nome) {
    let i = BaseDados.findIndex((bd) => bd.name === nome);

    if (i !== -1) {
        Lixeira.push(BaseDados[i]);
        BaseDados.splice(i, 1);
        alert(`User: ${nome} eliminado com sucesso`); // Usando crases
        imprimir(); // Atualiza a tela após eliminar
    } else {
        alert(`Impossivel encontrar ${nome}`);
    }
}

function main1(event) {
    
    const [nome, num] = ler_Campos(); // Captura os valores do array retornado

    if (nome === "" || num === "") {
        return alert("Preencha os campos para criar um novo user");
    }

    const novoUser = criar_JSON(nome, num);
    BaseDados.push(novoUser);
    
    imprimir(); // Mostra na tela assim que adiciona
}

btn.addEventListener('click', main1);