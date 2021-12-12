#include <stdio.h>

int main(){

	int matriz[5][5], linha, coluna, inter, i, j=0;

	for(linha=0; linha<5; linha++){

		for(coluna=0; coluna<5; coluna++){
	
			printf("[%i/%i]Informe o valor: ", linha+1, coluna+1);
			scanf("%i", &matriz[linha][coluna]);
			
		}
		
		system("cls");

	}
	
	for(linha=0; linha<5; linha++){
	
		i=0;

		for(coluna=0; coluna<5; coluna++){
		
			inter = matriz[linha][coluna];
			matriz[linha][coluna] = matriz[i][j];
			matriz[i][j] = inter;
		
			i++;
			
			printf("%i ", matriz[linha][coluna]);
				
		}
		
		j++;
		
		printf("\n");	

	}

return(0);
}
