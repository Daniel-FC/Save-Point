#include <stdio.h>

main(){

int vp[120], xp, ordenador=1;
int v1[30], x1=0, v2[30], x2=0, v3[30], x3=0, v4[30], x4=0;

for(xp=0; xp < 120; xp++){

	do{
	
		printf("[%i]Informe o valor\n", xp+1);
		scanf("%i", &vp[xp]);
		system("cls");
		
	}while(vp[xp] < -50 || vp[xp] > 150);
	
	switch(ordenador){
	
		case 1: v1[x1] = vp[xp]; x1++; ordenador++; break;
		case 2: v2[x2] = vp[xp]; x2++; ordenador++; break;
		case 3: v3[x3] = vp[xp]; x3++; ordenador++; break;
		case 4: v4[x4] = vp[xp]; x4++; ordenador=1; break;
	
	}
	
}

printf("V1=");
for(xp=0; xp < x1; xp++){

	printf(" %i", v1[xp]);
	
}

printf("\n\nV2=");
for(xp=0; xp < x2; xp++){

	printf(" %i", v2[xp]);
	
}

printf("\n\nV3=");
for(xp=0; xp < x3; xp++){

	printf(" %i", v3[xp]);
	
}

printf("\n\nV4=");
for(xp=0; xp < x4; xp++){

	printf(" %i", v4[xp]);
	
}

getch();
}
