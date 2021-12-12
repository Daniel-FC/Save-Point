#include <stdio.h>

main(){

int vetor[5][5], linha, coluna;


for(linha=0; linha < 5; linha++){

	for(coluna=0; coluna < 5; coluna++){

		printf("[%i,%i] Informe o valor:\n", linha, coluna);
		scanf("%i", &vetor[linha][coluna]);
	  		
	}
	
	system("cls");
	
}

printf("A matriz transposta é:\n");

for(coluna=0; coluna < 5; coluna++){

	for(linha=0; linha < 5; linha++){

		printf("%i ", vetor[linha][coluna]);
	  		
	}
	
	printf("\n");
	
}
getch();
}
