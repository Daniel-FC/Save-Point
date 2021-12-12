#include <stdio.h>

main(){

int a[10], b[10], vetor_a=0, vetor_b=0, c=0, rodar=0;

do{

	vetor_a++;
	vetor_b++;
	
	system("cls");
	printf("[%i] Informe o valor do vetor A:\n", vetor_a);
	scanf("%i", &a[vetor_a]);
	printf("[%i] Informe o valor do vetor B:\n", vetor_b);
	scanf("%i", &b[vetor_b]);

}while(vetor_a != 10 && vetor_b != 10);

system("cls");
vetor_a = 0;
vetor_b = 0;

for(c; c < 20; c++){
	
	if(c%2 == 0){
		vetor_a++;
		printf("%i, ", a[vetor_a]);
	}
	else{
		vetor_b++;
		printf("%i, ", b[vetor_b]);
	}

}

getch();
}
