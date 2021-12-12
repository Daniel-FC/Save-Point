#include <stdio.h>

#define tam 30
#define lin 12
#define col 7

main(){
	
	FILE *p_cod;
	int matriz[lin][col], pronta[lin*2][col-1], pt[lin*2][col-1], mat[lin][col-1], fim[5], ini=1, x, y, w, l, c, z, zz, xx=0, op, contF=0, lamb;
	char aux[tam];
	
	scanf("%i", &lamb);
	system("cls");
	//Zerando matrizes e vetores
	for(l=0; l<5; l++){fim[l]=0;}
	for(l=0; l<lin; l++){for(c=0; c<col; c++){matriz[l][c]=0;}}
	for(l=0; l<lin*2; l++){for(c=0; c<col-1; c++){pt[l][c]=0;pronta[l][c]=0;}}
	for(l=0; l<lin; l++){for(c=0; c<col-1; c++){mat[l][c]=0;}}	
	for(l=0, c=1; c<lin; l=l+2, c++){matriz[l][0]=c;matriz[l+1][0]=c;if(c==6){matriz[l][6]=6;matriz[l+1][6]=6;}}
	//Leitura do txt e converção Letra:Numero
	p_cod=fopen("AFN.txt", "r");
	for(x=0; fgets(aux, tam, p_cod)!=NULL; x++){
		//Inicial	
		if(x==0){
			
			for(c=9; aux[c+1]!='\0'; c++){
			
				if(aux[c]=='A'){ini=1;}
				if(aux[c]=='B'){ini=2;}
				if(aux[c]=='C'){ini=3;}
				if(aux[c]=='D'){ini=4;}
				if(aux[c]=='E'){ini=5;}
				if(aux[c]=='#'){ini=6;}
			
			}		
	
		}
		//Final	
		if(x==1){
			for(l=0, c=7; aux[c+1]!='\0'; l++, c++){
				
				if(aux[c]=='A'){fim[l]=1;}
				if(aux[c]=='B'){fim[l]=2;}
				if(aux[c]=='C'){fim[l]=3;}
				if(aux[c]=='D'){fim[l]=4;}
				if(aux[c]=='E'){fim[l]=5;}
				if(aux[c]=='#'){fim[l]=6;}				
				contF++;
				
			}
	
		}
		//Estados		
		if(x>=2){
		
			for(c=5; aux[c+1]!='\0'; c++){
			
				if(aux[c]=='A'){matriz[x-2][1]=1;}
				if(aux[c]=='B'){matriz[x-2][2]=2;}
				if(aux[c]=='C'){matriz[x-2][3]=3;}
				if(aux[c]=='D'){matriz[x-2][4]=4;}
				if(aux[c]=='E'){matriz[x-2][5]=5;}
				if(aux[c]=='#'){matriz[x-2][6]=6;}
				
			}			
		
		}

	}
	//Codigo	
	mat[0][ini-1]=ini;
	if(lamb==1){
		
		for(l=0; l<lin; l++){
			
			if(matriz[l][0]==ini)
				x=l;
			
			for(c=1; c<col; c++){	

				if(matriz[x-1][c]!=0)
					mat[0][c-1]=matriz[x-1][c];
				
			}
			
		}
		
	}
	for(z=0, x=1, zz=0; z<lin; z++, zz=zz+2){
		//Nome do estado (pt)		
		for(c=0; c<col-1; c++){
			
			for(l=0; l<lin; l++){
				
				if(matriz[l][0]==pt[zz][c])
					y=l-1;
			
			}
			for(w=0; w<col-1; w++){
				
				if(pt[zz][c]!=0 && matriz[y][w+1]!=0)
					pronta[zz][w]=matriz[y][w+1];
				if(pt[zz+1][c]!=0 && matriz[y+1][w+1]!=0)
					pronta[zz+1][w]=matriz[y+1][w+1];			
				
			}
										
		}
		//O que o estado reconhece (pronta)
		for(w=zz; w<zz+2; w++){
		
			for(l=0, op=1; l<lin; l++){
					
				for(c=0, y=0; c<col-2; c++){
						
					if(pronta[w][c]==mat[l][c])
						y++;
						
				}
				if(y==5)
					op=0;
					
			}	
			if(op!=0){
				
				for(c=0; c<col-1; c++)
					mat[x][c]=pronta[w][c];
				x++;
				
			}
			if(op==0 && pronta[w][5]==6 && xx==0){
				
				for(c=0; c<col-1; c++)
					mat[x][c]=pronta[w][c];
				x++;
				xx=1;
				
			}		
		}
		//Ordenação do vetor (mat)
		for(l=0; l<lin*2; l++){
			
			for(c=0; c<col-1; c++){
				
				if(l==zz+2)
					pt[l][c]=mat[z][c];
	
				if(l==zz+3)
					pt[l][c]=mat[z][c];
					
			}
		
		}		
	
	}
	//Converção Numero:Letra
	for(l=0; l<lin*2; l++){
		
		for(c=0, op=0, y=0, w=0; c<col-1; c++){
			
			for(x=0; x<contF; x++){
				
				if(pt[l][c]==fim[x])
					w=1;
				
			}
			
			if(pt[l][c]==1){printf("A");op=1;y=1;}
			if(pt[l][c]==2){printf("B");op=1;y=1;}
			if(pt[l][c]==3){printf("C");op=1;y=1;}
			if(pt[l][c]==4){printf("D");op=1;y=1;}
			if(pt[l][c]==5){printf("E");op=1;y=1;}
			if(pt[l][c]==6 && y==0){printf("#");op=1;}
			
		}
		if(op==1)
			printf(": \t");
		for(c=0, y=0; c<col-1; c++){
			
			if(pronta[l][c]==1){printf("A");y=1;}
			if(pronta[l][c]==2){printf("B");y=1;}
			if(pronta[l][c]==3){printf("C");y=1;}
			if(pronta[l][c]==4){printf("D");y=1;}
			if(pronta[l][c]==5){printf("E");y=1;}
			if(pronta[l][c]==6 && y==0){printf("#");}
			
		}
		if(w==1)
			printf("\t(FINAL)");
		if(op==1)
			printf("\n");
		
	}
		
}
