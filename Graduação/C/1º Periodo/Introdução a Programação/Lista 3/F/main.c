#include <stdio.h>

main(){

int p, v;
    
printf("Informe o valor:\n");
scanf("%i", &p);

v = p+20;
    
for(p; p!=v; p++){
printf("%i, ", p+1);
}
getch();
}
