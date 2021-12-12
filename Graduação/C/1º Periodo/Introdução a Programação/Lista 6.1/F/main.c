#include <stdio.h>

main(){

int A[10]={10, 20, 30, 40, 50, 60, 70, 80, 90, 100}, B[10]={9, 8, 7, 6, 5, 4, 3, 2, 1, 0}, rodarA=0, rodarB=0;

printf("Vetor A: ");

do{

	printf("%i ", A[rodarA]);
	rodarA++;

}while(rodarA != 10);

printf("\nVetor B: ");

do{

	printf(" %i ", B[rodarB]);
	rodarB++;

}while(rodarB != 10);

printf("\n\nVetor C: ");
rodarA = 0;

do{

	printf("%i ", A[rodarA]);
	rodarA++;

}while(rodarA != 9);

printf("%i", B[0]);

getch();
}
