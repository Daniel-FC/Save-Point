#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	
	int matriz[50][100], cor[50][51], l, c;
	int resp, elem;
	int x, y, z, t1, t2, t3;
	
	for(l=0; l<50; l++){
		
		for(c=0; c<100; c++){
			
			matriz[l][c]=0;
			
		}
	
	}
	
	//Lembrar: Enumerar partir do vértice de maior grau
	//Nome            //Ligação 1      //Ligação 2      //Ligação 3      //Ligação 4 
	matriz[0][0]= 1;  matriz[0][1]=2;  matriz[0][2]= 5; matriz[0][3]=10; matriz[0][4]=12;
	matriz[1][0]= 2;  matriz[1][1]=1;  matriz[1][2]= 3; matriz[1][3]= 6; matriz[1][3]=11;
	matriz[2][0]= 3;  matriz[2][1]=2;
	matriz[3][0]= 4;  matriz[3][1]=5;
	matriz[4][0]= 5;  matriz[4][1]=1;  matriz[4][2]= 4; matriz[4][3]= 6; matriz[4][4]= 8;
	matriz[5][0]= 6;  matriz[5][1]=2;  matriz[5][2]= 5; matriz[5][3]= 7; matriz[5][4]= 9;
	matriz[6][0]= 7;  matriz[6][1]=6;
	matriz[7][0]= 8;  matriz[7][1]=5;
	matriz[8][0]= 9;  matriz[8][1]=6;
	matriz[9][0]=10;  matriz[9][1]=1;
	matriz[10][0]=11; matriz[10][1]=2;
	matriz[11][0]=12; matriz[12][1]=1;

	do{
		
		printf("1) Obter coloração\n");
		printf("2) Imprimir representação do grafo\n");
		printf("\nInforme sua resposta: ");
		scanf("%i", &resp);
		
		switch(resp){
		
			case 1:
				//Coloração
				system("cls");
				
				//Estabilização da matriz
				for(l=0; l<50; l++){
					for(c=0; c<51; c++){
						
						cor[l][c]=0;
						
					}
				
				}
				for(l=0, elem=0; l<50; l++){
					
					if(matriz[l][0]!=0){
						
						elem++;
					
					}
				
				}
				for(l=0; l<elem; l++){
					
					cor[l][0]=(l+1)*(-1);
				
				}
				
				//Atribuição de valores
				for(z=0; z<elem; z++){
				
					for(l=0, x=0; l<50; l++){
						
						for(c=0; c<51; c++){
							
							if(matriz[z][0]==cor[l][c]){
								
								x++;
							
							}
							
						}
						
					}
					if(x==0){
						
						cor[z][1]=matriz[z][0];
					
					}
					for(l=0, y=2; l<elem; l++){
						
						for(c=0, x=0; c<elem; c++){
							
							if(cor[l][0]*(-1)==matriz[z][c]){
								
								x++;
							
							}
						
						}
						for(t1=0, t3=0; t1<elem; t1++){
							
							for(t2=0; t2<elem; t2++){
								
								if(cor[l][0]*(-1)==cor[t1][t2]){
									
									t3++;
								
								}
							
							}
						
						}
						if(x==0 && t3==0){
							
							cor[z][y]=cor[l][0]*(-1);
							y++;
						}
						
					}
					for(c=2; c<elem; c++){
						
						for(x=1; x<elem; x++){
							
							for(y=1; y<elem; y++){
								
								if(matriz[cor[z][c]-1][x]==cor[z][y] && cor[z][y]!=0 && cor[z][c]!=0){
									
									cor[z][y]=0;
								
								}
							
							}
						
						}
					}
				
				}
				
				//Otimização
				for(l=1; l<elem; l++){
					
					for(x=0; x<l; x++){
							
						for(c=1, t1=0; c<elem; c++){
							
							for(y=1; y<elem; y++){
								
								for(z=1; z<elem; z++){
							
									if(cor[l][c]==matriz[cor[x][y]-1][z] && cor[l][c]!=0){
										
										t1++;
										
									}	
								
								}

							}									
			
						}
						
						if(t1==0){
								
							for(y=1; y<elem; y++){
								
								if(cor[l][y]!=0){
									
									for(z=1, t3=0; t3==0; z++){
										
										if(cor[x][z]==0){
											
											t2=cor[l][y];
											cor[l][y]=cor[x][z];
											cor[x][z]=t2;
											t3=1;
											
										}
											
									}	
										
								}
	
							}
							
						}
						
					}

				}
				
				//Imprimir
				for(l=0; l<50; l++){
					
					for(c=0, x=0; c<51; c++){
					
						if(cor[l][c]!=0){
						
							for(y=1, z=0; y<51; y++){
								
								if(cor[l][y]!=0 && z==0){
						
									//Cores
									if(cor[l][c]<0 && cor[l][c]>-10){
										
										printf("cor 0%i:", cor[l][c]*(-1));
									
									}
									if(cor[l][c]<=-10 && cor[l][c]>-100){
										
										printf("cor %i:", cor[l][c]*(-1));
									
									}
									z++;
									x++;
								
								}
							
							}
							
							//Elementos
							if(cor[l][c]>=0 && cor[l][c]<10){
								
								printf("    %i", cor[l][c]);
							
							}
							if(cor[l][c]>=10 && cor[l][c]<100){
								
								printf("   %i", cor[l][c]);
							
							}
							if(cor[l][c]>=100 && cor[l][c]<1000){
								
								printf("  %i", cor[l][c]);
							
							}
							if(cor[l][c]>=1000){
								
								printf(" %i", cor[l][c]);
								
							}
							
						}
						
					}
					if(x!=0){
						
						printf("\n");
					
					}
					
				}
				for(l=0, y=0; l<elem; l++){
					
					for(c=1, x=0; c<elem; c++){
						
						if(cor[l][c]!=0){
							
							x++;
						
						}
					}
					if(x>0){
						
						y++;
					
					}
				
				}
				printf("\n\nForam necessarias: %i cores", y);
				resp=0;
				break;
				
			case 2:
				//Imprimir
				system("cls");
				for(l=0; l<50; l++){
				
					for(c=0, x=0; c<100; c++){
					
						if(matriz[l][c]!=0){
							
							//Elementos
							if(matriz[l][c]>0 && matriz[l][c]<10){
								
								printf("    %i->", matriz[l][c]);
							
							}
							if(matriz[l][c]>=10 && matriz[l][c]<100){
								
								printf("   %i->", matriz[l][c]);
							
							}
							if(matriz[l][c]>=100 && matriz[l][c]<1000){
								
								printf("  %i->", matriz[l][c]);
							
							}
							if(matriz[l][c]>=1000){
								
								printf(" %i->", matriz[l][c]);
							
							}
							x++;
					
						}
					
					}
					if(x!=0){
						
						printf("\n");
					
					}

				}
				printf("\n\n");	
				break;
				
			default:
				system("cls");
				printf("Valor inválido\n\n");
				resp=3;
				break;

		}
		
	}while(resp>0);

}
