#include <stdio.h>

main(){

int z=0, n, maior=0, menor=0;

while(z == 0){
	system("cls");
	printf("Informe o valor:\n");
	scanf("%i", &n);

	if(maior == 0 && menor == 0){
	maior = n;
	menor = n;
	}
	
	if(maior < n){
	maior = n;
	}
	
	if(menor > n){
	menor = n;
	}
	
	z = 2;
	
		system("cls");
		printf("Digite 0 caro queira adicionar mais um valor; \nDigite outro valor caso tenha terminado;\n\n");
		printf("Quer adicionar mais algum valor?");
		scanf("%i", &z);
	}
	

system("cls");
printf("O menor valor: %i\n", menor);
printf("O maior valor: %i", maior);

getch();
}
