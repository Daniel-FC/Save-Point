#include <stdio.h>

main(){

char nome[50];
float nota1, nota2, nota3, media;

printf("Infome o seu nome:\n");
scanf("%s", &nome);

printf("Informe sua primeira nota:\n");
scanf("%f", &nota1);
printf("Informe sua segunda nota:\n");
scanf("%f", &nota2);
printf("Informe sua terceira nota:\n");
scanf("%f", &nota3);

media = (nota1*4 + nota2*5 + nota3*6)/15;

if(media >= 7){
printf("\n----------------\n\n");
printf("%s, sua média foi: %.1f", nome, media);
}else{
printf("\n----------------\n\n");
printf("%s, você obteve média %.1f e não foi aprovado!", nome, media);
}
getch();
}
