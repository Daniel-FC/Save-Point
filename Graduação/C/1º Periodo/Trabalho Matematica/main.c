#include <stdio.h>

main(){

int matrizA[3][3], matrizB[3][3], matrizC[3][3], linhaA, colunaA, linhaB, colunaB, linhaC, colunaC, intermedio, operacao;
int la, ca, lb, cb, lc, cc;

printf("Se deseja somar matrizes digite 0.\nSe deseja mutiplicar matrizes digite 1.\nQualquer outro valor será ignorado.\n\nDigite o o valor:\n");
scanf("%i", &operacao);


if(operacao == 0 || operacao == 1){

	for(linhaA=0; linhaA < 3; linhaA++){
	
		system("cls");
	
		for(colunaA=0; colunaA < 3; colunaA++){
	
			printf("[%i,%i] Infome o valor para a matriz A:\n", linhaA+1, colunaA+1);
			scanf("%i", &matrizA[linhaA][colunaA]);
			
		}
		
	}
	
	for(linhaB=0; linhaB < 3; linhaB++){
	
		system("cls");
	
		for(colunaB=0; colunaB < 3; colunaB++){
	
			printf("[%i,%i] Informe o valor para a matriz B:\n", linhaB+1, colunaB+1);
			scanf("%i", &matrizB[linhaB][colunaB]);
			
		}
		
	}

}
else{
	
	system("cls");
	printf("Valor informado invalido!\nTente novamente.");

}

if(operacao == 0){

	linhaA=0;
	linhaB=0;

	for(linhaC=0; linhaC < 3; linhaC++){
	
		colunaA=0;
		colunaB=0;
	
		for(colunaC=0; colunaC < 3; colunaC++){
		
			matrizC[linhaC][colunaC] = matrizA[linhaA][colunaA] + matrizB[linhaB][colunaB];
	
			printf(" %i ", matrizC[linhaC][colunaC]);
			
			colunaA++;
			colunaB++;
			
		}
		
		linhaA++;
		linhaB++;
		printf("\n");
		
	}

}

if(operacao == 1){

linhaA=0;
system("cls");


	printf("O produto matricial de A por B é:\n\n");
	
	for(linhaC=0; linhaC < 3; linhaC++){
	              
	    colunaB=0;          
	
		for(colunaC=0; colunaC < 3; colunaC++){
		
			colunaA=0;
			linhaB=0;
			intermedio=0;
	
			for(colunaA; colunaA < 3; colunaA++){
			
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
	
}

getch();
}
