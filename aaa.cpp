#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


//--------------------------------- Definir cores
#define AZUL     0.0, 0.0, 1.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0, 1.0
#define AMARELO  1.0, 1.0, 0.0, 1.0
#define VERDE    0.0, 1.0, 0.0, 1.0
#define LARANJA  0.8, 0.6, 0.1, 1.0
#define WHITE    1.0, 1.0, 1.0, 1.0
#define BLACK    0.0, 0.0, 0.0, 1.0
#define GRAY    0.2, 0.2, 0.2, 1.0
#define PI		 3.14159

//------------------------------------------------------------ Sistema Coordenadas + objectos
GLfloat  xC=16.0, yC = 16.0, zC=15.0;
GLint    wScreen=600, hScreen=500;

GLfloat cube=3.0;
GLfloat buleP[]= {0, 0, 0};
																
GLfloat quad=3.0;
GLfloat quadP[]= { 3, -10, 0};

//------------------------------------------------------------ Observador
GLfloat  rVisao=4*cube, aVisao=0.5*PI;
GLfloat  obsP[] ={rVisao*cos(aVisao),rVisao*cos(aVisao), rVisao*sin(aVisao)};

GLfloat  angZoom=90;
GLfloat  incZoom=3;

void desenhaTexto(char *string) {
	glRasterPos2f(-20, 35);
	while (*string)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
}

void drawScene(){
	
	//Eixo dos zz
	glColor4f(AZUL);
	glBegin(GL_LINES);						
		glVertex3i(0,0,-xC); 
		glVertex3i(0,0, xC); 		
	glEnd();

    //Eixo dos yy
	glColor4f(VERDE);
	glBegin(GL_LINES);						
		glVertex3i(0,-xC,0); 
		glVertex3i(0,xC,0); 		
	glEnd();
	
	//Eixo dos xx
	glColor4f(VERMELHO);
	glBegin(GL_LINES);						
		glVertex3i(-xC,0,0); 
		glVertex3i( xC,0,0); 		
	glEnd();
	
	//CUBE
	glPushMatrix();

	glTranslatef(0,0,-cube);
	glColor4f(AMARELO);
	glutSolidCube(cube);

	glTranslatef(0,-cube, 0); 
	glColor4f(GRAY);
	glutSolidCube(cube);

	glTranslatef(0,2*cube, 0); 
	glColor4f(BLACK);
	glutSolidCube(cube);

	glTranslatef(-cube, -cube, 0); 
	glColor4f(VERDE);
	glutSolidCube(cube);

	glTranslatef(0,-cube, 0); 
	glColor4f(LARANJA);
	glutSolidCube(cube);

	glTranslatef(0,2*cube, 0); 
	glColor4f(AZUL);
	glutSolidCube(cube);

	glTranslatef(2*cube, -cube, 0); 
	glColor4f(VERMELHO);
	glutSolidCube(cube);

	glTranslatef(0,-cube, 0); 
	glColor4f(AZUL);
	glutSolidCube(cube);

	glTranslatef(0,2*cube, 0); 
	glColor4f(LARANJA);
	glutSolidCube(cube);
	//2
	glTranslatef(-cube,-2*cube,cube); 
	glColor4f(GRAY);
	glutSolidCube(cube);

	glTranslatef(0,2*cube, 0); 
	glColor4f(BLACK);
	glutSolidCube(cube);

	glTranslatef(-cube, -cube, 0); 
	glColor4f(VERDE);
	glutSolidCube(cube);

	glTranslatef(0,-cube, 0); 
	glColor4f(LARANJA);
	glutSolidCube(cube);

	glTranslatef(0,2*cube, 0); 
	glColor4f(AZUL);
	glutSolidCube(cube);

	glTranslatef(2*cube, -cube, 0); 
	glColor4f(VERMELHO);
	glutSolidCube(cube);

	glTranslatef(0,-cube, 0); 
	glColor4f(AZUL);
	glutSolidCube(cube);

	glTranslatef(0,2*cube, 0); 
	glColor4f(LARANJA);
	glutSolidCube(cube);

	glPopMatrix();

	//3
	glPushMatrix();

	glTranslatef(0,0,+cube);
	glColor4f(AMARELO);
	glutSolidCube(cube);

	glTranslatef(0,-cube, 0); 
	glColor4f(GRAY);
	glutSolidCube(cube);

	glTranslatef(0,2*cube, 0); 
	glColor4f(BLACK);
	glutSolidCube(cube);

	glTranslatef(-cube, -cube, 0); 
	glColor4f(VERDE);
	glutSolidCube(cube);

	glTranslatef(0,-cube, 0); 
	glColor4f(LARANJA);
	glutSolidCube(cube);

	glTranslatef(0,2*cube, 0); 
	glColor4f(AZUL);
	glutSolidCube(cube);

	glTranslatef(2*cube, -cube, 0); 
	glColor4f(VERMELHO);
	glutSolidCube(cube);

	glTranslatef(0,-cube, 0); 
	glColor4f(AZUL);
	glutSolidCube(cube);

	glTranslatef(0,2*cube, 0); 
	glColor4f(LARANJA);
	glutSolidCube(cube);
	glPopMatrix();

	//Quadrado
	glTranslatef(quadP[0], quadP[1], quadP[2]); 
	glColor4f(LARANJA);
	glBegin(GL_QUADS);
		glVertex3f( 0, 0, 0); 
		glVertex3f(quad, 0, 0); 
		glVertex3f(quad, quad, 0); 
		glVertex3f(0, quad, 0);
	glEnd();

	//2 Quadrado
	glTranslatef(quadP[0], quadP[1] + 5, quadP[2]); 
	glColor4f(VERMELHO);
	glBegin(GL_QUADS);
		glVertex3f( 0, 0, 0); 
		glVertex3f(5, 0, 0); 
		glVertex3f(5, 5, 0); 
		glVertex3f(0, 5, 0);
	glEnd();




}


void display(void){
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glViewport (0, 0, wScreen, hScreen);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angZoom, (GLdouble) wScreen / hScreen, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(obsP[0], obsP[1], obsP[2], 0,0,0, 0,1,0);
	drawScene();

	glutSwapBuffers();

}

GLvoid resize(GLsizei width, GLsizei height) {
	wScreen=width;
	hScreen=height;
	drawScene();	
}



void init(void) {
	glClearColor(WHITE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
		
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	srand(1);
}

void keyboard(unsigned char key, int x, int y){
	
	
	switch (key) {
	//--------------------------- Zoom
	case 'z':
	case 'Z':
		angZoom=angZoom+incZoom;
		if (angZoom>150)
			angZoom=150;
		glutPostRedisplay();
		break;
	//--------------------------- Zoom
	case 'a':
	case 'A':
		angZoom=angZoom-incZoom;
		if (angZoom<10)
			angZoom=10;
		glutPostRedisplay();
		break;


	//--------------------------- Escape
	case 27:
		exit(0);
		break;	
  }

}


void teclasNotAscii(int key, int x, int y){
	if(key == GLUT_KEY_UP || key == GLUT_KEY_DOWN) {

		if(key == GLUT_KEY_UP) 
			aVisao = (aVisao + 0.2) ;
		if(key == GLUT_KEY_DOWN) 
			aVisao = (aVisao - 0.2) ;

		obsP[1]=rVisao*cos(aVisao);
		obsP[2]=rVisao*sin(aVisao);
	}
	else{
		if(key == GLUT_KEY_LEFT) 
			aVisao = (aVisao + 0.2) ;
		if(key == GLUT_KEY_RIGHT) 
			aVisao = (aVisao - 0.2) ;

		obsP[0]=rVisao*cos(aVisao);
		obsP[2]=rVisao*sin(aVisao);
	}

	glutPostRedisplay();
}




//======================================================= MAIN
int main(int argc, char** argv){
	
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize (wScreen, hScreen); 
	glutInitWindowPosition (400, 100); 
	glutCreateWindow ("lol");
	
	init();
	glutSpecialFunc(teclasNotAscii); 
	glutReshapeFunc(resize);
	glutDisplayFunc(display); 
	glutKeyboardFunc(keyboard);
	
	glutMainLoop();
	
	return 0;
}
