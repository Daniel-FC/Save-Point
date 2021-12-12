#include <stdio.h>

main(){

float a, b, x, y=1, z=0;

printf("Informe um valor maior que 5:\n");
scanf("%f", &a);


if(a>5){
	for(b=1; b != a+1; b++){
		y = y*b;
		x = 1/y;
		z = z + x;
	}
    printf("\n%f", z+1);
}

else{
	printf("Valor invalido!! \nO programa sera fechado.");
	}

getch();
}
