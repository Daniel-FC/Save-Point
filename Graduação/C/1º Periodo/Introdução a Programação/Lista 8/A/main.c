#include <stdio.h>

struct DadosAlunos{

	int media;
	int idade;

};

main(){
	
	struct DadosAlunos aluno;

	
		printf("Informe a idade do aluno\n");
		scanf("%i", &aluno.idade);
		printf("Informe a media do aluno\n");
		scanf("%i", &aluno.media);
		
		system("cls");

		printf("Idade do aluno: %i\n", aluno.idade);
		printf("Media do aluno: %i", aluno.media);

getch();
}
