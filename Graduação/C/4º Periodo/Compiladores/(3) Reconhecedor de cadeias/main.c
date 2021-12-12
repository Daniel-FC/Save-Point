#include <stdio.h>
#include <string.h>

#define tam 50

struct armazem{
	
	char reservada[tam];
	char letra[tam];
	char numero[tam];
	char token[tam];
	
};

main(){

	FILE *p_cod, *p_res, *p_car, *log;
	int x, y, w, l, c, lin[tam], cont=1, contR=0, tipo[tam], op, ap;
	char cod[tam], res[tam], aux[tam];
	struct armazem A[tam], B;
	//Leitura de palavras reservadas
	p_res=fopen("[3] Palavras Reservadas.txt", "r");
	for(x=0; fgets(aux, tam, p_res)!=NULL; x++){
		
		strcpy(A[x].reservada, aux);
		contR++;
		
	}
	//Leitura de caracteres
	p_car=fopen("[4] Caracteres.txt", "r");
	for(x=0; fgets(aux, tam, p_car)!=NULL; x++){
		
		if(x==0)
			strcpy(B.letra, aux);
		if(x==1)
			strcpy(B.numero, aux);			
					
	}
	//Zerando vetores e strings
	for(l=0; l<tam; l++){for(c=0; c<tam; c++){A[l].token[c]=0; lin[l]=0; tipo[l]=0;}}
	//Separaçãp de tokens por linha e tipo
	p_cod=fopen("[1] Codigo.txt", "r");
	for(x=0; fgets(aux, tam, p_cod)!=NULL; x++, cont++){
		
		for(l=0; l<tam; l++){cod[l]=0;}
		for(l=0; aux[l+1]!='\0'; l++)
			cod[l]=aux[l];
					
		printf("%s", aux);
		for(l=0, c=0, op=0; cod[c]!='\0'; c++){

			if(cod[c]==' ' || cod[c]==';' || cod[c]==',' || cod[c]=='=' || cod[c]=='+' || cod[c]=='-' || cod[c]=='*' || cod[c]=='/'){
				
				if(ap==0)
					x++;
				l=0;
				if(op==3)
					op=1;
				if(op==4)
					op=2;
				ap=1;
										
			}
			if(cod[c]!=' '){
				
				lin[x]=cont;
				A[x].token[l]=cod[c];
				
				if(op==1)
					tipo[x]=3;
				if(op==2)
					tipo[x]=4;
									
				if(cod[c]==',')
					tipo[x]=5;
				if(cod[c]==';')
					tipo[x]=6;
				if(cod[c]=='+' || cod[c]=='-' || cod[c]=='/' || cod[c]=='*')
					tipo[x]=7;
				if(cod[c]=='='){
					
					tipo[x]=8;
					if(op==1)
						op=3;
					if(op==2)
						op=4;
											
				}
					
				if(l==2 || l==3){
			
					if(A[x].token[0]=='i' && A[x].token[1]=='n' && A[x].token[2]=='t'){
						
						tipo[x]=2;
						op=1;
						
					}
					if(A[x].token[0]=='c' && A[x].token[1]=='h' && A[x].token[2]=='a' && A[x].token[3]=='r'){
						
						tipo[x]=2;
						op=2;
						
					}

				}
				l++;
				ap=0;
													
			}

		}
			
		for(l=0; l<contR; l++){
			
			y=strncmp(aux, A[l].reservada, tam);
			if(y==0)
				tipo[x]=1;
			
		}
		
	}
	//Criação do tipo "em analise"
	for(l=0; l<x; l++){if(tipo[l]==0){tipo[l]=9;}}
	
	printf("\n\n***********************\n\n");

	//Analisador de erros
	for(l=0, op=0; l<x; l++){
	
		if(tipo[l]==3 || tipo[l]==4){
		
			for(c=0, y=1; A[l].token[c]!='\0'; c++){
				
				for(w=0; w<9; w++){
				
					if(c==0 && A[l].token[c]==B.numero[w])
						y=0;
					
				}
				if(c==0 && y==0){
					
					tipo[l]=100;
					printf("(%i) Erro lexico: declaracao de variavel com primeiro caractere numeral: %s\n", lin[l], A[l].token);
					op=1;
					
				}

			}
			
		}
		
	}
	if(op==0)
		printf("Codigo Valido!!!");
	
	//Criação do log
	log=fopen("[2] Log.txt", "w");
	for(l=0; l<x; l++){
		
		if(tipo[l]>=100 || tipo[l]==1 || tipo[l]==2 || tipo[l]==3 || tipo[l]==4 || tipo[l]==9)
			fprintf(log, "(%i) %s   ", lin[l], A[l].token);
		if(tipo[l]==5 || tipo[l]==6 || tipo[l]==7 || tipo[l]==8)
			fprintf(log, "(%i) %c   ", lin[l], A[l].token[0]);
					
		if(tipo[l]==100)
			fprintf(log, "ERRO\n");		
		if(tipo[l]==1)
			fprintf(log, "RESERVADA\n");
		if(tipo[l]==2)
			fprintf(log, "TIPO DE DADO\n");			
		if(tipo[l]==3)
			fprintf(log, "INTEIRO\n");				
		if(tipo[l]==4)
			fprintf(log, "CHAR\n");			
		if(tipo[l]==5)
			fprintf(log, "CARACTERE\n");
		if(tipo[l]==6)
			fprintf(log, "FINALIZADOR\n");
		if(tipo[l]==7)
			fprintf(log, "OPERADOR\n");
		if(tipo[l]==8)
			fprintf(log, "ATRIBUIDOR\n");
		if(tipo[l]==9)
			fprintf(log, "EM ANALISE\n");
														
	}

getch();
}
