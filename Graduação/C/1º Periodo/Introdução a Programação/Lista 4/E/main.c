#include <stdio.h>

main(){

int n, v;

printf("Digite o valor:\n");
scanf("%i", &n);

printf("\n--------------------\n\n");

for(v = n+1; v != n+21; v++){
printf("%i, ", v);
}
getch();
}
