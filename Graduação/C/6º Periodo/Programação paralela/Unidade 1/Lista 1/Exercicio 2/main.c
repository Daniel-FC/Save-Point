#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NT 4
#define TAM 100

int vetor[TAM], L;

void *Funcao (void  *arg){

	int l, c, n, x=pthread_self();
	
	for(l=x; l<TAM; l=l+NT){
		
		for(c=1, n=0; c<=l; c++){

			if(l%c==0)
				n++;
		
		}
		if(n==2){
			
			vetor[L]=l;
			L++;
			
		}
					
	}

}

int main (){
	
	int l, i;
	pthread_t threads[NT];
	
	for(i = 0; i < NT; i++)
		pthread_create(&threads[i], NULL, Funcao, NULL);
	
	for(i = 0; i < NT; i++)
		pthread_join(threads[i], NULL);
	
	for(l=0; l<L; l++)
		printf("%i ", vetor[l]);
		
	printf("\n\nQuantidade: %i", L);
		
}
