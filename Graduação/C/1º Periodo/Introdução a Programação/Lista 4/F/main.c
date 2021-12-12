#include <stdio.h>

main(){

int n, v;

printf("Digite o valor:\n");
scanf("%i", &n);

printf("\n--------------------\n\n");

if(n > 0){
for(v = 1; v != n; v++){

if(n%v == 0){
printf("%i, ", v);
}
}
printf("%i.", n);
}
else{
printf("Valor invalido.");
}
getch();
}
