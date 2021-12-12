#include <stdio.h>

int main(){

	int matriz[10][10], linha, coluna, inter, i, j;
	
	do{
	
		printf("Informe a quantidade de LINHAS da sua matriz:\n(lembre-se: deve ser um numero inteiro par / maior que 0 /menor que 10)\n");
		scanf("%i", &i);
		
		system("cls");
		
	}while(i%2 != 0 || i < 0 || i > 10);
	
	do{
	
		printf("Informe a quantidade de COLUNAS da sua matriz:\n(lembre-se: deve ser um numero inteiro / maior que 0 /menor que 10)\n");
		scanf("%i", &j);
		
		system("cls");
		
	}while(i < 0 || i > 10);
	
	for(linha=0; linha<i; linha++){

		for(coluna=0; coluna<j; coluna++){
		
			printf("[%i/%i]Informe o valor: ", linha+1, coluna+1);
			scanf("%i", &matriz[linha][coluna]);
	
		}
		
		system("cls");

	}
	
	for(linha=0; linha<i; linha++){

		for(coluna=0; coluna<j; coluna++){
	
			inter = matriz[linha][coluna];
			matriz[linha][coluna] = matriz[linha+1][coluna];
			matriz[linha+1][coluna] = inter;
			
		}
		
		linha++;

	}
	
	for(linha=0; linha<i; linha++){

		for(coluna=0; coluna<j; coluna++){
	
			printf("%i ", matriz[linha][coluna]);
			
		}
		
		printf("\n");

	}

return(0);
}
