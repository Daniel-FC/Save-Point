#include <stdio.h>

main(){

int voto, can1=0, can2=0, can3=0, can4=0, can5=0, nulo=0, rodar=1, empate=1, senha=0;

do{
	
	system("cls");
	printf("Voto em branco:      0\nCandidato Trekiudes: 1\nCandidato Trekoso:   2\nCandidato Trekudo:   3\nCandidato Treloso:   4\nCandidato Trelala:   5\nVoto nulo:           6++\n\n");
	
	printf("Informe a sua escolha\n");
	scanf("%i", &voto);
		
	switch(voto){
	
		case 0:
		break;
			
		case 1:
		can1++;
		break;
			
		case 2:
		can2++;
		break;
			
		case 3:
		can3++;
		break;
			
		case 4:
		can4++;
		break;
			
		case 5:
		can5++;
		break;
			
		default:
		nulo++;
		break;
	
	}
	
	system("cls");
	printf("Voto computado com sucesso.\n");
	
	do{
		
		printf("\nInforme a senha para liberar o proximo voto\n");
		scanf("%i", &senha);
		system("cls");
		
		if(senha == 123){
			do{
					
				printf("Digite 1 para realizar o proximo voto. Digite 0 para ver o resultado da votação.\n");
				scanf("%i", &rodar);
					
				if(rodar > 1 || rodar < 0){
				    system("cls");
					printf("\nValor incorreto! tente novamente.");
				}
					
			}while(rodar > 1 || rodar < 0);
		}
		else{
		system("cls");
		printf("Senha incorreta! tente novamente.\n");
		senha = 0;
		}

	}while(senha == 0);

}while(rodar == 1);

system("cls");

if(can1 > can2 && can1 > can3 && can1 > can4 && can1 > can5){
	printf("O candidato vencedor é Trekiudes\n\n");
	empate = 0;
}
if(can2 > can1 && can2 > can3 && can2 > can4 && can2 > can5){
	printf("O candidato vencedor é Trekoso\n\n");
	empate = 0;
}
if(can3 > can2 && can3 > can1 && can3 > can4 && can3 > can5){
	printf("O candidato vencedor é Trekudo\n\n");
	empate = 0;
}
if(can4 > can2 && can4 > can3 && can4 > can1 && can4 > can5){
	printf("O candidato vencedor é Treloso\n\n");
	empate = 0;
}
if(can5 > can2 && can5 > can3 && can5 > can4 && can5 > can1){
	printf("O candidato vencedor é Trelala\n\n");
	empate = 0;
}
if(empate == 1){
	printf("Não houve vencedor!\n\n");
}

printf("Trekiudes obteve %i voto's\n", can1);
printf("Trekoso obteve %i voto's\n", can2);
printf("Trekudo obteve %i voto's\n", can3);
printf("Treloso obteve %i voto's\n", can4);
printf("Trelala obteve %i voto's\n", can5);
printf("Voto's nulo's %i\n", nulo);
printf("\nTotal de votos %i", can1+can2+can3+can4+can5+nulo);

getch();
}
