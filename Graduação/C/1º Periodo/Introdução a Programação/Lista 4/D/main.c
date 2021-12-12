#include <stdio.h>

main(){

float vlr ,qtd, p_t=0, vazio=0, rodar=1;

for(rodar; rodar != 0; vazio++){

if(rodar != 0){

printf("Preço do produto:\n");
scanf("%f", &vlr);

if(vlr < 0){
printf("\n-------------------------\n");
printf("\nValor invalido!");
printf("\nCaso tenha terminado dijite 0, senão, digite outro valor.\n");
scanf("%i", &rodar);
printf("\n");
}
else{
printf("Quantidade do produto:\n");
scanf("%f", &qtd);

if(qtd < 0){
printf("\n-------------------------\n");
printf("\nValor invalido!");
printf("\nCaso tenha terminado dijite 0, senão, digite outro valor.\n");
scanf("%i", &rodar);
printf("\n");
}
}
}

if(vlr >= 0 && qtd >= 0){
p_t = vlr * qtd + p_t;

printf("\nCaso tenha terminado dijite 0, senão, digite outro valor.\n");
scanf("%i", &rodar);
printf("\n");
}
}
printf("-------------------------\n\n");
printf("preço total: %.2f", p_t);

getch();
}
