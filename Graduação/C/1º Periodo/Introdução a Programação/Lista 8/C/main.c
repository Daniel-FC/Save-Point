#include <stdio.h>

struct livro{

	char tit[20];
	int ano;
	int pagi;
	float prec;

}

main(){

	int menor=0, maior=0, localA[5], localB[5], xA=0, xB=0, n;
	float Mpagi=0;

	struct livro livro[5];

	for(n=0; n < 5; n++){
	
		printf("Informe o titulo do livro %i\n", n+1);
		scanf("%s", &livro[n].tit);
		printf("Informe o ano do livro %i\n", n+1);
		scanf("%i", &livro[n].ano);
		printf("Informe o numero de paginas do livro %i\n", n+1);
		scanf("%i", &livro[n].pagi);
		printf("Informe o preço do livro %i\n", n+1);
		scanf("%f", &livro[n].prec);
		
		Mpagi = Mpagi + livro[n].pagi;
		
		if(menor >= livro[n].prec || menor == 0){
		
			if(menor == livro[n].prec){
			
				xA++;
			
			}
			if(menor > livro[n].prec){
			
				xA = 0;
			
			}
		
			menor = livro[n].prec;
			localA[xA] = n;
	
		}
		
		if(maior <= livro[n].prec || maior == 0){
		
			if(maior == livro[n].prec){
			
				xB++;
			
			}
			if(maior < livro[n].prec){
			
				xB = 0;
			
			}
			
			maior = livro[n].prec;
			localB[xB] = n;

		}
		
		system("cls");
	
	}
	
	printf("A MEDIA DE PAGINAS DE TODOS OS LIVROS: %.2f", Mpagi/n);
	printf("\n\nLIVRO'S COM O'S MENOR'ES PRECO'S:");
	
	for(n=0; n < xA+1; n++){
	
		printf("\n\nInforme o titulo do livro %s\n", livro[ localA [n] ].tit);
		printf("Informe o ano do livro %i\n", livro[ localA [n] ].ano);
		printf("Informe o numero de paginas do livro %i\n", livro[ localA [n] ].pagi);
		printf("Informe o preço do livro %.2f\n", livro[ localA [n] ].prec);
		
	}

	printf("\n\nLIVRO'S COM O'S MAIOR'ES PRECO'S:");
	
	for(n=0; n < xB+1; n++){
	
		printf("\n\nInforme o titulo do livro %s\n", livro[ localB [n] ].tit);
		printf("Informe o ano do livro %i\n", livro[ localB [n] ].ano);
		printf("Informe o numero de paginas do livro %i\n", livro[ localB [n] ].pagi);
		printf("Informe o preço do livro %.2f\n", livro[ localB [n] ].prec);
		
	}

getch();
}
