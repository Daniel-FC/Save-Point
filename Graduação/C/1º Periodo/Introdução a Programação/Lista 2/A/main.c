#include <stdio.h>

main(){
       int idade;

       printf("Qual a sua idade? \n");
       scanf("%d", &idade);      
       
       printf("\n----------------------------------------------------\n");
       
       if (idade <= 7 && idade >= 5){
                 printf("\nVoc� pertence ao infantil A");
       }if (idade <= 10 && idade >= 8){
                 printf("\nVoc� pertence ao infantil B");
       }if (idade <= 13 && idade >= 11){
                 printf("\nVoc� pertence ao juvenil A");       
       }if (idade <= 17 && idade >= 14){
                 printf("\nVoc� pertence ao juvenil B");
       }if (idade >= 18){
                 printf("\nVoc� pertence ao adulto");          
                 }
       getch();
       
}
