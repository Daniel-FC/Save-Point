#include <stdio.h>

soma(int n){

	int x, s=0;
	
	for(x=0; x <= n; x++){
	
		s = s + x;
	
	}
	return(s);

}

main(){

	int n;
	
	printf("Informe o valor\n");
	scanf("%i", &n);
	
	printf("\nSomatorio dos n primeiros numeros: %i", soma(n));
	
getch();
}
