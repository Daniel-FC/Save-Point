#include <stdio.h>

main(){
char nome[50];
int salarioB, dependente, salarioL;

printf("Informe o seu nome? \n");
scanf("%s", &nome);
printf("Quanto é o seu salario bruto? \n");
scanf("%i", &salarioB);
printf("Quantos dependentes possui? \n");
scanf("%i", &dependente);
printf("\n--------------------------------\n");


if (salarioB <= 500){
             (salarioB = salarioB*0.93);       
}if (salarioB <= 900, salarioB >= 501){
             (salarioB = salarioB*0.91);
}if (salarioB >= 901){
             (salarioB = salarioB*0.89);
}       

salarioL = (salarioB + (15*dependente) + 140); 

printf("%s, seu salario liquido é: %i", nome, salarioL);

getch();
}
