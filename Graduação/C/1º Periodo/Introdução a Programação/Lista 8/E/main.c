#include <stdio.h>

struct registro{

	char nome[10];
	int mes;
	int RG;
	float salario;

}

main(){

	int n, niver;
	
	struct registro empregado[3];

	for(n=0; n < 3; n++){
	
		printf("Informe o nome do funcionario %i\n", n+1);
		scanf("%s", &empregado[n].nome);
		
		do{
		
			printf("Informe o mes de aniversario do funcionario %i\n", n+1);
			scanf("%i", &empregado[n].mes);
		
		}while(empregado[n].mes < 1 || empregado[n].mes > 12);
		
		printf("Informe o RG do funcionario %i\n", n+1);
		scanf("%i", &empregado[n].RG);
		printf("Informe o salario do funcionario %i\n", n+1);
		scanf("%f", &empregado[n].salario);
		
		system("cls");
	
	}

	do{
		
		printf("De qual mes queres saber os aniversariantes?\n");
		scanf("%i", &niver);
		system("cls");
		
	}while(niver < 1 || niver > 12);
		
	printf("ANIVERSARIANTES DE ");
			
	switch(niver){
			
		case 1: printf("JANEIRO"); break;
		case 2: printf("FEVEREIRO"); break;			
		case 3: printf("MARCO"); break;			
		case 4: printf("ABRIL"); break;			
		case 5: printf("MAIO"); break;			
		case 6: printf("JUNHO"); break;			
		case 7: printf("JULHO"); break;			
		case 8: printf("AGOSTO"); break;		
		case 9: printf("SETEMBRO"); break;				
		case 10: printf("OUTUBRO"); break;			
		case 11: printf("NOVEMBRO"); break;				
		case 12: printf("DEZEBRO"); break;
			
	}		
	
	for(n=0; n < 3; n++){
	
		if(niver == empregado[n].mes){
		
			printf("\n\n[%i]nome do funcionario %s\n", n+1, empregado[n].nome);
			printf("[%i]RG do funcionario %i\n", n+1, empregado[n].RG);
			printf("[%i]salario do funcionario %.2f", n+1, empregado[n].salario);
		
		}
	
	}

getch();
}
