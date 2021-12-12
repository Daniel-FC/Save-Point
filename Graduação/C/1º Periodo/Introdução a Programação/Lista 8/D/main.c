#include <stdio.h>

struct informacoes{

	int idade;
	char sexo[10];
	float salario;
	int filho;

}

main(){

	int n, rodar=1, max;
	float MI=0, MS=0, MF=0;

	struct informacoes habitantes[500];

	do{
	
		system("cls");
		
		printf("[%i] Informe a idade:\n", n+1);
		scanf("%i", &habitantes[n].idade);
		printf("[%i] Informe o sexo:\n", n+1);
		scanf("%s", &habitantes[n].sexo);
		printf("[%i] Informe o salario:\n", n+1);
		scanf("%f", &habitantes[n].salario);
		printf("[%i] Informe a quantidade de filhos:\n", n+1);
		scanf("%i", &habitantes[n].filho);
		
		MI = MI + habitantes[n].idade;
		MS = MS + habitantes[n].salario;
		MF = MF + habitantes[n].filho;
	
		n++;
		
		do{
				
			printf("\n\nDigite 0 caso tenha terminado. Digite 1 caso queira continuar.\n");
			scanf("%i", &rodar);
				
			if(rodar > 1 || rodar < 0){
				printf("\nValor incorreto! tente novamente.");
			}
				
		}while(rodar > 1 || rodar < 0);
	
	}while(rodar == 1 && n != 500);
	
	system("cls");
	printf("A media de idade: %.2f\n", MI/n);
	printf("A media de salario: %.2f\n", MS/n);
	printf("A media de idade: %.2f\n\n", MF/n);
	max = n;
	
	for(n=0; n < max; n++){
	
		printf("\n[%i]Idade %i\n", n+1, habitantes[n].idade);
		printf("[%i]sexo %s\n", n+1, habitantes[n].sexo);
		printf("[%i]salario %.2f\n", n+1, habitantes[n].salario);
		printf("[%i]Quantidade de filho %i\n", n+1, habitantes[n].filho);
		
	}

getch();
}
