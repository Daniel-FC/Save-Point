#include <stdio.h>

main(){

int primo[10], x=100, n, contador, y=0;
       
do{
           
	contador = 0;
           
	for(n=2; n < x; n++){
	                 
		if(x%n == 0){
		                        
			contador++;       
		                 
		}     
	                   
	}   
           
	if(contador == 0){
	                             
		primo[y] = x;
		printf("%i ", primo[y]);
		y++;             
	                 
	}
           
    x++;
           
}while(y < 10);
             
getch();       
}
