#include <stdio.h>

struct disciplina{

	int matricula;
	char nome[10];
	float nota1;
	float nota2;
	float nota3;

}

main(){
	
	int n, Maior1=0, M1[5], xA=0, MenorMg=0, M2[5], xB=0, MaiorMg=0, M3[5], xC=0;
	float Mg[5];

	struct disciplina aluno[5];

	for(n=0; n < 5; n++){
	
		printf("Informe a matricula do aluno %i\n", n+1);
		scanf("%i", &aluno[n].matricula);
		printf("Informe o nome do aluno %i\n", n+1);
		scanf("%s", &aluno[n].nome);
		printf("Informe a primeira nota do aluno %i\n", n+1);
		scanf("%f", &aluno[n].nota1);
		printf("Informe a segunda nota do aluno %i\n", n+1);
		scanf("%f", &aluno[n].nota2);
		printf("Informe a terceira nota do aluno %i\n", n+1);
		scanf("%f", &aluno[n].nota3);
		
		system("cls");
		
		if(Maior1 <= aluno[n].nota1){
		
			if(Maior1 == aluno[n].nota1){
			
				xA++;
			
			}
			if(Maior1 < aluno[n].nota1){
			
				xA = 0;
			
			}
		
			Maior1 = aluno[n].nota1;
			M1[xA] = n;
		
		}

		Mg[n] = aluno[n].nota1*4 + aluno[n].nota2*5 + aluno[n].nota3*6;
	
	}
	
	printf("ALUNO COM MAIOR NOTA's NA PRIMEIRA PROVA:\n");
	
	for(n=0; n < xA+1; n++){
	
		printf("\nMatricula: %i\n", aluno[ M1[n] ].matricula);
		printf("Nome: %s\n", aluno[ M1[n] ].nome);
	
	}
	
	for(n=0; n < 5; n++){
	
		if(MenorMg >= Mg[n] || MenorMg == 0){
			
			if(MenorMg == Mg[n]){
			
				xB++;
			
			}
			if(MenorMg < Mg[n]){
			
				xB = 0;
			
			}
		
			MenorMg = Mg[n];
			M2[xB] = n;
		
		}
		if(MaiorMg <= Mg[n]){
		
			if(MaiorMg == Mg[n]){
			
				xC++;
			
			}
			if(MaiorMg < Mg[n]){
			
				xC = 0;
			
			}
		
			MaiorMg = Mg[n];
			M3[xC]  = n;
		
		}
	
	}

	printf("\nALUNO COM MENOR MEDIA GERAL:\n");
	
	for(n=0; n < xB+1; n++){
	
		printf("\nMatricula: %i\n", aluno[ M2[n] ].matricula);
		printf("Nome: %s\n", aluno[ M2[n] ].nome);
	
	}
	
	printf("\nALUNO COM MAIOR MEDIA GERAL:\n");
	
	for(n=0; n < xC+1; n++){
	
		printf("\nMatricula: %i\n", aluno[ M3[n] ].matricula);
		printf("Nome: %s\n", aluno[ M3[n] ].nome);
	
	}
	
	printf("\nALUNOS APROVADOS:");
	
	for(n=0; n < 5; n++){
		
		if(Mg[n]/15 >= 7){
		
			printf("\n\nParabens aluno voce foi aprovado:\n");
			printf("Matricula: %i\n", aluno[n].matricula);
			printf("Nome: %s", aluno[n].nome);
		
		}
		else{
		
			printf("\n\nQue pena aluno voce foi reprovado:\n");
			printf("Matricula: %i\n", aluno[n].matricula);
			printf("Nome: %s", aluno[n].nome);
		
		}
	
	}
	
		
getch();
}
