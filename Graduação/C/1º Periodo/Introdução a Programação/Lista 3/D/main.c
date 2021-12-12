#include <stdio.h>

main(){

int p[20], i=0, n=0;

for(i= 0; i<= 19; i++){
printf("Informe o valor %i:\n", i+1);
scanf("%i",&p[i]);
n = n + p[i];
}

printf("\n-----------------------------------\n\n");
printf(" A soma é: %i\n", n);

getch();
}
