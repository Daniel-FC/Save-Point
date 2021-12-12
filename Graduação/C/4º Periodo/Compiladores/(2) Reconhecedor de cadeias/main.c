#include <stdio.h>
#include <string.h>

#define Tam 100

main(){
	
	FILE *file;
	int x=0, y=0, z, w, erro=0, in=0, fl=0, ch=0, pr=0, loop, t1=0, t2=0, cont=0, a, b, resp=0;
	char string[Tam]=" ", armazem[Tam]=" ", deposito[Tam]=" ", carga[Tam]=" ", teste[Tam]=" ";
	char it[Tam]=" ", fa[Tam]=" ", ca[Tam]=" ", l1[Tam]=" ", l2[Tam]=" ", l3[Tam]=" " , l4[Tam]=" " , l5[Tam]=" " , l6[Tam]=" ";
	
	file=fopen("String.txt", "r");
	while(fgets(teste, 100, file) != NULL){
		
		cont++;
		
		for(y=0; teste[y+1]!='\0'; y++, x++){
				
			string[x]=teste[y];
			
			if(cont==1)
				l1[y]=teste[y];
			if(cont==2)
				l2[y]=teste[y];				
			if(cont==3)
				l3[y]=teste[y];				
			if(cont==4)
				l4[y]=teste[y];				
			if(cont==5)
				l5[y]=teste[y];				
			if(cont==6)
				l6[y]=teste[y];				
				
		}
		printf("%s", teste);
		string[x]=' ';
		x++;

	}
	printf("\n\n***********************", string);	
	x=0; y=0;
	
	//Inicio
	if(string[x]=='i' && string[x+1]=='n' && string[x+2]=='i' && string[x+3]=='c'&& string[x+4]=='i'&& string[x+5]=='o' && string[x+6]==' ' && erro==0){}
	else{
		
		if(erro==0){erro=1;}
				
	}
	//Espaço 1
	if(string[x+6]!=' ' && erro==0){
	
		if(erro==0){erro=2;}
	
	}	
	//Declaracao
	if(string[x+7]=='d' && string[x+8]=='e' && string[x+9]=='c' && string[x+10]=='l' && string[x+11]=='a' && string[x+12]=='r' && string[x+13]=='a' && string[x+14]=='c' && string[x+15]=='a' && string[x+16]=='o' && string[x+17]==' ' && erro==0){}
	else{
		
		if(erro==0){erro=3;}
		
	}	
	//Espaço 2
	if(string[x+17]!=' ' && erro==0){
	
		if(erro==0){erro=4;}
	
	}
	x=x+18;	
	//Declaracao de inteiro
	if(string[x]=='i' && string[x+1]=='n' && string[x+2]=='t' && erro==0){
	
		in=1;
		x=x+3;
	
	}w=0;
	if(in==1){
	
		do{
	
			loop=0;
			//Espaço 3
			if(string[x]!=' ' && erro==0){
				
				if(erro==0){erro=6;}
				
			}
			x++;	
			//Declaração variavel
			if((string[x]=='0' || string[x]=='1' || string[x]=='2' || string[x]=='3' || string[x]=='4' || string[x]=='5' || string[x]=='6' || string[x]=='7' || string[x]=='8' || string[x]=='9') && erro==0){
			
				if(erro==0){erro=7;}
					
			}
			//Analise de Nomes reservados
			if((string[x]=='i' && string[x+1]=='n' && string[x+2]=='i' && string[x+3]=='c' && string[x+4]=='i' && string[x+5]=='o' && string[x+6]=='=') || (string[x]=='d' && string[x+1]=='e' && string[x+2]=='c' && string[x+3]=='l' && string[x+4]=='a' && string[x+5]=='r' && string[x+6]=='a' && string[x+7]=='c' && string[x+8]=='a' && string[x+9]=='o' && string[x+10]=='=') || (string[x]=='p' && string[x+1]=='r' && string[x+2]=='o' && string[x+3]=='c' && string[x+4]=='e' && string[x+5]=='d' && string[x+6]=='i' && string[x+7]=='m' && string[x+8]=='e' && string[x+9]=='n' && string[x+10]=='t' && string[x+11]=='o' && string[x+12]=='=') || (string[x]=='f' && string[x+1]=='i' && string[x+2]=='m' && string[x+3]=='=') || (string[x]=='i' && string[x+1]=='n' && string[x+2]=='t' && string[x+3]=='=') || (string[x]=='f' && string[x+1]=='l' && string[x+2]=='o' && string[x+3]=='a' && string[x+4]=='t' && string[x+5]=='=') || (string[x]=='c' && string[x+1]=='h' && string[x+2]=='a' && string[x+3]=='r')){
				
				if(erro==0){erro=32;}
				
			}
			
			while(string[x]!='=' && string[x]!=',' && string[x]!=';' && erro==0){
				
				armazem[y]=string[x];
				it[w]=string[x];
				x++; y++; w++;
				if(x==Tam-1){
						
					if(erro==0){erro=8;}
						
				}
					
			}
			it[w]=';'; w++;
			armazem[y]=';'; y++;
			//Caso tenha atribuição de valor
			if(string[x]=='=' && erro==0){
					
				x++;
				while(string[x]!=',' && string[x]!=';' && erro==0){
					
					if(string[x]!='0' && string[x]!='1' && string[x]!='2' && string[x]!='3' && string[x]!='4' && string[x]!='5' && string[x]!='6' && string[x]!='7' && string[x]!='8' && string[x]!='9' && erro==0){
						
						if(erro==0){erro=9;}
						
					}
					x++;
					if(x==Tam-1){
							
						if(erro==0){erro=10;}
							
					}
						
				}
			
			}
			//Caso tenha declaração de mais de uma variavel
			if(string[x]==',' && erro==0){
			
				loop=1;
	
			}
			x++;
	
		}while(loop==1);
		//Espaço 4
		if(string[x]!=' ' && erro==0){
			
			if(erro==0){erro=11;}
			
		}
		x++;
	
	}
	
	//Declaracao de float
	if(string[x]=='f' && string[x+1]=='l' && string[x+2]=='o' && string[x+3]=='a' && string[x+4]=='t' && erro==0){
	
		fl=1;
		x=x+5;
	
	}w=0;
	if(fl==1){
	
		do{
			
			loop=0;
			//Espaço 5
			if(string[x]!=' ' && erro==0){
				
				if(erro==0){erro=12;}
				
			}
			x++;
			//Declaração variavel
			if((string[x]=='0' || string[x]=='1' || string[x]=='2' || string[x]=='3' || string[x]=='4' || string[x]=='5' || string[x]=='6' || string[x]=='7' || string[x]=='8' || string[x]=='9') && erro==0){
			
				if(erro==0){erro=13;}
					
			}
			//Analise de Nomes reservados
			if((string[x]=='i' && string[x+1]=='n' && string[x+2]=='i' && string[x+3]=='c' && string[x+4]=='i' && string[x+5]=='o' && string[x+6]=='=') || (string[x]=='d' && string[x+1]=='e' && string[x+2]=='c' && string[x+3]=='l' && string[x+4]=='a' && string[x+5]=='r' && string[x+6]=='a' && string[x+7]=='c' && string[x+8]=='a' && string[x+9]=='o' && string[x+10]=='=') || (string[x]=='p' && string[x+1]=='r' && string[x+2]=='o' && string[x+3]=='c' && string[x+4]=='e' && string[x+5]=='d' && string[x+6]=='i' && string[x+7]=='m' && string[x+8]=='e' && string[x+9]=='n' && string[x+10]=='t' && string[x+11]=='o' && string[x+12]=='=') || (string[x]=='f' && string[x+1]=='i' && string[x+2]=='m' && string[x+3]=='=') || (string[x]=='i' && string[x+1]=='n' && string[x+2]=='t' && string[x+3]=='=') || (string[x]=='f' && string[x+1]=='l' && string[x+2]=='o' && string[x+3]=='a' && string[x+4]=='t' && string[x+5]=='=') || (string[x]=='c' && string[x+1]=='h' && string[x+2]=='a' && string[x+3]=='r')){
				
				if(erro==0){erro=32;}
				
			}
					
			while(string[x]!='=' && string[x]!=',' && string[x]!=';' && erro==0){
				
				armazem[y]=string[x];
				fa[w]=string[x];
				x++; y++; w++;
				if(x==Tam-1){
						
					if(erro==0){erro=14;}
						
				}
					
			}
			fa[w]=';'; w++;		
			armazem[y]=';'; y++;
			//Caso tenha atribuição de valor
			if(string[x]=='=' && erro==0){
				
				x++;
				if(string[x]!='0' && string[x]!='1' && string[x]!='2' && string[x]!='3' && string[x]!='4' && string[x]!='5' && string[x]!='6' && string[x]!='7' && string[x]!='8' && string[x]!='9' && erro==0){
						
					if(erro==0){erro=15;}
						
				}					
				x++;
				while(string[x]!='.' && string[x]!=',' && string[x]!=';' && erro==0){
					
					if(string[x]!='0' && string[x]!='1' && string[x]!='2' && string[x]!='3' && string[x]!='4' && string[x]!='5' && string[x]!='6' && string[x]!='7' && string[x]!='8' && string[x]!='9' && erro==0){
						
						if(erro==0){erro=16;}
						
					}
					x++;
					if(x==Tam-1){
							
						if(erro==0){erro=17;}
							
					}
						
				}
				if(string[x]=='.'){
					
					x++;
					while(string[x]!=',' && string[x]!=';' && erro==0){
						
						if(string[x]!='0' && string[x]!='1' && string[x]!='2' && string[x]!='3' && string[x]!='4' && string[x]!='5' && string[x]!='6' && string[x]!='7' && string[x]!='8' && string[x]!='9' && erro==0){
							
							if(erro==0){erro=18;}
							
						}
						x++;
						if(x==Tam-1){
								
							if(erro==0){erro=19;}
								
						}
							
					}					
					
				}

			}			
			//Caso tenha declaração de mais de uma variavel
			if(string[x]==',' && erro==0){
			
				loop=1;
	
			}
			x++;			

		}while(loop==1);
		//Espaço 6
		if(string[x]!=' ' && erro==0){
			
			if(erro==0){erro=20;}
			
		}
		x++;
		
	}
	//Declaracao de char
	if(string[x]=='c' && string[x+1]=='h' && string[x+2]=='a' && string[x+3]=='r' && erro==0){
	
		ch=1;
		x=x+4;
	
	}w=0;
	if(ch==1){
	
		do{
	
			loop=0;
			//Espaço 3
			if(string[x]!=' ' && erro==0){
				
				if(erro==0){erro=37;}
				
			}
			x++;	
			//Declaração variavel
			if((string[x]=='0' || string[x]=='1' || string[x]=='2' || string[x]=='3' || string[x]=='4' || string[x]=='5' || string[x]=='6' || string[x]=='7' || string[x]=='8' || string[x]=='9') && erro==0){
			
				if(erro==0){erro=38;}
					
			}
			//Analise de Nomes reservados
			if((string[x]=='i' && string[x+1]=='n' && string[x+2]=='i' && string[x+3]=='c' && string[x+4]=='i' && string[x+5]=='o' && string[x+6]=='=') || (string[x]=='d' && string[x+1]=='e' && string[x+2]=='c' && string[x+3]=='l' && string[x+4]=='a' && string[x+5]=='r' && string[x+6]=='a' && string[x+7]=='c' && string[x+8]=='a' && string[x+9]=='o' && string[x+10]=='=') || (string[x]=='p' && string[x+1]=='r' && string[x+2]=='o' && string[x+3]=='c' && string[x+4]=='e' && string[x+5]=='d' && string[x+6]=='i' && string[x+7]=='m' && string[x+8]=='e' && string[x+9]=='n' && string[x+10]=='t' && string[x+11]=='o' && string[x+12]=='=') || (string[x]=='f' && string[x+1]=='i' && string[x+2]=='m' && string[x+3]=='=') || (string[x]=='i' && string[x+1]=='n' && string[x+2]=='t' && string[x+3]=='=') || (string[x]=='f' && string[x+1]=='l' && string[x+2]=='o' && string[x+3]=='a' && string[x+4]=='t' && string[x+5]=='=') || (string[x]=='c' && string[x+1]=='h' && string[x+2]=='a' && string[x+3]=='r')){
				
				if(erro==0){erro=39;}
				
			}
			
			while(string[x]!='=' && string[x]!=',' && string[x]!=';' && erro==0){
				
				armazem[y]=string[x];
				ca[w]=string[x];
				x++; y++; w++;
				if(x==Tam-1){
						
					if(erro==0){erro=40;}
						
				}
					
			}
			ca[w]=';'; w++;
			armazem[y]=';'; y++;
			//Caso tenha atribuição de valor
			if(string[x]=='=' && erro==0){
					
				x++;
				while(string[x]!=',' && string[x]!=';' && erro==0){
					
					x++;
					if(x==Tam-1){
							
						if(erro==0){erro=41;}
							
					}
						
				}
			
			}
			//Caso tenha declaração de mais de uma variavel
			if(string[x]==',' && erro==0){
			
				loop=1;
	
			}
			x++;
	
		}while(loop==1);
		//Espaço 4
		if(string[x]!=' ' && erro==0){
			
			if(erro==0){erro=42;}
			
		}
		x++;
	
	}	
	if(in==0 && fl==0 && ch==0 && erro==0 && string[x]!='p' && string[x+1]!='r' && string[x+2]!='o' && string[x+3]!='c'&& string[x+4]!='e'&& string[x+5]!='d' && string[x+6]!='i' && string[x+7]!='m' && string[x+8]!='e' && string[x+9]!='n' && string[x+10]!='t' && string[x+11]!='o'){
		
		if(erro==0){erro=5;}
		
	}	
	//procedimento
	if(string[x]=='p' && string[x+1]=='r' && string[x+2]=='o' && string[x+3]=='c'&& string[x+4]=='e'&& string[x+5]=='d' && string[x+6]=='i' && string[x+7]=='m' && string[x+8]=='e' && string[x+9]=='n' && string[x+10]=='t' && string[x+11]=='o' && string[x+12]==' ' && erro==0){}
	else{
		
		if(erro==0){erro=21;}
				
	}
	x=x+12;
	//Espaço 7
	if(string[x]!=' ' && erro==0){
	
		if(erro==0){erro=22;}
	
	}
	x++; y=0;
	if(string[x]=='f' && string[x+1]=='i' && string[x+2]=='m' && erro==0){pr=1;}
	if((string[x]=='0' || string[x]=='1' || string[x]=='2' || string[x]=='3' || string[x]=='4' || string[x]=='5' || string[x]=='6' || string[x]=='7' || string[x]=='8' || string[x]=='9') && string[x+1]==';'){t1=1;}
	if((string[x]!='0' || string[x]!='1' || string[x]!='2' || string[x]!='3' || string[x]!='4' || string[x]!='5' || string[x]!='6' || string[x]!='7' || string[x]!='8' || string[x]!='9') && string[x+1]==';'){t2=1;}
	if(t1==1 || t2==1){x=x+3;}
	if(pr==0 && t1==0 && t2==0){
	
		//Operação Variavel 1
		if((string[x]=='0' || string[x]=='1' || string[x]=='2' || string[x]=='3' || string[x]=='4' || string[x]=='5' || string[x]=='6' || string[x]=='7' || string[x]=='8' || string[x]=='9') && erro==0){
				
			if(erro==0){erro=23;}
						
		}
		//Analise de Nomes reservados
		if((string[x]=='i' && string[x+1]=='n' && string[x+2]=='i' && string[x+3]=='c' && string[x+4]=='i' && string[x+5]=='o' && string[x+6]=='=') || (string[x]=='d' && string[x+1]=='e' && string[x+2]=='c' && string[x+3]=='l' && string[x+4]=='a' && string[x+5]=='r' && string[x+6]=='a' && string[x+7]=='c' && string[x+8]=='a' && string[x+9]=='o' && string[x+10]=='=') || (string[x]=='p' && string[x+1]=='r' && string[x+2]=='o' && string[x+3]=='c' && string[x+4]=='e' && string[x+5]=='d' && string[x+6]=='i' && string[x+7]=='m' && string[x+8]=='e' && string[x+9]=='n' && string[x+10]=='t' && string[x+11]=='o' && string[x+12]=='=') || (string[x]=='f' && string[x+1]=='i' && string[x+2]=='m' && string[x+3]=='=') || (string[x]=='i' && string[x+1]=='n' && string[x+2]=='t' && string[x+3]=='=') || (string[x]=='f' && string[x+1]=='l' && string[x+2]=='o' && string[x+3]=='a' && string[x+4]=='t' && string[x+5]=='=') || (string[x]=='c' && string[x+1]=='h' && string[x+2]=='a' && string[x+3]=='r')){
					
			if(erro==0){erro=33;}
					
		}	
		while(string[x]!='=' && erro==0){
					
			deposito[y]=string[x];
			x++; y++;
			if(x==Tam-1){
							
				if(erro==0){erro=24;}
							
			}
						
		}
		deposito[y]=';'; y++; x++;
		do{
		
			loop=0;
			//Analise de Nomes reservados
			if((string[x]=='i' && string[x+1]=='n' && string[x+2]=='i' && string[x+3]=='c' && string[x+4]=='i' && string[x+5]=='o' && ((string[x+6]!='+' || string[x+6]!='-' || string[x+6]!='*' || string[x+6]!='/' || string[x+6]!=';'))) || (string[x]=='d' && string[x+1]=='e' && string[x+2]=='c' && string[x+3]=='l' && string[x+4]=='a' && string[x+5]=='r' && string[x+6]=='a' && string[x+7]=='c' && string[x+8]=='a' && string[x+9]=='o' && ((string[x+10]!='+' || string[x+10]!='-' || string[x+10]!='*' || string[x+10]!='/' || string[x+10]!=';'))) || (string[x]=='p' && string[x+1]=='r' && string[x+2]=='o' && string[x+3]=='c' && string[x+4]=='e' && string[x+5]=='d' && string[x+6]=='i' && string[x+7]=='m' && string[x+8]=='e' && string[x+9]=='n' && string[x+10]=='t' && string[x+11]=='o' && ((string[x+12]!='+' || string[x+12]!='-' || string[x+12]!='*' || string[x+12]!='/' || string[x+12]!=';'))) || (string[x]=='f' && string[x+1]=='i' && string[x+2]=='m' && ((string[x+3]!='+' || string[x+3]!='-' || string[x+3]!='*' || string[x+3]!='/' || string[x+3]!=';'))) || (string[x]=='i' && string[x+1]=='n' && string[x+2]=='t' && ((string[x+3]!='+' || string[x+3]!='-' || string[x+3]!='*' || string[x+3]!='/' || string[x+3]!=';'))) || (string[x]=='f' && string[x+1]=='l' && string[x+2]=='o' && string[x+3]=='a' && string[x+4]=='t' && ((string[x+5]!='+' || string[x+5]!='-' || string[x+5]!='*' || string[x+5]!='/' || string[x+5]!=';') || (string[x]=='c' && string[x+1]=='h' && string[x+2]=='a' && string[x+3]=='r')))){
					
				if(erro==0){erro=33;}
					
			}
			//Operação Variavel 2-n
			if(string[x]!='0' && string[x]!='1' && string[x]!='2' && string[x]!='3' && string[x]!='4' && string[x]!='5' && string[x]!='6' && string[x]!='7' && string[x]!='8' && string[x]!='9' && erro==0){
	
				while(string[x]!='+' && string[x]!='-' && string[x]!='*' && string[x]!='/' && string[x]!=';' && erro==0){
						
					deposito[y]=string[x];
					x++; y++;
					if(x==Tam-1){
								
						if(erro==0){erro=25;}
								
					}
							
				}
				deposito[y]=';'; y++;
			
			}
			else{
	
				x++;
				while(string[x]!='.' && string[x]!='+' && string[x]!='-' && string[x]!='*' && string[x]!='/' && string[x]!=';' && erro==0){
							
					if(string[x]!='0' && string[x]!='1' && string[x]!='2' && string[x]!='3' && string[x]!='4' && string[x]!='5' && string[x]!='6' && string[x]!='7' && string[x]!='8' && string[x]!='9' && erro==0){
								
						if(erro==0){erro=26;}
								
					}
					x++;
					if(x==Tam-1){
									
						if(erro==0){erro=27;}
									
					}
								
				}
				if(string[x]=='.'){
							
					x++;
					while(string[x]!='+' && string[x]!='-' && string[x]!='*' && string[x]!='/' && string[x]!=';' && erro==0){
								
						if(string[x]!='0' && string[x]!='1' && string[x]!='2' && string[x]!='3' && string[x]!='4' && string[x]!='5' && string[x]!='6' && string[x]!='7' && string[x]!='8' && string[x]!='9' && erro==0){
									
							if(erro==0){erro=28;}
									
						}
						x++;
						if(x==Tam-1){
										
							if(erro==0){erro=29;}
										
						}
									
					}					
							
				}		
			
			}		
			if(string[x]=='+' || string[x]=='-' || string[x]=='*' || string[x]=='/'){
	
				loop=1;
				
			}
			x++;
		
		}while(loop==1);
		//Espaço 8
		if(string[x]!=' ' && erro==0){
		
			if(erro==0){erro=30;}
		
		}
		x++;	
	
	}
	//Fim
	if(string[x]=='f' && string[x+1]=='i' && string[x+2]=='m' && string[x+3]==' ' && erro==0){}
	else{
		
		if(erro==0){erro=31;}
			
	}
	if(in==0 && fl==0 && ch==0 && pr==0){
		
		if(erro==0){erro=36;}
		
	}
	if(erro==0 && (in==1 || fl==1 || ch==1) && pr==0 && t1==0 && t2==0){
	
		//Analise de declaração de variavel	
		for(x=0; x<Tam; x++){teste[x]=0;}
		for(x=0; x<Tam; x++){teste[x]=armazem[x];}
		for(in=0, z=0; teste[in]!='\0'; in++, z++){
			
			for(x=0; x<Tam; x++){string[x]=0;}
			for(x=0; teste[in]!=';'; x++, in++){
				
				string[x]=teste[in];
				
			}
			for(fl=0, w=0; armazem[fl]!='\0'; fl++, w++){
				
				for(x=0; x<Tam; x++){carga[x]=0;}
				for(x=0; armazem[fl]!=';'; x++, fl++){
						
					carga[x]=armazem[fl];
						
				}
				y=strncmp(string, carga, Tam);			
				if(y==0 && z!=w){
					
					if(erro==0){erro=34;}
					
				}	
			
			}		
	
		}
		for(in=0; deposito[in]!='\0'; in++){
		
			for(x=0; x<Tam; x++){string[x]=0;}
			for(x=0; deposito[in]!=';'; x++, in++){
			
				string[x]=deposito[in];
			
			}
			for(fl=0, z=0; armazem[fl]!='\0'; fl++){
			
				for(x=0; x<Tam; x++){carga[x]=0;}
				
				for(loop=0; armazem[fl]!=';'; loop++, fl++){
						
					carga[loop]=armazem[fl];
						
				}
				y=strncmp(string, carga, Tam);
				if(y==0){z=1;}
	
			}
			if(z!=1){
					
				if(erro==0){erro=35;}
					
			}
		
		}

		if(cont==6){
			
			for(in=0, a=0; ca[in]!='\0'; in++){
			
				for(x=0; x<Tam; x++){string[x]=0;}
				for(x=0; ca[in]!=';'; x++, in++){
				
					string[x]=ca[in];
				
				}
				for(fl=0; deposito[fl]!='\0'; fl++){
				
					for(x=0; x<Tam; x++){carga[x]=0;}
					
					for(loop=0; deposito[fl]!=';'; loop++, fl++){
							
						carga[loop]=deposito[fl];
							
					}
					y=strncmp(string, carga, Tam);
					if(y==0){a=1;}
		
				}
			
			}
			for(in=0, b=0; it[in]!='\0'; in++){
			
				for(x=0; x<Tam; x++){string[x]=0;}
				for(x=0; it[in]!=';'; x++, in++){
				
					string[x]=it[in];
				
				}
				for(fl=0; deposito[fl]!='\0'; fl++){
				
					for(x=0; x<Tam; x++){carga[x]=0;}
					
					for(loop=0; deposito[fl]!=';'; loop++, fl++){
							
						carga[loop]=deposito[fl];
							
					}
					y=strncmp(string, carga, Tam);
					if(y==0){b=1;}
		
				}
			
			}					
			for(in=0; fa[in]!='\0'; in++){
			
				for(x=0; x<Tam; x++){string[x]=0;}
				for(x=0; fa[in]!=';'; x++, in++){
				
					string[x]=fa[in];
				
				}
				for(fl=0; deposito[fl]!='\0'; fl++){
				
					for(x=0; x<Tam; x++){carga[x]=0;}
					
					for(loop=0; deposito[fl]!=';'; loop++, fl++){
							
						carga[loop]=deposito[fl];
							
					}
					y=strncmp(string, carga, Tam);
					if(y==0){b=1;}
		
				}
			
			}				
		
			if(a==1 && b==1)
				if(erro==0){erro=43;}
	
		}
		
	}
	
	if(cont==6){
		
		if(l1[0]=='i' && l1[1]=='n' && l1[2]=='i' && l1[3]=='c' && l1[4]=='i' && l1[5]=='o' && l1[6]!='\0'){
			
			erro=45;
			printf("\n\n(1)Erro sintatico: palavra reservada escrita incorretamente 'inicio'");
			
		}
		if(l2[0]=='d' && l2[1]=='e' && l2[2]=='c' && l2[3]=='l' && l2[4]=='a' && l2[5]=='r' && l2[6]=='a' && l2[7]=='c' && l2[8]=='a' && l2[9]=='o' && l2[10]!='\0'){
			
			erro=46;
			printf("\n\n(2)Erro sintatico: palavra reservada escrita incorretamente 'declaracao'");
			
		}			
		if(l4[0]=='p' && l4[1]=='r' && l4[2]=='o' && l4[3]=='c' && l4[4]=='e' && l4[5]=='d' && l4[6]=='i' && l4[7]=='m' && l4[8]=='e' && l4[9]=='n' && l4[10]=='t' && l4[11]=='o' && l4[12]!='\0'){
			
			erro=47;
			printf("\n\n(4)Erro sintatico: palavra reservada escrita incorretamente 'procedimento'");
			
		}		
		if(l6[0]=='f' && l6[1]=='i' && l6[2]=='m' && l6[3]!='\0'){
			
			erro=48;
			printf("\n\n(6)Erro sintatico: palavra reservada escrita incorretamente 'fim'");
			
		}		
		
	}
	
	if(cont<4){
			
		erro=44;
		printf("\nErro: apenas %s %s %s encontrado no codigo", l1, l2, l3);
			
	}	
	
	switch(erro){
		
		case 0: printf("\nCodigo valido!!"); break;
		case 1: printf("\nCodigo invalido!!"); printf("\n\n(1)Erro sintatico: palavra reservada escrita incorretamente 'inicio'"); break;
		case 2: printf("\nCodigo invalido!!"); printf("\n\n(1-2)Erro sintatico: Falta de espacamento pos 'inicio'"); break;
		case 3: printf("\nCodigo invalido!!"); printf("\n\n(2)Erro sintatico: palavra reservada escrita incorretamente 'declaracao'"); break;
		case 4: printf("\nCodigo invalido!!"); printf("\n\n(2-3)Erro sintatico: Falta de espacamento pos 'declaracao'"); break;
		case 5: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro sintatico: Ausencia de palavra reservada 'int' ou 'float'"); break;
		case 6: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro sintatico: Falta de espacamento pos 'int'"); break;
		case 7: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro lexico: Declaracao de variavel int com primeiro caractere numeral"); break;
		case 8: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro lexico: Ausencia de simbolo correto na declaracao de uma variavel int, sugestao: '=', ',' e ';'"); break;
		case 9: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro semantico: Valores inteiros não podem possuir letras ou simbolos"); break;
		case 10: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro lexico: Ausencia de simbolo correto na declaracao de uma variavel int, sugestao: ',' e ';'"); break;
		case 11: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro sintatico: Falta de espacamento pós declaracao de variavel int"); break;
		case 12: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro sintatico: Falta de espacamento pós 'float"); break;
		case 13: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro lexico: Declaracao de variavel float com primeiro caractere numeral"); break;
		case 14: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro lexico: Ausencia de simbolo correto na declaracao de uma variavel float, sugestao: '=', ',' e ';'"); break;
		case 15: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro semantico: Valores de float não podem possuir letras ou simbolos"); break;
		case 16: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro semantico: Valores de float não podem possuir letras ou simbolos"); break;
		case 17: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro lexico: Ausencia de simbolo correto na declaracao de uma variavel float, sugestao: '.', ',' e ';'"); break;
		case 18: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro semantico: Valores de float não podem possuir letras ou simbolos"); break;
		case 19: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro lexico: Ausencia de simbolo correto na declaracao de uma variavel float, sugestao: ',' e ';'"); break;
		case 20: printf("\nCodigo invalido!!"); printf("\n\n(3-4)Erro sintatico: Falta de espacamento pos declaracao de variavel float"); break;
		case 21: printf("\nCodigo invalido!!"); printf("\n\n(4)Erro sintatico: palavra reservada escrita incorretamente 'procedimento'"); break;
		case 22: printf("\nCodigo invalido!!"); printf("\n\n(4-5)Erro sintatico: Falta de espacamento pos 'procedimento'"); break;
		case 23: printf("\nCodigo invalido!!"); printf("\n\n(5)Erro lexico: Variavel com primeiro caractere numeral"); break;
		case 24: printf("\nCodigo invalido!!"); printf("\n\n(5)Erro lexico: Ausencia de simbolo correto na operacao, sugestao: '='"); break;
		case 25: printf("\nCodigo invalido!!"); printf("\n\n(5)Erro lexico: Ausencia de simbolo correto na operacao, sugestao: '+', '-', '*', '/' e ';'"); break;
		case 26: printf("\nCodigo invalido!!"); printf("\n\n(5)Erro lexico: Variavel com primeiro caractere numeral e algum nao numeral depois"); break;
		case 27: printf("\nCodigo invalido!!"); printf("\n\n(5)Erro lexico: Ausencia de simbolo correto na operacao, sugestao: '.', '+', '-', '*', '/' e ';'"); break;
		case 28: printf("\nCodigo invalido!!"); printf("\n\n(5)Erro lexico: Variavel com primeiro caractere numeral e algum nao numeral depois"); break;
		case 29: printf("\nCodigo invalido!!"); printf("\n\n(5)Erro lexico: Ausencia de simbolo correto na operacao, sugestao: +', '-', '*', '/' e ';'"); break;
		case 30: printf("\nCodigo invalido!!"); printf("\n\n(5-6)Erro sintatico: Falta de espacamento pos operacao"); break;
		case 31: printf("\nCodigo invalido!!"); printf("\n\n(6)Erro sintatico: Palavra reservada escrita incorretamente 'fim'"); break;
		case 32: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro sintatico: Nome de variavel declarada com palavra reservada"); break;
		case 33: printf("\nCodigo invalido!!"); printf("\n\n(5)Erro sintatico: Palavra reservada nao pode ser usada na operacao"); break;
		case 34: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro sintatico: Variavel ja declarada anteriormente"); break;
		case 35: printf("\nCodigo invalido!!"); printf("\n\n(6)Erro sintatico: Uso de uma variavel nao declarada na operacao"); break;
		case 36: printf("\nCodigo invalido!!"); printf("\n\n(5)Erro sintatico: Uso de uma variavel nao declarada na operacao"); break;
		case 37: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro sintatico: Falta de espacamento pos 'char'"); break;
		case 38: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro lexico: Declaracao de variavel char com primeiro caractere numeral"); break;
		case 39: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro sintatico: Nome de variavel declarada com palavra reservada"); break;
		case 40: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro lexico: Ausencia de simbolo correto na declaracao de uma variavel char, sugestao: '=', ',' e ';'"); break;
		case 41: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro lexico: Ausencia de simbolo correto na declaracao de uma variavel char, sugestao: ',' e ';'"); break;
		case 42: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro sintatico: Falta de espacamento pós declaracao de variavel char"); break;
		case 43: printf("\nCodigo invalido!!"); printf("\n\n(3)Erro semantico: Variavel char nao se mistura na operacao com int e float"); break;
		
	}
	
	scanf("%i", &resp);
	
	if(resp==1){
		
		system("cls");
		printf("        ARQUIVO LOG\n\n");
		
		if(erro!=45)
			printf("inicio             RESERVADA\n");
		else
			printf("inicio             ERRO\n");
		if(erro!=46)
			printf("declaracao         RESERVADA\n");
		else
			printf("declaracao         ERRO\n");		
		if(erro!=47)
			printf("procedimento       RESERVADA\n");
		else
			printf("procedimento       ERRO\n");		
		if(erro!=48)
			printf("fim                RESERVADA\n\n");
		else
			printf("fim                ERRO\n\n");		
		

		for(x=0; it[x]!='\0'; x++){
			
			if(it[x]!=';' && erro!=7 && erro!=8 && erro!=9)
				printf("%c                  INTEIRO\n", it[x]);
			if(erro==7 || erro==8 || erro==9)
				printf("%c                  ERRO\n", it[x]);
				
		}
		for(x=0; fa[x]!='\0'; x++){
			
			if(fa[x]!=';' && erro!=13 && erro!=14 && erro!=15 && erro!=16 && erro!=17 && erro!=18 && erro!=19)
				printf("%c                  FLOAT\n", fa[x]);
			if(erro==13 || erro==14 || erro==15 || erro==16 || erro==17 || erro==18 || erro==19)
				printf("%c                  ERRO\n", fa[x]);
							
		}		
		for(x=0; ca[x]!='\0'; x++){
			
			if(ca[x]!=';'&& erro!=38 && erro!=39 && erro!=40)
				printf("%c                  CHAR\n", ca[x]);
			if(erro==38 || erro==39 || erro==40)
				printf("%c                  ERRO\n", ca[x]);
							
		}		
		
	}
	
}

