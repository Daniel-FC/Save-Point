window.addEventListener('load', start);

let users = [ user = [name="Abner", email="aaa@aaa.com", senha="123"], 
              user = [name="Bernado", email="bbb@bbb.com", senha="321"],
              user = [name="Carlinha", email="ccc@ccc.com", senha="213"], ];
let inputName = null;
let state = 0;

function start() {
  inputListar = document.querySelector('#listar');
  inputEntrar = document.querySelector('#entrar');
  inputCadastrar = document.querySelector('#cadastrar');
  inputSair = document.querySelector('#sair');

  inputTitulo = document.querySelector('#titulo');
  inputName = document.querySelector('#nome');
  inputEmail = document.querySelector('#email');
  inputPassword = document.querySelector('#senha');
  inputSend = document.querySelector('#enviar');
  inputUsuarios = document.querySelector('#usuarios');

  preventFormSubmit();
  activateInput();
}

function preventFormSubmit() {
  function handleFormSubmit(event) {
    event.preventDefault();
  }

  let form = document.querySelector('form');
  form.addEventListener('submit', handleFormSubmit);
}

function activateInput() {
  function cadastrarScreen(){
    state = 0;
    render();
  }
  function entrarScreen(){
    state = 1;
    render();
  }
  function listarScreen(){
    state = 2;
    render();
  }
  function sairScreen(){
    state = 3;
    render();
  }

  inputSend.addEventListener('click', addUser);
  inputCadastrar.addEventListener('click', cadastrarScreen);
  inputEntrar.addEventListener('click', entrarScreen);
  inputListar.addEventListener('click', listarScreen);
  inputSair.addEventListener('click', sairScreen);
  render();
  inputName.focus();
}

function addUser(){
  let user = [inputName.value, inputEmail.value, inputPassword.value]

  let existe = 0
  for(let i=0; i < users.length; i++){
    if(inputEmail.value==users[i][1] && inputPassword.value==users[i][2]){
      existe = 1;
    }
  }

  if(state==0){
    if(existe == 0){
      users.push(user);
      inputName.value = '';
      inputEmail.value = '';
      inputPassword.value = '';
      alert("Usuario cadastrado com sucesso!!");
    } else {
      alert("ATENÇÃO!! USUARIO JA CADASTRADO!!");
    }
    console.log(users)
  }
  else {
    if(existe == 1){
      state = 2;
      alert("Login realizado com sucesso!!");
    } else {
      alert("ATENÇÃO!! USUARIO NÃO EXISTE!!");
    }
    console.log(users)
    render();
  }
}

function render() {
  inputName.value = '';
  inputEmail.value = '';
  inputPassword.value = '';

  inputEntrar.style.border = "0px solid white";
  inputCadastrar.style.border = "0px solid white";
  inputListar.style.border = "0px solid white";

  if(state===0){
    renderCadastrar();
  }
  if(state===1){
    renderEntrar();
  }
  if(state===2){
    renderListar();
  }
  if(state===3){
    renderSair();
  }
}

function renderCadastrar(){
  inputTitulo.innerText = "CADASTRAR"
  inputCadastrar.style.border = "1px solid white";

  inputListar.style.display = "none";
  inputEntrar.style.display = "inline";
  inputCadastrar.style.display = "inline";
  inputSair.style.display = "none";

  inputName.style.display = "block";
  inputEmail.style.display = "inline";
  inputPassword.style.display = "inline";
  inputSend.style.display = "inline";
  inputUsuarios.style.display = "none";
}

function renderEntrar(){
  inputTitulo.innerText = "ENTRAR"
  inputEntrar.style.border = "1px solid white";

  inputListar.style.display = "none";
  inputEntrar.style.display = "inline";
  inputCadastrar.style.display = "inline";
  inputSair.style.display = "none";

  inputName.style.display = "none";
  inputEmail.style.display = "inline";
  inputPassword.style.display = "inline";
  inputSend.style.display = "inline";
  inputUsuarios.style.display = "none";
}

function renderListar(){
  inputTitulo.innerText = "USUARIOS"
  inputListar.style.border = "1px solid white";

  inputListar.style.display = "inline";
  inputEntrar.style.display = "none";
  inputCadastrar.style.display = "none";
  inputSair.style.display = "inline";

  inputName.style.display = "none";
  inputEmail.style.display = "none";
  inputPassword.style.display = "none";
  inputSend.style.display = "none";
  inputUsuarios.style.display = "inline";
  listar();
}

function renderSair() {
  renderCadastrar();
  alert("DESLOGADO COM SUCESSO!!");
}

function listar() {
  console.log(users);
  inputUsuarios.innerText = " ";
  inputUsuarios.innerText = users[0][0] + ", " + users[0][1];
  for(let i=1; i < users.length; i++){
    inputUsuarios.innerText = inputUsuarios.innerText + " // " + users[i][0] + ", " + users[i][1];
  }
  
}