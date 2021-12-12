#include <stdio.h>

main(){

float d, t, v;

printf("Informe a distancia percorrida (KM):\n");
scanf("%f", &d);
printf("Informe o tempo gasto (h):\n");
scanf("%f", &t);

v = d/t;

printf("\n------------------\n\n");
printf("Sua velocidade media foi: %fkm/h", v);

getch();
}
