#include <stdio.h>

main(){

int numero;

printf("Informe um numero:\n");
scanf("%i", &numero);

printf("\n-------------------\n\n");
printf("O antecessor do seu numero �: %i\nO sucessor do seu numero �: %i", numero-1, numero+1);

getch();
}
