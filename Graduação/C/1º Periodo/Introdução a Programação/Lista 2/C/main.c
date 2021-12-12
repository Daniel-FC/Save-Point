#include <stdio.h>

main(){

int cod, qtde;
float p_item, p_total;

printf("100: Misto quente\n101: Cachorro Quente\n102: Bauru\n103: Hamburguer\n104: Cheeseburguer\n105: Refrigerante\n\n");

printf("Digite o código do produto aqui:\n");
scanf("%d", &cod);

switch(cod){

case 100:
p_item = 1.20;
printf("Misto quente!\n");
break;

case 101:
p_item = 1.30;
printf("Cachorro quente!\n");
break;

case 102:
p_item = 1.50;
printf("Bauru!\n");
break;

case 103:
p_item = 1.20;
printf("Hamburguer!\n");
break;

case 104:
p_item = 1.30;
printf("Cheeseburguer!\n");
break;

case 105:
p_item = 1.00;
printf("Refrigerante!\n");
break;

default:
p_item = 0;
printf("código invalido!\n");
break;
}

if(p_item != 0){
printf("Quantidade pedida: \n");
scanf("%d", &qtde);
p_total = qtde*p_item;
printf("Valor total do pedido %.2f", p_total);
}else{
printf("O programa será fechado!\n");
}
getch();
}
