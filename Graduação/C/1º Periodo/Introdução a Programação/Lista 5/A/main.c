#include <stdio.h>

main(){
       
float p, b, t, d;

printf("Quantos paezinhos vendeu?\n");      
scanf("%f", &p);       
printf("Quantas broas vendeu?\n");   
scanf("%f", &b); 

t = p*0.12 + b*1.5;
d = t*0.1;

printf("\nValor total arrecadado: %.2f\nValor a ser depositado: %.2f", t, d);

getch();
}
