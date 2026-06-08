const btnNovoFilme = document.getElementById('add_Filme');
const modal = document.getElementById('add-modal');
const backdrop = document.getElementById('backdrop');

const btnCancelar = document.getElementById('cancelar');
const btnConfirmar = document.getElementById('adicionar');

const movie = document.getElementById("movie-list");

let MeusFilmes = [];

btnNovoFilme.addEventListener('click', () => {
    modal.classList.toggle('visible'); 
    backdrop.classList.toggle('visible');

});

btnCancelar.addEventListener('click', ()=>{
    modal.classList.toggle('visible');
    backdrop.classList.toggle('visible');
});

btnConfirmar.addEventListener('click', ()=>{

    let filme = document.getElementById('title').value;
    let url = document.getElementById('image-url').value;
    let classficacao = document.getElementById('rating').value;

    let OsFilme = {
        Nome: filme,
        URL: url,
        classficacao: classficacao
    }

    MeusFilmes.push(OsFilme);
    console.log(MeusFilmes);

        movie.innerHTML += `<div>
                                <p><b>Nome do seu FIlme:</b> ${filme}</p>
                                <img src="${url}">
                                <p><b>Sua Classficação:</b> ${classficacao}</p>
                            </div>`;

        movie.style


    modal.classList.toggle('visible');
    backdrop.classList.toggle('visible');
});
