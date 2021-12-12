#include <stdio.h>

treco(int i){

	if(i < 5){
		i = 0;
	}
	if(i >= 5 && i <= 7){
		i = 1;
	}
	if(i >= 8 && i <= 10){
		i = 2;
	}
	if(i >= 11 && i <= 13){
		i = 3;
	}
	if(i >= 14 && i <= 17){
		i = 4;
	}
	if(i >= 18){
		i = 5;
	}
	return i;

}

main(){

int idade;

printf("Informe a idade do nadador\n");
scanf("%i", &idade);

if(treco(idade) == 0){
	printf("\nValor invalido");
}
if(treco(idade) == 1){
	printf("\nInfantil A");
}
if(treco(idade) == 2){
	printf("\nInfantil B");
}
if(treco(idade) == 3){
	printf("\nJuvenil A");
}
if(treco(idade) == 4){
	printf("\nInfantil B");
}
if(treco(idade) == 5){
	printf("\nAdulto");
}

getch();
}
