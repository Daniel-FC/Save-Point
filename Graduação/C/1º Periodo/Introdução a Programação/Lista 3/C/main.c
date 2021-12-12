#include <stdio.h>

main(){

int p[50], i=0, n=0;

for(i= 0; i<= 49; i++){
printf("Informe o valor %i:\n", i+1);
scanf("%i",&p[i]);

if(p[i] >100){
n = n + 1;
}
}
printf("\n-----------------------------------\n\n");
printf("%i numeros são maiores que 100!\n", n);

getch();
}
