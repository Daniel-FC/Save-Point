const api = "https://reactnd-books-api.udacity.com"

let todos = [];

let lendo = [];
let queroLer = [];
let leituraConcluida = [];
let nenhum = [];

let lendoSemFiltro = [];
let queroLerSemFiltro = [];
let leituraConcluidaSemFiltro= [];
let nenhumSemFiltro = [];

let qtd = 0;

// Generate a unique token for storing your bookshelf data on the backend server.
let token = localStorage.token
if (!token)
  token = localStorage.token = Math.random().toString(36).substr(-8)

window.addEventListener('load', () => {
  tabLendo = document.querySelector('#tabLendo');
  tabQueroLer = document.querySelector('#tabQueroLer');
  tabLeituraConcluida  = document.querySelector('#tabLeituraConcluida ');
  tabNenhum = document.querySelector('#tabNenhum');
  inputSearch = document.querySelector('#search');

  getAll();
  setTimeout(() => { await(); }, 1500);
});

const headers = {
  'Accept': 'application/json',
  'Authorization': token
}

function getAll() {
  fetch(`${api}/books`, { headers })
    .then(res => res.json())
    .then(data => {
      data.books;
      todos = data.books
    });
}

function await() {
  todos = todos.map( book => {
    return {
      id: qtd++,
      titulo: book.title,
      imagem: book.imageLinks.smallThumbnail
    }
  });
  nenhum = todos;

  nenhumSemFiltro = nenhum;
  lendoSemFiltro = lendo;
  queroLerSemFiltro = queroLer;
  leituraConcluidaSemFiltro = leituraConcluida;

  filtrar();
  render();
}

function render(){
  renderLendo();
  renderQueroLer();
  renderLeituraConcluida();
  renderNenhum();
  buttons();
}

function renderLendo(){
  let booksHTML = ' ';
  for(let i=0; i< lendo.length; i++){
    booksHTML += '<div>'
    booksHTML += '<img src="' + lendo[i].imagem + '" >';
    booksHTML += lendo[i].titulo;
    booksHTML += '<i id="' + lendo[i].id + '" class="fas fa-book-open btnLendo"></i>';
    booksHTML += '<i id="' + lendo[i].id + '" class="fas fa-book btnQueroLer"></i>'
    booksHTML += '<i id="' + lendo[i].id + '" class="fas fa-check-circle btnLeituraConcluida"></i>'
    booksHTML += '<i id="' + lendo[i].id + '" class="fas fa-times-circle btnNenhum"></i>'
    booksHTML += '</div>';
  }
  tabLendo.innerHTML = booksHTML;
}

function renderQueroLer(){
  let booksHTML = ' ';
  for(let i=0; i< queroLer.length; i++){
    booksHTML += '<div>'
    booksHTML += '<img src="' + queroLer[i].imagem + '" >';
    booksHTML += queroLer[i].titulo;
    booksHTML += '<i id="' + queroLer[i].id + '" class="fas fa-book-open btnLendo"></i>';
    booksHTML += '<i id="' + queroLer[i].id + '" class="fas fa-book btnQueroLer"></i>'
    booksHTML += '<i id="' + queroLer[i].id + '" class="fas fa-check-circle btnLeituraConcluida"></i>'
    booksHTML += '<i id="' + queroLer[i].id + '" class="fas fa-times-circle btnNenhum"></i>'
    booksHTML += '</div>';
  }
  tabQueroLer.innerHTML = booksHTML;
}

function renderLeituraConcluida(){
  let booksHTML = ' ';
  for(let i=0; i< leituraConcluida.length; i++){
    booksHTML += '<div>'
    booksHTML += '<img src="' + leituraConcluida[i].imagem + '" >';
    booksHTML += leituraConcluida[i].titulo;
    booksHTML += '<i id="' + leituraConcluida[i].id + '" class="fas fa-book-open btnLendo"></i>';
    booksHTML += '<i id="' + leituraConcluida[i].id + '" class="fas fa-book btnQueroLer"></i>'
    booksHTML += '<i id="' + leituraConcluida[i].id + '" class="fas fa-check-circle btnLeituraConcluida"></i>'
    booksHTML += '<i id="' + leituraConcluida[i].id + '" class="fas fa-times-circle btnNenhum"></i>'
    booksHTML += '</div>';
  }
  tabLeituraConcluida.innerHTML = booksHTML;
}

function renderNenhum(){
  let booksHTML = ' ';
  for(let i=0; i< nenhum.length; i++){
    booksHTML += '<div>'
    booksHTML += '<img src="' + nenhum[i].imagem + '" >';
    booksHTML += nenhum[i].titulo;
    booksHTML += '<i id="' + nenhum[i].id + '" class="fas fa-book-open btnlendo"></i>';
    booksHTML += '<i id="' + nenhum[i].id + '" class="fas fa-book btnQueroLer"></i>'
    booksHTML += '<i id="' + nenhum[i].id + '" class="fas fa-check-circle btnLeituraConcluida"></i>'
    booksHTML += '<i id="' + nenhum[i].id + '" class="fas fa-times-circle btnNenhum"></i>'
    booksHTML += '</div>';
  }
  tabNenhum.innerHTML = booksHTML;
}

function buttons() {
  const btn_nenhum_lendo = Array.from(tabNenhum.querySelectorAll('.btnLendo'));
  const btn_queroLer_lendo = Array.from(tabQueroLer.querySelectorAll('.btnLendo'));
  const btn_LeituraConcluida_lendo = Array.from(tabLeituraConcluida.querySelectorAll('.btnLendo'));
  const btn_Lendo_lendo = Array.from(tabLendo.querySelectorAll('.btnLendo'));
  const btnLendo = [...btn_nenhum_lendo, ...btn_queroLer_lendo, ...btn_LeituraConcluida_lendo, ...btn_Lendo_lendo];

  const btn_nenhum_nenhum = Array.from(tabNenhum.querySelectorAll('.btnNenhum'));
  const btn_queroLer_nenhum = Array.from(tabQueroLer.querySelectorAll('.btnNenhum'));
  const btn_LeituraConcluida_nenhum = Array.from(tabLeituraConcluida.querySelectorAll('.btnNenhum'));
  const btn_Lendo_nenhum = Array.from(tabLendo.querySelectorAll('.btnNenhum'));
  const btnNenhum = [...btn_nenhum_nenhum, ...btn_queroLer_nenhum, ...btn_LeituraConcluida_nenhum, ...btn_Lendo_nenhum];

  const btn_nenhum_LeituraConcluida = Array.from(tabNenhum.querySelectorAll('.btnLeituraConcluida'));
  const btn_queroLer_LeituraConcluida = Array.from(tabQueroLer.querySelectorAll('.btnLeituraConcluida'));
  const btn_LeituraConcluida_LeituraConcluida = Array.from(tabLeituraConcluida.querySelectorAll('.btnLeituraConcluida'));
  const btn_Lendo_LeituraConcluida = Array.from(tabLendo.querySelectorAll('.btnLeituraConcluida'));
  const btnLeituraConcluida = [...btn_nenhum_LeituraConcluida, ...btn_queroLer_LeituraConcluida, ...btn_LeituraConcluida_LeituraConcluida, ...btn_Lendo_LeituraConcluida];

  const btn_nenhum_queroLer = Array.from(tabNenhum.querySelectorAll('.btnQueroLer'));
  const btn_queroLer_queroLer = Array.from(tabQueroLer.querySelectorAll('.btnQueroLer'));
  const btn_LeituraConcluida_queroLer = Array.from(tabLeituraConcluida.querySelectorAll('.btnQueroLer'));
  const btn_Lendo_queroLer = Array.from(tabLendo.querySelectorAll('.btnQueroLer'));
  const btnQueroLer = [...btn_nenhum_queroLer, ...btn_queroLer_queroLer, ...btn_LeituraConcluida_queroLer, ...btn_Lendo_queroLer];

  btnLendo.forEach(button => {
    button.addEventListener('click', () => addToLendo(button.id));
  })
  btnNenhum.forEach(button => {
    button.addEventListener('click', () => addToNenhum(button.id));
  })
  btnLeituraConcluida.forEach(button => {
    button.addEventListener('click', () => addToLeituraConcluida(button.id));
  })
  btnQueroLer.forEach(button => {
    button.addEventListener('click', () => addToQueroLer(button.id));
  })
}

function addToLendo(id) {
  let existe = 0;
  for(let i=0; i<lendo.length; i++){
    if(lendo[i].id==id){
      existe = 1;
    }
  }
  if(existe==0){
    lendo.push(todos[id]);

    temp = nenhum;
    nenhum = [];
    for(let i=0; i<temp.length; i++){
      if(temp[i].id!=id){
        nenhum = [...nenhum, temp[i]];
      }
    }

    temp = queroLer ;
    queroLer  = [];
    for(let i=0; i<temp.length; i++){
      if(temp[i].id!=id){
        queroLer = [...queroLer , temp[i]];
      }
    }

    temp = leituraConcluida  ;
    leituraConcluida = [];
    for(let i=0; i<temp.length; i++){
      if(temp[i].id!=id){
        leituraConcluida  = [...leituraConcluida  , temp[i]];
      }
    }

    nenhumSemFiltro = nenhum;
    lendoSemFiltro = lendo;
    queroLerSemFiltro = queroLer;
    leituraConcluidaSemFiltro = leituraConcluida;
    render();
  }
}

function addToNenhum(id) {
  let existe = 0;
  for(let i=0; i<nenhum.length; i++){
    if(nenhum[i].id==id){
      existe = 1;
    }
  }
  if(existe==0){
    nenhum.push(todos[id]);

    temp = lendo;
    lendo = [];
    for(let i=0; i<temp.length; i++){
      if(temp[i].id!=id){
        lendo = [...lendo, temp[i]];
      }
    }

    temp = queroLer ;
    queroLer  = [];
    for(let i=0; i<temp.length; i++){
      if(temp[i].id!=id){
        queroLer = [...queroLer , temp[i]];
      }
    }

    temp = leituraConcluida  ;
    leituraConcluida = [];
    for(let i=0; i<temp.length; i++){
      if(temp[i].id!=id){
        leituraConcluida  = [...leituraConcluida  , temp[i]];
      }
    }

    nenhumSemFiltro = nenhum;
    lendoSemFiltro = lendo;
    queroLerSemFiltro = queroLer;
    leituraConcluidaSemFiltro = leituraConcluida;
    render();
  }
}

function addToLeituraConcluida(id) {
  let existe = 0;
  for(let i=0; i<leituraConcluida.length; i++){
    if(leituraConcluida[i].id==id){
      existe = 1;
    }
  }
  if(existe==0){
    leituraConcluida.push(todos[id]);

    temp = nenhum;
    nenhum = [];
    for(let i=0; i<temp.length; i++){
      if(temp[i].id!=id){
        nenhum = [...nenhum, temp[i]];
      }
    }

    temp = queroLer ;
    queroLer  = [];
    for(let i=0; i<temp.length; i++){
      if(temp[i].id!=id){
        queroLer = [...queroLer , temp[i]];
      }
    }

    temp = lendo;
    lendo = [];
    for(let i=0; i<temp.length; i++){
      if(temp[i].id!=id){
        lendo  = [...lendo , temp[i]];
      }
    }

    nenhumSemFiltro = nenhum;
    lendoSemFiltro = lendo;
    queroLerSemFiltro = queroLer;
    leituraConcluidaSemFiltro = leituraConcluida;
    render();
  }
}

function addToQueroLer (id) {
  let existe = 0;
  for(let i=0; i<queroLer.length; i++){
    if(queroLer[i].id==id){
      existe = 1;
    }
  }
  if(existe==0){
    queroLer.push(todos[id]);

    temp = nenhum;
    nenhum = [];
    for(let i=0; i<temp.length; i++){
      if(temp[i].id!=id){
        nenhum = [...nenhum, temp[i]];
      }
    }

    temp = lendo;
    lendo = [];
    for(let i=0; i<temp.length; i++){
      if(temp[i].id!=id){
        lendo = [...lendo , temp[i]];
      }
    }

    temp = leituraConcluida  ;
    leituraConcluida = [];
    for(let i=0; i<temp.length; i++){
      if(temp[i].id!=id){
        leituraConcluida  = [...leituraConcluida  , temp[i]];
      }
    }

    nenhumSemFiltro = nenhum;
    lendoSemFiltro = lendo;
    queroLerSemFiltro = queroLer;
    leituraConcluidaSemFiltro = leituraConcluida;
    render();
  }
}

function filtrar(){
  function handleTyiping(event) {
    filtro = event.target.value;

    nenhum = [];
    for(let i=0; i<nenhumSemFiltro.length; i++){
      tam = 0;
      control = 0;
      if(nenhumSemFiltro[i].titulo.length>filtro.length){
        max = filtro.length;
      } 
      else {
        max = nenhumSemFiltro[i].titulo.length;
      }
      for (let u=0; u<max; u++) { 
        if(nenhumSemFiltro[i].titulo[u].toUpperCase()==filtro[u].toUpperCase() && control==0){
          tam++;
        }
        else {
          control++;
        }
      }
      if(tam==max){
        nenhum = [...nenhum  , nenhumSemFiltro[i]];
      }
    }

    lendo= [];
    for(let i=0; i<lendoSemFiltro.length; i++){
      tam = 0;
      control = 0;
      if(lendoSemFiltro[i].titulo.length>filtro.length){
        max = filtro.length;
      } 
      else {
        max = lendoSemFiltro[i].titulo.length;
      }
      for (let u=0; u<max; u++) { 
        if(lendoSemFiltro[i].titulo[u].toUpperCase()==filtro[u].toUpperCase() && control==0){
          tam++;
        }
        else {
          control++;
        }
      }
      if(tam==max){
        lendo = [...lendo  , lendoSemFiltro[i]];
      }
    }

    queroLer = [];
    for(let i=0; i<queroLerSemFiltro.length; i++){
      tam = 0;
      control = 0;
      if(queroLerSemFiltro[i].titulo.length>filtro.length){
        max = filtro.length;
      } 
      else {
        max = queroLerSemFiltro[i].titulo.length;
      }
      for (let u=0; u<max; u++) { 
        if(queroLerSemFiltro[i].titulo[u].toUpperCase()==filtro[u].toUpperCase() && control==0){
          tam++;
        }
        else {
          control++;
        }
      }
      if(tam==max){
        queroLer = [...queroLer  , queroLerSemFiltro[i]];
      }
    }

    leituraConcluida = [];
    for(let i=0; i<leituraConcluidaSemFiltro.length; i++){
      tam = 0;
      control = 0;
      if(leituraConcluidaSemFiltro[i].titulo.length>filtro.length){
        max = filtro.length;
      } 
      else {
        max = leituraConcluidaSemFiltro[i].titulo.length;
      }
      for (let u=0; u<max; u++) { 
        if(leituraConcluidaSemFiltro[i].titulo[u].toUpperCase()==filtro[u].toUpperCase() && control==0){
          tam++;
        }
        else {
          control++;
        }
      }
      if(tam==max){
        leituraConcluida = [...leituraConcluida  , leituraConcluidaSemFiltro[i]];
      }
    }
    render();
  }

  inputSearch.addEventListener('keyup', handleTyiping);
}
