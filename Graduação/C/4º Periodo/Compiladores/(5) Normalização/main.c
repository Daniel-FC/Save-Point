#include <stdio.h>
#include <string.h>

#define tam 100

struct armazem{
	
	char string[tam];
	char caminho[1];
	
};

main(){
	
	FILE *p_cod;
	int x, y, w, z, e, f, l, c, qtdL, cont=0, resp, excluir[tam], comp[3];
	char aux[tam], aux2[tam], inicial[1];
	struct armazem A[tam][2], B[tam];
	
	for(l=0; l<tam; l++){for(c=0; c<2; c++){for(x=0; x<tam; x++){A[l][c].string[x]=0;B[l].caminho[0]=0;excluir[l]=0;}}}
	//Leitura do txt
	p_cod=fopen("Codigo.txt", "r");
	for(x=0; fgets(aux, tam, p_cod)!=NULL; cont++){
		
		if(cont==0)
			inicial[0]=aux[9];
			
		else{

			for(l=0, c=3; aux[c+1]!='\0'; c++){
				
				if(aux[c]=='|'){
					
					x++;
					l=0;
					
				}
				else{
					
					A[x][0].string[0]=aux[0];
					A[x][1].string[l]=aux[c];
					l++;
					
				}
				qtdL=x+1;
	
			}
			x++;
		
		}	

	}
	
	printf("Selecione uma opcao:\n");
	printf("Para remover producoes inuteis digite: 1\n");
	printf("Para remover producoes unitarias digite: 2\n");
	printf("Para remover lambdas producoes digite: 3\n");
	printf("Para remover esquerda recursoes digite: 4\n");
	printf("Para normalizar digite: 5\n");
	printf("\nresposta: ");
	scanf("%i", &resp);
	system("cls");
	
	//Reptição de sentença
	for(l=0; l<qtdL; l++){
			
		for(c=0; c<tam; c++){
			
			if(l!=c){
				
				y=strncmp(A[l][0].string, A[c][0].string, tam);
				x=strncmp(A[l][1].string, A[c][1].string, tam);	
				if(x==0 && y==0){
					
					for(w=0; w<tam; w++){
							
						A[c][0].string[w]=0;
						A[c][1].string[w]=0;
						excluir[c]=1;
					
					}

				}			
				
			}
			
		}

	}	
	//Produção inutel
	if(resp==1 || resp==5){
		
		B[0].caminho[0]=inicial[0];
		for(w=0, y=1; w<10; w++){
			
			for(l=0; l<qtdL; l++){
				
				x=strncmp(A[l][0].string, B[w].caminho, 1);
				if(excluir[l]!=1 && x==0){
				
					for(c=0; c<tam; c++){
						
						if(A[l][1].string[c]=='S' || A[l][1].string[c]=='A' || A[l][1].string[c]=='B' || A[l][1].string[c]=='C' || A[l][1].string[c]=='D' || A[l][1].string[c]=='E'){
								
							B[y].caminho[0]=A[l][1].string[c];
							y++;
								
						}
						
					}
					
				}
		
			}		
		
		}
		for(l=0; l<tam; l++){
			
			for(c=0, y=0; c<tam; c++){
				
				x=strncmp(A[l][0].string, B[c].caminho, 1);
				if(x==0)
					y=1;
				
			}
			if(y==0)
				excluir[l]=1;
			
		}
		for(l=0; l<qtdL; l++){B[l].caminho[0]=0;}
		for(l=0, y=0; l<qtdL; l++){
		
			for(c=0; c<qtdL; c++){
			
				x=strncmp(A[l][0].string, A[c][0].string, 1);
				if(l!=c && x==0){
					
					B[y].caminho[0]=A[l][0].string[0];
					y++;
					
				}

			}

		}
		for(l=0; l<y; l++){
		
			for(c=0, w=0; c<y; c++){
			
				x=strncmp(A[l][0].string, B[c].caminho, 1);
				if(x==0)
					w=1;
			
			}
			if(w==0){
				
				if(A[l][0].string[0]=='S'){comp[0]=0;}if(A[l][0].string[0]=='A'){comp[0]=1;}if(A[l][0].string[0]=='B'){comp[0]=2;}if(A[l][0].string[0]=='C'){comp[0]=3;}if(A[l][0].string[0]=='D'){comp[0]=4;}if(A[l][0].string[0]=='E'){comp[0]=5;}
				
				for(w=0, x=0; w<tam; w++){
				
					if(A[l][1].string[w]=='a' || A[l][1].string[w]=='b' || A[l][1].string[w]=='c' || A[l][1].string[w]=='d' || A[l][1].string[w]=='e' || A[l][1].string[w]=='#'){comp[1]=-1;}
					if(A[l][1].string[w]=='S'){comp[1]=0;}if(A[l][1].string[w]=='A'){comp[1]=1;}if(A[l][1].string[w]=='B'){comp[1]=2;}if(A[l][1].string[w]=='C'){comp[1]=3;}if(A[l][1].string[w]=='D'){comp[1]=4;}if(A[l][1].string[w]=='E'){comp[1]=5;}
					
					if(comp[0]==comp[1] && x==0)
						x=1;
					if(comp[1]>0 && comp[0]!=comp[1])
						x=2;	
				
				}
				if(x==1){
					
					x=strncmp(A[l][0].string, inicial, 1);
					if(x!=0){
						
						excluir[l]=1;
						for(x=0; x<tam; x++){
						
							for(w=0; w<tam; w++){
						
								if(A[x][1].string[w]=='a' || A[x][1].string[w]=='b' || A[x][1].string[w]=='c' || A[x][1].string[w]=='d' || A[x][1].string[w]=='e' || A[x][1].string[w]=='#'){comp[1]=-1;}
								if(A[x][1].string[w]=='S'){comp[1]=0;}if(A[x][1].string[w]=='A'){comp[1]=1;}if(A[x][1].string[w]=='B'){comp[1]=2;}if(A[x][1].string[w]=='C'){comp[1]=3;}if(A[x][1].string[w]=='D'){comp[1]=4;}if(A[x][1].string[w]=='E'){comp[1]=5;}
	
								if(comp[0]==comp[1])
									excluir[x]=1;
									
							}
						
						}
						
					}
					
				}
	
			}

		}

	}
	//Produção unitaria
	if(resp==2 || resp==5){
	
		for(l=0; l<qtdL; l++){B[l].caminho[0]=0;}
		for(l=0, y=0; l<qtdL; l++){
			
			if(excluir[l]!=1){
				
				for(c=0; c<qtdL; c++){
				
					x=strncmp(A[l][0].string, A[c][0].string, 1);
					if(l!=c && x==0){
						
						B[y].caminho[0]=A[l][0].string[0];
						y++;
						
					}
	
				}
			
			}

		}
		for(l=0; l<qtdL; l++){
			
			if(excluir[l]!=1){
				
				for(c=0, w=0; c<y; c++){
				
					x=strncmp(A[l][0].string, B[c].caminho, 1);
					if(x==0)
						w=1;
				
				}
				if(w==0){
					
					x=strncmp(A[l][0].string, inicial, 1);
					if(x!=0){
						
						excluir[l]=1;
						strcpy(aux, A[l][1].string);
						
						if(A[l][0].string[0]=='S'){comp[0]=0;}if(A[l][0].string[0]=='A'){comp[0]=1;}if(A[l][0].string[0]=='B'){comp[0]=2;}if(A[l][0].string[0]=='C'){comp[0]=3;}if(A[l][0].string[0]=='D'){comp[0]=4;}if(A[l][0].string[0]=='E'){comp[0]=5;}
						for(x=0; x<qtdL; x++){
						
							if(excluir[x]!=1){
								
								for(e=0; e<tam; e++){aux2[e]=0;}
								for(w=0, z=0; w<A[x][1].string[w]!='\0'; w++){
									
									if(A[x][1].string[w]=='S'){comp[1]=0;}if(A[x][1].string[w]=='A'){comp[1]=1;}if(A[x][1].string[w]=='B'){comp[1]=2;}if(A[x][1].string[w]=='C'){comp[1]=3;}if(A[x][1].string[w]=='D'){comp[1]=4;}
									if(A[x][1].string[w]=='a'){comp[1]=-1;}if(A[x][1].string[w]=='b'){comp[1]=-2;}if(A[x][1].string[w]=='c'){comp[1]=-3;}if(A[x][1].string[w]=='d'){comp[1]=-4;}if(A[x][1].string[w]=='e'){comp[1]=-5;}if(A[x][1].string[w]=='#'){comp[1]=-6;}
									
									if(comp[0]==comp[1]){
										
										for(f=0; f<aux[f]!='\0'; f++, z++){
											
											if(aux[f]=='S'){comp[2]=0;}if(aux[f]=='A'){comp[2]=1;}if(aux[f]=='B'){comp[2]=2;}if(aux[f]=='C'){comp[2]=3;}if(aux[f]=='D'){comp[2]=4;}if(aux[f]=='E'){comp[2]=5;}
											if(aux[f]=='a'){comp[2]=-1;}if(aux[f]=='b'){comp[2]=-2;}if(aux[f]=='c'){comp[2]=-3;}if(aux[f]=='d'){comp[2]=-4;}if(aux[f]=='e'){comp[2]=-5;}if(aux[f]=='#'){comp[2]=-6;}
											
											if(comp[2]==0){aux2[z]='S';}if(comp[2]==1){aux2[z]='A';}if(comp[2]==2){aux2[z]='B';}if(comp[2]==3){aux2[z]='C';}if(comp[2]==4){aux2[z]='D';}if(comp[2]==5){aux2[z]='E';}
											if(comp[2]==-1){aux2[z]='a';}if(comp[2]==-2){aux2[z]='b';}if(comp[2]==-3){aux2[z]='c';}if(comp[2]==-4){aux2[z]='d';}if(comp[2]==-5){aux2[z]='e';}if(comp[2]==-6){aux2[z]='#';}
											
										}
										
									}
									else{
										
										aux2[z]=A[x][1].string[w];
										z++;
											
									}
		
								}
								strcpy(A[x][1].string, aux2);
							
							}
	
						}						
						
					}
					
				}
				
			}
			
		}

	}
	//Lambda produção
	if(resp==3 || resp==5){
	
		for(l=0; l<tam; l++){aux[l]=0;}
		aux[0]='#';
		for(l=0; l<tam; l++){
			
			if(excluir[l]!=1){
					
				x=strncmp(A[l][1].string, aux, 1);
				if(x==0){
						
					if(A[l][0].string[0]=='S'){comp[0]=0;}if(A[l][0].string[0]=='A'){comp[0]=1;}if(A[l][0].string[0]=='B'){comp[0]=2;}if(A[l][0].string[0]=='C'){comp[0]=3;}if(A[l][0].string[0]=='D'){comp[0]=4;}if(A[l][0].string[0]=='E'){comp[0]=5;}
					excluir[l]=1;
						
					for(c=0, y=qtdL; c<y; c++){
						
						for(w=0; w<tam; w++){aux2[w]=0;}
						for(w=0, z=0, e=0; A[c][1].string[w]!='\0'; w++){
							
							if(A[c][1].string[w]=='S'){comp[1]=0;}if(A[c][1].string[w]=='A'){comp[1]=1;}if(A[c][1].string[w]=='B'){comp[1]=2;}if(A[c][1].string[w]=='C'){comp[1]=3;}if(A[c][1].string[w]=='D'){comp[1]=4;}if(A[c][1].string[w]=='E'){comp[1]=5;}
							if(A[c][1].string[w]=='a'){comp[1]=-1;}if(A[c][1].string[w]=='b'){comp[1]=-2;}if(A[c][1].string[w]=='c'){comp[1]=-3;}if(A[c][1].string[w]=='d'){comp[1]=-4;}if(A[c][1].string[w]=='e'){comp[1]=-5;}if(A[c][1].string[w]=='#'){comp[1]=-6;}
							
							if(comp[0]!=comp[1]){
								
								if(comp[1]==0){aux2[z]='S';}if(comp[1]==1){aux2[z]='A';}if(comp[1]==2){aux2[z]='B';}if(comp[1]==3){aux2[z]='C';}if(comp[1]==4){aux2[z]='D';}if(comp[1]==5){aux2[z]='E';}
								if(comp[1]==-1){aux2[z]='a';}if(comp[1]==-2){aux2[z]='b';}if(comp[1]==-3){aux2[z]='c';}if(comp[1]==-4){aux2[z]='d';}if(comp[1]==-5){aux2[z]='e';}if(comp[1]==-6){aux2[z]='#';}
								z++;
								
							}							
							if(comp[0]==comp[1]){
							
								if(A[c][0].string[0]=='S'){comp[2]=0;}if(A[c][0].string[0]=='A'){comp[2]=1;}if(A[c][0].string[0]=='B'){comp[2]=2;}if(A[c][0].string[0]=='C'){comp[2]=3;}if(A[c][0].string[0]=='D'){comp[2]=4;}if(A[c][0].string[0]=='E'){comp[2]=5;}
								if(comp[2]==0){A[qtdL][0].string[0]='S';}if(comp[2]==1){A[qtdL][0].string[0]='A';}if(comp[2]==2){A[qtdL][0].string[0]='B';}if(comp[2]==3){A[qtdL][0].string[0]='C';}if(comp[2]==4){A[qtdL][0].string[0]='D';}if(comp[2]==5){A[qtdL][0].string[0]='E';}
								e=1;
								qtdL++;	
														
							}
	
						}
						if(e==1){
							
							strcpy(A[qtdL-1][1].string, aux2);
							if(aux2[0]=='\0')
								qtdL--;
							
						}
						
					}

				}				
			
			}

		}

	}
	//Esquerda recursão
	if(resp==4 || resp==5){

		e=qtdL;
		for(l=0, f=0; l<e; l++){
			
			if(excluir[l]!=1){
			
				if(A[l][1].string[0]=='S' || A[l][1].string[0]=='A' || A[l][1].string[0]=='B' || A[l][1].string[0]=='C' || A[l][1].string[0]=='D' || A[l][1].string[0]=='E'){
					
					for(c=0; c<tam; c++){aux[c]=0;}
					if(f==0){aux[0]='X';}if(f==1){aux[0]='Y';}if(f==2){aux[0]='K';}if(f==3){aux[0]='W';}if(f==4){aux[0]='Z';}
					f++;
					
					for(c=0; c<e; c++){
						
						y=0;
						x=strncmp(A[c][0].string, A[l][0].string, 1);
						if(x==0 && l!=c){
							
							for(x=0; x<tam; x++){aux2[x]=0;}
							y=1;
							for(x=0; A[c][1].string[x]!='\0'; x++){
							
								aux2[x]=A[c][1].string[x];
							
							}
							
						}
						if(x==0 && l==c){
							
							for(x=0; x<tam; x++){aux2[x]=0;}
							for(x=0; A[c][1].string[x+1]!='\0'; x++){
							
								aux2[x]=A[c][1].string[x+1];
							
							}
							
							strcpy(A[qtdL][0].string, aux);
							strcpy(A[qtdL][1].string, aux2);
							qtdL++;
							aux2[x]=aux[0];
							strcpy(A[qtdL][0].string, aux);
							strcpy(A[qtdL][1].string, aux2);
							qtdL++;					
						
						}
						if(y==1){
							
							aux2[x]=aux[0];
							strcpy(A[qtdL][0].string, A[c][0].string);
							strcpy(A[qtdL][1].string, aux2);
							qtdL++;
							
						}
							
					
					}
					
				}
				
			}
	
		}

	}
	//Tabela de print
	for(y=0; y<=10; y++){
		
		for(l=0, x=0; l<qtdL; l++){
			
			if(excluir[l]!=1){
			
				if(A[l][0].string[0]=='S' && x==0 && y==0){printf("%s: ", A[l][0].string, A[l][1].string); x++;}
				if(A[l][0].string[0]=='S' && x!=0 && y==0){printf("%s|", A[l][1].string);}
				if(A[l][0].string[0]=='A' && x==0 && y==1){printf("%s: ", A[l][0].string, A[l][1].string); x++;}
				if(A[l][0].string[0]=='A' && x!=0 && y==1){printf("%s|", A[l][1].string);}
				if(A[l][0].string[0]=='B' && x==0 && y==2){printf("%s: ", A[l][0].string, A[l][1].string); x++;}
				if(A[l][0].string[0]=='B' && x!=0 && y==2){printf("%s|", A[l][1].string);}
				if(A[l][0].string[0]=='C' && x==0 && y==3){printf("%s: ", A[l][0].string, A[l][1].string); x++;}
				if(A[l][0].string[0]=='C' && x!=0 && y==3){printf("%s|", A[l][1].string);}		
				if(A[l][0].string[0]=='D' && x==0 && y==4){printf("%s: ", A[l][0].string, A[l][1].string); x++;}
				if(A[l][0].string[0]=='D' && x!=0 && y==4){printf("%s|", A[l][1].string);}		
				if(A[l][0].string[0]=='E' && x==0 && y==5){printf("%s: ", A[l][0].string, A[l][1].string); x++;}
				if(A[l][0].string[0]=='E' && x!=0 && y==5){printf("%s|", A[l][1].string);}			
				if(A[l][0].string[0]=='X' && x==0 && y==6){printf("%s: ", A[l][0].string, A[l][1].string); x++;}
				if(A[l][0].string[0]=='X' && x!=0 && y==6){printf("%s|", A[l][1].string);}			
				if(A[l][0].string[0]=='Y' && x==0 && y==7){printf("%s: ", A[l][0].string, A[l][1].string); x++;}
				if(A[l][0].string[0]=='Y' && x!=0 && y==7){printf("%s|", A[l][1].string);}			
				if(A[l][0].string[0]=='K' && x==0 && y==8){printf("%s: ", A[l][0].string, A[l][1].string); x++;}
				if(A[l][0].string[0]=='K' && x!=0 && y==8){printf("%s|", A[l][1].string);}		
				if(A[l][0].string[0]=='W' && x==0 && y==9){printf("%s: ", A[l][0].string, A[l][1].string); x++;}
				if(A[l][0].string[0]=='W' && x!=0 && y==9){printf("%s|", A[l][1].string);}
				if(A[l][0].string[0]=='Z' && x==0 && y==10){printf("%s: ", A[l][0].string, A[l][1].string); x++;}
				if(A[l][0].string[0]=='Z' && x!=0 && y==10){printf("%s|", A[l][1].string);}
			
			}
				
		}
		if(x>0)
			printf("\n");		
			
	}
		
}
