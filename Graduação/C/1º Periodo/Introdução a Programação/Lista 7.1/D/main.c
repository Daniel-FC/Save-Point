#include <stdio.h>

treco(int a, int b){

	if(b > a || b == 0){
	
		return a;
	
	}
	else{
	
		return b;
	
	}
	
}

main(){

int matriz[6][6], linha, coluna, x, y, L=0, C=5, menor=0;


for(linha=0; linha < 6; linha++){

	for(coluna=0; coluna < 6; coluna++){

		printf("[%i,%i] Informe o valor:\n", linha+1, coluna+1);
		scanf("%i", &matriz[linha][coluna]);
		
		if(linha==L && coluna==C){
		
			menor = treco(matriz[linha][coluna], menor);
			
			if(menor == matriz[linha][coluna]){
			
				x = linha;		
				y = coluna;
			
			}
		
			L++;
			C--;
			
		}
	  		
	}
	
	system("cls");
	
}

printf("O menor valor encontrado na diagonal secundaria foi %i nas coordenadas: [%i,%i]", menor, x+1, y+1);

getch();
}
