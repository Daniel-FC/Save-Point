#include <stdio.h>

main(){

int valor, cinquenta, vinte, dez, cinco, dois, um;

printf("Informe o valor do saque:\n");
scanf("%i", &valor);

cinquenta = (valor)/50;
vinte = (valor - (cinquenta*50))/20;
dez = (valor - (cinquenta*50 + vinte*20))/10;
cinco = (valor - (cinquenta*50 + vinte*20 + dez*10))/5;
dois = (valor - (cinquenta*50 + vinte*20 + dez*10 + cinco*5))/2;
um = (valor - (cinquenta*50 + vinte*20 + dez*10 + cinco*5 + dois*2))/1;

if(cinquenta > 0){
printf("\nNotas de cinquenta: %i", cinquenta);}
if(vinte > 0){
printf("\nNotas de vinte: %i", vinte);}
if(dez > 0){
printf("\nNotas de dez: %i", dez);}
if(cinco > 0){
printf("\nNotas de cinco: %i", cinco);}
if(dois > 0){
printf("\nNotas de dois: %i", dois);}
if(um > 0){
printf("\nNotas de um: %i", um);}

getch();
}
