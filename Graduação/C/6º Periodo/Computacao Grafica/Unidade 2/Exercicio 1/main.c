#include <stdio.h>
#include <stdlib.h>

#define L 4
#define C 3

int main (){

	int escolha, l, c;
	float x, y, z, x1, y1, z1;
	//FIGURA: QUADRADO 2D
	float matriz[L][C];
	
	//PONTO 1: ESQUERDA CIMA
	matriz[0][0]=0;  //Coordenada X
	matriz[0][1]=20; //Coordenada Y
	matriz[0][2]=10; //Coordenada Z

	//PONTO 2: DIREITA CIMA
	matriz[1][0]=20; //Coordenada X
	matriz[1][1]=20; //Coordenada Y
	matriz[1][2]=10; //Coordenada Z	

	//PONTO 3: DIREITA BAIXO
	matriz[2][0]=20; //Coordenada X
	matriz[2][1]=0;  //Coordenada Y
	matriz[2][2]=10; //Coordenada Z	

	//PONTO 4: ESQUERDA BAIXO
	matriz[3][0]=0;  //Coordenada X
	matriz[3][1]=0;  //Coordenada Y
	matriz[3][2]=10; //Coordenada Z	

	printf("Digite 1 para ESCALA\n");
	printf("Digite 2 para TRANSLACAO\n");
	printf("Digite 3 para ROTACAO\n");
	scanf("%i", &escolha);
	
	system("cls");
	
	if(escolha==1){
	
		printf("Digite o multiplicador de X: ");
		scanf("%f", &x);		
		printf("Digite o multiplicador de Y: ");
		scanf("%f", &y);
		printf("Digite o multiplicador de Z: ");
		scanf("%f", &z);
		
	}
	if(escolha==2){
	
		printf("Digite o deslocamento no X: ");
		scanf("%f", &x);		
		printf("Digite o deslocamento no Y: ");
		scanf("%f", &y);
		printf("Digite o deslocamento no Z: ");
		scanf("%f", &z);
							
	}
	if(escolha==3){
	
		printf("Digite o girar em torno de X: ");
		scanf("%f", &x);		
		printf("Digite o girar em torno de Y: ");
		scanf("%f", &y);
		printf("Digite o girar em torno de Z: ");
		scanf("%f", &z);		
					
	}

	system("cls");

	printf("COORDENADAS INICIAIS\n");
	for(l=0; l<L; l++){
		
		printf("Ponto%i:", l+1);
		for(c=0; c<C; c++)		
			printf(" [%.2f]", matriz[l][c]);
		printf("\n");
		
	}
	printf("--------------------------------\n\n");
	
	switch(escolha){
		
		case 1:
			
			for(l=0; l<L; l++)
				matriz[l][0]*=x;

			for(l=0; l<L; l++)
				matriz[l][1]*=y;

			for(l=0; l<L; l++)
				matriz[l][2]*=z;
			break;
		
		case 2:
			for(l=0; l<L; l++)
				matriz[l][0]+=x;

			for(l=0; l<L; l++)
				matriz[l][1]+=y;

			for(l=0; l<L; l++)
				matriz[l][2]+=z;			
			break;		
		
		case 3:
			while(x>360)
				x-=360;
			while(y>360)
				y-=360;
			while(z>360)
				z-=360;

			//Girar em torno de X	
			if(x>180){
				
				x1=matriz[0][1];
				matriz[0][1]=matriz[3][1];
				matriz[3][1]=x1;				

				x1=matriz[0][2];
				matriz[0][2]=matriz[3][2];
				matriz[3][2]=x1;

				x1=matriz[1][1];
				matriz[1][1]=matriz[2][1];
				matriz[2][1]=x1;

				x1=matriz[1][2];
				matriz[1][2]=matriz[2][2];
				matriz[2][2]=x1;
				x-=180;					
				
			}
			
			y1=matriz[0][1]-matriz[3][1];
			if(y1<0)
				y1*=-1;
			
			for(l=0; l<L; l++){
				
				if(l<2)
					matriz[l][1]-=y1/180*x;
				else
					matriz[l][1]+=y1/180*x;
				
			}
			
			z1=y1/2;
			if(x>90)
				x=180-x;
					
			for(l=0; l<L; l++){
				
				if(l<2)
					matriz[l][2]+=z1/90*x;	
				else
					matriz[l][2]-=z1/90*x;
					
			}
			
			
			//Girar em torno de Y
			if(y>180){
				
				y1=matriz[0][0];
				matriz[0][0]=matriz[1][0];
				matriz[1][0]=y1;				

				y1=matriz[0][2];
				matriz[0][2]=matriz[1][2];
				matriz[1][2]=y1;

				y1=matriz[2][0];
				matriz[2][0]=matriz[3][0];
				matriz[3][0]=y1;

				y1=matriz[2][2];
				matriz[2][2]=matriz[3][2];
				matriz[3][2]=y1;
				y-=180;					
				
			}

			x1=matriz[1][0]-matriz[0][0];
			if(x1<0)
				x1*=-1;
				
			for(l=0; l<L; l++){
				
				if(l==0 || l==L-1)
					matriz[l][0]+=x1/180*y;
				else
					matriz[l][0]-=x1/180*y;
				
			}
					
			z1=x1/2;
			if(y>90)
				y=180-y;
					
			for(l=0; l<L; l++){
				
				if(l==0 || l==L-1)
					matriz[l][2]+=z1/90*y;
				else
					matriz[l][2]-=z1/90*y;
					
			}			


			//Girar em torno de Z
			//FALTOU GIRAR EM TORNO DO Z PQ DEU PREGUIÇA DE PENSAR, MAS A LOGICA É ESSA?
		break;		
		
	}
	
	for(l=0; l<L; l++){
		
		printf("Ponto%i:", l+1);
		for(c=0; c<C; c++){	
			
			printf(" [%.2f]", matriz[l][c]);
		
		}
		printf("\n");
		
	}
	
}
