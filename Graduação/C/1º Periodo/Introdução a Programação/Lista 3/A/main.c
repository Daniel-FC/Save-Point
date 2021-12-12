#include <stdio.h>

int main(){

    int numero, par;

    for(numero = 0; numero <= 100; numero++){
        par = numero %2;
        
        if(par != 0)
            printf("%i ", numero);
    }

    getch();
}
