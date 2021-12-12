#include <stdio.h>

struct DadosAlunos{

	int media;
	int idade;

};

main(){
	
	int n;

	struct DadosAlunos aluno[10];
	
	for(n=0; n < 10; n++){
	
		printf("Informe a idade do aluno %i\n", n+1);
		scanf("%i", &aluno[n].idade);
		printf("Informe a media do aluno %i\n", n+1);
		scanf("%i", &aluno[n].media);
		
		system("cls");
	
	}
	
	for(n=0; n < 10; n++){
	
		printf("Idade do aluno %i: %i\n", n+1, aluno[n].idade);
		printf("Media do aluno %i: %i\n\n", n+1, aluno[n].media);
	
	}

getch();
}
