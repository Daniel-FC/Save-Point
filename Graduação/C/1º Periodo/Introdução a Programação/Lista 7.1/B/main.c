#include <stdio.h>

main(){

int vetor[5][5], linha, coluna, somaT=0, somaDP=0, somaL4=0, somaC2=0;

for(linha=0; linha < 5; linha++){

	for(coluna=0; coluna < 5; coluna++){

		printf("[%i,%i] Informe o valor\n", linha, coluna);
		scanf("%i", &vetor[linha][coluna]);
		
		somaT = somaT + vetor[linha][coluna];
	
		if(linha == 4){
		
			somaL4 = somaL4 + vetor[linha][coluna];
		
		}
		
		if(coluna == 2){
		
			somaC2 = somaC2 + vetor[linha][coluna];
		
		}
		
		if(coluna == linha){
		
			somaDP = somaDP + vetor[linha][coluna];
		
		}

	}
		
	system("cls");

}

printf("Soma da linha 4: %i\n", somaL4);
printf("Soma da coluna 2: %i\n", somaC2);
printf("Soma da diagonal principal: %i\n", somaDP);
printf("Soma de todos os elementos: %i\n", somaT);

getch();
}
