#include <stdio.h>

main(){

int numero;

printf("Informe um numero:\n");
scanf("%i", &numero);

printf("\n-------------------\n\n");
printf("O antecessor do seu numero é: %i\nO sucessor do seu numero é: %i", numero-1, numero+1);

getch();
}
