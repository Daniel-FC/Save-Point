#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <conio.c>

#define N 10 //Quantidade de filosófosz

pthread_mutex_t mutex_hashi[N]; //Quantidade de hashis
pthread_t filosofo[N]; //Quantidade de filosofos

int id[N], active_mutex;

void pegar_hashis(int *filo){ //filosofo tenta pegar hashi

	if(active_mutex==1)
		sleep(1);

	pthread_mutex_lock(&(mutex_hashi[*filo])); //bloqueia um hashi
	if(*filo < N-1){
		
		pthread_mutex_lock(&(mutex_hashi[*filo+1])); //bloqueia o outro hashi
		
	}
	else{
		
		pthread_mutex_lock(&(mutex_hashi[0])); //se for o quinto filosofo ele bloqueia o hashi da posicao 0, e não uma posicao a mais que ele
		
	}
	
}

void largar_hashis(int *filo){
	
	if(active_mutex==1)
		sleep(1);	
	
	pthread_mutex_unlock(&(mutex_hashi[*filo])); //filosofo larga um hashi
	if(*filo < N-1){
		
		pthread_mutex_unlock(&(mutex_hashi[*filo+1])); //filosofo larga o outro hashi
		
	}
	else{
		
		pthread_mutex_unlock(&(mutex_hashi[0])); //se for o quinto filosofo, libera o hachi da posicao zero
		
	}	
	
}

void * vida_filosofo (void *var){ //representa toda atividade realizada na vida do filosofo
	
	int * filo = (int *) (var); //identificacao do filosofo
	while(1){ //vida eterna
		
		//pensar
		int pensar = (rand()%10+2); //tempo para pensar
		textcolor(2); //altera a cor do texto
		printf("Filosofo %d: esta pensando por %d segundos\n", *filo, pensar); //Resposta de saida
		sleep(1);
		
		//filosofo está com fome, pois parou de pensar
		sleep(2);
		pegar_hashis(filo); //tentando pegar os hashis
		textcolor(7); //altera a cor do texto
		printf("Filosofo %d: pegou os hashis\n", *filo); //Resposta de saida
		sleep(1);
		int comer = (rand()%5+1); //tempo para comer
		textcolor(3); //altera a cor do texto
		printf("Filosofo %d: esta comendo por %d segundos.\n", *filo, comer); //Resposta de saida
		sleep(0.5);
		largar_hashis(filo); //larga os hashis, pois já terminou de comer
		textcolor(7); //altera a cor do texto
		printf("Filosofo %d: devolveu os hashis\n", *filo); //Resposta de saida
		
	}
	pthread_exit(NULL);
	
}

int main(){

	for(int i=0; i<N ; i++){
		
		pthread_mutex_init(&(mutex_hashi[i]), NULL); //cria as areas criticas
		
	}
	for(int j=0; j<N ; j++){
		
		id[j]=j;
		pthread_create(&filosofo[j], NULL, &vida_filosofo, (void *) &id[j]); //cria as threads
		
	}	
	while(1){ //nao encerra o codigo
		
	}
	
} //O monitor consiste de um conjunto de procedimentos para permitir a manipulação de um recurso compartilhado, uma trava de exclusão mútua, as variáveis associadas ao recurso e uma invariante que define as premissas para evitar disputa de recursos.
