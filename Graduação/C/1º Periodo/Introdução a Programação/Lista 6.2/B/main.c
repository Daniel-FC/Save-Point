#include <stdio.h>
#include <stdlib.h>

/* a flag serve para determina quando esta a pecorrer uma palavra ou nao
ou seja quando a flag passa de 0 para 1 é porque é uma nova palavra e incrementa o total */

/* o fgets serve para fazer a leitura  e o stdin é a entrada padrao sendo limitado o numero 
de caracter para vetor mais um */

/* onde tiver '\0' esta se referindo a um valor vazio */

main() {
	char frase[50];
        int i, flag=0, total=0;
        
        printf("Introduza a frase\n");
        fgets(frase,51,stdin);
        
        for(i=0;frase[i]!='\0';i++) {
                if(!flag && frase[i]!=' ') {
                        flag=1;
                        total++;
                }
                else if(flag && frase[i]==' ')
                        flag=0;
        }
        printf("O numero de palavras: %d\n",total);
        
        return 0;

}
