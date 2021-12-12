#include <stdio.h>

main(){

int vetor[50], x=0, inter, y=0;


do{

	printf("[%i]Informe o valor: \n", x+1);
	scanf("%i", &vetor[x]);
	system("cls");
	
	x++;

}while(x != 50);

do{
	x=0;
	y++;
	
	do{
		
		
		if(vetor[x] == 0){
		
			inter = vetor[x+1];
			vetor[x+1] = vetor[x];
			vetor[x] = inter;
		
		}
		
		x++;
	
	}while(x != 50);
	
}while(y != 50);

x = 0;
printf("Vetor compactado: ");

do{

	printf("%i ", vetor[x]);
	
	x++;

}while(x != 50);

getch();
}
