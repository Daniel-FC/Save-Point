#include <stdlib.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int i, j, fase=0;
float angle=0.0;
float lx=0.0f, ly=0.0f, lz=-1.0f;
float x=0.0f, y=5.0f, z=0.0f;
float tx, ty, tz;

void changeSize(int w, int h) {

	if (h == 0){h = 1;}

	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glutSolidTeapot(50.0f);
	
}

void Luz (void){ 

	GLfloat luzAmbiente[4]={0.1,0.1,0.1,1}; 
	GLfloat luzDifusa[4]={1,1,1,1.0};	   // "cor" 
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
	GLfloat posicaoLuz[4]={0, 50, 0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela será preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material 
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);  
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);
		
}

void chave(int x, int y, int z, float c1, float c2, float c3) {
	
	glPushMatrix();
	glColor3f(c1, c2, c3);
	glTranslatef(x, y, z);
	glutSolidSphere(5, 5, 5);
	glPopMatrix();

}

void premio(int x, int y, int z, float c1, float c2, float c3, int v) {
	
	glPushMatrix();
	glColor3f(c1, c2, c3);
	glTranslatef(x, y, z);
	glutWireSphere(v, v, v);
	glPopMatrix();

}

void obstaculo1(int x1, int x2, int y1, int y2, int z1, int z2, float c1, float c2, float c3) {
	
	glColor3f(c1, c2, c3);
	glBegin(GL_QUADS);
		glVertex3f(x1, y1, z1);
		glVertex3f(x1, y2, z2);
		glVertex3f(x2, y2, z2);
		glVertex3f(x2, y1, z1);
	glEnd();

}

void obstaculo2(int x1, int x2, int y1, int y2, int z1, int z2, float c1, float c2, float c3) {
	
	glColor3f(c1, c2, c3);
	glBegin(GL_QUADS);
		glVertex3f(x1, y1, z1);
		glVertex3f(x1, y2, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x2, y1, z2);
	glEnd();

}

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Luz();
	glLoadIdentity();
	gluLookAt(x, y, z, x+lx, y+ly, z+lz, 0.0f, 1.0f, 0.0f); //Camera
	
	obstaculo1(-100,  100,   0,   0, -100,  100, 1.0, 1.0, 1.0); //Piso
	obstaculo1(-100,  100, 100, 100, -100,  100, 1.0, 1.0, 1.0); //Teto

	obstaculo1(-100,  100,   0, 100,  100,  100, 0.1, 0.1, 0.1); //Limite1
	obstaculo1(-100,  100,   0, 100, -100, -100, 0.1, 0.1, 0.1); //Limite2
	obstaculo2( 100,  100,   0, 100, -100,  100, 0.9, 0.9, 0.9); //Limite3
	obstaculo2(-100, -100,   0, 100, -100,  100, 0.9, 0.9, 0.9); //Limite4
	
	premio(-70,  5,  10, 1.0, 1.0, 0.0, 1); //premio
	premio(-70,  5,  10, 1.0, 0.0, 1.0, 2); //premio
	premio(-70,  5,  10, 0.0, 1.0, 1.0, 3); //premio
	premio(-70,  5,  10, 1.0, 0.0, 0.0, 4); //premio
	premio(-70,  5,  10, 0.0, 1.0, 0.0, 5); //premio
	premio(-70,  5,  10, 0.0, 0.0, 1.0, 6); //premio
	
	if(fase<7){
		
		obstaculo1(-100,    0, 50, 50, -100,  -80, 1.0, 1.0, 1.0); //Separador1
		obstaculo1(  20,  100, 50, 50, -100,  -80, 1.0, 1.0, 1.0); //Separador2
		obstaculo1(-100,  100, 50, 50,  -80,  -40, 1.0, 1.0, 1.0); //Separador3
		obstaculo1(-100,  -40, 50, 50,  -40,   20, 1.0, 1.0, 1.0); //Separador4
		obstaculo1(  20,  100, 50, 50,  -40,   20, 1.0, 1.0, 1.0); //Separador5
		obstaculo1(-100,  100, 50, 50,   20,   80, 1.0, 1.0, 1.0); //Separador6
		obstaculo1( -80,   80, 50, 50,   80,  100, 1.0, 1.0, 1.0); //Separador7
		
		if(fase<1){obstaculo2( -20,    0,    0,  50,  -40,  -40, 0.0, 0.0, 1.0);} //Porta A
		if(fase<1){obstaculo2(  20,   20,    0,  50,  -20,    0, 0.0, 0.0, 1.0);} //Porta A
		if(fase<2){obstaculo2(  80,  100,   50, 100,   60,   60, 1.0, 0.0, 0.0);} //Porta B
		if(fase<3){obstaculo2(  80,   80,    0,  50,   20,   40, 1.0, 1.0, 0.0);} //Porta C
		if(fase<4){obstaculo2(  20,   20,    0,  50,  -80,  -60, 1.0, 0.0, 1.0);} //Porta D
		if(fase<5){obstaculo2(  80,   80,   50, 100,    0,   20, 0.5, 0.4, 0.1);} //Porta E
		if(fase<6){obstaculo2(  60,   80,   50, 100,   40,   40, 1.0, 0.5, 0.0);} //Porta F
		
		if(fase<1){chave(-90, 55, -10, 0.0, 0.0, 1.0);} //Chave 1
		if(fase<2){chave(-90,  5, -90, 1.0, 0.0, 0.0);} //Chave 2
		if(fase<3){chave( 90, 55,  30, 1.0, 1.0, 0.0);} //Chave 3
		if(fase<4){chave( 70,  5, -30, 1.0, 0.0, 1.0);} //Chave 4
		if(fase<5){chave(-70, 55, -90, 0.5, 0.4, 0.1);} //Chave 5
		if(fase<6){chave( 90, 55, -30, 1.0, 0.5, 0.0);} //Chave 6
		
		obstaculo2(-11,    -9,   0, 100,    -5,   -5, 0.0, 1.0, 0.0); //Referencia central
		obstaculo2(-11,    -9,   0, 100,   -15,  -15, 0.0, 1.0, 0.0); //Referencia central
		obstaculo2(-15,   -15,   0, 100,   -11,   -9, 0.0, 1.0, 0.0); //Referencia central
		obstaculo2( -5,    -5,   0, 100,   -11,   -9, 0.0, 1.0, 0.0); //Referencia central
	
		obstaculo2( -91,  -89,   0, 100,    85,   85, 0.0, 1.0, 0.0); //Referencia baixo esquerda
		obstaculo2( -91,  -89,   0, 100,    95,   95, 0.0, 1.0, 0.0); //Referencia baixo esquerda
		obstaculo2( -85,  -85,   0, 100,    89,   91, 0.0, 1.0, 0.0); //Referencia baixo esquerda
		obstaculo2( -95,  -95,   0, 100,    89,   91, 0.0, 1.0, 0.0); //Referencia baixo esquerda
		
		obstaculo2(  89,  91,   0, 100,    85,   85, 0.0, 1.0, 0.0); //Referencia baixo direita
		obstaculo2(  89,  91,   0, 100,    95,   95, 0.0, 1.0, 0.0); //Referencia baixo direita
		obstaculo2(  85,  85,   0, 100,    89,   91, 0.0, 1.0, 0.0); //Referencia baixo direita
		obstaculo2(  95,  95,   0, 100,    89,   91, 0.0, 1.0, 0.0); //Referencia baixo direita
	
		obstaculo2(   9,  11,   0, 100,   -95,  -95, 0.0, 1.0, 0.0); //Referencia cima
		obstaculo2(   9,  11,   0, 100,   -85,  -85, 0.0, 1.0, 0.0); //Referencia cima
		obstaculo2(   5,   5,   0, 100,   -91,  -89, 0.0, 1.0, 0.0); //Referencia cima
		obstaculo2(  15,  15,   0, 100,   -91,  -89, 0.0, 1.0, 0.0); //Referencia cima
		
		// ||| BAIXO |||
	 	obstaculo2(-80, -80, 0, 50, -100, -60, 0.7, 0.7, 0.7);
	 	obstaculo2(-40, -40, 0, 50, -100, -60, 0.7, 0.7, 0.7);
	 	obstaculo2(  0,   0, 0, 50, -100, -60, 0.7, 0.7, 0.7);
	 	obstaculo2( 20,  20, 0, 50, -100, -80, 0.7, 0.7, 0.7);
	 	obstaculo2( 60,  60, 0, 50, -100, -80, 0.7, 0.7, 0.7);
	 	
	 	obstaculo2(-60, -60, 0, 50,  -80, -40, 0.7, 0.7, 0.7);
	 	obstaculo2(-20, -20, 0, 50,  -80, -40, 0.7, 0.7, 0.7);
	 	obstaculo2( 40,  40, 0, 50,  -80, -60, 0.7, 0.7, 0.7);
	 	obstaculo2( 80,  80, 0, 50,  -80, -60, 0.7, 0.7, 0.7);
	 	
	 	obstaculo2(-40, -40, 0, 50,  -40,  60, 0.7, 0.7, 0.7);
	 	obstaculo2( 20,  20, 0, 50,  -40, -20, 0.7, 0.7, 0.7);
	 	obstaculo2( 60,  60, 0, 50,  -40, -20, 0.7, 0.7, 0.7);
	 	
	 	obstaculo2(-80, -80, 0, 50,  -20,  20, 0.7, 0.7, 0.7);
	 	obstaculo2( 40,  40, 0, 50,  -20,  80, 0.7, 0.7, 0.7);
	 	obstaculo2( 80,  80, 0, 50,  -20,  20, 0.7, 0.7, 0.7);
	 	
	 	obstaculo2(-60, -60, 0, 50,    0,  20, 0.7, 0.7, 0.7);
	 	obstaculo2( 20,  20, 0, 50,    0, 100, 0.7, 0.7, 0.7);
	 	
	 	obstaculo2(-20, -20, 0, 50,   20,  60, 0.7, 0.7, 0.7);
	 	obstaculo2( 60,  60, 0, 50,   20,  60, 0.7, 0.7, 0.7);
	 	
	 	obstaculo2(-80, -80, 0, 50,   40,  60, 0.7, 0.7, 0.7);
	 	obstaculo2(-60, -60, 0, 50,   40,  60, 0.7, 0.7, 0.7);
	 	obstaculo2(  0,   0, 0, 50,   40,  80, 0.7, 0.7, 0.7);
	 	obstaculo2( 80,  80, 0, 50,   40,  80, 0.7, 0.7, 0.7);
	 	
	 	// --- BAIXO ---
	 	obstaculo2(  0,  80, 0, 50,  -60, -60, 0.3, 0.3, 0.3);
	 	
	 	obstaculo2(-100,-60, 0, 50,  -40, -40, 0.3, 0.3, 0.3);
	 	obstaculo2( -40,-20, 0, 50,  -40, -40, 0.3, 0.3, 0.3);
	 	obstaculo2(   0, 20, 0, 50,  -40, -40, 0.3, 0.3, 0.3);
	 	obstaculo2(  40,100, 0, 50,  -40, -40, 0.3, 0.3, 0.3);
	 	
	 	obstaculo2(-100,-40, 0, 50,  -20, -20, 0.3, 0.3, 0.3);
	 	obstaculo2(  20, 40, 0, 50,  -20, -20, 0.3, 0.3, 0.3);
	 	obstaculo2(  60, 80, 0, 50,  -20, -20, 0.3, 0.3, 0.3);
	 	
	 	obstaculo2(  60, 80, 0, 50,    0,   0, 0.3, 0.3, 0.3);
	 	
	 	obstaculo2( -80,-60, 0, 50,   20,  20, 0.3, 0.3, 0.3);
	 	obstaculo2( -40, 20, 0, 50,   20,  20, 0.3, 0.3, 0.3);
	 	obstaculo2(  60, 80, 0, 50,   20,  20, 0.3, 0.3, 0.3);
	
	 	obstaculo2(-100,  0, 0, 50,   80,  80, 0.3, 0.3, 0.3);
	 	obstaculo2(  40,100, 0, 50,   80,  80, 0.3, 0.3, 0.3);
	 	
	 	// ||| CIMA |||
	 	obstaculo2(-60, -60, 50, 100, -100, -80, 0.8, 0.8, 0.8);
	 	obstaculo2(-40, -40, 50, 100, -100, -80, 0.8, 0.8, 0.8);
	 	
	 	obstaculo2(-20, -20, 50, 100,  -80, -40, 0.8, 0.8, 0.8);
	 	obstaculo2( 80,  80, 50, 100,  -80,   0, 0.8, 0.8, 0.8);
	 	
	 	obstaculo2(-40, -40, 50, 100,  -60, -20, 0.8, 0.8, 0.8);
	 	obstaculo2( 40,  40, 50, 100,  -60,   0, 0.8, 0.8, 0.8);
	 	
	 	obstaculo2( 20,  20, 50, 100,  -40,  20, 0.8, 0.8, 0.8);
	 	obstaculo2( 60,  60, 50, 100,  -40, -20, 0.8, 0.8, 0.8);
	 	
	 	obstaculo2(-80, -80, 50, 100,    0,  20, 0.8, 0.8, 0.8);
	 	obstaculo2(-40, -40, 50, 100,    0,  20, 0.8, 0.8, 0.8);
	 	obstaculo2( 60,  60, 50, 100,    0,  80, 0.8, 0.8, 0.8);
	 	
	 	obstaculo2(-60, -60, 50, 100,   20,  80, 0.8, 0.8, 0.8);
	 	obstaculo2( 80,  80, 50, 100,   20, 100, 0.8, 0.8, 0.8);
	 	
	 	obstaculo2( 20,  20, 50, 100,   40,  80, 0.8, 0.8, 0.8);
	 	obstaculo2( 40,  40, 50, 100,   40, 100, 0.8, 0.8, 0.8);
	 	
	 	obstaculo2(-80, -80, 50, 100,   60, 100, 0.8, 0.8, 0.8);
	 	obstaculo2(-40, -40, 50, 100,   60,  80, 0.8, 0.8, 0.8);
	 	obstaculo2(-20, -20, 50, 100,   60,  80, 0.8, 0.8, 0.8);
	 	
	 	obstaculo2(  0,   0, 50, 100,   80, 100, 0.8, 0.8, 0.8);
	 	
	 	// --- CIMA ---
	 	obstaculo2( -80,-60, 50, 100,  -80, -80, 0.2, 0.2, 0.2);
	 	obstaculo2(  20, 80, 50, 100,  -80, -80, 0.2, 0.2, 0.2);
	 	
	 	obstaculo2(-100,-60, 50, 100,  -60, -60, 0.2, 0.2, 0.2);
	 	obstaculo2(  20, 60, 50, 100,  -60, -60, 0.2, 0.2, 0.2);
	 	
	 	obstaculo2(-100,-60, 50, 100,  -40, -40, 0.2, 0.2, 0.2);
	 	obstaculo2( -40, 20, 50, 100,  -40, -40, 0.2, 0.2, 0.2);
	 	obstaculo2(  40,100, 50, 100,  -40, -40, 0.2, 0.2, 0.2);
	 	
	 	obstaculo2(-100,-40, 50, 100,  -20, -20, 0.2, 0.2, 0.2);
	 	obstaculo2(  40, 60, 50, 100,  -20, -20, 0.2, 0.2, 0.2);
	 	
	 	obstaculo2(-100,-40, 50, 100,    0,   0, 0.2, 0.2, 0.2);
	 	
	 	obstaculo2( -40, 60, 50, 100,   20,  20, 0.2, 0.2, 0.2);
	 	obstaculo2(  80,100, 50, 100,   20,  20, 0.2, 0.2, 0.2);
	 	
	 	obstaculo2(-100, 20, 50, 100,   40,  40, 0.2, 0.2, 0.2);
	 	
	 	obstaculo2( -60,-40, 50, 100,   60,  60, 0.2, 0.2, 0.2);
	 	obstaculo2(   0, 20, 50, 100,   60,  60, 0.2, 0.2, 0.2);
	 	
	 	obstaculo2( -20, 0, 50, 100,   80,  80, 0.2, 0.2, 0.2);
	 	
	}
	
	glutSwapBuffers();
	
}

int solido(float tx, float ty, float tz){
	
	int ver=1;
	
	if(((x>-95 && x<-85) && (y>50 && y<60) && (z>-15 && z< -5)) && fase==0){fase++;}
	if(((x>-95 && x<-85) && (y> 0 && y<10) && (z>-95 && z<-85)) && fase==1){fase++;}
	if(((x> 85 && x< 95) && (y>50 && y<60) && (z> 25 && z< 35)) && fase==2){fase++;}
	if(((x> 65 && x< 75) && (y> 0 && y<10) && (z>-35 && z<-25)) && fase==3){fase++;}
	if(((x>-75 && x<-65) && (y>50 && y<60) && (z>-95 && z<-85)) && fase==4){fase++;}
	if(((x> 85 && x< 95) && (y>50 && y<60) && (z>-35 && z<-25)) && fase==5){fase++;}
	if(((x>-75 && x<-65) && (y> 0 && y<10) && (z>  5 && z< 15)) && fase==6){fase++;}
	
	if(fase<1){if(((tx< 19 || tx> 21) || (tz<-20 || tz>  0) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}} //Porta A
	if(fase<1){if(((tx<-20 || tx>  0) || (tz<-41 || tz>-39) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}} //Porta A
	if(fase<2){if(((tx< 80 || tx>100) || (tz< 59 || tz> 61) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}} //Porta B
	if(fase<3){if(((tx< 79 || tx> 81) || (tz< 20 || tz> 40) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}} //Porta C
	if(fase<4){if(((tx< 19 || tx> 21) || (tz<-80 || tz>-60) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}} //Porta D
	if(fase<5){if(((tx< 79 || tx> 81) || (tz<  0 || tz> 20) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}} //Porta E
	if(fase<6){if(((tx< 60 || tx> 80) || (tz< 39 || tz> 41) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}} //Porta F
	
	if(fase<7){
		
		if(((tx<-100 || tx>  0) || (ty< 49 || ty> 51) || (tz<-100 || tz>-80)) && ver!=-1){ver=1;} else{ver=-1;} //Separador1
		if(((tx<  20 || tx>100) || (ty< 49 || ty> 51) || (tz<-100 || tz>-80)) && ver!=-1){ver=1;} else{ver=-1;} //Separador2
		if(((tx<-100 || tx>100) || (ty< 49 || ty> 51) || (tz< -80 || tz>-40)) && ver!=-1){ver=1;} else{ver=-1;} //Separador3
		if(((tx<-100 || tx>-40) || (ty< 49 || ty> 51) || (tz< -40 || tz> 20)) && ver!=-1){ver=1;} else{ver=-1;} //Separador4
		if(((tx<  20 || tx>100) || (ty< 49 || ty> 51) || (tz< -40 || tz> 20)) && ver!=-1){ver=1;} else{ver=-1;} //Separador5
		if(((tx<-100 || tx>100) || (ty< 49 || ty> 51) || (tz<  20 || tz> 80)) && ver!=-1){ver=1;} else{ver=-1;} //Separador6
		if(((tx< -80 || tx> 80) || (ty< 49 || ty> 51) || (tz<  80 || tz>100)) && ver!=-1){ver=1;} else{ver=-1;} //Separador7
	
		// ||| BAIXO |||
		if(((tx< -81 || tx>-79) || (tz<-100 || tz>-60) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx< -41 || tx>-39) || (tz<-100 || tz>-60) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  -1 || tx>  1) || (tz<-100 || tz>-60) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  19 || tx> 21) || (tz<-100 || tz>-80) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  59 || tx> 61) || (tz<-100 || tz>-80) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		
		if(((tx< -61 || tx>-59) || (tz< -80 || tz>-40) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx< -21 || tx>-19) || (tz< -80 || tz>-40) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  39 || tx> 41) || (tz< -80 || tz>-60) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  79 || tx> 81) || (tz< -80 || tz>-60) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		
		if(((tx< -41 || tx>-39) || (tz< -40 || tz> 60) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  19 || tx> 21) || (tz< -40 || tz>-20) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  59 || tx> 61) || (tz< -40 || tz>-20) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		
		if(((tx< -81 || tx>-79) || (tz< -20 || tz> 20) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  39 || tx> 41) || (tz< -20 || tz> 80) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  79 || tx> 81) || (tz< -20 || tz> 20) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		
		if(((tx< -61 || tx>-59) || (tz<   0 || tz> 20) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  19 || tx> 21) || (tz<   0 || tz>100) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		 	
		if(((tx< -21 || tx>-19) || (tz<  20 || tz> 60) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  59 || tx> 61) || (tz<  20 || tz> 60) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		 	
		if(((tx< -81 || tx>-79) || (tz<  40 || tz> 60) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx< -61 || tx>-59) || (tz<  40 || tz> 60) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  -1 || tx>  1) || (tz<  40 || tz> 80) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  79 || tx> 81) || (tz<  40 || tz> 80) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		
		// --- BAIXO ---
		if(((tx<   0 || tx> 80) || (tz< -61 || tz>-59) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		
		if(((tx<-100 || tx>-60) || (tz< -41 || tz>-39) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx< -40 || tx>-20) || (tz< -41 || tz>-39) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<   0 || tx> 20) || (tz< -41 || tz>-39) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  40 || tx>100) || (tz< -41 || tz>-39) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		
		if(((tx<-100 || tx>-40) || (tz< -21 || tz>-19) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  20 || tx> 40) || (tz< -21 || tz>-19) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  60 || tx> 80) || (tz< -21 || tz>-19) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		 	
		if(((tx<  60 || tx> 80) || (tz<  -1 || tz>  1) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
			
		if(((tx< -80 || tx>-60) || (tz<  19 || tz> 21) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx< -40 || tx> 20) || (tz<  19 || tz> 21) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  60 || tx> 80) || (tz<  19 || tz> 21) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		 	
		if(((tx<-100 || tx>  0) || (tz<  79 || tz> 81) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  40 || tx>100) || (tz<  79 || tz> 81) || ty>50) && ver!=-1){ver=1;} else{ver=-1;}
	
		 // ||| CIMA |||
		if(((tx< -61 || tx>-59) || (tz<-100 || tz>-80) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx< -41 || tx>-39) || (tz<-100 || tz>-80) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		
		if(((tx< -21 || tx>-19) || (tz< -80 || tz>-40) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  79 || tx> 81) || (tz< -80 || tz>  0) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		
		if(((tx< -41 || tx>-39) || (tz< -60 || tz>-20) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  39 || tx> 41) || (tz< -60 || tz>  0) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		
		if(((tx<  19 || tx> 21) || (tz< -40 || tz> 20) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  59 || tx> 61) || (tz< -40 || tz>-20) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		
		if(((tx< -81 || tx>-79) || (tz<   0 || tz> 20) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx< -41 || tx>-39) || (tz<   0 || tz> 20) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  59 || tx> 61) || (tz<   0 || tz> 20) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}	
		
		if(((tx< -61 || tx>-59) || (tz<  20 || tz> 80) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  79 || tx> 81) || (tz<  20 || tz>100) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		 	
		if(((tx<  19 || tx> 21) || (tz<  40 || tz> 80) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  39 || tx> 41) || (tz<  40 || tz>100) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		 	
		if(((tx< -81 || tx>-79) || (tz<  60 || tz>100) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx< -41 || tx>-39) || (tz<  60 || tz> 80) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx< -21 || tx>-19) || (tz<  60 || tz> 80) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		 	
		if(((tx<  -1 || tx>  1) || (tz<  80 || tz>100) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
	
		 // --- CIMA ---
		if(((tx< -80 || tx>-60) || (tz< -81 || tz>-79) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  20 || tx> 80) || (tz< -81 || tz>-79) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		
		if(((tx<-100 || tx>-60) || (tz< -61 || tz>-59) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  20 || tx> 60) || (tz< -61 || tz>-59) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		 	
		if(((tx<-100 || tx>-60) || (tz< -41 || tz>-39) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx< -40 || tx> 20) || (tz< -41 || tz>-39) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  40 || tx>100) || (tz< -41 || tz>-39) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		 	
		if(((tx<-100 || tx>-40) || (tz< -21 || tz>-19) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  40 || tx> 60) || (tz< -21 || tz>-19) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		 	
		if(((tx<-100 || tx>-40) || (tz<  -1 || tz>  1) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		 	
		if(((tx< -40 || tx> 60) || (tz<  19 || tz> 21) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<  80 || tx>100) || (tz<  19 || tz> 21) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		 	
		if(((tx<-100 || tx> 20) || (tz<  31 || tz> 49) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		 	
		if(((tx< -60 || tx>-40) || (tz<  51 || tz> 69) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		if(((tx<   0 || tx> 20) || (tz<  51 || tz> 69) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		 	
		if(((tx< -20 || tx>  0) || (tz<  79 || tz> 81) || ty<50) && ver!=-1){ver=1;} else{ver=-1;}
		
	}

	return ver;
	
}

void processNormalKeys(unsigned char key, int xx, int yy) { 	

	if(key == 'w'){
		
		tx = x;
		ty=y+1;
		tz = z;
		if(ty<100){
			
			if(solido(tx, ty, tz)==1)
				y++;
			
		}
		
	}

	if(key == 's'){

		tx = x;
		ty=y-1;
		tz = z;
		if(ty>0){
			
			if(solido(tx, ty, tz)==1)
				y--;
			
		}
			
	}
	
	if(key == 'd')
		ly += 0.05f;

	if(key == 'a')
		ly -= 0.05f;
    	
} 

void processSpecialKeys(int key, int xx, int yy) {

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
			if((tx>-100 && tx<100) && (tz>-100 && tz<100)){
				
				if(solido(tx, ty, tz)==1){
				
					x += lx * fraction * 2;
					z += lz * fraction * 2;
				
				}
				
			}
		break;
			
		case GLUT_KEY_DOWN:
			tx = x - (lx * fraction * 2);
			ty = y;
			tz = z - (lz * fraction * 2);
			if((tx>-100 && tx<100) && (tz>-100 && tz<100)){
				
				if(solido(tx, ty, tz)==1){
				
					x -= lx * fraction * 2;
					z -= lz * fraction * 2;
				
				}
				
			}
		break;
			
	}
	
}

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1050, 500);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 1;
	
}
