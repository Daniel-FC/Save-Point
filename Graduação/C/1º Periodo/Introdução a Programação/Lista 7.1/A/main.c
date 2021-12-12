#include <stdio.h>

main(){

int vetor[3][3], linha, coluna, soma[3]={0};

for(linha=0; linha < 3; linha++){

	for(coluna=0; coluna < 3; coluna++){

		printf("[%i,%i] Informe o valor\n", linha, coluna);
		scanf("%i", &vetor[linha][coluna]);

	}
	
	system("cls");
	
}

for(coluna=0; coluna < 3; coluna++){

	for(linha=0; linha < 3; linha++){

		soma[coluna] = soma[coluna] + vetor[linha][coluna];

	}
	
	printf("Soma coluna %i: %i |", coluna, soma[coluna]);
	
}
getch();
}
