#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "pdiAlgorithm.h"
#include <windows.h>
#include <math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int fase=0;
float pontuacao=0;
float angle=0.0;
float lx=0.0f, ly=0.0f, lz=-1.0f;
float x=0.0f, y=5.0f, z=20.0f;
float tx, ty, tz;
float v1=100, v2=100, v3=100, v4=100;
GLuint tex;

void changeSize(int w, int h){

	if (h == 0){h = 1;}

	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glutSolidTeapot(50.0f);
	
}

void obstaculo1(int x1, int x2, int y1, int y2, int z1, int z2, float c1, float c2, float c3){
	
	glColor3f(c1, c2, c3);
	glBegin(GL_QUADS);
		glVertex3f(x1, y1, z1);
		glVertex3f(x1, y2, z2);
		glVertex3f(x2, y2, z2);
		glVertex3f(x2, y1, z1);
	glEnd();

}

void obstaculo2(int x1, int x2, int y1, int y2, int z1, int z2, float c1, float c2, float c3){
	
	glColor3f(c1, c2, c3);
	glBegin(GL_QUADS);
		glVertex3f(x1, y1, z1);
		glVertex3f(x1, y2, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x2, y1, z2);
	glEnd();

}

void tela1(int x1, int x2, int y1, int y2, int z1, int z2, int num){

	textura(num);
    glBindTexture(GL_TEXTURE_2D, tex);
    glEnable(GL_TEXTURE_2D);	
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
		glTexCoord2i(0, 0); glVertex3f(x1, y1, z1);
		glTexCoord2i(0, 1); glVertex3f(x1, y2, z2);
		glTexCoord2i(1, 1); glVertex3f(x2, y2, z2);
		glTexCoord2i(1, 0); glVertex3f(x2, y1, z1);
	glEnd();

}

void tela2(int x1, int x2, int y1, int y2, int z1, int z2, int num){

	textura(num);
    glBindTexture(GL_TEXTURE_2D, tex);
    glEnable(GL_TEXTURE_2D);	
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
		glTexCoord2i(0, 0); glVertex3f(x1, y1, z1);
		glTexCoord2i(0, 1); glVertex3f(x1, y2, z1);
		glTexCoord2i(1, 1); glVertex3f(x2, y2, z2);
		glTexCoord2i(1, 0); glVertex3f(x2, y1, z2);
	glEnd();

}

void textura(int num){

	int l, c, i;
	unsigned char temp[400][400];
	glClearColor(1.0, 1.0, 1.0, 0.0);
	
	for(l=0; l<400; l++){
		for(c=0; c<400; c++){
			
			if(num<5)
				temp[l][c]=0;	
			if(num==5)
				temp[l][c]=texDat5[l][c];
			if(num==6)
				temp[l][c]=texDat6[l][c];				
			if(num==7)
				temp[l][c]=texDat7[l][c];				
	
			if(num==1 && fase>1)
				temp[l][c]=texDat1[l][c];
			if(num==2 && fase>3)
				temp[l][c]=texDat2[l][c];
			if(num==3 && fase>5)
				temp[l][c]=texDat3[l][c];				
			if(num==4 && fase>7)
				temp[l][c]=texDat4[l][c];	
	
			i = (rand()%100);
			if(num==1 && fase==1){
				temp[l][c]=texDat1[l][c];
				if(i<=v1){
					i = (rand()%2);
					if(i==0)
						temp[l][c]=0;
					if(i==1)
						temp[l][c]=255;
				}					
			}
			
			if(num==2 && fase==3){
				temp[l][c]=texDat2[l][c];
				if(i<=v2){
					i = (rand()%2);
					if(i==0)
						temp[l][c]=0;
					if(i==1)
						temp[l][c]=255;
				}					
			}	
			
			if(num==3 && fase==5){
				temp[l][c]=texDat3[l][c];
				if(i<=v3){
					i = (rand()%2);
					if(i==0)
						temp[l][c]=0;
					if(i==1)
						temp[l][c]=255;
				}					
			}			
			
			if(num==4 && fase==7){
				temp[l][c]=texDat4[l][c];
				if(i<=v4){
					i = (rand()%2);
					if(i==0)
						temp[l][c]=0;
					if(i==1)
						temp[l][c]=255;
				}					
			}				
											
		}	
	}
	if(fase==1)
		v1 = v1 -0.02;
	if(fase==3)
		v2 = v2 -0.02;
	if(fase==5)
		v3 = v3 -0.02;
	if(fase==7)
		v4 = v4 -0.02;
	
    glBindTexture(GL_TEXTURE_2D, tex);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, 400, 400, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, temp);
    
}

void renderScene(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x, y, z, x+lx, y+ly, z+lz, 0.0f, 1.0f, 0.0f); //Camera
	
	tela1( -40,  -20, 5, 25,  -19, -19, 1); //Tela 1
	tela1( -70,  -50, 5, 25,  -19, -19, 2); //Tela 2
	tela1(-100,  -80, 5, 25,  -19, -19, 3); //Tela 3
	tela1(-130, -110, 5, 25,  -19, -19, 4); //Tela 4
	
	tela1( -40,   10,  0,  0, -20, 30, 5); //Piso
	tela1( -90,  -40,  0,  0, -20, 30, 5); //Piso
	tela1(-140,  -90,  0,  0, -20, 30, 5); //Piso
	
	tela1( -40,   10, 30, 30, -20, 30, 6); //Teto
	tela1( -90,  -40, 30, 30, -20, 30, 6); //Teto
	tela1(-140,  -90, 30, 30, -20, 30, 6); //Teto
	
	tela1(  -20,   10, 0, 30, -20, -20, 7); //Parede_Frente
	tela1(  -50,  -20, 0, 30, -20, -20, 7); //Parede_Frente
	tela1(  -80,  -50, 0, 30, -20, -20, 7); //Parede_Frente
	tela1( -110,  -80, 0, 30, -20, -20, 7); //Parede_Frente
	tela1( -140, -110, 0, 30, -20, -20, 7); //Parede_Frente

	tela1(  -20,  10, 0, 30, 30, 30, 7); //Parede_Tras
	tela1(  -50, -20, 0, 30, 30, 30, 7); //Parede_Tras
	tela1(  -80, -50, 0, 30, 30, 30, 7); //Parede_Tras
	tela1( -110, -80, 0, 30, 30, 30, 7); //Parede_Tras
	tela1( -140, -80, 0, 30, 30, 30, 7); //Parede_Tras
	
	tela2(  10,   10, 0, 30, -20, 30, 7); //Parede_Direita
	
	tela2(-140, -140,  0, 30, -20,  0, 7); //Parede_Esquerda
	tela2(-140, -140,  0, 30,  10, 30, 7); //Parede_Esquerda
	tela2(-140, -140, 20, 30,   0, 10, 7); //Parede_Esquerda
	
	obstaculo1(-160, -140,  0,  0, -20, 30, 1-((0.6)/210)*pontuacao, 0.3+((0.7)/210)*pontuacao, 0.0); //Piso_Elevador
	obstaculo1(-160, -140, 30, 30, -20, 30, 1-((0.6)/210)*pontuacao, 0.3+((0.7)/210)*pontuacao, 0.0); //Teto_Elevador
	obstaculo1(-160, -140, 0, 30, -20, -20, 1-((0.6)/210)*pontuacao, 0.3+((0.7)/210)*pontuacao, 0.3+((0.1)/210)*pontuacao); //Parede_Frente_Elevador
	obstaculo1(-160, -140, 0, 30,  30,  30, 1-((0.6)/210)*pontuacao, 0.3+((0.7)/210)*pontuacao, 0.3+((0.1)/210)*pontuacao); //Parede_Tras_Elevador
	obstaculo2(-160, -160, 0, 30, -20,  30, 1-((1.0)/210)*pontuacao, 0.3+((0.7)/210)*pontuacao, 0.3+((0.1)/210)*pontuacao); //Parede_Esquerda_Elevador	
	
	if(fase==0)
		obstaculo1( -40,  -20, 1, 1, 0, 10, 0.0, 0.0, 1.0); //Area1
	if(fase==2)
		obstaculo1( -70,  -50, 1, 1, 0, 10, 0.0, 0.0, 1.0); //Area2
	if(fase==4)	
		obstaculo1(-100,  -80, 1, 1, 0, 10, 0.0, 0.0, 1.0); //Area3
	if(fase==6)
		obstaculo1(-130, -110, 1, 1, 0, 10, 0.0, 0.0, 1.0); //Area4
		
	glutSwapBuffers();
	
}

int solido(float tx, float ty, float tz){

	int ver=1;
	
	if(((tx<-161 || tx>  11) || (tz<-21 || tz>-19) || ty>30) && ver!=-1){ver=1;} else{ver=-1;}
	if(((tx<-161 || tx>  11) || (tz< 29 || tz> 31) || ty>30) && ver!=-1){ver=1;} else{ver=-1;}
	if(((tx<   9 || tx>  11) || (tz<-21 || tz> 31) || ty>30) && ver!=-1){ver=1;} else{ver=-1;}
	if(((tx<-161 || tx>-159) || (tz<-21 || tz> 31) || ty>30) && ver!=-1){ver=1;} else{ver=-1;}
	
	if(((tx<-141 || tx>-139) || (tz<-21 || tz>  1) || ty>30) && ver!=-1){ver=1;} else{ver=-1;}
	if(((tx<-141 || tx>-139) || (tz<  9 || tz> 31) || ty>30) && ver!=-1){ver=1;} else{ver=-1;}
	
	if(((x>= -40 && x<= -20) && (y<=30) && (z>=0 && z<=10)) && fase==0){x= -30; z=29; fase++;}
	if(((x>= -70 && x<= -50) && (y<=30) && (z>=0 && z<=10)) && fase==2){x= -60; z=29; fase++;}
	if(((x>=-100 && x<= -80) && (y<=30) && (z>=0 && z<=10)) && fase==4){x= -90; z=29; fase++;}
	if(((x>=-130 && x<=-110) && (y<=30) && (z>=0 && z<=10)) && fase==6){x=-120; z=29; fase++;}
	
	if(((x>=-160 && x<=-150) && (pontuacao>=210) && (z>=-20 && z<=30))){y=35;}
	
	return ver;

}

void processSpecialKeys(int key, int xx, int yy){

	float fraction = 0.35f;

	switch (key){
		
		case GLUT_KEY_LEFT:
			angle -= 0.05f;
			lx = sin(angle);
			lz = -cos(angle);
		break;
		
		case GLUT_KEY_RIGHT:
			angle += 0.05f;
			lx = sin(angle);
			lz = -cos(angle);
		break;
		
		case GLUT_KEY_UP:
			tx = x + (lx * fraction * 2);
			ty = y;
			tz = z + (lz * fraction * 2);	
			if(solido(tx, ty, tz)==1){
				x += lx * fraction * 2;
				z += lz * fraction * 2;	
			}
		break;
			
		case GLUT_KEY_DOWN:
			tx = x - (lx * fraction * 2);
			ty = y;
			tz = z - (lz * fraction * 2);
			if(solido(tx, ty, tz)==1){
				x -= lx * fraction * 2;
				z -= lz * fraction * 2;
			}
		break;
			
	}
	
}

void GerenciaMouse(int button, int state, int x, int y){
	if (button == GLUT_RIGHT_BUTTON)
    	if (state == GLUT_DOWN)
        	CriaMenu();
        	
    glutPostRedisplay();
}

void MenuPrincipal(int op){
	
	int veri=0;
	if( ((fase==1 && op==3) || (fase==3 && op==1) || (fase==5 && op==2) || (fase==7 && op==4)) && veri==0 ){
		
		if( (fase==1 && (v1<=100 && v1>90)) || (fase==3 && (v2<=100 && v2>90)) || (fase==5 && (v3<=100 && v3>90)) || (fase==7 && (v4<=100 && v4>90)) )
			pontuacao += 100;
		if( (fase==1 && (v1<=90 && v1>70)) || (fase==3 && (v2<=90 && v2>70)) || (fase==5 && (v3<=90 && v3>70)) || (fase==7 && (v4<=90 && v4>70)) ){
			if(fase==1)
				pontuacao += (v1*1.5)-36.5;	
			if(fase==3)
				pontuacao += (v2*1.5)-36.5;				
			if(fase==5)
				pontuacao += (v3*1.5)-36.5;	
			if(fase==7)
				pontuacao += (v4*1.5)-36.5;				
		}		
		if( (fase==1 && (v1<=70 && v1>50)) || (fase==3 && (v2<=70 && v2>50)) || (fase==5 && (v3<=70 && v3>50)) || (fase==7 && (v4<=70 && v4>50)) ){
			if(fase==1)
				pontuacao += (v1*2)-72;	
			if(fase==3)
				pontuacao += (v2*2)-72;				
			if(fase==5)
				pontuacao += (v3*2)-72;
			if(fase==7)
				pontuacao += (v4*2)-72;				
		}		
		if( (fase==1 && (v1<=50 && v1>40)) || (fase==3 && (v2<=50 && v2>40)) || (fase==5 && (v3<=50 && v3>40)) || (fase==7 && (v4<=50 && v4>40)) ){
			if(fase==1)
				pontuacao += (v1*1.5)-v1+4.5;
			if(fase==3)
				pontuacao += (v2*1.5)-v2+4.5;			
			if(fase==5)
				pontuacao += (v3*1.5)-v3+4.5;
			if(fase==7)
				pontuacao += (v4*1.5)-v4+4.5;						
		}	
		if( (fase==1 && (v1<=40 && v1>20)) || (fase==3 && (v2<=40 && v2>20)) || (fase==5 && (v3<=40 && v3>20)) || (fase==7 && (v4<=40 && v4>20)) )
			pontuacao += 25;
		if( (fase==1 && (v1<=20 && v1>10)) || (fase==3 && (v2<=20 && v2>10)) || (fase==5 && (v3<=20 && v3>10)) || (fase==7 && (v4<=20 && v4>10)) ){
			if(fase==1)
				pontuacao += (v1*2)-15;	
			if(fase==3)
				pontuacao += (v2*2)-15;				
			if(fase==5)
				pontuacao += (v3*2)-15;
			if(fase==7)
				pontuacao += (v4*2)-15;				
		}		
		if( (fase==1 && (v1<=10)) || (fase==3 && (v2<=10)) || (fase==5 && (v3<=10)) || (fase==7 && (v4<=10)) )
			pontuacao += 5;			
			
		printf("Certo! %f\n", pontuacao);
		veri++;
		fase++;	
	}
	if( ((fase==1 && (op==0 || op==1 || op==2 || op==4)) || (fase==3 && (op==0 || op==2 || op==3 || op==4)) || (fase==5 && (op==0 || op==1 || op==3 || op==4)) || (fase==7 && (op==0 || op==1 || op==2 || op==3))) && veri==0 ){

		if( (fase==1 && (v1<=100 && v1>90)) || (fase==3 && (v2<=100 && v2>90)) || (fase==5 && (v3<=100 && v3>90)) || (fase==7 && (v4<=100 && v4>90)) )
			pontuacao -= 100;
		if( (fase==1 && (v1<=90 && v1>70)) || (fase==3 && (v2<=90 && v2>70)) || (fase==5 && (v3<=90 && v3>70)) || (fase==7 && (v4<=90 && v4>70)) ){
			if(fase==1)
				pontuacao -= (v1*5)-350;
			if(fase==3)
				pontuacao -= (v2*5)-350;		
			if(fase==5)
				pontuacao -= (v3*5)-350;
			if(fase==7)
				pontuacao -= (v4*5)-350;			
		}
		if( (fase==1 && (v1<=70 && v1>30)) || (fase==3 && (v2<=70 && v2>50)) || (fase==5 && (v3<=70 && v3>50)) || (fase==7 && (v4<=70 && v4>50)) ){
				pontuacao -= 0;
		}
		if( (fase==1 && (v1<=30)) || (fase==3 && (v2<=20)) || (fase==5 && (v3<=20)) || (fase==7 && (v4<=20)) ){
			if(fase==1)
				pontuacao += (v1-30-1)*3;
			if(fase==3)
				pontuacao += (v2-30-1)*3;			
			if(fase==5)
				pontuacao += (v3-30-1)*3;
			if(fase==7)
				pontuacao += (v4-30-1)*3;						
		}

		printf("Errado! %f\n", pontuacao);
		veri++;
		fase++;	
	}

    glutPostRedisplay();
}

void CriaMenu(){
    int menu;

	menu = glutCreateMenu(MenuPrincipal);
	glutAddMenuEntry("Mona Lisa", 0);
    glutAddMenuEntry("Lena", 1);
    glutAddMenuEntry("Coruja", 2);
    glutAddMenuEntry("Calopsita", 0);
    glutAddMenuEntry("Nyan Cat", 3);
    glutAddMenuEntry("Xuxa", 0);
    glutAddMenuEntry("Os Simpsons", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
}

int main(int argc, char** argv){
	
    Image *lenaImg = imgReadPPM("./Imagens/imagem1.pnm");
    Image *lenaImgGray = img_Bin(lenaImg, 1);
    
    lenaImg = imgReadPPM("./Imagens/imagem2.pnm");
    lenaImgGray = img_Bin(lenaImg, 2);
    
    lenaImg = imgReadPPM("./Imagens/imagem3.pnm");
    lenaImgGray = img_Bin(lenaImg, 3);
 
    lenaImg = imgReadPPM("./Imagens/imagem4.pnm");
    lenaImgGray = img_Bin(lenaImg, 4);
	
    lenaImg = imgReadPPM("./Imagens/imagem5.pnm");
    lenaImgGray = img_Bin(lenaImg, 5);
    
    lenaImg = imgReadPPM("./Imagens/imagem6.pnm");
    lenaImgGray = img_Bin(lenaImg, 6);

    lenaImg = imgReadPPM("./Imagens/imagem7.pnm");
    lenaImgGray = img_Bin(lenaImg, 7);
    
	imgDestroy(lenaImg);
    imgDestroy(lenaImgGray);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1050, 500);
	glutCreateWindow("Museu UERN");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutMouseFunc(GerenciaMouse);  
	glutSpecialFunc(processSpecialKeys);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;

}
