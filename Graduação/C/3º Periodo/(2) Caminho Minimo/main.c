#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	
	int matriz[50][250], caminho[51][51], l, c;
	int resp, v1, v2;
	int x, y, z, l1, confirmador;
	
	for(l=0; l<50; l++){
		
		for(c=0; c<250; c++){
			
			matriz[l][c]=0;
		
		}
	
	}
	
	//Nome V         Peso V                   Peso A                Nome V          Peso V                   Peso A                Nome V           Peso V                   Peso A                Nome V           Peso V
	matriz[0][0]= 1; matriz[0][1]=11*(-1000); matriz[0][2]=87*(-1); matriz[0][3]=2; matriz[0][4]=40*(-1000);
	matriz[1][0]= 2; matriz[1][1]=40*(-1000); matriz[1][2]=68*(-1); matriz[1][3]=3; matriz[1][4]=86*(-1000); matriz[1][5]=16*(-1); matriz[1][6]= 4; matriz[1][7]=25*(-1000);
	matriz[2][0]= 3; matriz[2][1]=86*(-1000); matriz[2][2]=52*(-1); matriz[2][3]=6; matriz[2][4]= 6*(-1000); 
	matriz[3][0]= 4; matriz[3][1]=25*(-1000); matriz[3][2]=87*(-1); matriz[3][3]=1; matriz[3][4]=11*(-1000); matriz[3][5]= 6*(-1); matriz[3][6]= 6; matriz[3][7]= 6*(-1000); matriz[3][8]=11*(-1); matriz[3][9]=10; matriz[3][10]=78*(-1000);
	matriz[4][0]= 5; matriz[4][1]=39*(-1000); matriz[4][2]=49*(-1); matriz[4][3]=3; matriz[4][4]=86*(-1000);
	matriz[5][0]= 6; matriz[5][1]= 6*(-1000); matriz[5][2]= 6*(-1); matriz[5][3]=3; matriz[5][4]=86*(-1000); matriz[5][5]= 6*(-1); matriz[5][6]= 9; matriz[5][7]=94*(-1000);
	matriz[6][0]= 7; matriz[6][1]=64*(-1000); matriz[6][2]= 1*(-1); matriz[6][3]=5; matriz[6][4]=39*(-1000); matriz[6][5]=93*(-1); matriz[6][6]= 6; matriz[6][7]= 6*(-1000); matriz[6][8]= 3*(-1); matriz[6][9]= 8; matriz[6][10]=58*(-1000);
	matriz[7][0]= 8; matriz[7][1]=58*(-1000); matriz[7][2]=11*(-1); matriz[7][3]=9; matriz[7][4]=94*(-1000);
	matriz[8][0]= 9; matriz[8][1]=94*(-1000); matriz[8][2]=20*(-1); matriz[8][3]=7; matriz[8][4]=64*(-1000);
	matriz[9][0]=10; matriz[9][1]=78*(-1000); matriz[9][2]=68*(-1); matriz[9][3]=6; matriz[9][4]= 6*(-1000); matriz[9][5]= 4*(-1); matriz[9][6]=9; matriz[9][7]=94*(-1000);
	
	do{
		
		printf("1) Obter o caminho minimo\n");
		printf("2) Imprimir representação do grafo\n");
		printf("\nInforme sua resposta: ");
		scanf("%i", &resp);
		
		switch(resp){
		
			case 1:
				//Caminho minimo
				system("cls");
				printf("Informe o vertice de partida: ");
				scanf("%i", &v1);
				printf("Informe o vertice de chegada: ");
				scanf("%i", &v2);
				for(l=0, x=0, y=0; l<50; l++){
					
					//Armazém de coordenadas
					if(matriz[l][0]==v1){
						
						l1=l; 
						x++;
					
					}
					if(matriz[l][0]==v2){
						
						x++;
					
					}
					if(matriz[l][0]!=0){
						
						y++;
						
					}
				
				}
				if(x<2){
					
					printf("Valor inválido\n\n");
				
				}
				else{
					
					//Atribuição de simbolos
					for(l=0; l<51; l++){
						
						for(c=0; c<51; c++){
							
							caminho[l][c]=-1; 
							caminho[l1+1][c]=-2;
						
						}
					
					}
					caminho[0][0]=-3;
					caminho[0][1]=-4;
					
					//Estabilização da matriz
					for(l=0; l<50; l++){
						
						caminho[l+1][0]=matriz[l][0];
					
					}
					for(c=2, x=1; c<y+2; c++, x++){
						
						caminho[0][c]=x;
					
					}	
				
					//Atribuição de valores
					for(c=3; c<250; c=c+3){
							
						if(matriz[l1][c]!=0){
							
							caminho[matriz[l1][c]][1]=(matriz[l1][1]/-1000)+(matriz[l1][c-1]/-1)+(matriz[l1][c+1]/-1000);
							caminho[matriz[l1][c]][2]=caminho[matriz[l1][c]][1];
								
						}
						
					}
					for(z=2; z<y+1; z++){
					
						for(l=1, confirmador=999999; l<51; l++){
							
							if(caminho[l][z]>0){
								
								caminho[l][z+1]=caminho[l][z];
								for(c=3; c<250; c=c+3){
								
									for(x=1; x<51; x++){
										
										if(caminho[x][0]==matriz[l-1][c]){
											
											if(caminho[x][z]>caminho[l][z]+(matriz[l-1][c-1]/-1)+(matriz[l-1][c+1]/-1000) || caminho[x][z]==-1){
												
												if(caminho[x][z+1]!=-1){
													
													confirmador=caminho[x][z+1];
													
												}
												caminho[x][z+1]=caminho[l][z]+(matriz[l-1][c-1]/-1)+(matriz[l-1][c+1]/-1000);
												if(confirmador<caminho[x][z+1]){
													
													caminho[x][z+1]=confirmador;
													
												}
												
											}
											
										}	
										
									}
								
								}
									
							}
								
						}
					
					}

					//Imprimir
					system("cls");
					for(l=0; l<y+1; l++){
									
						for(c=0, x=0; c<y+1; c++){
										
							if(caminho[l][c]!=0){
								
								//Valores
								if(caminho[l][c]>=0 && caminho[l][c]<10){
									
									printf("    %i", caminho[l][c]);
								
								}
								if(caminho[l][c]>=10 && caminho[l][c]<100){
									
									printf("   %i", caminho[l][c]);
								
								}
								if(caminho[l][c]>=100 && caminho[l][c]<1000){
									
									printf("  %i", caminho[l][c]);
								
								}
								if(caminho[l][c]>=1000){
									
									printf(" %i", caminho[l][c]);
								
								}
								
								//Simbolos
								if(caminho[l][c]==-1){
									
									printf("  ###", caminho[l][c]); x++;
								
								}
								if(caminho[l][c]==-2){
									
									printf("    0", caminho[l][c]); 
								
								}
								if(caminho[l][c]==-3){
									
									printf("   --", caminho[l][c]); 

								}
								if(caminho[l][c]==-4){
									
									printf("  INI", caminho[l][c]); 
								
								}
								x++;
								
							}
								
						}			
						if(x!=0){
							
							printf("\n");
						
						}
							
					}
						
				}
				if(caminho[v2][y]==-2){
					
					printf("\n\n   O menor caminho de %i a %i é: 0", v1, v2);
				
				}
				else{
				
					if(caminho[v2][y]>0){
						
						printf("\n\n   O menor caminho de %i a %i é: %i", v1, v2, caminho[v2][y]);
					
					}
					if(caminho[v2][y]<0){
						
						printf("\n\n   O menor caminho de %i a %i é: ###", v1, v2);
					
					}
					
				}
				resp=0;
				break;
				
			case 2:
				//Imprimir
				system("cls");
				for(l=0; l<50; l++){
					
					for(c=0, x=0; c<250; c++){
						
						if(matriz[l][c]!=0){
							
							//Nome V
							if(matriz[l][c]>0 && matriz[l][c]<10){
								
								printf("    %i", matriz[l][c]);
							
							}
							if(matriz[l][c]>=10 && matriz[l][c]<100){
								
								printf("   %i", matriz[l][c]);
							
							}
							if(matriz[l][c]>=100 && matriz[l][c]<1000){
								
								printf("  %i", matriz[l][c]);
							
							}
							if(matriz[l][c]>=1000){
								
								printf(" %i", matriz[l][c]);
							
							}
							
							//Peso V
							if(matriz[l][c]<=-1000 && matriz[l][c]>-10000){
								
								printf("  *%i", matriz[l][c]/-1000);
							
							}
							if(matriz[l][c]<=-10000 && matriz[l][c]>-100000){
								
								printf(" *%i", matriz[l][c]/-1000);
							
							}
							
							//Peso A
							if(matriz[l][c]<0 && matriz[l][c]>-10){
								
								printf("    -0%i->", matriz[l][c]*(-1));
							
							}
							if(matriz[l][c]<=-10 && matriz[l][c]>-100){
								
								printf("    -%i->", matriz[l][c]*(-1));
							
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
