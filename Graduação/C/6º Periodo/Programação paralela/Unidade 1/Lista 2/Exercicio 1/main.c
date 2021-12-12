#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NT 2
#define TAM 100

int vetor[TAM], ind=-1;
pthread_mutex_t mutex;

void *Funcao (void  *arg){
	int local;

	while(1){
		pthread_mutex_lock(&mutex);
		local = ++ind;
		pthread_mutex_unlock(&mutex);
		if(local >= TAM)
			break;
		vetor[local]=rand()%100;
		printf("vetor[%d] = %d\n", local, vetor[local]);
	}
	pthread_exit(NULL);
}

int main (){
	int l;
	pthread_t threads[NT];
	srand(time(0));
	
	pthread_mutex_init(&mutex, NULL);
	
	for(l=0; l<NT; l++)
		pthread_create(&threads[l], NULL, Funcao, (void*) NULL);

	for(l=0; l<NT; l++)
		pthread_join(threads[l], NULL);
	
	for(l=0; l<TAM; l++)
		printf("%d - %i\n", l, vetor[l]);
		
	pthread_mutex_destroy(&mutex);
	return 0;

}
