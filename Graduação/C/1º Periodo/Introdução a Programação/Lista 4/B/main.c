#include <stdio.h>

main(){

int n, v=1, f;

printf("Informe o valor:\n");
scanf("%i", &n);
f = n;

if(n > 0){
for(n; n != 1; n--){
v = v*n;
}
printf("\n-----------------------\n\n");
printf("O fadorial de %i é:%i", f, v);
}
if(n == 0){
printf("\n-----------------------\n\n");
printf("O fatorial de 0 é: 1");
}
if(n < 0){
printf("\n-----------------------\n\n");
printf("Valor invalido!\n\nO programa sera fechado.");
}
getch();
}
