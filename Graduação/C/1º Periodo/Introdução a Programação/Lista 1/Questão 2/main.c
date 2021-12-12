#include <stdio.h>

main(){

int num_1, num_2 = 3;

printf("Digite um valor:\n");
scanf("%i", &num_1);

printf("\nNumero magico: %i\n", num_1 + num_2);
num_2 = num_1;
num_1 = num_1 + num_2;

printf("\nnum_1 = %i e num_2 = %i\n", num_1, num_2);

getch();
}
