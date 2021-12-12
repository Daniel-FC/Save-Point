#include <stdio.h>
#include <string.h>

#define tam 500

struct armazem{

	char string[tam];
	
};

main(){
	
	FILE *p_cod, *log;
	int x, y, k, w, z, z1, z2, z3, l, c, qtdL, qtdC, erro=0, vetor[tam], vetorE[tam], matriz[tam][2], tipo[tam];
	char aux[tam], num[10], let[26], simbolos[tam];
	struct armazem A[tam];

	strcpy(num, "0123456789");
	strcpy(let, "abcdefghijklmnopqrstuvwxyz");
	
	//Zerando strings, matrizes e vetores...
	for(l=0; l<tam; l++){for(c=0; c<tam; c++){matriz[l][0]=0;simbolos[l]=0;matriz[l][1]=0;vetor[l]=0;vetorE[l]=0;tipo[l]=0;A[l].string[c]=0;}}
	//Leitura do codigo
	p_cod=fopen("[1] Codigo.txt", "r");
	for(qtdL=0, x=1, z=0; fgets(aux, tam, p_cod)!=NULL; qtdL++, x++){
	
		for(l=0, c=0, y=qtdL; aux[c+1]!='\0'; l++, c++){
			
			w=strncmp(aux, "-\n", tam);
			if(w==0){
				
				z++;
				qtdC=z;
				matriz[qtdL][0]=-1;
				
			}
			if(aux[c]==' '){
				
				l=-1;
				qtdL++;
				
			}
			if(aux[c]=='=')	{
				
				l=0;
				qtdL++;
				
			}	
			A[qtdL].string[l]=aux[c];
			vetor[qtdL]=x;
			tipo[qtdL]=z;

		}
		w=strncmp(A[y].string, "hotdog", tam);
		if(w==0)
			matriz[y][0]=28;
		w=strncmp(A[y].string, "banana", tam);
		if(w==0){
			
			matriz[y][0]=6;
			for(c=y+1; c<=qtdL; c++){
				
				matriz[c][0]=7;
				if(A[c].string[0]=='=')
					matriz[c][0]=8;

			}

		}
		w=strncmp(A[y].string, "caju", tam);
		if(w==0){
			
			matriz[y][0]=9;
			for(c=y+1; c<=qtdL; c++){
				
				matriz[c][0]=10;
				if(A[c].string[0]=='=')
					matriz[c][0]=11;

			}

		}
		w=strncmp(A[y].string, "GBbanana", tam);
		if(z==0){
			
			if(w==0){
				
				matriz[y][0]=12;
				for(c=y+1; c<=qtdL; c++){
					
					matriz[c][0]=13;
					if(A[c].string[0]=='=')
						matriz[c][0]=14;
	
				}
	
			}
			
		}
		if(z!=0 && w==0){
			
			printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Variavel global declarada em local indevido!! [%s]\n\n", vetor[l], tipo[y], A[y].string);
			erro=1;
			for(c=y; c<=qtdL; c++){
				
				vetorE[c]=1;
				matriz[c][0]=999;
			
			}
		
		}
		w=strncmp(A[y].string, "GBcaju", tam);
		if(z==0){
			
			if(w==0){
				
				matriz[y][0]=15;
				for(c=y+1; c<=qtdL; c++){
					
					matriz[c][0]=16;
					if(A[c].string[0]=='=')
						matriz[c][0]=17;
	
				}
	
			}
			
		}
		if(z!=0 && w==0){
			
			printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Variavel global declarada em local indevido!! [%s]\n\n", vetor[l], tipo[y], A[y].string);
			erro=1;
			for(c=y; c<=qtdL; c++){
				
				vetorE[c]=1;
				matriz[c][0]=999;
			
			}

		}
		
	}

	for(z=1; z<=qtdC; z++){
	
		//Comparação de ALFACE (1)
		for(l=0, c=0; l<qtdL; l++){x=strncmp(A[l].string, "alface", tam);if(x==0 && z==tipo[l]){matriz[l][0]=1;c++;}}
		for(l=0; l<qtdL; l++){if(matriz[l][0]==1  && z==tipo[l]){matriz[l][1]=c;}}
		//Comparação de BROCOLIS (2)
		for(l=0, c=0; l<qtdL; l++){x=strncmp(A[l].string, "brocolis", tam);if(x==0 && z==tipo[l]){matriz[l][0]=2;c++;}}
		for(l=0; l<qtdL; l++){if(matriz[l][0]==2  && z==tipo[l]){matriz[l][1]=c;}}
		//Comparação de COUVE (3)
		for(l=0, c=0; l<qtdL; l++){x=strncmp(A[l].string, "couve", tam);if(x==0 && z==tipo[l]){matriz[l][0]=3;c++;}}
		for(l=0; l<qtdL; l++){if(matriz[l][0]==3  && z==tipo[l]){matriz[l][1]=c;}}
		//Comparação de REPOLHO (4)
		for(l=0, c=0; l<qtdL; l++){x=strncmp(A[l].string, "repolho", tam);if(x==0 && z==tipo[l]){matriz[l][0]=4;c++;}}
		for(l=0; l<qtdL; l++){if(matriz[l][0]==4  && z==tipo[l]){matriz[l][1]=c;}}
		//Comparação dE NOME DO ALGORITIMO (5)	
		for(l=0, y=0; l<qtdL; l++){if(z==tipo[l]){for(c=0, x=0; A[l].string[c]!='\0'; c++){if(A[l].string[0]=='"'){x=1;}}if(A[l].string[c-1]=='"' && x==1){matriz[l][0]=5;y++;}}}
		for(l=0; l<qtdL; l++){if(matriz[l][0]==5  && z==tipo[l]){matriz[l][1]=y;}}
	
	}
	
	for(l=0; l<qtdL; l++){
		
		if(matriz[l][0]==5){
			
			for(c=l+1; c<qtdL; c++){
			
				w=strncmp(A[l].string, A[c].string, tam);
				if(w==0){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("[Sintatico] Codigo Invalido: Nome de estrutura repetida!! [%s]\n\n", A[l].string);					
						
				}
			
			}
			
		}
	
	}

	for(z=1; z<=qtdC; z++){
	
		//Ausencia de palavra reservada
		for(l=0, x=0; l<qtdL; l++){if(z==tipo[l] && matriz[l][0]==1){x++;}}
		if(x==0){for(l=0; l<qtdL; l++){if(z==tipo[l] && matriz[l][0]==2){w=l;}}printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ausencia de palavra reservada alface\n\n", vetor[w], z);erro=1;}
		
		for(l=0, x=0; l<qtdL; l++){if(z==tipo[l] && matriz[l][0]==2){x++;}}
		if(x==0){for(l=0; l<qtdL; l++){if(z==tipo[l] && matriz[l][0]==3){w=l;}}printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ausencia de palavra reservada brocolis\n\n", vetor[w], z);erro=1;}		

		for(l=0, x=0; l<qtdL; l++){if(z==tipo[l] && matriz[l][0]==3){x++;}}
		if(x==0){for(l=0; l<qtdL; l++){if(z==tipo[l] && matriz[l][0]==4){w=l;}}printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ausencia de palavra reservada couve\n\n", vetor[w], z);erro=1;}

		for(l=0, x=0; l<qtdL; l++){if(z==tipo[l] && matriz[l][0]==4){x++;}}
		if(x==0){for(l=0; l<qtdL; l++){w=l;}printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ausencia de palavra reservada couve\n\n", vetor[w], z);erro=1;}	

		for(l=0, x=0; l<qtdL; l++){if(matriz[l][0]==5 && z==tipo[l]){x=1;}}
		if(x==0){for(l=0, x=0; l<qtdL; l++){if(z==tipo[l] && matriz[l][0]==1){w=l;}}printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ausencia nomeacao do codigo\n\n", vetor[w], z);erro=1;}
	
	}

	for(z=1; z<=qtdC; z++){
	
		//Repetição de palavra reservada
		for(l=0; l<qtdL; l++){
	
			if(matriz[l][1]>1 && z==tipo[l]){
				
				erro=1;
				vetorE[l]=1;
				printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Palavra reservada repetida!! [%s]\n\n", vetor[l], z, A[l].string);
				
			}
		
		}
		//Ordem das palavras reservadas
		for(l=0; l<qtdL; l++){
			
			for(c=0; c<qtdL; c++){
				
				if(matriz[l][0]==1 && (matriz[c][0]==2 || matriz[c][0]==3 || matriz[c][0]==4) && l>c && tipo[l]==tipo[c] && tipo[l]==z){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem de palavras reservadas incorreta!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);
					
				}
				if(matriz[l][0]==2 && (matriz[c][0]==3 || matriz[c][0]==4) && l>c && tipo[l]==tipo[c] && tipo[l]==z){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem de palavras reservadas incorreta!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);
									
				}				
				if(matriz[l][0]==3 && (matriz[c][0]==4) && l>c && tipo[l]==tipo[c] && tipo[l]==z){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem de palavras reservadas incorreta!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);
									
				}
							
			}		
			
		}
	
	}

	for(z=1; z<=qtdC; z++){
	
		//Erros na variavel
		for(l=0; l<qtdL; l++){
			
			if(tipo[l]==z){
		
				if(matriz[l][0]==7 || matriz[l][0]==10 || matriz[l][0]==13 || matriz[l][0]==16){
					
					for(c=0; c<10; c++){
					
						if(A[l].string[0]==num[c]){
						
							vetorE[l]=1;
							erro=1;
							printf("(%i){Estrututa: %i}[Lexico] Codigo Invalido: Nome de variavel comecando com caractere numeral!! [%s]\n\n", vetor[l], z, A[l].string);
						
						}
		
					}
					for(c=l+1; c<qtdL; c++){
					
						x=strncmp(A[l].string, A[c].string, tam);
						if(x==0 && tipo[l]==tipo[c]){
							
							if((matriz[l][0]==7 && matriz[c][0]==10) || (matriz[l][0]==10 && matriz[c][0]==7) || (matriz[l][0]==13 && matriz[c][0]==16) || (matriz[l][0]==16 && matriz[c][0]==13) || (matriz[l][0]==matriz[c][0])){
							
								vetorE[l]=1;
								vetorE[c]=1;
								erro=1;
								printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Nome de variavel declarada mais de uma vez!! [%s]\n\n", vetor[l], z, A[l].string);
							
							}
						
						}
		
					}
					x=strncmp(A[l].string, "alface", tam);
					if(x==0){erro=1;vetorE[l]=1;printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Nome de variavel usando palavra reservada!! [%s]\n\n", vetor[l], z, A[l].string);}
					x=strncmp(A[l].string, "brocolis", tam);
					if(x==0){erro=1;vetorE[l]=1;printf("(%i)[Semantico]Codigo Invalido: Nome de variavel usando palavra reservada!! [%s]\n\n", vetor[l], z, A[l].string);}
					x=strncmp(A[l].string, "couve", tam);
					if(x==0){erro=1;vetorE[l]=1;printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Nome de variavel usando palavra reservada!! [%s]\n\n", vetor[l], z, A[l].string);}
					x=strncmp(A[l].string, "repolho", tam);
					if(x==0){erro=1;vetorE[l]=1;printf("(%i)[Semantico] Codigo Invalido: Nome de variavel usando palavra reservada!! [%s]\n\n", vetor[l], z, A[l].string);}
					x=strncmp(A[l].string, "banana", tam);
					if(x==0){erro=1;vetorE[l]=1;printf("(%i){Estrututa: %i}[Semantico]Codigo Invalido: Nome de variavel usando palavra reservada!! [%s]\n\n", vetor[l], z, A[l].string);}
					x=strncmp(A[l].string, "caju", tam);
					if(x==0){erro=1;vetorE[l]=1;printf("(%i)[Semantico] Codigo Invalido: Nome de variavel usando palavra reservada!! [%s]\n\n", vetor[l], z, A[l].string);}
					x=strncmp(A[l].string, "carne", tam);
					if(x==0){erro=1;vetorE[l]=1;printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Nome de variavel usando palavra reservada!! [%s]\n\n", vetor[l], z, A[l].string);}
					x=strncmp(A[l].string, "frango", tam);
					if(x==0){erro=1;vetorE[l]=1;printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Nome de variavel usando palavra reservada!! [%s]\n\n", vetor[l], z,  A[l].string);}
					x=strncmp(A[l].string, "peixe", tam);
					if(x==0){erro=1;vetorE[l]=1;printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Nome de variavel usando palavra reservada!! [%s]\n\n", vetor[l], z, A[l].string);}
					x=strncmp(A[l].string, "coxinha", tam);
					if(x==0){erro=1;vetorE[l]=1;printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Nome de variavel usando palavra reservada!! [%s]\n\n", vetor[l], z, A[l].string);}
					x=strncmp(A[l].string, "empada", tam);
					if(x==0){erro=1;vetorE[l]=1;printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Nome de variavel usando palavra reservada!! [%s]\n\n", vetor[l], z, A[l].string);}
					x=strncmp(A[l].string, "pastel", tam);
					if(x==0){erro=1;vetorE[l]=1;printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Nome de variavel usando palavra reservada!! [%s]\n\n", vetor[l], z, A[l].string);}
					x=strncmp(A[l].string, "lasanha", tam);
					if(x==0){erro=1;vetorE[l]=1;printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Nome de variavel usando palavra reservada!! [%s]\n\n", vetor[l], z, A[l].string);}
					x=strncmp(A[l].string, "pizza", tam);
					if(x==0){erro=1;vetorE[l]=1;printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Nome de variavel usando palavra reservada!! [%s]\n\n", vetor[l], z, A[l].string);}
					x=strncmp(A[l].string, "hotdog", tam);
					if(x==0){erro=1;vetorE[l]=1;printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Nome de variavel usando palavra reservada!! [%s]\n\n", vetor[l], z, A[l].string);}
					x=strncmp(A[l].string, "de", tam);
					if(x==0){erro=1;vetorE[l]=1;printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Nome de variavel usando palavra reservada!! [%s]\n\n", vetor[l], z, A[l].string);}
					x=strncmp(A[l].string, "ate", tam);
					if(x==0){erro=1;vetorE[l]=1;printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Nome de variavel usando palavra reservada!! [%s]\n\n", vetor[l], z, A[l].string);}											
				}
				if(matriz[l][0]==8 || matriz[l][0]==14){
					
					for(w=1, y=0; A[l].string[w]!='\0'; w++){
						
						for(c=0, x=0; c<10; c++){
							
							if(A[l].string[w]==num[c])
								x=1;
							
						}
						if(x==0)
							y=1;
						
					}
					if(y==1){
						
						vetorE[l]=1;
						erro=1;
						printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Atribuicoes a variaveis tipo BANANA so recebem numeros!! [%s]\n\n", vetor[l], z, A[l].string);					
						
					}
			
				}
				if(matriz[l][0]==11 || matriz[l][0]==17){
					
					for(w=1, y=0; A[l].string[w]!='\0'; w++){
						
						for(c=0, x=0; c<26; c++){
							
							if(A[l].string[w]==let[c])
								x=1;
							
						}
						if(x==0)
							y=1;
						
					}
					if(y==1){
						
						vetorE[l]=1;
						erro=1;
						printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Atribuicoes a variaveis tipo CAJU so recebem letras!! [%s]\n\n", vetor[l], z, A[l].string);					
						
					}
			
				}
			
			}
	
		}
	
	}

	for(z=1; z<=qtdC; z++){
	
		for(l=0; l<qtdL; l++){
				
			if(tipo[l]==z){
				
				if(matriz[l][0]==6 || matriz[l][0]==9){
					
					for(c=0; c<qtdL; c++){
					
						if(((matriz[c][0]==1 && l<c) || (matriz[c][0]==2 && l>c)) && tipo[l]==tipo[c]){
							
							vetorE[l]=1;
							vetorE[c]=1;
							erro=1;
							printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem de palavras reservadas incorreta!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);					
							
						}
		
					}
			
				}
				if((matriz[l][0]==8 && matriz[l+1][0]==8) || (matriz[l][0]==11 && matriz[l+1][0]==11)){
				
					vetorE[l]=1;
					vetorE[l+1]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Atribuicoes seguidas!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[l+1].string);			
				
				}
			
			}
	
		}
	
	}
	
	for(z=1; z<=qtdC; z++){
	
		for(l=0; l<qtdL; l++){
		
			if(z==tipo[l]){
		
				w=strncmp(A[l].string, "lasanha", tam);
				if(w==0){
					
					matriz[l][0]=18;
					
				}
			
			}
			
		}
		for(l=0; l<qtdL; l++){
	
			if(z==tipo[l] && matriz[l-1][0]==18){
				
				for(c=0, x=0; A[l].string[c]!='\0'; c++){
					
					if(A[l].string[0]=='(')
						x=1;

				}
				if(A[l].string[c-1]==')' && x==1)
					matriz[l][0]=19;

			}
		
		}
		for(l=0; l<qtdL; l++){
		
			if(z==tipo[l]){
			
				if(matriz[l][0]==19){
					
					for(c=0; c<tam; c++)
						aux[c]=0;
					for(c=1, x=0; A[l].string[c+1]!='\0'; c++, x++)
						aux[x]=A[l].string[c];
					for(c=0, y=0; c<tam; c++){
						
						if((matriz[c][0]==7 || matriz[c][0]==10 || matriz[c][0]==13 || matriz[c][0]==16) && (tipo[l]==tipo[c] || tipo[c]==0)){
							
							w=strncmp(aux, A[c].string, tam);
							if(w==0)
								y++;
							
						}
							
					}
					if(y==0){
						
						printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Leitura de dados deve possuir variavel valida!! [%s]\n\n", vetor[l], z, aux);
						vetorE[l]=1;
						erro=1;	
	
					}
	
				}

			}

		}

	}
	
	for(l=0; l<qtdL; l++)
		matriz[l][1]=0;

	for(z=1; z<=qtdC; z++){
	
		for(l=0; l<qtdL; l++){
		
			if(z==tipo[l]){
		
				w=strncmp(A[l].string, "pizza", tam);
				if(w==0){
					
					matriz[l][0]=20;
					matriz[l][1]=vetor[l];
					
				}
				if(matriz[l][1]==vetor[l] && vetor[l]==vetor[l+1]){
					
					matriz[l+1][0]=21;
					matriz[l+1][1]=vetor[l];
					
				}
				
			}
			
		}
		for(l=0, y=0, z1=0, z3=0; l<qtdL; l++){
		
			if(z==tipo[l]){
		
				if(matriz[l][1]!=0 && y==0){
					
					y=l+1;
					w=strncmp(A[l+1].string, "(", tam);
					if(w!=0)
						z1=1;
					
				}	
				if(matriz[l][1]!=0 && matriz[l][1]!=matriz[l+1][1]){
					
					k=l;
					w=strncmp(A[l].string, ")", tam);
					if(w!=0)
						z1=1;
					z2=y;
					z3=1;				
					y=0;
					
				}
				if(z3==1){
					
					for(c=z2+1; c<=k-1; c++)
						matriz[c][0]=22;
					z3=0;
					
				}
				if(z1==1){
					
					z1=0;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Deve-se abrir e fechar parantese na escrita de dados!!\n\n", vetor[l], z);
					for(c=z2; c<=k; c++)
						vetorE[c]=1;
					erro=1;					
					
				}
			
			}

		}
		for(l=0; l<qtdL; l++){
		
			if(matriz[l][0]==22 && z==tipo[l]){
				
				z3=0;
				for(c=0; c<qtdL; c++){
				
					if((matriz[c][0]==7 || matriz[c][0]==13) && (tipo[l]==tipo[c] || tipo[c]==0)){
						
						w=strncmp(A[l].string, A[c].string, tam);
						if(w==0){matriz[l][0]=23;z3=1;}
							
					}
					if((matriz[c][0]==10 || matriz[c][0]==16) && (tipo[l]==tipo[c] || tipo[c]==0)){
						
						w=strncmp(A[l].string, A[c].string, tam);
						if(w==0){matriz[l][0]=24;z3=1;}
							
					}
						
				}
				for(c=0, z2=0; A[l].string[c]!='\0'; c++){
				
					for(x=0, z1=0; x<10; x++){
						
						if(A[l].string[c]==num[x]){
							
							z1=1;
							
						}
						
					}
					if(z1==0)
						z2=1;

				}
				if(z2==0){matriz[l][0]=25;z3=1;}
				for(c=0, z1=0, z2=0; A[l].string[c]!='\0'; c++){
					
					if(A[l].string[0]=='°')
						z1=1;
				
				}
				if(A[l].string[c-1]=='°')
					z2=1;
				if(z1==1 && z2==1){matriz[l][0]=26;z3=1;}
					
				w=strncmp(A[l].string, "+", tam);
				if(w==0){matriz[l][0]=27;z3=1;}
				w=strncmp(A[l].string, "-", tam);
				if(w==0){matriz[l][0]=27;z3=1;}
				w=strncmp(A[l].string, "*", tam);
				if(w==0){matriz[l][0]=27;z3=1;}
				w=strncmp(A[l].string, "/", tam);
				if(w==0){matriz[l][0]=27;z3=1;}	
	
				if(z3==0){
					
					printf("(%i){Estrututa: %i}[semantico] Codigo Invalido: Nao se enquadra nas regras de escrita de dados!! [%s]\n\n", vetor[l], z, A[l].string);
					vetorE[l]=1;
					erro=1;	
					
				}
	
			}

		}
		for(l=0; l<qtdL; l++){
		
			if(matriz[l][0]==27 && matriz[l+1][0]!=23 && matriz[l+1][0]!=25 && z==tipo[l]){
				
				printf("(%i){Estrututa: %i}[semantico] Codigo Invalido: Nao se enquadra nas regras de escrita de dados!! [%s]\n\n", vetor[l], z, A[l].string);
				vetorE[l]=1;
				erro=1;						
				
			}

		}
		
	}

	for(l=0; l<qtdL; l++)
		matriz[l][1]=0;
	
	for(z=1; z<=qtdC; z++){
		
		for(l=0; l<qtdL; l++){
			
			if(z==tipo[l]){
	
				if(matriz[l][0]==28)
					y=vetor[l];
	
				if(vetor[l]==y && matriz[l][0]!=28){
					
					matriz[l][0]=29;
					matriz[l][1]=1;
					
				}
					
				
			}

		}
		for(l=0; l<qtdL; l++){
		
			if(z==tipo[l] && matriz[l][0]==29){
					
				for(c=0, z2=0; A[l].string[c]!='\0'; c++){
				
					for(x=0, z1=0; x<10; x++){
						
						if(A[l].string[c]==num[x]){
							
							z1=1;
							
						}
						
					}
					if(z1==0)
						z2=1;

				}
				if(z2==0){matriz[l][0]=32;z3=1;}
				for(c=0, z2=0; A[l].string[c]!='\0'; c++){
				
					for(x=0, z1=0; x<26; x++){
						
						if(A[l].string[c]==let[x]){
							
							z1=1;
							
						}
						
					}
					if(z1==0)
						z2=1;

				}
				if(z2==0){matriz[l][0]=33;z3=1;}
				for(c=0; c<qtdL; c++){
				
					if((matriz[c][0]==7 || matriz[c][0]==13) && (tipo[l]==tipo[c] || tipo[c]==0)){
						
						w=strncmp(A[l].string, A[c].string, tam);
						if(w==0){matriz[l][0]=30;z3=1;}
							
					}
					if((matriz[c][0]==10 || matriz[c][0]==16) && (tipo[l]==tipo[c] || tipo[c]==0)){
						
						w=strncmp(A[l].string, A[c].string, tam);
						if(w==0){matriz[l][0]=31;z3=1;}
							
					}
						
				}
				
				w=strncmp(A[l].string, "+", tam);
				if(w==0){matriz[l][0]=34;z3=1;}
				w=strncmp(A[l].string, "-", tam);
				if(w==0){matriz[l][0]=34;z3=1;}
				w=strncmp(A[l].string, "*", tam);
				if(w==0){matriz[l][0]=34;z3=1;}
				w=strncmp(A[l].string, "/", tam);
				if(w==0){matriz[l][0]=34;z3=1;}	
				w=strncmp(A[l].string, "->", tam);
				if(w==0){matriz[l][0]=35;z3=1;}	

				if(z3==0){
					
					printf("(%i){Estrututa: %i}[semantico] Codigo Invalido: Nao se enquadra nas regras de escrita do bloco!! [%s]\n\n", vetor[l], z, A[l].string);
					vetorE[l]=1;
					erro=1;	
					
				}					
			
			}
	
		}
		for(l=0, z1=0, x=0, k=0; l<qtdL; l++){
		
			if(z==tipo[l]){
				
				if(matriz[l][1]==1 && x==0){
				
					if(matriz[l][0]==30 && matriz[l+1][0]==35 && (matriz[l+2][0]==30 || matriz[l+2][0]==32)){z1=1;}
					if(matriz[l][0]==31 && matriz[l+1][0]==35 && (matriz[l+2][0]==31 || matriz[l+2][0]==33)){z1=2;}
					if(z1==0){
						
						printf("(%i){Estrututa: %i}[semantico] Codigo Invalido: Essa sequencia nao se enquadra nas regras de escrita do bloco!! [%s %s %s]\n\n", vetor[l], z, A[l].string, A[l+1].string, A[l+2].string);
						vetorE[l]=1;
						erro=1;						
		
					}
					x=1;
					
				}
				if(matriz[l][0]==34 && matriz[l+1][0]!=30 && matriz[l+1][0]!=31 && matriz[l+1][0]!=32 && matriz[l+1][0]!=33){
					
						printf("(%i){Estrututa: %i}[semantico] Codigo Invalido: Operador matematico nao se enquadra na sequencia correta!! [%s]\n\n", vetor[l], z, A[l].string);
						vetorE[l]=1;
						erro=1;						
					
				}
				if(z1==1){
					
					if(matriz[l][0]==31 || matriz[l][0]==33){
						
						printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Nao e possivel atribuir strings para variaveis tipo banana!! [%s]\n\n", vetor[l], z, A[l].string);
						vetorE[l]=1;
						erro=1;	
						
					}
					
				}
				if(z1==2){
					
					if(matriz[l][0]==30 || matriz[l][0]==32){
						
						printf("(%i){Estrututa: %i}[Semantico] Codigo Invalido: Nao e possivel atribuir numeros para variaveis tipo caju!! [%s]\n\n", vetor[l], z, A[l].string);
						vetorE[l]=1;
						erro=1;	
						
					}
					
				}				
				if(matriz[l][1]==0){
					
					x=0;
					z2=0;
					
				}
	
			}

		}

		for(l=0, x=0, y=4; l<qtdL; l++){
		
			if(z==tipo[l]){
		
				if(matriz[l][1]==1)
					x++;
				
				if(matriz[l][1]==0)
					x=0;
				
				if(x==y){
					
					z1=0;
					w=strncmp(A[l].string, "+", tam);
					if(w==0){z1=1;}
					w=strncmp(A[l].string, "-", tam);
					if(w==0){z1=1;}			
					w=strncmp(A[l].string, "/", tam);
					if(w==0){z1=1;}			
					w=strncmp(A[l].string, "*", tam);
					if(w==0){z1=1;}
					
					if(z1==0){
						
						printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Operador matematico nao se enquadra na sequencia correta!!\n\n", vetor[l], z);
						vetorE[l]=1;
						erro=1;					
						
					}
					y=y+2;
					
				}
				
			}
		
		
		}

	}

	for(z=1; z<=qtdC; z++){
	
		for(l=0; l<qtdL; l++){
		
			if(z==tipo[l]){
			
				w=strncmp(A[l].string, "carne", tam);
				if(w==0){matriz[l][0]=36;}
				w=strncmp(A[l].string, "frango", tam);
				if(w==0){matriz[l][0]=37;}	
				w=strncmp(A[l].string, "peixe", tam);
				if(w==0){matriz[l][0]=38;}			

			}
		
		}
		for(l=0, y=99999; l<qtdL; l++){
			
			if(z==tipo[l]){
	
				if(matriz[l][0]==36)
					y=vetor[l];
	
				if(vetor[l]==y && matriz[l][0]!=36 && matriz[l][0]!=37 && matriz[l][0]!=38){
					
					matriz[l][0]=60;
					
				}
	
			}

		}		
		for(l=0; l<qtdL; l++){
		
			if(z==tipo[l] && matriz[l][0]==36){
			
				for(c=0, z3=0; c<qtdL; c++){
				
					if((matriz[c][0]==7 || matriz[c][0]==13) && (tipo[l+1]==tipo[c] || tipo[c]==0)){
						
						w=strncmp(A[l+1].string, A[c].string, tam);
						if(w==0){z3=1;}
							
					}
												
				}
				if(z3==0){
					
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Variavel invalida no laco de repeticao!! [%s]\n\n", vetor[l], z, A[l+1].string);
					vetorE[l+1]=1;
					erro=1;						
					
				}
				if(z3==1)
					matriz[l+1][0]=61;

				w=strncmp(A[l+2].string, "de", tam);
				if(w==0){matriz[l+2][0]=62;}
				else{
					
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Falta da palavra 'de' no laco de repeticao!! [%s]\n\n", vetor[l], z, A[l+2].string);
					vetorE[l+2]=1;
					erro=1;						
					
				}
				for(c=0, z3=0; c<qtdL; c++){
				
					if((matriz[c][0]==7 || matriz[c][0]==13) && (tipo[l+3]==tipo[c] || tipo[c]==0)){
						
						w=strncmp(A[l+3].string, A[c].string, tam);
						if(w==0){z3=1;}
							
					}
												
				}
				for(c=0, z2=0; A[l+3].string[c]!='\0'; c++){
				
					for(x=0, z1=0; x<10; x++){
						
						if(A[l+3].string[c]==num[x]){
							
							z1=1;
							
						}
						
					}
					if(z1==0)
						z2=1;

				}
				if(z2==0){z3=1;}
				if(z3==0){
					
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Variavel invalida no laco de repeticao!! [%s]\n\n", vetor[l], z, A[l+3].string);
					vetorE[l+3]=1;
					erro=1;						
					
				}
				if(z3==1)
					matriz[l+3][0]=63;

				w=strncmp(A[l+4].string, "ate", tam);
				if(w==0){matriz[l+4][0]=64;}
				else{
					
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Falta da palavra 'ate' no laco de repeticao!! [%s]\n\n", vetor[l], z, A[l+4].string);
					vetorE[l+4]=1;
					erro=1;						
					
				}

				for(c=0, z3=0; c<qtdL; c++){
				
					if((matriz[c][0]==7 || matriz[c][0]==13) && (tipo[l+5]==tipo[c] || tipo[c]==0)){
						
						w=strncmp(A[l+5].string, A[c].string, tam);
						if(w==0){z3=1;}
							
					}
												
				}
				for(c=0, z2=0; A[l+5].string[c]!='\0'; c++){
				
					for(x=0, z1=0; x<10; x++){
						
						if(A[l+5].string[c]==num[x]){
							
							z1=1;
							
						}
						
					}
					if(z1==0)
						z2=1;

				}
				if(z2==0){z3=1;}
				if(z3==0){
					
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Variavel invalida no laco de repeticao!! [%s]\n\n", vetor[l], z, A[l+5].string);
					vetorE[l+5]=1;
					erro=1;						
					
				}
				if(z3==1)
					matriz[l+5][0]=65;

				if(matriz[l+6][0]!=37){
					
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Falta de frango no laco de repeticao!! [%s]\n\n", vetor[l], z, A[l+6].string);
					vetorE[l+6]=1;
					erro=1;						
					
				}

			}
		
		}
		for(l=0, x=0, y=0; l<qtdL; l++){
		
			if(z==tipo[l]){
			
				if(matriz[l][0]==37)
					x++;
					
				if(matriz[l][0]==38)
					y++;
				
				if(y>x){
					
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Frango deve aparecer depois de carne!! [%s]\n\n", vetor[l], z, A[l].string);
					vetorE[l]=1;
					erro=1;							
					
				}

			}
			
		}
		if(y!=x){
			
			printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Deve-se abrir e fechar o laco de repeticao!!\n\n", vetor[l], z);
			erro=1;				
			
		}
			
	}

	for(z=1; z<=qtdC; z++){
	
		for(l=0; l<qtdL; l++){
		
			if(z==tipo[l]){
			
				w=strncmp(A[l].string, "coxinha", tam);
				if(w==0){matriz[l][0]=40;}
				w=strncmp(A[l].string, "empada", tam);
				if(w==0){matriz[l][0]=41;}	
				w=strncmp(A[l].string, "pastel", tam);
				if(w==0){matriz[l][0]=42;}			

			}
		
		}
		for(l=0, y=99999; l<qtdL; l++){
			
			if(z==tipo[l]){
	
				if(matriz[l][0]==40)
					y=vetor[l];
	
				if(vetor[l]==y && matriz[l][0]!=40 && matriz[l][0]!=41 && matriz[l][0]!=42){
					
					matriz[l][0]=70;
					
				}
	
			}

		}		
		for(l=0; l<qtdL; l++){
		
			if(z==tipo[l] && matriz[l][0]==40){
			
				w=strncmp(A[l+1].string, "(", tam);
				if(w==0){matriz[l+1][0]=71;}
				else{
					
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Falta da palavra '(' na estrutura de condicao!! [%s]\n\n", vetor[l], z, A[l+1].string);
					vetorE[l+1]=1;
					erro=1;						
					
				}
				for(c=0, z3=0; c<qtdL; c++){
				
					if((matriz[c][0]==7 || matriz[c][0]==13) && (tipo[l+2]==tipo[c] || tipo[c]==0)){
						
						w=strncmp(A[l+2].string, A[c].string, tam);
						if(w==0){z3=1;}
							
					}
												
				}
				for(c=0, z2=0; A[l+2].string[c]!='\0'; c++){
				
					for(x=0, z1=0; x<10; x++){
						
						if(A[l+2].string[c]==num[x]){
							
							z1=1;
							
						}
						
					}
					if(z1==0)
						z2=1;

				}
				if(z2==0){z3=1;}
				if(z3==0){
					
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Variavel invalida na estrutura de condicao!! [%s]\n\n", vetor[l], z, A[l+2].string);
					vetorE[l+2]=1;
					erro=1;						
					
				}
				if(z3==1)
					matriz[l+2][0]=72;

				z3=0;
				w=strncmp(A[l+3].string, ">", tam);
				if(w==0){z3=1;}
				w=strncmp(A[l+3].string, "<", tam);
				if(w==0){z3=1;}				
				w=strncmp(A[l+3].string, ">=", tam);
				if(w==0){z3=1;}				
				w=strncmp(A[l+3].string, "<=", tam);
				if(w==0){z3=1;}					
				w=strncmp(A[l+3].string, "==", tam);
				if(w==0){z3=1;}					
				if(z3==1){matriz[l+3][0]=73;}
				else{
					
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Operador logico escrito de modo errado!! [%s]\n\n", vetor[l], z, A[l+3].string);
					vetorE[l+3]=1;
					erro=1;						
					
				}	
				for(c=0, z3=0; c<qtdL; c++){
				
					if((matriz[c][0]==7 || matriz[c][0]==13) && (tipo[l+4]==tipo[c] || tipo[c]==0)){
						
						w=strncmp(A[l+4].string, A[c].string, tam);
						if(w==0){z3=1;}
							
					}
												
				}
				for(c=0, z2=0; A[l+4].string[c]!='\0'; c++){
				
					for(x=0, z1=0; x<10; x++){
						
						if(A[l+4].string[c]==num[x]){
							
							z1=1;
							
						}
						
					}
					if(z1==0)
						z2=1;

				}
				if(z2==0){z3=1;}
				if(z3==0){
					
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Variavel invalida na estrutura de condicao!! [%s]\n\n", vetor[l], z, A[l+4].string);
					vetorE[l+4]=1;
					erro=1;						
					
				}
				if(z3==1)
					matriz[l+4][0]=74;

				w=strncmp(A[l+5].string, ")", tam);
				if(w==0){matriz[l+5][0]=75;}
				else{
					
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Falta da palavra ')' na estrutura de condicao!! [%s]\n\n", vetor[l], z, A[l+5].string);
					vetorE[l+5]=1;
					erro=1;						
					
				}
				if(matriz[l+6][0]!=41){
					
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Falta de empada na estrutura de condicao!! [%s]\n\n", vetor[l], z, A[l+6].string);
					vetorE[l+6]=1;
					erro=1;						
					
				}

			}
			
		}
		for(l=0, x=0, y=0; l<qtdL; l++){
		
			if(z==tipo[l]){
			
				if(matriz[l][0]==40)
					x++;
					
				if(matriz[l][0]==42)
					y++;
				
				if(y>x){
					
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Empada deve aparecer depois de coxinha!! [%s]\n\n", vetor[l], z, A[l].string);
					vetorE[l]=1;
					erro=1;							
					
				}

			}
			
		}
		if(y!=x){
			
			printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Deve-se abrir e fechar a estrutura de condicao!!\n\n", vetor[l], z);
			erro=1;				
			
		}
	
	}

	for(z=1; z<=qtdC; z++){
	
		for(l=0; l<qtdL; l++){
			
			for(c=0; c<qtdL; c++){
				
				if(matriz[l][0]==18 && (matriz[c][0]==4) && l>c && tipo[l]==tipo[c] && tipo[l]==z){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem incorreta Leitura de dados inserido em local indevido!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);
					
				}
				if(matriz[l][0]==18 && (matriz[c][0]==3) && l<c && tipo[l]==tipo[c] && tipo[l]==z){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem incorreta Leitura de dados inserido em local indevido!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);
					
				}
				if(matriz[l][0]==20 && (matriz[c][0]==4) && l>c && tipo[l]==tipo[c] && tipo[l]==z){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem incorreta Escrita de dados inserida em local indevido!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);
					
				}
				if(matriz[l][0]==20 && (matriz[c][0]==3) && l<c && tipo[l]==tipo[c] && tipo[l]==z){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem incorreta Escrita de dados inserida em local indevido!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);
					
				}
				if(matriz[l][0]==28 && (matriz[c][0]==4) && l>c && tipo[l]==tipo[c] && tipo[l]==z){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem incorreta Bloco inserido em local indevido!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);
					
				}
				if(matriz[l][0]==28 && (matriz[c][0]==3) && l<c && tipo[l]==tipo[c] && tipo[l]==z){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem incorreta Bloco inserido em local indevido!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);
					
				}
				if(matriz[l][0]==36 && (matriz[c][0]==4) && l>c && tipo[l]==tipo[c] && tipo[l]==z){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem incorreta Laco de repeticao inserido em local indevido!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);
					
				}
				if(matriz[l][0]==36 && (matriz[c][0]==3) && l<c && tipo[l]==tipo[c] && tipo[l]==z){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem incorreta Laco de repeticao inserido em local indevido!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);
					
				}
				if(matriz[l][0]==38 && (matriz[c][0]==4) && l>c && tipo[l]==tipo[c] && tipo[l]==z){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem incorreta Laco de repeticao inserido em local indevido!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);
					
				}
				if(matriz[l][0]==38 && (matriz[c][0]==3) && l<c && tipo[l]==tipo[c] && tipo[l]==z){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem incorreta Laco de repeticao inserido em local indevido!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);
					
				}	
				if(matriz[l][0]==40 && (matriz[c][0]==4) && l>c && tipo[l]==tipo[c] && tipo[l]==z){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem incorreta Estrutura de condicao inserido em local indevido!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);
					
				}
				if(matriz[l][0]==40 && (matriz[c][0]==3) && l<c && tipo[l]==tipo[c] && tipo[l]==z){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem incorreta Estrutura de condicao inserido em local indevido!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);
					
				}				
				if(matriz[l][0]==42 && (matriz[c][0]==4) && l>c && tipo[l]==tipo[c] && tipo[l]==z){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem incorreta Estrutura de condicao inserido em local indevido!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);
					
				}
				if(matriz[l][0]==42 && (matriz[c][0]==3) && l<c && tipo[l]==tipo[c] && tipo[l]==z){
					
					vetorE[l]=1;
					vetorE[c]=1;
					erro=1;
					printf("(%i){Estrututa: %i}[Sintatico] Codigo Invalido: Ordem incorreta Estrutura de condicao inserido em local indevido!! [%s]<->[%s]\n\n", vetor[l], z, A[l].string, A[c].string);
					
				}				

			}		
			
		}
	
	}
	
	for(z=1; z<=qtdC; z++){
		
		//Leitura dos erros
		for(l=0; l<qtdL; l++){
			
			if(matriz[l][0]==0){
				
				printf("(%i){Estrututa: %i}[Lexica] Codigo Invalido: Token nao reconhecido!! [%s]\n\n", vetor[l], z, A[l].string);
				matriz[l][0]=999;
				erro=1;
				
			}
				
			if(vetorE[l]==1)
				matriz[l][0]=999;
		
		}
	
	}
	if(erro==0)
		printf("Codigo valido!!\n\n");
		
	//Criação do log
	log=fopen("[2] Log.txt", "w");
	for(l=0; l<qtdL; l++){
		
		if(matriz[l][0]!=-1){

			fprintf(log, "(%i) %s ", vetor[l], A[l].string);
			
			if(matriz[l][0]==0)
				fprintf(log, "\t[NÃO RECONHECIDO]\n");		
			if(matriz[l][0]==1 || matriz[l][0]==2 || matriz[l][0]==3 || matriz[l][0]==4)
				fprintf(log, "\t[RESERVADA]\n");
			if(matriz[l][0]==5)
				fprintf(log, "\t[NOME DO ALGORITMO]\n");		
			if(matriz[l][0]==6 || matriz[l][0]==9)
				fprintf(log, "\t[TIPO DE DADO]\n");
			if(matriz[l][0]==7 || matriz[l][0]==10)
				fprintf(log, "\t[variavel]\n");
			if(matriz[l][0]==8 || matriz[l][0]==11)
				fprintf(log, "\t[atribuição do dado]\n");
			if(matriz[l][0]==12 || matriz[l][0]==15)
				fprintf(log, "\t[GB TIPO DE DADO]\n");		
			if(matriz[l][0]==13 || matriz[l][0]==16)
				fprintf(log, "\t[GB variavel]\n");
			if(matriz[l][0]==14 || matriz[l][0]==17)
				fprintf(log, "\t[GB atribuição do dado]\n");
			if(matriz[l][0]==18)
				fprintf(log, "\t[LEITURA DE DADOS]\n");
			if(matriz[l][0]==19)
				fprintf(log, "\t[dado lido]\n");
			if(matriz[l][0]==20)
				fprintf(log, "\t[ESCRITA DE DADOS]\n");
			if(matriz[l][0]==21 || matriz[l][0]==22 || matriz[l][0]==24)
				fprintf(log, "\t[dado escrito]\n");
			if(matriz[l][0]==23 || matriz[l][0]==30 || matriz[l][0]==31 || matriz[l][0]==61)
				fprintf(log, "\t[variavel]\n");
			if(matriz[l][0]==25 || matriz[l][0]==32)
				fprintf(log, "\t[num]\n");	
			if(matriz[l][0]==26 || matriz[l][0]==33)
				fprintf(log, "\t[txt]\n");					
			if(matriz[l][0]==27 || matriz[l][0]==34)
				fprintf(log, "\t[operador matematico]\n");				
			if(matriz[l][0]==28)
				fprintf(log, "\t[BLOCO]\n");
			if(matriz[l][0]==29)
				fprintf(log, "\t[estrutura do bloco]\n");			
			if(matriz[l][0]==35)
				fprintf(log, "\t[atribuição]\n");					
			if(matriz[l][0]==36 || matriz[l][0]==37 || matriz[l][0]==38)
				fprintf(log, "\t[REPETIÇÃO]\n");
			if(matriz[l][0]==63 || matriz[l][0]==65 || matriz[l][0]==72  || matriz[l][0]==74)
				fprintf(log, "\t[inteiro]\n");
			if(matriz[l][0]==62 || matriz[l][0]==64)
				fprintf(log, "\t[estrutura de repetição]\n");
			if(matriz[l][0]==40 || matriz[l][0]==41 || matriz[l][0]==42)
				fprintf(log, "\t[CONDIÇÃO]\n");
			if(matriz[l][0]==73)
				fprintf(log, "\t[eperador logico]\n");
			if(matriz[l][0]==70 || matriz[l][0]==71 || matriz[l][0]==75)
				fprintf(log, "\t[estrutura de condição]\n");	
			if(matriz[l][0]==999)
				fprintf(log, "\t[ERRO]\n");
			
		}
		else{fprintf(log, "\n");};
		
	}
	for(l=0, y=0; l<qtdL; l++){
		
		for(c=0; A[l].string[c]!='\0'; c++){
			
			for(x=0, w=0; x<y; x++){
				
				if(A[l].string[c]==simbolos[x])
					w++;
				
			}
			if(w==0){
				
				simbolos[y]=A[l].string[c];
				y++;
				
			}
			
		}
			
	}
	fprintf(log, "\n\nTabela de simbolos: { %s }", simbolos);

}
