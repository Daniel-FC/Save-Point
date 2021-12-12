#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NT 2
#define TAM 10

int conta;
pthread_mutex_t mutex;

void *Funcao (void  *arg){

	int l, x, i;
	
	for(l=0; l<TAM; l++){
		
		x=rand()%2;
		i=rand()%20;
		
		if(x==0){

			pthread_mutex_lock(&mutex);
			conta+=i;
			pthread_mutex_unlock(&mutex);
			
			printf("<<< Deposito de: %i, Saldo: %i\n", i, conta);
			
		}
		
		if(x==1){
			
			if(conta>=i){

				pthread_mutex_lock(&mutex);
				conta-=i;
				pthread_mutex_unlock(&mutex);
				
				printf(">>> Saque de: %i, Saldo: %i\n", i, conta);
			
			}
			else{
				
				printf(">>> Saque de: %i, Saldo: %i IMPOSSIVEL DE REALIZAR\n", i, conta);
				
			}
			
		}
	}
	pthread_exit(NULL);

}

int main (){
	
	int l;
	pthread_t threads[NT];
	srand(time(0));

	pthread_mutex_init(&mutex, NULL);
	
	conta=rand()%30;
	printf("Saldo inicial: %i\n\n", conta);
	
	for(l=0; l<NT; l++)
		pthread_create(&threads[l], NULL, Funcao, NULL);

	for(l=0; l<NT; l++)
		pthread_join(threads[l], NULL);
	
	printf("\nSaldo final: %i", conta);

	pthread_mutex_destroy(&mutex);

}
