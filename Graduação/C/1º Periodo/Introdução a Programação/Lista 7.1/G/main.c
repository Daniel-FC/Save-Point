#include <stdio.h>

main(){

int vetor[4][4], inter[16], x=0, linha, coluna, somaT=0;


for(linha=0; linha < 4; linha++){

	for(coluna=0; coluna < 4; coluna++){

		printf("[%i,%i] Informe o valor:\n", linha, coluna);
		scanf("%i", &vetor[linha][coluna]);
		
		if(coluna > linha){
		
			inter[x] = vetor[linha][coluna];
		
		}
		else{
		
			inter[x] = 0;
		
		}
		
		x++;
		
	}
	
	system("cls");
	
}

for(x=0; x < 16; x++){

	somaT = somaT + inter[x];

}

printf("A soma dos elementos acima da matriz principal é: %i", somaT);

getch();
}
