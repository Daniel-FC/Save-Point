#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NT 4
#define TAM 100

int vetor[TAM];


void Quick(int vetor[10], int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim);   

}

void *Funcao (void  *arg){

	int l, c, x;

	x = pthread_self();
	printf("Thread [%d]: %d a %d\n", x, (x - 1) * (TAM / NT), x * (TAM / NT));
	for(l=(x - 1) * (TAM / NT); l< ( x * (TAM / NT) )-1; l++){

		for(c=l+1; c<x * (TAM / NT); c++){
			
			if(vetor[l]>vetor[c]){
				
				int tmp =vetor[l];
				vetor[l]=vetor[c];
				vetor[c]=tmp;
				
			}
			
		}		
				
	}

}

int main (){

	int l;
	pthread_t threads[NT];
	
	srand(time(0));
	for(l=0; l<TAM; l++)
		vetor[l]=(rand()%1000);
	
	for(l=0; l<NT; l++)
		pthread_create(&threads[l], NULL, Funcao, NULL);

	for(l=0; l<NT; l++)
		pthread_join(threads[l], NULL);
	
	Quick(vetor, 0, TAM);	
	
	printf("\n");
	for(l=0; l<TAM; l++)
		printf("%i ", vetor[l]);
		
}
