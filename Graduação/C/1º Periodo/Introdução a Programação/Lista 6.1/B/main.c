#include <stdio.h>

main(){

int n[15], add=0, maior=0, menor=0;

while(add != 15){

	add++;
	
	system("cls");
	printf("[%i] Informe o valor:\n", add);
	scanf("%i", &n[add]);
	
	if(maior == 0 && menor == 0){
		maior = n[add];
		menor = n[add];
	}
		
	if(maior < n[add]){
		maior = n[add];
	}
		
	if(menor > n[add]){
		menor = n[add];
	}

}

system("cls");
printf("A soma do menor e do maior vetor é %i", menor+maior);

getch();
}
