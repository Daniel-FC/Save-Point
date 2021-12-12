#include <stdio.h>

treco(int a, int b){

	int c;

	c = a*b;	
	return c;

}

main(){
       
	int M[6][6], V[36]={0}, linha, coluna, A, x=0;
	
	printf("Informe o valor do mutiplicador\n"); 
	scanf("%i", &A);
	system("cls");
	
	for(linha=0; linha < 6; linha++){
	           
	   for(coluna=0; coluna < 6; coluna++){
	           
	      printf("[%i,%i]Informe o valor:\n", linha+1, coluna+1);
	      scanf("%i", &M[linha][coluna]);
	      
	      V[x]= treco(M[linha][coluna], A);
	      x++;
	           
	   }            
	     
	   system("cls");
	           
	}
	
	for(x=0; x < 36; x++){
	
		printf("V%i=%i | ", x+1, V[x]);    
	           
	}   
	
getch();
}
