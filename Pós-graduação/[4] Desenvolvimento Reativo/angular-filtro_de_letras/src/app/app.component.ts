import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  vogais = ['a', 'e', 'i', 'o', 'u'];
  currentValue = 'abacate';

  getVogais() {
    const letras = [];

    for (let i=0; i < this.currentValue.length; i++) {
      for(let j=0; j < this.vogais.length; j++){
        if(this.currentValue.charAt(i)==this.vogais[j]){
          letras.push(" " + this.currentValue.charAt(i));
        }
      }
   }

    return letras;
  }

  getNaoVogais() {
    const letras = [];

    for (let i=0; i < this.currentValue.length; i++) {
      let existe=0;
      for(let j=0; j < this.vogais.length; j++){
        if(this.currentValue.charAt(i)==this.vogais[j]){
          existe++;
        }
      }
      if(existe==0){
        letras.push(" " + this.currentValue.charAt(i));
      }
   }
   
    return letras;
  }

}
