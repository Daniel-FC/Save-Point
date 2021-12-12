#include <stdio.h>

struct condominio{

	char nome[10];
	int n_apt;
	float area;
	int n_moradores;
	float valor;

}

main(){

	int n, rodar, resposta, PT=0, qtd=0, menor=0, localA[40], xA=0, maior=0, localB[40], xB=0, maiorM=0, localC[40], xC=0;
	float AT=0;
	
	struct condominio apartamento[40];
	
	do{
		
		printf("[%i]Informe seu nome:\n", n+1);
		scanf("%s", &apartamento[n].nome);
		printf("[%i]Informe o numero do seu apartamento:\n", n+1);
		scanf("%i", &apartamento[n].n_apt);
		printf("[%i]Informe o tamanho do seu apartamento:\n", n+1);
		scanf("%f", &apartamento[n].area);
		printf("[%i]Informe a quantidade de moradores do seu apartamento:\n", n+1);
		scanf("%i", &apartamento[n].n_moradores);
		printf("[%i]Informe a mensalidade do seu apartamento:\n", n+1);
		scanf("%f", &apartamento[n].valor);
		
		AT = AT + apartamento[n].area;
		PT = PT + apartamento[n].n_moradores;
		
		if(menor >= apartamento[n].area || menor == 0){
		
			if(menor == apartamento[n].area){
			
				xA++;
			
			}
			if(menor > apartamento[n].area){
			
				xA = 0;
			
			}
		
			menor = apartamento[n].area;
			localA[xA] = n;
	
		}
		
		if(maior <= apartamento[n].area){
		
			if(maior == apartamento[n].area){
			
				xB++;
			
			}
			if(maior < apartamento[n].area){
			
				xB = 0;
			
			}
			
			maior = apartamento[n].area;
			localB[xB] = n;

		}
		
		if(maiorM <= apartamento[n].n_moradores){
		
			if(maiorM == apartamento[n].n_moradores){
			
				xC++;
			
			}
			if(maiorM < apartamento[n].n_moradores){
			
				xC = 0;
			
			}
			
			maiorM = apartamento[n].n_moradores;
			localC[xC] = n;

		}
		
		n++;
		qtd++;
			
		do{
			
			system("cls");
				
			printf("Digite 0 caso tenha terminado. Digite 1 caso queira adicionar mais apartamentos.\n");
			scanf("%i", &rodar);
				
			if(rodar > 1 || rodar < 0){
				printf("\nValor incorreto! tente novamente.");
			}
				
		}while(rodar > 1 || rodar < 0);
		
		system("cls");
		
	}while(rodar == 1 && n < 40);
	
	do{
	
		printf("Digite 1: Para saber a area total do condominio;\n");
		printf("Digite 2: Para saber o preco por apartamento;\n");
		printf("Digite 3: Para saber os dados do maior apartamento;\n");
		printf("Digite 4: Para saber os dados do menor apartamento;\n");
		printf("Digite 5: Para saber a quantidade de moradores do condominio;\n");
		printf("Digite 6: Para saber os dados do apartamento com mais moradores;\n");
		printf("Digite 7: Fechar o programa;\n");
	
		printf("\nDigite aqui:\n");
		scanf("%i", &resposta);
		
		system("cls");
		
	}while(resposta < 1 || resposta > 7);
	
		
	switch(resposta){
	
		case 1: printf("A area total do condominio é: %.2f", AT); break;
		case 2: printf("O preco por apartamento:\n");
		for(n=0; n < qtd; n++){
		
			printf("\nNumero do apartamento: %i\n", apartamento[n].n_apt);
			printf("Valor a pagar %.2f:\n", apartamento[n].valor);
		
		}break;
		case 3: printf("Dados do maior apartamento:\n");
		for(n=0; n < xB+1; n++){
			
			printf("\nPropietario: %s\n", apartamento[ localB[n] ].nome);
			printf("Numero do apartamento: %i\n", apartamento[ localB[n] ].n_apt);
			printf("Tamanho do apartamento: %.2f\n", apartamento[ localB[n] ].area);
			printf("Quantidade de moradores: %.i\n", apartamento[ localB[n] ].n_moradores);
			printf("Mnesalidade: %.2f\n", apartamento[ localB[n] ].valor);
		
		}break;
		case 4: printf("Dados do menor apartamento:\n");
		for(n=0; n < xA+1; n++){
			
			printf("\nPropietario: %s\n", apartamento[ localA[n] ].nome);
			printf("Numero do apartamento: %i\n", apartamento[ localA[n] ].n_apt);
			printf("Tamanho do apartamento: %.2f\n", apartamento[ localA[n] ].area);
			printf("Quantidade de moradores: %.i\n", apartamento[ localA[n] ].n_moradores);
			printf("Mnesalidade: %.2f\n", apartamento[ localA[n] ].valor);
		
		}break;
		case 5: printf("A quantidade de moradores do condominio é: %i", PT); break;
		case 6: printf("Dados do apartamento com mais moradores:\n");
		for(n=0; n < xC+1; n++){
			
			printf("\nPropietario: %s\n", apartamento[ localC[n] ].nome);
			printf("Numero do apartamento: %i\n", apartamento[ localC[n] ].n_apt);
			printf("Tamanho do apartamento: %.2f\n", apartamento[ localC[n] ].area);
			printf("Quantidade de moradores: %.i\n", apartamento[ localC[n] ].n_moradores);
			printf("Mnesalidade: %.2f\n", apartamento[ localC[n] ].valor);
		
		}break;	
		case 7: printf("O programa sera fechado."); break;
	
	}

getch();
}
