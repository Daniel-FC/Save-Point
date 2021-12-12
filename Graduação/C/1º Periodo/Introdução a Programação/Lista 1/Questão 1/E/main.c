#include <stdio.h>

main(){

float a, b, c, d, e;

printf("Informe o valor de A:\n");
scanf("%f", &a);
printf("Informe o valor de B:\n");
scanf("%f", &b);

c = (b-a)/3;
d = a + c;
e = b - c;

printf("\n---------------------\n\n");
printf("\na=%.2f | b=%.2f | d=%.2f | e=%.2f", a, b, d, e);

getch();
}
