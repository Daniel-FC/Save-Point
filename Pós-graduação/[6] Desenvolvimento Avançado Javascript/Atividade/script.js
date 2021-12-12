const mensagem = document.querySelector('.mensagem');
const pontuacao = document.querySelector('.pontuacao');
const buttons = document.querySelectorAll('button');
const pontuacoes = [0,0];
let contador = 0;

for ( let i = 0 ; i < buttons.length-1 ; i++){
	buttons[i].addEventListener('click', startButton);
}
buttons[buttons.length-1].addEventListener('click', startVoice);

//==============================================================================

function startButton(e){
	if(contador<3){
		Gerador(e.target.innerText);
			contador=0;
	} else{
		resultSpeaker.innerHTML = 'DESATIVADO';
	}
}

//==============================================================================

function startVoice(e){
	var speakBtn = document.querySelector('#speakbt');
	var resultSpeaker = document.querySelector('#resultSpeak');

	if (window.SpeechRecognition || window.webkitSpeechRecognition) {

			var SpeechRecognition = SpeechRecognition || webkitSpeechRecognition;

			var myRecognition = new SpeechRecognition();

			myRecognition.lang = 'pt-BR';

			speakBtn.addEventListener('click', function () {

					try {

							myRecognition.start();

							resultSpeaker.innerHTML = "Estou te ouvindo!";

					} catch (erro) {
							alert('erro:' + erro.message);
					}

			}, false);

			myRecognition.addEventListener('result', function (evt) {

					var resultSpeak = evt.results[0][0].transcript;

					console.log(resultSpeak);

					resultSpeaker.innerHTML = resultSpeak;
					if(resultSpeaker.innerHTML == 'Pedra' || resultSpeaker.innerHTML == 'pedra' ||
					resultSpeaker.innerHTML == 'Papel' || resultSpeaker.innerHTML == 'papel' ||
					resultSpeaker.innerHTML == 'Tesoura' || resultSpeaker.innerHTML == 'tesoura'){
						if(contador<3){
							Gerador(resultSpeaker.innerHTML);
							contador=0;
						} else{
							resultSpeaker.innerHTML = 'DESATIVADO';
						}

					} else{
						contador++;
						resultSpeaker.innerHTML = 'Se você disse alguma coisa, não ouvi muito bem! [' + contador + '] erro´s';
					}

					switch (resultSpeak.toLowerCase()) {
							case 'clarear':
									document.body.style.backgroundColor = '#33cc99';
									break;
							case 'escurecer':
									document.body.style.backgroundColor = '#047751';
									break;
							case 'meu site':
									window.location.href = 'https://www.jetersonlordano.com.br';
									break;
					}

					if (resultSpeak.match(/buscar por/)) {

							resultSpeaker.innerHTML = 'Redirecionando...';

							setTimeout(function () {

									var resultado = resultSpeak.split('buscar por');
									window.location.href = 'https://www.google.com.br/search?q=' + resultado[1];

							}, 2000);
					}

			}, false);

			myRecognition.addEventListener('error', function (evt) {

					resultSpeaker.innerHTML = 'Se você disse alguma coisa, não ouvi muito bem!';

			}, false);

	} else {
			resultSpeaker.innerHTML = 'Seu navegador não suporta tanta tecnologia!';
	}

	
}

//==============================================================================

function Gerador(result){
	//obtem escolha do usuario
	let opcaoUsuario = result;
	
	//obtem escolha do computador por um numero aleatorio
	let opcaoComputador = Math.random();

	if (opcaoComputador < .34){
		opcaoComputador = 'Pedra';
	} else if (opcaoComputador <= .67){
		opcaoComputador = 'Papel';
	} else {
		opcaoComputador = 'Tesoura';
	}

	let resultado = verificarVencedor(opcaoUsuario, opcaoComputador);

	if (resultado === 'Jogador'){
		resultado += ' venceu!';
		pontuacoes[0]++;
	}

	if (resultado === 'Computador'){
		resultado += ' venceu!';
		pontuacoes[1]++;
	}

	if (resultado === 'Empate'){
		resultado += '. Empate!'
	}

	pontuacao.innerHTML = 'Jogador: [ ' + pontuacoes[0]+ ' ] Computador: [ ' + pontuacoes[1] + ' ]';

	//Imprime as opcoes selecionadas
	ImprimeResultado('Jogador: <strong>' + opcaoUsuario + '</strong> Computador: <strong>' + opcaoComputador + '</strong><br>' + resultado);
}

//==============================================================================

function ImprimeResultado(texto){
	mensagem.innerHTML = texto;
}

//==============================================================================

function verificarVencedor(jogador, computador){
	if (jogador === computador){
		return 'Empate';
	}
	if (jogador == 'Pedra' || jogador == 'pedra'){
		if(computador === 'Papel'){
			return 'Computador';
		} else {
			return 'Jogador';
		}
	}
	if (jogador == 'Papel' || jogador == 'papel'){
		if (computador === 'Tesoura'){
			return 'Computador';
		} else {
			return 'Jogador';
		}
	}
	if (jogador == 'Tesoura' || jogador == 'tesoura'){
		if (computador === 'Pedra'){
			return 'Computador';
		} else {
			return 'Jogador';
		}
	}
}


