#include <stdio.h>

main(){

int matrizA[20][20], matrizB[20][20], vetorC[200], A=0, n, qtd=0, linhaA, colunaA, linhaB, colunaB, linhaC[200], colunaC[200];

for(linhaA=0; linhaA < 20; linhaA++){

	for(colunaA=0; colunaA < 20; colunaA++){
	
		A++;
		matrizA[linhaA][colunaA] = A;
	
	}

}

for(linhaB=0; linhaB < 20; linhaB++){

	for(colunaB=0; colunaB < 20; colunaB++){
		
		do{
		
			printf("[%i,%i]Informe um valor maior que zero:\n", linhaB+1, colunaB+1);
			scanf("%i", &matrizB[linhaB][colunaB]);
			system("cls");
			
		}while(matrizB[linhaB][colunaB] <= 0);

	}

}

for(n=0; n > 200; n++){

	vetorC[n] = 0;
	linhaC[n] = 0;
	colunaC[n] = 0;

}

n=0;

for(linhaA=0; linhaA < 20; linhaA++){

	for(colunaA=0; colunaA < 20; colunaA++){
	
		for(linhaB=0; linhaB < 20; linhaB++){

			for(colunaB=0; colunaB < 20; colunaB++){
			
				if(matrizA[linhaA][colunaA] == matrizB[linhaB][colunaB]){
				
					vetorC[n] = matrizB[linhaB][colunaB];
					linhaC[n] = linhaB;
					colunaC[n] = colunaB;
					n++;
					qtd++;
				
				}
		
			}

		}
		
	}

}

printf("Existe'm %i numero's detectado's na matriz B que tambem esta'o em A: ", qtd);

for(n=0; n < qtd; n++){

	if(vetorC[n] != 0){
	
		printf("%i(%i/%i), ", vetorC[n], linhaC[n]+1, colunaC[n]+1);
	
	}

}

getch();
}
