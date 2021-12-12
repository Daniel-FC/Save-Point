#include <stdio.h>

main(){

int n;

printf("Informe o valor:\n");
scanf("%i", &n);

if(n%2 == 0){
printf("\nO numero é par e");
} 
else{
printf("\nO numero é impar e");
}

if(n>0 && n!=0){
printf(" positivo");
}
if(n<0 && n!=0){
printf(" negativo");
}
if(n == 0){
printf(" neutro");
}





}
