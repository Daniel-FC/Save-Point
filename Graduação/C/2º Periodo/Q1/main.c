#include <stdio.h>

int main(){

	int vetor[100], x=0, total=0, rodar=1, menor, dif, posi, i, n;

	do{
	
		printf("[%i]]Infome o valor:\n", x+1);
		scanf("%i", &vetor[x]);
		
		total = total + vetor[x];

		do{

			printf("\nDeseja adicionar mais valores? Se sim dijite 1, Se não digite 0.\n");
			scanf("%i", &rodar);

		}while(rodar<0 || rodar>1);

		system("cls");
		x++;
		i=x;
	
	}while(rodar==1 && x<100);

	for(x=0; x<i; x++){

		dif = (total/i) - vetor[x];

		if(dif<0){

			dif = dif*-1;

		}
		if(x==0){

			menor = dif;
			n = vetor[x];
			posi = x;

		}
		if(dif < menor){

			menor = dif;
   			n = vetor[x];
			posi = x;

		}

	}

	printf("O numero mais proximo da media é o %i e está na posição %i", n, posi+1);

	return(0);
}
