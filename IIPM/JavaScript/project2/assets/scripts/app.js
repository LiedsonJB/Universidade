const ATAQUE_Maximo = 30;
const VidaMAX = 100

let vidaJogador;
let n = 3;
let Bonus = true;
let vidaMonstro = VidaMAX;

let Ataque_Monster;
let Ataque_Player;

let MyStatus = [];

let valorLido = parseInt(prompt("Digite a sua vida que desejas comecar: "));

if(isNaN(valorLido) || valorLido <= 0)
    vidaJogador = VidaMAX;
else 
    vidaJogador = valorLido;

adjustHealthBars(vidaJogador);



const ataque = (tipo) => {
    if(tipo === 'AtaqueHandler'){

        Ataque_Player = Math.floor(Math.random() * 10) + 1;
        Ataque_Monster = Math.floor(Math.random() * 10) + 1;

        let valorAfetado = dealMonsterDamage(Ataque_Monster);
        vidaMonstro -= valorAfetado;

        const valorAfetadoP = dealPlayerDamage(Ataque_Player);
        vidaJogador -= valorAfetadoP;

    }else {
        Ataque_Monster = Math.floor(Math.random() * 10) + 1;

        let valorAfetado = dealMonsterDamage(ATAQUE_Maximo);
        vidaMonstro -= valorAfetado;

        const valorAfetadoP = dealPlayerDamage(Ataque_Monster);
        vidaJogador -= valorAfetadoP;
    }

    let entradaLog = {
        Evento: tipo,
        Valor_D_P: valorAfetadoP,
        valor_D_M: valorAfetado,
        vidaMonstro: vidaMonstro,
        vidaPlayer: vidaJogador
    }
    MyStatus.push(entradaLog);
    EstadoJogo();
}

const EstadoJogo = () => {

    if(vidaJogador <= 0 && Bonus){
        increasePlayerHealth(VidaMAX);
        vidaJogador = VidaMAX;
        Bonus = false;
        removeBonusLife();
        alert("Utilizas-te o seu bonus")
    }

    if(vidaJogador <= 0 || vidaMonstro <= 0){
        if(vidaJogador <= 0)
            alert("O CPU Venceu");
        else if(vidaJogador <= 0 && vidaMonstro <= 0)
            alert("Empate!!!");
        else
            alert("Voce venceu");

        resetGame(VidaMAX);
    }
    
}

function attackHandler(){

    ataque('AtaqueHandler');

    EstadoJogo();
}

function ATTACKMAX(){
    ataque("StrongAtaque");

    EstadoJogo();
    
}

function recuperar(){
    let vida = Math.random() * 10 + 1;

    if(vidaJogador === VidaMAX)
        alert("Sua vida esta cheia, impossivel recarregar");
    else{

        if(n >= 0){
            n--;
            alert("Recuperando vida...");
            alert("Restam apenas " + n + " vidas disponiveis");

            if((vidaJogador + vida) >= VidaMAX){
                vidaJogador = VidaMAX;
                increasePlayerHealth(VidaMAX);
            }else{
                vidaJogador += vida;
                increasePlayerHealth(vida)
            }
        }else{
            alert("Esgotaste suas recargas de vida");
        }
    }  
}

attackBtn.addEventListener('click', attackHandler);
strongAttackBtn.addEventListener('click', ATTACKMAX);
healBtn.addEventListener('click', recuperar);
logBtn.addEventListener('click', () => {
    console.log(MyStatus);
});