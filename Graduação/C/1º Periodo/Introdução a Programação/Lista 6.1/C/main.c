#include <stdio.h>

main(){

int n[15], add=0, x=20, y=0, p[15], adc=0, qtd;

do{

	add++;
	
	printf("[%i] Informe o valor\n", add);
	scanf("%i", &n[add]);
	
	if(x == n[add]){
		adc++;
		p[adc] = add;
		y = 1;
	}
	
}while(add != 15);

system("cls");

if(y == 1){
	
	qtd = adc;
	adc = 1;
	
	printf("O numero magico foi encontrado no's vetor'es");
	
	for(adc; adc != qtd+1; adc++){
		printf(" %i", p[adc]);
	}
	
}
else{
	printf("O numero magico não foi encontrado em nenhuma posição");
}

getch();
}
