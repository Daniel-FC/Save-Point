#include <stdio.h>

treco(int a, int b){

	do{
	
	a = a - b; 
	
	}while(a > 0);
	
	if(a == 0){

		a = 1;
	
	}
	else{
	
		a = 0;
	
	}
	return(a);

}

main(){

int n1, n2;

printf("Informe o divisor\n");
scanf("%i", &n1);
printf("Informe o cociente\n");
scanf("%i", &n2);

	if(treco(n1, n2) == 1){

		printf("\nE divisor\n");
	
	}
	else{
	
		printf("\nNao e divisor\n");
	
	}

getch();
}
