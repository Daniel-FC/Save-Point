#include <stdio.h>

main(){

float d=0, n, v;

printf("Digite o valor:\n");
scanf("%f", &n);

printf("\n--------------------\n\n");

if(n > 10){
for(v = 1; v != n+1; v++){
d = d + 1/v;
}
printf("O valor é: %.2f", d);
}
else{
printf("Valor invalido.");
}
getch();
}
