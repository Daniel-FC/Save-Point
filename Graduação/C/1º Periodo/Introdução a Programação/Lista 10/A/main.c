#include <stdio.h>

int par(int n){

	if(n%2 == 0){
	
		n=1;
	
	}
	else{
	
		n=0;
	
	}
	return n;
	
}

int tres(int n){

	if(n%3 == 0){
	
		n=1;
	
	}
	else{
	
		n=0;
	
	}
	return n;
	
}

int cinco(int n){

	if(n%5 == 0){
	
		n=1;
	
	}
	else{
	
		n=0;
	
	}
	return n;
	
}

int primo(int n){

int contador=0, x;
         
	for(x=1; x <= n; x++){
	               
		if(n%x == 0){
		              
			contador++;     
		            
		}
                        
	}
   
	if(contador <= 2){
	       
		n=1;
	              
	}
	else{
	
		n=0;
	
	}
	return n;
	
}

int perfeito(int n){

int x, vetor[1000], k=0, inter=0;

	for(x=1; x < n; x++){
	               
		if(n%x == 0){
		              
			vetor[k] = x;
			k++;   
		            
		}
                        
	}
   
	for(x=0; x < k; x++){
	
		inter = inter + vetor[x];
	
	}
	
	if(inter == n){
	
		n = 1;
	
	}
	else{
	
		n = 0;
	
	}
	return n;
	
}

int main(){

	int n;
	
	printf("Informe o valor\n");
	scanf("%i", &n);
	system("cls");

	if(par(n) == 1){
	
		printf("E par\n");
	
	}
	else{
	
		printf("E impar\n");
	
	}
	
	if(tres(n) == 1){
	
		printf("E divisivil por 3\n");
	
	}
	else{
	
		printf("Nao e divisivil por 3\n");
	
	}
	
	if(cinco(n) == 1){
	
		printf("E divisivil por 5\n");
	
	}
	else{
	
		printf("Nao e divisivil por 5\n");
	
	}
	
	if(primo(n) == 1){
	
		printf("E primo\n");
	
	}
	else{
	
		printf("Nao e primo\n");
	
	}
	
	if(perfeito(n) == 1){
	
		printf("E perfeito\n");
	
	}
	else{
	
		printf("Nao e perfeito\n");
	
	}

getch();
}
