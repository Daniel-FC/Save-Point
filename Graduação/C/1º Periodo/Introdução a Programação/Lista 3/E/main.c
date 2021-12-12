#include <stdio.h>

main(){

int p, v;
    
printf("Insira um valor para oqual deseja calcular seu fatorial:\n");
scanf("%i", &p);

if(p >= 0){    
for(v = 1 ; p > 1; p--){
v = v * p;
}
printf("\n--------------\n\n");
printf("Fatorial calculado: %i", v);
}
else{
printf("\nValor invalido.\n\nO programa sera fechado!");
}
getch();
}
