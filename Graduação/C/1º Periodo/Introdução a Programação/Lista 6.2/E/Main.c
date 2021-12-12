#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int mat[5][3],vet[5],n=0,x=1,r=0;
	
	for(n=0;n<5;n++){
		printf("\n digite o gabarito");
		scanf("%d",&vet[n]);
	}
	for(x=1;x<=3;x++){
		for(n=0;n<5;n++){
			printf("digite sua aposta canditado %d\n",x);
			scanf("%d", &mat[n][x]);
		}	
	}
	for(x=1;x<=3;x++){
		for(n=0;n<5;n++){
			if(mat[n][x] == vet[n]){
				r=r+1;
				if(r==5){
					printf("jogador %d e um ganhador\n",x);
					r=0;
				}	
			}	
		}	
	}
		printf("PARABENS");
			getch();
}
