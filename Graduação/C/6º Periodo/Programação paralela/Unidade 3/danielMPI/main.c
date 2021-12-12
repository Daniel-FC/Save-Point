#include <mpi.h>
#include <stdio.h>
#include <time.h>

#define TAM 58 //Quantidade de nós
#define POP 50 //Tamanho da população
#define GERA 1000 //Quantidade de gerações
#define MEL 10 //Quantidade de Melhores da população
#define MELS 1 //Quantidade de Melhores da população copiados para geraçao seguinte

int main(int argc, char **argv){
	
	int size, rank;
	int l, c, x, y, comp, geracao=0;
	int matriz[TAM][TAM], popu[POP][TAM+1], melhor[MEL][TAM+1], copia[TAM+1];
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;
	srand(time(0)+rank);
	clock_t tempo = clock();;
	int comparador[size][TAM+1];
	
	//Gerar e compartilhar matriz
	if(rank==0){

		for(l=0; l<TAM; l++){

			for(c=0; c<TAM; c++)
				scanf("%i", &matriz[l][c]);
			
				
		}
		MPI_Bcast(matriz, TAM*TAM, MPI_INT, 0, MPI_COMM_WORLD);
	
	}
	if(rank!=0)
		MPI_Bcast(matriz, TAM*TAM, MPI_INT, 0, MPI_COMM_WORLD);

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
	for(l=0, comp=0, x=999999999; l<MEL; l++){

		if(x>melhor[l][TAM]){
			
			x=melhor[l][TAM];
			y=l;
			
		}
					
	}
	for(c=0; c<TAM+1; c++)
		copia[c] = melhor[y][c];

	//Receber resultado
	if(rank!=0)
		MPI_Send(copia, TAM+1, MPI_INT, 0, 0, MPI_COMM_WORLD);

	if(rank==0){
		
		for(c=0; c<TAM+1; c++)
			comparador[0][c] = copia[c];
		for(l=1; l<size; l++){
			
			MPI_Recv(copia, TAM+1, MPI_INT, l, 0, MPI_COMM_WORLD, &status);
			for(c=0; c<TAM+1; c++)
				comparador[l][c] = copia[c];
			
		}
		printf("\n\n");
		for(l=0, x=999999999; l<size; l++){
		
			printf("Melhor do %i: ", l);
			for(c=0; c<TAM; c++){
				
				printf("%i ", comparador[l][c]);
				
			}
			printf("= %i\n", comparador[l][c]);
			if(x>comparador[l][TAM]){
				
				x=comparador[l][TAM];
				y=l;
				
			}
		
		}
		printf("\n>>> ");
		for(c=0; c<TAM; c++)
			printf("%i ", comparador[y][c]);
		printf("= %i <<<\n\n", comparador[y][c]);
		printf("Tempo: %f\n\n",(clock() - tempo) / (double)CLOCKS_PER_SEC);		
	
	}

	MPI_Finalize();
	return 0;
	
}
