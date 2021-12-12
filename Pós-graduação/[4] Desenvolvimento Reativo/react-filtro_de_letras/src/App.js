import React, { Component, Fragment } from 'react';

export default class App extends Component {
  constructor() {
    super();

    this.state = {
      currentValue: 'abacate'
    };

    this.vogais = ['a', 'e', 'i', 'o', 'u'];
  }

  getVogais() {
    const letras = [];

    for (let i=0; i < this.state.currentValue.length; i++) {
      for(let j=0; j < this.vogais.length; j++){
        if(this.state.currentValue.charAt(i)==this.vogais[j]){
          letras.push(" " + this.state.currentValue.charAt(i));
        }
      }
   }

    return letras;
  }

  getNaoVogais() {
    const letras = [];

    for (let i=0; i < this.state.currentValue.length; i++) {
      let existe=0;
      for(let j=0; j < this.vogais.length; j++){
        if(this.state.currentValue.charAt(i)==this.vogais[j]){
          existe++;
        }
      }
      if(existe==0){
        letras.push(" " + this.state.currentValue.charAt(i));
      }
   }
   
    return letras;
  }

  render() {
    return (
      <Fragment>
        <h3>Filtro de letras - React</h3>
        <div>
          <div>
            <label>
              Contador
              <input
                type="text"
                min="1"
                max="200"
                value={this.state.currentValue}
                onChange={event =>
                  this.setState({ currentValue: event.target.value })
                }
              />
            </label>
          </div>
          <ul>
            <li>
              <b>Vogais da frase:</b>
              <span >{ this.getVogais() }</span>
            </li>
            <li>
              <b>Não vogais da frase:</b>
              <span >{ this.getNaoVogais() }</span>
            </li>
          </ul>
        </div>
      </Fragment>
    );
  }
}
