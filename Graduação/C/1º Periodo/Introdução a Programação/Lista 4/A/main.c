#include <stdio.h>

main(){

int H=0, N, V;

printf("Informe o valor inicial:\n");
scanf("%i", &N);
V = N;
N++;

for(N; N != 1; N--){
H = H + N;
}
printf("\n---------------\n\n");
printf("O valor final é: %i", H-V);

getch();
}
