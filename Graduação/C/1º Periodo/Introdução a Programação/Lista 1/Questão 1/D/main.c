#include <stdio.h>

main(){

int A, B, C, R, S;
float D;

printf("Informe o valor de A\n");
scanf("%i", &A);
printf("Informe o valor de B\n");
scanf("%i", &B);
printf("Informe o valor de C\n");
scanf("%i", &C);

R = (A*A + 2*A*B + B*B);
S = (B*B + 2*B*C + B*C);

D = (R+S)/2;

printf("\nO valor de D é: %.1f", D);

getch();
}
