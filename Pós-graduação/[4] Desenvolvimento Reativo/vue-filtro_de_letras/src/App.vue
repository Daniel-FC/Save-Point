<template>
  <div>
    <h3>
      Filtro de letras - Vue
    </h3>
    <div>
      <div>
        <label>
          Contador
          <input
            type="text"
            min="1"
            max="200"
            v-model="currentValue"
          >
        </label>
      </div>
      <ul>
        <li>
          <b>Vogais da frase:</b>
          <span >{{ getVogais() }}</span>
        </li>
        <li>
          <b>Não vogais na frase:</b>
          <span >{{ getNaoVogais() }}</span>
        </li>
      </ul>
    </div>
  </div>
</template>

<script>
export default {
  name: 'app',

  created() {
    this.vogais = ['a', 'e', 'i', 'o', 'u'];
  },

  data() {
    return {
      currentValue: 'abacate'
    }
  },

  methods: {
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
    },
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
    },
  }
}
</script>

<style>
body {
  padding: 20px;
}
</style>
