#include <stdio.h>

main(){

int inicial, final, soma=0, inicio;

printf("Qual o valor inicial?\n");
scanf("%i", &inicial);
printf("Qual o valor Final?\n");
scanf("%i", &final);

inicio = inicial;

for(inicial; inicial!=final; inicial++){
soma = inicial + soma;
}

printf("\n----------------\n\n");
printf("A soma dos valores que est�o entre os dois numeros �: %i", soma-inicio);
getch();
}
