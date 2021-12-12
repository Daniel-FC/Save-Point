#include <GL/glut.h>

GLfloat escala = 1;
GLfloat rotacao = 0;
GLfloat movx, movy = 0;
int xyz = 0;

void Desenha(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5, 5, -5, 5);
	
	glScalef(escala, escala, 0);
	glTranslatef(movx, movy, 0);
	
	if(xyz==0)
		glRotatef(rotacao, 1, 0, 0);
	if(xyz==1)
		glRotatef(rotacao, 0, 1, 0);	
	if(xyz==2)
		glRotatef(rotacao, 0, 0, 1);	
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
		
	glBegin(GL_QUADS);
		glColor3f(0, 0, 1);
		glVertex2f(-3, -3);
		glVertex2f(-3, 0);
		glColor3f(0, 0, 0);
		glVertex2f(3, 0);
		glVertex2f(3, -3);		
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(1, 0, 0);
		glVertex2f(-4, 0);
		glColor3f(0, 0, 0);
		glVertex2f(4, 0);
		glVertex2f(0, 4);	
	glEnd();
	
	glBegin(GL_QUADS);
		glColor3f( 0.2, 0.3, 0.4 );
		glVertex2f(-1, -3);
		glVertex2f(-1, -1);
		glColor3f(0, 0, 0);
		glVertex2f(0, -1);
		glVertex2f(0, -3);		
	glEnd();

	glFlush();

}

void Teclas(unsigned char tecla, GLint x, GLint y){

	switch(tecla){
		
		case '+':
			escala+=0.2;
		break;

		case '-':
			escala-=0.2;
		break;
			
		case '1':
			rotacao+=3;
		break;

		case '2':
			rotacao-=3;
		break;	

		case 'x':
			xyz=0;			
		break;			
		
		case 'y':
			xyz=1;			
		break;	
			
		case 'z':
			xyz=2;			
		break;
			
	}	
	Desenha();

}

void TeclasEspeciais(unsigned char tecla, GLint x, GLint y){

	switch(tecla){
		
		case GLUT_KEY_UP:
			movy++;
		break;			

		case GLUT_KEY_DOWN:
			movy--;
		break;	

		case GLUT_KEY_LEFT:
			movx--;
		break;	
		
		case GLUT_KEY_RIGHT:
			movx++;
		break;			
		
	}
	Desenha();

}

int main(){ 

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 500);
	glutInitWindowPosition(250, 60);
	glutCreateWindow("Casinha Muito Loka");
	glutKeyboardFunc(Teclas);
	glutSpecialFunc(TeclasEspeciais);
	glutDisplayFunc(Desenha);
	glClearColor(0, 1, 0, 0);
	glutMainLoop();
	return 0;
	
}
