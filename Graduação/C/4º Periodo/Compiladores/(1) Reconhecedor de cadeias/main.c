#include <stdio.h>
#include <string.h>

#define Tam 100

main(){
	
	FILE *file;
	int x=0, y=0, z, w, erro=0, in=0, fl=0, pr=0, loop, t1=0, t2=0;
	char string[Tam]=" ", armazem[Tam]=" ", deposito[Tam]=" ", carga[Tam]=" ", teste[Tam]=" ";
	
	file=fopen("String.txt", "r");
	while(fgets(teste, 100, file) != NULL){
		
		for(y=0; teste[y+1]!='\0'; y++, x++){
				
			string[x]=teste[y];
				
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
	
	}
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
			if((string[x]=='i' && string[x+1]=='n' && string[x+2]=='i' && string[x+3]=='c' && string[x+4]=='i' && string[x+5]=='o' && string[x+6]=='=') || (string[x]=='d' && string[x+1]=='e' && string[x+2]=='c' && string[x+3]=='l' && string[x+4]=='a' && string[x+5]=='r' && string[x+6]=='a' && string[x+7]=='c' && string[x+8]=='a' && string[x+9]=='o' && string[x+10]=='=') || (string[x]=='p' && string[x+1]=='r' && string[x+2]=='o' && string[x+3]=='c' && string[x+4]=='e' && string[x+5]=='d' && string[x+6]=='i' && string[x+7]=='m' && string[x+8]=='e' && string[x+9]=='n' && string[x+10]=='t' && string[x+11]=='o' && string[x+12]=='=') || (string[x]=='f' && string[x+1]=='i' && string[x+2]=='m' && string[x+3]=='=') || (string[x]=='i' && string[x+1]=='n' && string[x+2]=='t' && string[x+3]=='=') || (string[x]=='f' && string[x+1]=='l' && string[x+2]=='o' && string[x+3]=='a' && string[x+4]=='t' && string[x+5]=='=')){
				
				if(erro==0){erro=32;}
				
			}
			while(string[x]!='=' && string[x]!=',' && string[x]!=';' && erro==0){
				
				armazem[y]=string[x];
				x++; y++;
				if(x==Tam-1){
						
					if(erro==0){erro=8;}
						
				}
					
			}
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
	
	}	
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
			if((string[x]=='i' && string[x+1]=='n' && string[x+2]=='i' && string[x+3]=='c' && string[x+4]=='i' && string[x+5]=='o' && string[x+6]=='=') || (string[x]=='d' && string[x+1]=='e' && string[x+2]=='c' && string[x+3]=='l' && string[x+4]=='a' && string[x+5]=='r' && string[x+6]=='a' && string[x+7]=='c' && string[x+8]=='a' && string[x+9]=='o' && string[x+10]=='=') || (string[x]=='p' && string[x+1]=='r' && string[x+2]=='o' && string[x+3]=='c' && string[x+4]=='e' && string[x+5]=='d' && string[x+6]=='i' && string[x+7]=='m' && string[x+8]=='e' && string[x+9]=='n' && string[x+10]=='t' && string[x+11]=='o' && string[x+12]=='=') || (string[x]=='f' && string[x+1]=='i' && string[x+2]=='m' && string[x+3]=='=') || (string[x]=='i' && string[x+1]=='n' && string[x+2]=='t' && string[x+3]=='=') || (string[x]=='f' && string[x+1]=='l' && string[x+2]=='o' && string[x+3]=='a' && string[x+4]=='t' && string[x+5]=='=')){
				
				if(erro==0){erro=32;}
				
			}			
			while(string[x]!='=' && string[x]!=',' && string[x]!=';' && erro==0){
				
				armazem[y]=string[x];
				x++; y++;
				if(x==Tam-1){
						
					if(erro==0){erro=14;}
						
				}
					
			}			
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
	if(in==0 && fl==0 && erro==0 && string[x]!='p' && string[x+1]!='r' && string[x+2]!='o' && string[x+3]!='c'&& string[x+4]!='e'&& string[x+5]!='d' && string[x+6]!='i' && string[x+7]!='m' && string[x+8]!='e' && string[x+9]!='n' && string[x+10]!='t' && string[x+11]!='o'){
		
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
		if((string[x]=='i' && string[x+1]=='n' && string[x+2]=='i' && string[x+3]=='c' && string[x+4]=='i' && string[x+5]=='o' && string[x+6]=='=') || (string[x]=='d' && string[x+1]=='e' && string[x+2]=='c' && string[x+3]=='l' && string[x+4]=='a' && string[x+5]=='r' && string[x+6]=='a' && string[x+7]=='c' && string[x+8]=='a' && string[x+9]=='o' && string[x+10]=='=') || (string[x]=='p' && string[x+1]=='r' && string[x+2]=='o' && string[x+3]=='c' && string[x+4]=='e' && string[x+5]=='d' && string[x+6]=='i' && string[x+7]=='m' && string[x+8]=='e' && string[x+9]=='n' && string[x+10]=='t' && string[x+11]=='o' && string[x+12]=='=') || (string[x]=='f' && string[x+1]=='i' && string[x+2]=='m' && string[x+3]=='=') || (string[x]=='i' && string[x+1]=='n' && string[x+2]=='t' && string[x+3]=='=') || (string[x]=='f' && string[x+1]=='l' && string[x+2]=='o' && string[x+3]=='a' && string[x+4]=='t' && string[x+5]=='=')){
					
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
			if((string[x]=='i' && string[x+1]=='n' && string[x+2]=='i' && string[x+3]=='c' && string[x+4]=='i' && string[x+5]=='o' && ((string[x+6]!='+' || string[x+6]!='-' || string[x+6]!='*' || string[x+6]!='/' || string[x+6]!=';'))) || (string[x]=='d' && string[x+1]=='e' && string[x+2]=='c' && string[x+3]=='l' && string[x+4]=='a' && string[x+5]=='r' && string[x+6]=='a' && string[x+7]=='c' && string[x+8]=='a' && string[x+9]=='o' && ((string[x+10]!='+' || string[x+10]!='-' || string[x+10]!='*' || string[x+10]!='/' || string[x+10]!=';'))) || (string[x]=='p' && string[x+1]=='r' && string[x+2]=='o' && string[x+3]=='c' && string[x+4]=='e' && string[x+5]=='d' && string[x+6]=='i' && string[x+7]=='m' && string[x+8]=='e' && string[x+9]=='n' && string[x+10]=='t' && string[x+11]=='o' && ((string[x+12]!='+' || string[x+12]!='-' || string[x+12]!='*' || string[x+12]!='/' || string[x+12]!=';'))) || (string[x]=='f' && string[x+1]=='i' && string[x+2]=='m' && ((string[x+3]!='+' || string[x+3]!='-' || string[x+3]!='*' || string[x+3]!='/' || string[x+3]!=';'))) || (string[x]=='i' && string[x+1]=='n' && string[x+2]=='t' && ((string[x+3]!='+' || string[x+3]!='-' || string[x+3]!='*' || string[x+3]!='/' || string[x+3]!=';'))) || (string[x]=='f' && string[x+1]=='l' && string[x+2]=='o' && string[x+3]=='a' && string[x+4]=='t' && ((string[x+5]!='+' || string[x+5]!='-' || string[x+5]!='*' || string[x+5]!='/' || string[x+5]!=';')))){
					
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
	if(erro==0 && (in==1 || fl==1) && pr==0 && t1==0 && t2==0){
	
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
	
	}
	if(in==0 && fl==0 && pr==0){
		
		if(erro==0){erro=36;}
		
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
		
	}

}

