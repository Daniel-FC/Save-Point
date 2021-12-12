#include <stdio.h>
#include <stdlib.h>

main(){

	int matriz[101][101], matrizB[101][3], l , c;
	int vetorA[101], vA;
	int resp, x, y, z, w, k, q, e;

	for(l=0; l<=100; l++){
	
		for(c=0; c<=100; c++){
		
			matriz[l][c]=0;
			
		}
		
	}
	do{
		
		for(x=0; x<=99; x++){
				
			for(l=0; l<=99; l++){
						
				if(matriz[l][0]>matriz[l+1][0] && matriz[l+1][0]!=0){
							
					for(c=0; c<=99; c++){
								
						y=matriz[l][c];
						matriz[l][c]=matriz[l+1][c];
						matriz[l+1][c]=y;
				
					}
							
				}
				for(c=2; c<=98; c=c+2){
										
					if(matriz[l][c]>matriz[l][c+2] && matriz[l][c+2]!=0){
													
						y=matriz[l][c];
						matriz[l][c]=matriz[l][c+2];
						matriz[l][c+2]=y;
						y=matriz[l][c-1];
						matriz[l][c-1]=matriz[l][c+1];
						matriz[l][c+1]=y;
													
					}
													
				}
								
			}
				
		}
		for(l=0; l<=100; l++){
		
			for(c=0; c<=100; c++){
			
				if(matriz[l][c]==9999){
					
					matriz[l][c]=0;
					
				}
			
			}
	
		}
		printf("Para inserir um vertice:     digite 1:\n");
		printf("Para remover um vertice:     digite 2:\n");
		printf("Para inserir uma aresta:     digite 3:\n");
		printf("Para remover uma aresta:     digite 4:\n");
		printf("Para classificar a matriz:   digite 5:\n");
		printf("Para imprimir a matriz:      digite 6:\n");
		printf("Para arvore geradora minima: digite 7:\n");	
		printf("Digite aqui: ");
		scanf("%i", &resp);
		switch(resp){

			case 1:
				y=0;
				do{

					system("cls");
					if(y==1){
						
						printf("VALOR INVALIDO\n\n");
						
					}
					printf("Atencao, apenas numeros inteiros positivos\n\n");
					printf("Nomeie o vertice inserido: ");
					scanf("%i", &x);
					y=1;
				
				}while(x<1);
				system("cls");
				for(l=0, c=0, y=0, z=0; l<=100; l++){
					
					if(matriz[l][c]==x){
						
						printf("VERTICE JA EXISTE\n\n");
						z++;
						
					}
					else{
						
						if(matriz[l][c]==0 && y==0 && z==0){
							
							printf("VERTICE INSERIDO\n\n");
							matriz[l][c]=x;
							y++;
							
						}
						
					}	
					
				}
				break;
				
			case 2:
				system("cls");
				if(matriz[0][0]==0){
					
					printf("NAO HA NENHUM VERTICE\n\n");
					
				}
				else{
					
					printf("Qual o nome do vertice a ser removida? ");
					scanf("%i", &x);
					system("cls");
					for(l=0, y=0; l<=100; l++){
					
						if(matriz[l][0]==x){
							
							for(c=0; c<=100; c++){
							
								matriz[l][c]=9999;
				
							}
							printf("VERTICE REMOVIDO\n\n");
							y++;
							
						}	
						
					}
					for(l=0; l<=100; l++){
					
						for(c=2; c<=100; c=c+2){
							
							if(matriz[l][c]==x){
								
								matriz[l][c]=9999;
								matriz[l][c-1]=9999;
								
							}
						
						}
					
					}
					if(y==0){
						
						printf("VERTICE NAO EXISTE\n\n");
						
					}
						
				}
				break;
				
			case 3:
				system("cls");
				if(matriz[0][0]==0){
					
					printf("NAO HA NENHUM VERTICE\n\n");
				}
				else{
					
					printf("Qual o vertice de partida? ");	
					scanf("%i", &x);
					printf("Qual o vertice de chegada? ");
					scanf("%i", &y);
					for(l=0, z=0; l<=100; l++){
						
						if(matriz[l][0]==x){
							
							w=l;
							z++;
							
						}
						if(matriz[l][0]==y){
							
							k=l;
							z++;
							
						}
						
					}
					if(z<2){
						
						system("cls");
						printf("VERTICE NAO EXISTE\n\n");
						
					}
					else{
						
						y=0;
						do{
							
							system("cls");
							if(y==1){
										
								printf("VALOR INVALIDO\n\n");
										
							}
							printf("Atencao, apenas numeros inteiros positivos\n\n");
							printf("Qual o peso da aresta? ");
							scanf("%i", &z);
							y=1;
							
						}while(z<1);
						system("cls");
						printf("ARESTA INSERIDA\n\n");
						for(c=1, x=0, y=0; c<=100; c++){
							
							if(matriz[w][c]==0 && x==0){
								
								matriz[w][c]=z*(-1);
								matriz[w][c+1]=matriz[k][0];
								x++;
								
							}
							if(matriz[k][c]==0 && y==0 && w!=k){
								
								matriz[k][c]=z*(-1);
								matriz[k][c+1]=matriz[w][0];
								y++;
								
							}
				
						}
				
					}
					
				}
				break;
				
			case 4:
				system("cls");
				if(matriz[0][0]==0){
									
					printf("NAO HA NENHUM VERTICE\n\n");
				
				}
				else{
				
					printf("Informe o primeiro vertice: ");
					scanf("%i", &x);
					printf("Informe o segundo vertice: ");
					scanf("%i", &y);
					for(l=0, z=0; l<=100; l++){
										
						if(matriz[l][0]==x){
											
							w=l;
							z++;
											
						}
						if(matriz[l][0]==y){
											
							k=l;
							z++;
											
						}
										
					}
					if(z<2){
					
						system("cls");
						printf("VERTICE NAO EXISTE\n\n");
					
					}
					else{
						
						printf("Informe o peso da aresta a ser removida: ");
						scanf("%i", &z);
						system("cls");
						for(c=2, q=0, e=0; c<=98; c=c+2){
						
							if(matriz[w][c]==y && matriz[w][c-1]==z*(-1) && q==0){
								
								printf("ARESTA REMOVIDA\n\n");
								matriz[w][c]=9999;
								matriz[w][c-1]=9999;
								q++;
								
							}
							if(matriz[k][c]==x && matriz[k][c-1]==z*(-1) && e==0 && w!=k){
								
								matriz[k][c]=9999;
								matriz[k][c-1]=9999;
								e++;
								
							}
				
						}
						if(q==0){
							
							printf("ARESTA NAO EXISTE\n\n");
							
						}
						
					}
				
				}
				break;
				
			case 5:
				system("cls");
				if(matriz[0][0]==0){
									
					printf("NAO HA NENHUM VERTICE\n\n");
									
				}
				else{
					
					for(l=0; l<=100; l++){
				
						vetorA[l]=0;
				
					}
					for(l=0, vA=0; l<=100; l++){
				
						if(matriz[l][0]!=0){
							
							vetorA[vA]=matriz[l][0];
							vA++;
				
						}
				
					}
					for(l=0, w=0; l<=100; l++){
						
						for(x=0, y=0; x<vA; x++){
							
							z=0;
							for(c=2; c<=100; c++){
								
								if(vetorA[x]==matriz[l][c] && z==0 && vetorA[x]!=matriz[l][0]){
									
									y++;
											
								}
					
							}
				
						}
						if(y>=vA-1){
							
							w++;
							
						}
					
					}
					if(w>=vA-1){
						
						printf("E um grafo completo\n");
						
					}
					else{
						
						printf("Nao e um grafo completo\n");
						
					}
					for(l=0, x=0; l<=100; l++){

						for(c=2; c<=100; c=c+2){
						
							if(matriz[l][c]==matriz[l][c+2] && matriz[l][c]!=matriz[l][0] && matriz[l][c]!=0){
						
								x++;
						
							}
							
						}
					
					}
					if(x==0){
						
						printf("Nao e um multigrafo\n\n");
						
					}
					else{
						
						printf("E um multigrafo\n\n");
						
					}
				
				}
				break;
				
			case 6:
				system("cls");
				for(l=0; l<=100; l++){ 
					
					for(c=0, y=0; c<=100; c++){
					
						if(matriz[l][c]!=0){
							
							if(matriz[l][c]<0 && matriz[l][c]>-10){
							
								printf("*%i->    ", matriz[l][c]*(-1));
							
							}
							if(matriz[l][c]<=-10 && matriz[l][c]>-100){
							
								printf("*%i->   ", matriz[l][c]*(-1));
							
							}
							if(matriz[l][c]<=-100 && matriz[l][c]>-1000){
							
								printf("*%i->  ", matriz[l][c]*(-1));
							
							}
							if(matriz[l][c]<=-1000){
							
								printf("*%i-> ", matriz[l][c]*(-1));
							
							}
							if(matriz[l][c]>0 && matriz[l][c]<10){
							
								printf("%i    ", matriz[l][c]);
							
							}
							if(matriz[l][c]>=10 && matriz[l][c]<100){
							
								printf("%i   ", matriz[l][c]);
								
							}
							if(matriz[l][c]>=100 && matriz[l][c]<1000){
							
								printf("%i  ", matriz[l][c]);
								
							}
							if(matriz[l][c]>=1000){
							
								printf("%i ", matriz[l][c]);
								
							}
							y++;
						
						}
						
					} 
					
					if(y!=0){
					
						printf("\n");
						
					}
					
				}
				printf("\n\n");
				break;
				
			case 7:
				system("cls");
				if(matriz[0][0]==0){
									
					printf("NAO HA NENHUM VERTICE\n\n");
									
				}
				else{
				                  
					for(l=0, x=0; l<=100; l++){
				                             
						for(c=0; c<=2; c++){ 
				                               
							matrizB[l][c]=0;
							matrizB[l][0]=matriz[l][0];
							if(matriz[l][1]==0 && matriz[l][0]!=0){
								
								x++; 
				                                               
				        	}
				                           
				    	}     
				   
				    }
				    if(x!=0){
				                        
				        printf("NAO EXISTE ARVORE GERADORA MINIMA\n\n");     
				                    
				    }
				    else{
				                         
				        for(l=0; l<=100; l++){
				                                 
							for(c=1, x=-9999999; c<=100; c=c+2){
				                                     
				                if(matriz[l][c]>x && matriz[l][c]!=0){
				                                    
				                    x=matriz[l][c];
				                    z=c;
				                                                    
				                }
				      
				        	}
				            matrizB[l][1]=matriz[l][z]; 
							matrizB[l][2]=matriz[l][z+1];    
				        
				        }
				        for(l=0; l<=100; l++){
						
							for(x=0; x<=100; x++){
							
								if(matrizB[l][1]==matrizB[x][1] && matrizB[l][0]==matrizB[x][2] && matrizB[l][2]==matrizB[x][0]){
									
									matrizB[x][1]=0;
	
								}
	
							}

						}
				        for(l=0, x=0; l<=100; l++){
				        
							x=x+matrizB[l][1];              
							if(matrizB[l][1]!=0){
				                          
				                printf("       +%i\n", matrizB[l][1]*(-1));
				                                           
				            }

				        }
				        printf("Total: %i\n\n", x*(-1));
				                            
				    }
				                   
				}
				break;
				
			default:
				system("cls");
				printf("VALOR INVALIDO\n\n");
				resp=10;
				break;
				
		}
		
	}while(resp>0);

}
