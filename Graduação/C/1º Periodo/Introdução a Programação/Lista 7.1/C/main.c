#include <stdio.h>

main(){

int vetor[20][20], linha, coluna, m, n;

printf("Informe a quantidade de linhas da matriz com um tamanho maximo de 20\n");
scanf("%i", &m);
printf("Informe a quantidade de colunas da matriz com um tamanho maximo de 20\n");
scanf("%i", &n);
system("cls");

for(linha=0; linha < m; linha++){

	for(coluna=0; coluna < n; coluna++){

		if(linha < coluna){
		
			vetor[linha][coluna] = 2*linha + 7*coluna - 2;
		
		}
		
		if(linha == coluna){
		
			vetor[linha][coluna] = 3*linha - 1;
		
		}
		
		if(linha > coluna){
		
			vetor[linha][coluna] = 4*linha - 10*coluna;
		
		}
		
		printf("%i ", vetor[linha][coluna]);

	}
	
	printf("\n");
	
}

getch();
}
