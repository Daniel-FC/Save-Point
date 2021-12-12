#include <stdio.h>

main(){

int matrizA[4][6], matrizB[6][4], matrizC[4][4], linhaA, colunaA, linhaB, colunaB, linhaC, colunaC, intermedio;

for(linhaA=0; linhaA < 4; linhaA++){

	for(colunaA=0; colunaA < 6; colunaA++){

		printf("[%i,%i] Infome o valor para a matriz A:\n", linhaA, colunaA);
		scanf("%i", &matrizA[linhaA][colunaA]);
		
	}
	
	system("cls");
	
}

for(linhaB=0; linhaB < 6; linhaB++){

	for(colunaB=0; colunaB < 4; colunaB++){

		printf("[%i,%i] Informe o valor para a matriz B:\n", linhaB, colunaB);
		scanf("%i", &matrizB[linhaB][colunaB]);
		
	}
	
	system("cls");
	
}

linhaA=0;

printf("O produto matricial de A por B é:\n\n");

for(linhaC=0; linhaC < 4; linhaC++){
              
    colunaB=0;          

	for(colunaC=0; colunaC < 4; colunaC++){
	
		colunaA=0;
		linhaB=0;
		intermedio=0;

		for(colunaA; colunaA < 6; colunaA++){
		
			intermedio =  matrizA[linhaA][colunaA] *  matrizB[linhaB][colunaB] + intermedio;
			
			linhaB++;
		
		}
		
		matrizC[linhaC][colunaC] = intermedio;
	
		colunaB++;
		
		printf(" %i ", matrizC[linhaC][colunaC]);
	
	}
	
	printf("\n");
	linhaA++;
	
}
getch();
}
