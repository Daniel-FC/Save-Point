#include <stdio.h>
#include <math.h>

#define tam 4 //Altere aqui a quantidade de interações

main(){
	
	int l, c;
	float x[tam+1]={-0.5,0,0.5,1,1.5}, y[tam+1], a1[tam+1], a2[tam+1], a3[tam+1];
	
	for(l=0; l<tam+1; l++)
		y[l]=pow(x[l], 3) + x[l] -10; //Altere aqui a esquação
		
	for(l=0; l<tam+1; l++){
		
		for(c=0, a1[l]=1, a2[l]=1, a3[l]=1; c<tam+1; c++){
			
			if(l!=c){
				
				a1[l]=a1[l]*y[l];
				a2[l]=a2[l]*(y[l]*(-x[c]));
				a3[l]=a3[l]*(x[l]-x[c]);
				
			}
			
		}
		
	}
	for(l=0; l<tam+1; l++)
		printf("Y[%i]= (%.2fX^%i + %.2f) / %.2f\n", l, a1[l], tam, a2[l], a3[l]);
		
	printf("\n*******************\n\n");
	
	for(l=0; l<tam+1; l++){
		
		a1[l]=a1[l]/a3[l];
		a2[l]=a2[l]/a3[l];
		
	}
	for(l=0; l<tam+1; l++)
		printf("Y[%i]= %.2fX^%i + %.2f\n", l, a1[l], tam, a2[l]);
		
	printf("\n*******************\n\n");
	
	for(l=1; l<tam+1; l++){
		
		a1[0]=a1[l]+a1[0];
		a2[0]=a2[l]+a2[0];
		
	}
	printf("Y= %.2fX^%i + %.2f\n", a1[0], tam, a2[0]);			

	
}
