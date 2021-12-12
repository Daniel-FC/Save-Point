#include <stdio.h>

main(){

int x, n, contador;

for(x=1; x < 100; x++){
         
	contador = 0;
         
	for(n=1; n <= x; n++){
	               
		if(x%n == 0){
		              
			contador++;     
		            
		}
                        
	}
   
	if(contador <= 2){
	       
		printf("%i ", x);
	              
	}         
               
}
           
getch();       
}
