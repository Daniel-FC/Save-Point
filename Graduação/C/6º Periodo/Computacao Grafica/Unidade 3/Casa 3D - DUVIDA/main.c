#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
 
void display();
void specialKeys();

GLfloat escala=1;
GLfloat movx=0, movy=0, movz=0;
double rotate_y=0; 
double rotate_x=0;

void display(){
 
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glTranslatef(movx, movy, movz);
	glScalef(escala, escala, escala);
	glRotatef( rotate_x, 1.0, 0.0, 0.0 );
	glRotatef( rotate_y, 0.0, 1.0, 0.0 );	
	
 	 //Lado amarelo - FRENTE
 	glBegin(GL_POLYGON);
	 	glColor3f( 1.0, 1.0, 0.0 );
		glVertex3f(  0.5, -0.5, -0.5 );
	    glVertex3f(  0.5,  0.5, -0.5 );
	   	glVertex3f( -0.5,  0.5, -0.5 );
	  	glVertex3f( -0.5, -0.5, -0.5 );
  	glEnd();

  	//Lado branco - TRASEIRA
	glBegin(GL_POLYGON);
	  	glColor3f(   1.0,  1.0, 1.0 );
	  	glVertex3f(  0.5, -0.5, 0.5 );
	  	glVertex3f(  0.5,  0.5, 0.5 );
	  	glVertex3f( -0.5,  0.5, 0.5 );
	  	glVertex3f( -0.5, -0.5, 0.5 );
  	glEnd();
  	
  	//Lado roxo - DIREITA
	glBegin(GL_POLYGON);
	  	glColor3f(  1.0,  0.0,  1.0 );
	  	glVertex3f( 0.5, -0.5, -0.5 );
	  	glVertex3f( 0.5,  0.5, -0.5 );
	  	glVertex3f( 0.5,  0.5,  0.5 );
	  	glVertex3f( 0.5, -0.5,  0.5 );
  	glEnd();
 
  	//Lado verde - ESQUERDA
	glBegin(GL_POLYGON);
	  	glColor3f(   0.0,  1.0,  0.0 );
	  	glVertex3f( -0.5, -0.5, 0.5 );
	  	glVertex3f( -0.5,  0.5,  0.5 );
	  	glVertex3f( -0.5,  0.5, -0.5 );
	  	glVertex3f( -0.5, -0.5, -0.5 );
  	glEnd();
 
  	//Lado azul - TOPO
	glBegin(GL_POLYGON);
	  	glColor3f(   0.0,  0.0,  1.0 );
	  	glVertex3f(  0.5,  0.5,  0.5 );
		glVertex3f(  0.5,  0.5, -0.5 );
	  	glVertex3f( -0.5,  0.5, -0.5 );
	  	glVertex3f( -0.5,  0.5,  0.5 );
  	glEnd();
 
	//Lado vermelho - BASE
	glBegin(GL_POLYGON);
	  	glColor3f(   1.0,  0.0,  0.0 );
	  	glVertex3f(  0.5, -0.5, -0.5 );
	  	glVertex3f(  0.5, -0.5,  0.5 );
	  	glVertex3f( -0.5, -0.5, 0.5 );
	  	glVertex3f( -0.5, -0.5, -0.5 );
  	glEnd();
 
	//Teto branco - FRENTE
 	glBegin(GL_POLYGON);
	 	glColor3f( 0.8, 0.8, 0.8 );
		glVertex3f( -0.5, 0.5, -0.5 );
	    glVertex3f(  0.0, 1.0,  0.0 );
	   	glVertex3f(  0.5, 0.5, -0.5 );
  	glEnd();

 	///Teto amarelo - TRASEIRA
 	glBegin(GL_POLYGON);
	 	glColor3f( 0.8, 0.8, 0.2 );
		glVertex3f( -0.5, 0.5, 0.5 );
	    glVertex3f(  0.0, 1.0, 0.0 );
	   	glVertex3f(  0.5, 0.5, 0.5 );
  	glEnd();
 
  	//Teto verde - DIREITA
	glBegin(GL_POLYGON);
		glColor3f( 0.2, 0.8, 0.2 );
		glVertex3f(  0.5, 0.5, -0.5 );
	    glVertex3f(  0.0, 1.0, 0.0 );
	   	glVertex3f(  0.5, 0.5, 0.5 );
  	glEnd(); 
 
  	//Teto roxo - ESQUERDA
	glBegin(GL_POLYGON);
		glColor3f(  0.8,  0.2,  0.8 );
		glVertex3f( -0.5, 0.5, -0.5 );
	    glVertex3f(  0.0, 1.0, 0.0 );
	   	glVertex3f( -0.5, 0.5, 0.5 );
  	glEnd();

 	 //Porta - FRENTE
 	glBegin(GL_POLYGON);
	 	glColor3f( 0.2, 0.3, 0.4 );
		glVertex3f(  0.0, -0.5, -0.51 );
	    glVertex3f(  0.0,  0.1, -0.51 );
	   	glVertex3f( -0.3,  0.1, -0.51 );
	  	glVertex3f( -0.3, -0.5, -0.51 );
  	glEnd();

  	glFlush();
  	glutSwapBuffers();
 
}

void Keys( unsigned char key, GLint x, GLint y ){

	if (key == '+')
    	escala += 5;

	else if (key == '-')
    	escala -= 5;
    		
	if (key == 'w')
    	movy++;

	else if (key == 's')
    	movy--;   	

	else if (key == 'a')
    	movx--; 	
    	
	else if (key == 'd')
    	movx++;

	else if (key == 'r')
    	movz++;

	else if (key == 'f')
    	movz--;
    	
	glutPostRedisplay();
 
}

void specialKeys( int key, int x, int y ){
 
	if(key == GLUT_KEY_RIGHT)
    	rotate_y += 5;
 
	if(key == GLUT_KEY_LEFT)
    	rotate_y -= 5;
 
	if(key == GLUT_KEY_UP)
    	rotate_x += 5;
 
  	if(key == GLUT_KEY_DOWN)
    	rotate_x -= 5;
 
  	glutPostRedisplay();
 
}
 
int main(int argc, char* argv[]){
 
  	glutInit(&argc,argv);
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 	glutInitWindowSize(500, 500);
	glutInitWindowPosition(350, 60);
  	glutCreateWindow("Casinha Muito Loka");
  	glEnable(GL_DEPTH_TEST);
  	glutDisplayFunc(display);
  	glutSpecialFunc(Keys);
  	glutSpecialFunc(specialKeys);
 	glClearColor(0.5, 0.5, 0.5, 0);
  	glutMainLoop();
  	return 0;
  	
}
