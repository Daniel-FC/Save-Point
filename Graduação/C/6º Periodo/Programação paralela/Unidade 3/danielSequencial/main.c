#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 58 //Quantidade de nós
#define POP 50 //Tamanho da população
#define GERA 1000 //Quantidade de gerações
#define MEL 10 //Quantidade de Melhores da população
#define MELS 1 //Quantidade de Melhores da população copiados para geraçao seguinte

int main(){
	
	int l, c, x, y, comp, geracao=0;
	int matriz[TAM][TAM], popu[POP][TAM+1], melhor[MEL][TAM+1], copia[TAM+1];	
	srand(time(0));
	clock_t tempo = clock();
	
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
	
	//Algoritmo genetico
	while(geracao<GERA){
	
		//Calculo do custo do caminho
		for(l=0; l<POP; l++){
			
			for(c=0, popu[l][TAM]=0; c<TAM-1; c++)
				popu[l][TAM]+=matriz[popu[l][c]][popu[l][c+1]];
			popu[l][TAM]+=matriz[popu[l][c]][popu[l][0]];
				
		}
		
		//Melhores individuos
		for(l=0; l<MEL; l++){
		
			melhor[l][TAM]=999999999;
			for(x=0; x<POP; x++){
			
				if(melhor[l][TAM]>popu[x][TAM]){
				
					for(c=0, comp=0; c<MEL; c++){
					
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

		//Parar
		if(GERA-1==geracao)
			break;

		//Clonagem
		for(l=0; l<MELS; l++){
			
			for(c=0; c<TAM+1; c++)
				popu[l][c]=melhor[l][c];
				
		}
		for(; l<POP/2; l++){
		
			x=rand()%MEL;
			for(c=0; c<TAM+1; c++)
				popu[l][c]=melhor[x][c];
		
		}

		//Mutação
		for(l=MELS; l<POP/2; l++){
		
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
		for(l=POP/2; l<POP; l++){
					
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
				popu[l][y]=melhor[0][y];
				c++;
				
			}

			//Parte dos cromossomos de um random
			x=rand()%(MEL-1)+1;
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

		}
		geracao++;
	
	}

	//Resultado
	printf("\n~~~Melhor individuo em %i geracoe's~~~\n", GERA);
	for(l=0, comp=0, x=999999999; l<MEL; l++){

		if(x>melhor[l][TAM]){
			
			x=melhor[l][TAM];
			y=l;
			
		}
					
	}
	for(c=0; c<TAM; c++)
		printf("%i ", melhor[y][c]);
	printf("= %i\n", melhor[y][TAM]);
	printf("\nTempo: %f\n\n",(clock() - tempo) / (double)CLOCKS_PER_SEC);
	return 0;
}
