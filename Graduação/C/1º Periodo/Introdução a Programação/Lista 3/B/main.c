#include <stdio.h>

int main(){

    int numero, resto;
    
    for(numero = 1000; numero <= 2000; numero++){
        resto = numero%5;
        
        if(resto == 0){
            printf("%i ", numero);}
}
getch();
}
