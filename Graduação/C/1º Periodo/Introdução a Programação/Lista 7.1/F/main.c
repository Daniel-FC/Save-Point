#include <stdio.h>

main(){

int vetor[6][6], element[6], x=0, linha, coluna;

for(linha=0; linha < 6; linha++){

	for(coluna=0; coluna < 6; coluna++){

		printf("[%i,%i] Informe o valor:\n", linha, coluna);
		scanf("%i", &vetor[linha][coluna]);
		
		if(linha == coluna){
		
			element[x] = vetor[linha][coluna];
			x++;
		
		}
		
	}
	
	system("cls");
	
}

x=0;

for(linha=0; linha < 6; linha++){

	for(coluna=0; coluna < 6; coluna++){

		printf("%i ", vetor[linha][coluna]*element[x]);
			
	}
	
	printf(" -Linha x %i\n", element[x]);
	x++;
	
}

getch();
}
