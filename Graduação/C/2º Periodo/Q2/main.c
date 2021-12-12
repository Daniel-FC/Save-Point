#include <stdio.h>

int main(){

	int vetorA[100], vetorB[100], vetorC[200], rodar, x, y, n, A=0, B=0;
	
	do{
	
		printf("VetorA(%i) Infome o valor:", x+1);
		scanf("%i", &vetorA[x]);

		do{

			printf("\nDeseja adicionar mais valores? Se sim dijite 1, Se não digite 0.\n");
			scanf("%i", &rodar);

		}while(rodar<0 || rodar>1);
		
		system("cls");
		A++;
		x++;

	}while(rodar==1 && x<100);
	
	x=0;
	
	do{
	
		printf("VetorB(%i) Infome o valor:", x+1);
		scanf("%i", &vetorB[x]);

		do{

			printf("\nDeseja adicionar mais valores? Se sim dijite 1, Se não digite 0.\n");
			scanf("%i", &rodar);

		}while(rodar<0 || rodar>1);
		
		system("cls");
		B++;
		x++;

	}while(rodar==1 && x<100);
	
	for(x=0; x<A; x++){
	
		vetorC[x] = vetorA[x];
	
	}
	
	for(x=0; x<B; x++){
	
		n=0;
	
		for(y=0; y<A; y++){
		
			if(vetorB[x] == vetorC[y]){
			
				n=1;
			
			}
		
		}
		
		if(n==0){
		
			vetorC[A] = vetorB[x];
			A++;
			
		}
	
	}
	
	for(x=0; x<A; x++){
	
		printf("%i ", vetorC[x]);
	
	}

return(0);
}
