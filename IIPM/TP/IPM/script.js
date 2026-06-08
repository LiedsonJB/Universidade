const moluscos = [
    {
        nome: "Ancylus milleri",
        descricao: "Testa cónica e transparente, vértice obtuso projetado para trás.",
        habitat: "Água doce (riachos).",
        origem: "Endémica.",
        conservacao: "Extinta (EX).",
        distribuicao: ["Santiago"]
    },
    {
        nome: "Bulinus forskalii",
        descricao: "Molusco oblongo com estrias transversais finas e espiral de 3,5 voltas.",
        habitat: "Não especificado.",
        origem: "Nativa.",
        conservacao: "Vulnerável (VU), Pouco Preocupante (LC).",
        distribuicao: ["São Nicolau", "Boa Vista", "Santiago"]
    },
    {
        nome: "Radix natalensis ssp. stuebeli",
        descricao: "Concha em forma de rim, alongada, com estrias finas e transparentes.",
        habitat: "Não especificado.",
        origem: "Endémica.",
        conservacao: "Vulnerável (VU).",
        distribuicao: ["São Nicolau", "Boa Vista", "Santiago"]
    },
    {
        nome: "Radix auricularia ssp. ribeirensis",
        descricao: "Concha subperfurada em forma de ampulheta, com estrias finas.",
        habitat: "Não especificado.",
        origem: "Endémica.",
        conservacao: "Em Perigo (EN).",
        distribuicao: ["Santo Antão"]
    },
    {
        nome: "Cecilioides acicula",
        descricao: "Concha turriforme-cilíndrica, transparente e brilhante.",
        habitat: "Nas raízes das árvores.",
        origem: "Introduzida provável.",
        conservacao: "Vulnerável (VU), Pouco Preocupante (LC).",
        distribuicao: ["Santo Antão", "São Vicente", "São Nicolau", "Sal", "Boa Vista", "Maio", "Santiago", "Fogo", "Brava"]
    },
    {
        nome: "Eremina advena",
        descricao: "Concha castanho-amarelada com faixas escuras variáveis.",
        habitat: "Sob pedras e raízes de Euphorbias.",
        origem: "Endémica.",
        conservacao: "Em Perigo Crítico (CR).",
        distribuicao: ["Santo Antão", "São Vicente", "São Nicolau", "Maio", "Santiago", "Fogo", "Brava"]
    },
    {
        nome: "Eremina myristica",
        descricao: "Concha globosa e rugosa, ovada e azulada por dentro.",
        habitat: "Não especificado.",
        origem: "Endémica.",
        conservacao: "Em Perigo Crítico (CR).",
        distribuicao: ["Ilhéu Raso", "Maio", "Santiago"]
    },
    {
        nome: "Leptaxis bollei",
        descricao: "Concha sólida em forma de cone fino e translúcido.",
        habitat: "Não especificado.",
        origem: "Endémica.",
        conservacao: "Em Perigo (EN).",
        distribuicao: ["Santo Antão", "São Vicente", "São Nicolau", "Sal", "Maio", "Santiago", "Fogo", "Brava"]
    },
    {
        nome: "Lauria cylindracea",
        descricao: "Concha brilhante e translúcida com seis voltas convexas.",
        habitat: "Não especificado.",
        origem: "Nativa.",
        conservacao: "Vulnerável (VU).",
        distribuicao: ["Santo Antão", "São Nicolau", "Santiago"]
    },
    {
        nome: "Zootecus insularis ssp. subdiaphanus",
        descricao: "Concha subcilíndrica, branca e opaca.",
        habitat: "Habitante do deserto.",
        origem: "Subespécie endémica.",
        conservacao: "Não avaliada.",
        distribuicao: ["Santo Antão", "São Vicente", "Santa Luzia", "Ilhéu Branco", "São Nicolau", "Sal", "Boa Vista", "Maio", "Santiago", "Fogo", "Brava"]
    },
    {
        nome: "Quickia concisa ssp. wollastoni",
        descricao: "Concha ovada, fina e transparente, cor verde-pálida.",
        habitat: "Não especificado.",
        origem: "Endémica.",
        conservacao: "Em Perigo (EN).",
        distribuicao: ["Santo Antão", "São Nicolau", "Brava"]
    },
    {
        nome: "Caracollina lenticula",
        descricao: "Concha pequena, opaca, castanha e lenticular.",
        habitat: "Não especificado.",
        origem: "Nativa.",
        conservacao: "Vulnerável (VU).",
        distribuicao: ["São Vicente", "São Nicolau", "Brava"]
    }
];
document.addEventListener("DOMContentLoaded", function () {
    const buscarButton = document.getElementById("buscar");
    const voltarButton = document.getElementById("voltar");
    const backdrop = document.getElementById("backdrop");
    const caixa = document.getElementById("vercaixa");
    const inputNome = document.getElementById("Nome");
    const resultadoDiv = document.getElementById("resultadoF");
    const searchNome = document.getElementById("searchNome");

    buscarButton.addEventListener("click", function () {
       console.log(searchNome)
        if (searchNome.value.trim() === "") {
            alert("Por favor, insira um nome para pesquisar.");
            return;
        } else {

            backdrop.classList.add("visible");
            caixa.classList.add("visible");

            let resultadoFiltro = filtarnome(searchNome.value, moluscos);

            inputNome.value = `A procura de: ${searchNome.value}`;

            resultadoDiv.innerHTML = resultadoFiltro.map(molusco =>
                `<div>
                    <h3>${molusco.nome}</h3>
                    <p><b>Descricao:</b> ${molusco.descricao}</p>
                    <p><b>habitat:</b> ${molusco.habitat}</p>
                    <p><b>origem:</b> ${molusco.origem}</p>
                    <p><b>conservacao:</b> ${molusco.conservacao}</p>
                    <p><b>distribuicao:</b> ${molusco.distribuicao}</p>
                </div>`
            ).join('');
            resultadoDiv.style.fontSize = "1.1rem";
            resultadoDiv.style.margin = "0 5rem";
            caixa.style.height = "50rem";
            caixa.style.top = "2rem"
            caixa.style.width = '50%';
        }
    });

    voltarButton.addEventListener("click", function () {
        backdrop.classList.remove("visible");
        caixa.classList.remove("visible");
        caixa.style.width = '30%';
    });
});

document.addEventListener('DOMContentLoaded', () => {
    const btn1 = document.getElementById("btn1");
    const btn2 = document.getElementById("btn2");
    const btn3 = document.getElementById("btn3");
    const btn4 = document.getElementById("btn4");
    const btn5 = document.getElementById("btn5");
    const btn6 = document.getElementById("btn6");
    const btn7 = document.getElementById("btn7");
    const btn8 = document.getElementById("btn8");

    btn1.addEventListener('click', () => {
        filtarStatus('Em Perigo Crítico (CR).');
    });
    
    btn2.addEventListener('click', () => {
        filtarStatus('Extinta (EX).');
    });
    
    btn3.addEventListener('click', () => {
        filtarStatus('Vulnerável (VU).');
    });
    
    btn4.addEventListener('click', () => {
        filtarStatus('Pouco Preocupante (LC).');
    });
    
    btn5.addEventListener('click', () => {
        filtarStatus('Em Perigo (EN).');
    });
    btn6.addEventListener('click', () => {
        filtarStatus('desaparecido');
    });
    btn7.addEventListener('click', () => {
        filtarStatus('Dados Deficientes');
    });
    btn8.addEventListener('click', () => {
        filtarStatus('Quase Ameaçado');
     });
});

document.addEventListener("DOMContentLoaded", function () {
    const voltarButton = document.getElementById("voltar");
    const backdrop = document.getElementById("backdrop");
    const caixa = document.getElementById("vercaixa");
    const inputNome = document.getElementById("Nome");
    const resultadoDiv = document.getElementById("resultadoF");
    const speciesElements = document.querySelectorAll(".species");


    voltarButton.addEventListener("click", function() {
        backdrop.classList.remove("visible");
        caixa.classList.remove("visible");
    });


    speciesElements.forEach(species => {
        const speciesImage = species.querySelector(".ImgMolusco");
        const aux = speciesImage;
        speciesImage.addEventListener("click", function () {
            const speciesName = species.querySelector(".nomeEsp").innerText;
            const speciesData = moluscos.find(molusco => molusco.nome.toLowerCase() === speciesName.toLowerCase());

            if (speciesData) {
                document.querySelector("#vercaixa #Nome").value = speciesData.nome;
                document.querySelector("#vercaixa #resultadoF").innerHTML = `
                    <img src="${aux.src}" alt="${speciesData.nome}" style="max-width: 100%;" />
                    <p><strong>Descricao:</strong> ${speciesData.descricao}</p>
                    <p><strong>Habitat:</strong> ${speciesData.habitat}</p>
                    <p><strong>Origem:</strong> ${speciesData.origem}</p>
                    <p><strong>Conservação:</strong> ${speciesData.conservacao}</p>
                    <p><strong>Distribuição:</strong> ${speciesData.distribuicao.join(', ')}</p>
                `;

                backdrop.classList.add("visible");
                caixa.classList.add("visible")

                inputNome.style.textAlign = "center";
                inputNome.style.top = "1rem";
                caixa.style.width = "40%";
                caixa.style.height = "88%";
                caixa.style.top = "1rem";
                resultadoDiv.style.margin = "1rem 2rem";
                voltarButton.style.marginTop = "10rem";

                speciesImage.aux();
            }
        });
    });
});

function filtarnome(nome, lista) {
    return lista.filter(function (molusco) {
        return molusco.nome.toLowerCase().includes(nome.toLowerCase());
    });
}

function filtarStatus(Nomestatus) {
    let resultadoFiltro = moluscos.filter(molusco => molusco.conservacao === Nomestatus);

    const voltarButton = document.getElementById("voltar");
    const backdrop = document.getElementById("backdrop");
    const caixa = document.getElementById("vercaixa");
    const inputNome = document.getElementById("Nome");
    const resultadoDiv = document.getElementById("resultadoF");

    backdrop.classList.add("visible");
    caixa.classList.add("visible")

    if (resultadoFiltro.length > 0) {
         inputNome.value = `Sobre o status de: ${Nomestatus}`;
        resultadoDiv.innerHTML += resultadoFiltro.map(moluscos =>
                `<div>
                    <h3>${moluscos.nome}</h3>
                    <p><b>Descricao:</b> ${moluscos.descricao}</p>
                    <p><b>habitat:</b> ${moluscos.habitat}</p>
                    <p><b>origem:</b> ${moluscos.origem}</p>
                    <p><b>conservacao:</b> ${moluscos.conservacao}</p>
                    <p><b>distribuicao:</b> ${moluscos.distribuicao}</p>
                </div>`
        ).join('');
        caixa.style.width = '50%';
        caixa.style.height = '100%';
        caixa.style.top = '0.3rem'
        caixa.style.margin = '0 2rem';
        caixa.style.alignItems = 'center';
        
    } else {
       inputNome.value = `Sobre o status de: ${Nomestatus}`;

        resultadoDiv.innerHTML = `<div>
            <p>Sem especie conhecida</p>
            	</div > `
    }

    voltarButton.addEventListener("click", function () {
        caixa.style.width = '30%';
        caixa.style.height = '50rem';
        caixa.style.top = '2rem'
        caixa.style.margin = '0 0';
        backdrop.classList.remove("visible");
        caixa.classList.remove("visible");
        resultadoDiv.style = '';
    });
}
