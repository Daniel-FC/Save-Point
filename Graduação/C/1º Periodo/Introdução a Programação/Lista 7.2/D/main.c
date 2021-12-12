#include <stdio.h>

main(){

int matriz[8][8], linha, coluna, x=0;

for(linha=0; linha < 8; linha++){

	for(coluna=0; coluna < 8; coluna++){
	
		x++;
		matriz[linha][coluna] = x;
	
	}
		
}

for(linha=0; linha < 8; linha++){

	for(coluna=0; coluna < 8; coluna++){


		if(coluna > linha){
		
			matriz[linha][coluna] = 0;
		
		}
		
		if(matriz[linha][coluna] >= 10){
		printf("%i ", matriz[linha][coluna]);
		}
		else{
		printf(" %i ", matriz[linha][coluna]);
		}
	
	}
	
	printf("\n");
		
}

getch();
}
