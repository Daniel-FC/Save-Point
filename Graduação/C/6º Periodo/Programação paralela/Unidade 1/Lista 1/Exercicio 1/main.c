#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NT 3
#define TAM 100

int vetor[TAM], matriz[NT][TAM];

void *Funcao (void  *arg){
	
	int l, x , y=*(int *)arg;
	
	x = pthread_self();
	printf("Thread [%i]: %i\n", x, y);
	
	for(l=0; l<TAM; l++)
		matriz[x-1][l]=vetor[l]*y;
	
}

int main (){
	
	int l, c, maior=0;
	pthread_t threads[NT];
	int dados[NT];
	
	srand(time(0));
	printf("Original: ");
	for(l=0; l<TAM; l++){
		
		vetor[l]=rand()%100;
		printf("%i ", vetor[l]);
			
	}
	printf("\n\n");
	
	for(l=0; l<NT; l++){
		
		dados[l]=rand()%10;
		pthread_create(&threads[l], NULL, Funcao, (void*) &dados[l]);
		
	}

	for(l=0; l<NT; l++)
		pthread_join(threads[l], NULL);


	for(l=0; l<NT; l++){
		
		printf("\nThread [%i]: ", l);
		for(c=0; c<TAM; c++){
			
			printf("%i ", matriz[l][c]);
			if(maior<matriz[l][c])
				maior=matriz[l][c];
			
		}
		printf("\n");
	
	}
	printf("\nMaior: %i", maior);
		
}
