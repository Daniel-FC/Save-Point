#include <stdio.h>

main(){

int matriz[6][6]={{0,400,300,250,150,100},
                  {400,0,100,250,300,350},
                  {300,100,0,200,250,280},
                  {250,250,200,0,300,380},
				  {150,300,250,300,0,50},
				  {100,350,280,380,50,0}};
				  
int v[5], add;

printf("Natal-      1\nMossoro-    2\nAssu-       3\nCaico-      4\nMacaiba-    5\nParnamirim- 6\n\n");
printf("Informe a cidade inicial\n");
scanf("%i", &v[0]);

for(add=1; add < 6; add++){

	system("cls");
	printf("Natal-      0\nMossoro-    1\nAssu-       2\nCaico-      3\nMacaiba-    4\nParnamirim- 5\n\n");
	printf("[%i]Infome a sua rota:\n", add);
	scanf("%i", &v[add]);

}

system("cls");
printf("A distância percorrida: %i", matriz[ v[0]-1 ][ v[1]-1 ] + matriz[ v[1]-1 ][ v[2]-1 ] + matriz[ v[2]-1 ][ v[3]-1 ] + matriz[ v[3]-1 ][ v[4]-1 ] + matriz[ v[4]-1 ][ v[5]-1 ]);

getch();
}
