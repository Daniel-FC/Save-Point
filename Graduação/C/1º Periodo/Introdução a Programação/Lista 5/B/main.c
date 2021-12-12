#include <stdio.h>

main(){

int n, C, D, U;

printf("Informe o valor:\n");
scanf("%i", &n);

C = n/100;
D = n%100;
U = D%10;

printf("\nCentena: %i\n", C);
printf("Dezena: %i\n", D/10);
printf("Unidade: %i", U);

getch();
}
