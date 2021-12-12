#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TAM 58 //Quantidade de nós
#define POP 50 //Tamanho da população (NO MINIMO MEL*NT)
#define GERA 1000 //Quantidade de gerações
#define MEL 10 //Quantidade de melhores da população
#define NT 3 //Numero de Thread

int matriz[TAM][TAM], popu[POP][TAM+1], melhor[MEL*NT][TAM+1], copia[TAM+1];

void *AGenetico (void  *arg){
	
	int l, c, x, y, comp, geracao=0, id=pthread_self();
	
	while(geracao<GERA){

		//Calculo do custo do caminho
		for(l=(id-1)*POP/NT; l<id*POP/NT; l++){
			
			for(c=0, popu[l][TAM]=0; c<TAM-1; c++)
				popu[l][TAM]+=matriz[popu[l][c]][popu[l][c+1]];
			popu[l][TAM]+=matriz[popu[l][c]][popu[l][0]];
				
		}
		
		//Melhores individuos
		for(l=(id-1)*MEL; l<id*MEL; l++){
		
			melhor[l][TAM]=999999999;
			for(x=(id-1)*POP/NT; x<id*POP/NT; x++){
			
				if(melhor[l][TAM]>popu[x][TAM]){
				
					for(c=(id-1)*MEL, comp=0; c<id*MEL; c++){
					
						if(popu[x][TAM]==melhor[c][TAM])
							comp++;					
					
					}
					if(comp==0){
						
						melhor[l][TAM]=popu[x][TAM];
						y=x;
					}	
						
				}
			
			}
			for(c=0; c<TAM+1; c++)
				melhor[l][c]=popu[y][c];			

		}
		
		if(GERA-1==geracao)
			break;

		//Clonagem
		for(c=0; c<TAM+1; c++)
			popu[(id-1)*POP/NT][c]=melhor[(id-1)*MEL][c];		
		for(l=((id-1)*POP/NT)+1; l<(id*POP/NT)-(((id*POP/NT)-((id-1)*POP/NT))/2); l++){
		
			x=rand()%(id*MEL-1)+1;
			for(c=0; c<TAM+1; c++)
				popu[l][c]=melhor[x][c];
		
		}

		//Mutação
		for(l=((id-1)*POP/NT)+1; l<((id-1)*POP/NT)+(POP/NT); l++){
		
			x=rand()%(TAM/2);
			y=rand()%(TAM/2)+(TAM/2);
			for(c=0; c<TAM; c++)
				copia[c]=popu[l][c];
			for(c=x; c<y; c++){
			
				popu[l][c+1]=copia[c];			
			
			}
			popu[l][x]=copia[c];

		}

		//Cruzamento
		for(l=(id*POP/NT)-(((id*POP/NT)-((id-1)*POP/NT))/2); l<(id*POP/NT); l++){
			
			//Resetando indivuduo
			for(c=0; c<TAM; c++)
				popu[l][c]=-1;
			
			//Metade dos cromossomos do melhor
			c=0;
			while(c<TAM/2){
				
				comp=1;
				while(comp){
				
					y=rand()%TAM;
					if(popu[l][y]==-1)
						comp=0;
										
				}
				popu[l][y]=melhor[MEL*(id-1)][y];
				c++;
				
			}

			//Parte dos cromossomos de um random
			x=rand()%(MEL-1)+((id-1)*MEL)+1;		
			for(c=0; c<TAM; c++){
			
				for(y=0, comp=0; y<TAM; y++){
					
					if(melhor[x][c]==popu[l][y])
						comp++;
		
				}
				if(comp==0 && popu[l][c]==-1)
					popu[l][c]=melhor[x][c];			

			}
	
			//Cromossomos que sobraram
			for(c=0; c<TAM; c++){
			
				for(y=0, comp=0; y<TAM; y++){
					
					if(melhor[x][c]==popu[l][y])
						comp++;
		
				}
				if(comp==0){
									
					for(y=0; y<TAM; y++){
					
						if(popu[l][y]==-1 && comp==0){
							
							popu[l][y]=melhor[x][c];
							comp++;
							
						}
					
					}
					
				}

			}
			
			//Certificação final
			for(c=0; c<TAM; c++){
		
				if(popu[l][c]==-1){
					
					for(x=0; x<TAM; x++){
						
						for(y=0, comp=0; y<TAM; y++){
							
							if(popu[l][y]==x)
								comp++;
							
						}
						if(comp==0)
							popu[l][c]=x;
						
					}
						
				}

			}

		}

		geracao++;
		
	}
	pthread_exit(NULL);
	
}

int main (){

	int l, c, x, y, comp;
	pthread_t threads[NT];
	srand(time(0));
	
	//Entradas
	for(l=0; l<TAM; l++){
		
		for(c=0; c<TAM; c++)
			scanf("%i", &matriz[l][c]);
			
	}
	
	//Gerador de população inicial
	for(l=0; l<POP; l++){

		for(c=0; c<TAM; c++){

			x=1;
			while(x){
			
				popu[l][c]=rand()%TAM;
				for(y=0, comp=0; y<c; y++){
				
					if(popu[l][c]==popu[l][y])
						comp++;
				
				}
				if(comp==0)
					x=0;

			}				

		}

	}	

	//Threads
	for(l=0; l<NT; l++)
		pthread_create(&threads[l], NULL, AGenetico, NULL);
		
	for(l=0; l<NT; l++)		
		pthread_join(threads[l], NULL);

	//Resultado
	printf("\n~~~Melhor individuo em %i geracoe's~~~\n", GERA);
	for(l=0, comp=0, x=999999999; l<MEL*NT; l++){

		if(x>melhor[l][TAM] && melhor[l][TAM]!=0){
			
			x=melhor[l][TAM];
			y=l;
			
		}
					
	}
	for(c=0; c<TAM; c++)
		printf("%i ", melhor[y][c]);
	printf("= %i\n", melhor[y][TAM]);
	
}
