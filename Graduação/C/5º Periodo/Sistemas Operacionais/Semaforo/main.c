#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <conio.c>

#define N 5                        //Quantidade de filosófos
#define PENSANDO 0                 //Id para estado pensando
#define FAMINTO 1                  //Id para estado faminto
#define COMENDO 2                  //Id para estado comendo
#define ESQUERDA (id_filosofo+4)%N //Id do filosofo da esquerda do id
#define DIREITA (id_filosofo+1)%N  //Id do filosofo da direita do id
  
sem_t mutex;
sem_t S[N];
  
void *filosofo(void *num);
void pegar_hashi(int);
void devolver_hashi(int);
void teste(int);
  
int estado[N]; //Estado dos filosofos
int filo_num[N] = {0, 1, 2, 3, 4};
  

void *filosofo(void *num){ //função que simula um filosofo
    
	while(1){ //vida eterna
		
        int *i=num;
        
        sleep(1);
        pegar_hashi(*i); //Chama a função
        sleep(0);
        devolver_hashi(*i); //Chama a função
        
    }
    
}
  
void pegar_hashi(int id_filosofo){ //função que o filosofo pega os hashis da mesa
	
    sem_wait(&mutex); //entra na regiao critica
    estado[id_filosofo] = FAMINTO; //altera o estado do filosofo
    textcolor(11); //altera a cor do texto
    printf("Filosofo %d esta com fome\n", id_filosofo+1); //Resposta de saida
    teste(id_filosofo); //Verifica a intencao de pegar os hashis
    sem_post(&mutex); //sai da regiao critica
    sem_wait(&S[id_filosofo]); //bloqueia os hashis
    sleep(1);
    
}
  
void teste(int id_filosofo){ //procedimento que filosofo tem intencao de pegar os hashis para comer
	
    if(estado[id_filosofo]==FAMINTO && estado[ESQUERDA]!=COMENDO && estado[DIREITA]!=COMENDO){ //condição para o filosofo comer
    	
        estado[id_filosofo] = COMENDO; //filosofo ganhou a vez de comer
        sleep(2);
        textcolor(7); //altera a cor do texto
        printf("Filosofo %d pegou os hashis %d e %d ", id_filosofo+1, ESQUERDA+1, id_filosofo+1); //Resposta de saida
        textcolor(3); //altera a cor do texto
        printf("Filosofo %d esta comendo\n", id_filosofo+1); //Resposta de saida
        sem_post(&S[id_filosofo]); //libera os hashis
        
    }
    
}
  
void devolver_hashi(int id_filosofo){ //procedimento filosofo devolve os hashis a mesa
	
    sem_wait(&mutex); //entra na regiao critica
    estado[id_filosofo] = PENSANDO; //terminou de comer
    textcolor(7); //altera a cor do texto
    printf("Filosofo %d devolve os hashis %d e %d ", id_filosofo+1, ESQUERDA+1, id_filosofo+1); //Resposta de saida
    textcolor(2); //Aaltera a cor do texto
    printf("Filosofo %d esta pensando\n", id_filosofo+1); //Resposta de saida
    teste(ESQUERDA); //ve se o visinho da esquerda pode comer
    teste(DIREITA); //ve se o visinho da direita pode comer
    sem_post(&mutex); //sai da regiao critica
    
}

int main(){
	
    int i; //contador auxiliar
    pthread_t thread_id[N];
    sem_init(&mutex, 0, 1);
    
    for(i=0; i<N; i++){
	
        sem_init(&S[i], 0, 0); //criacao dos hashis
        
    }
	
	for(i=0; i<N; i++){
		
        pthread_create(&thread_id[i], NULL, filosofo, &filo_num[i]);  //cria as threads
        textcolor(2); //altera a cor do texto
        printf("Filosofo %d esta pensando\n", i+1); //Resposta de saida
        
    }
    
    for(i=0; i<N; i++){
    	
        pthread_join(thread_id[i], NULL); //fazer a junção das threads
    
	}
	
}
