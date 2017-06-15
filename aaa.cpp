#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "square.hpp"


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

GLfloat draw_interval = 500;

//small cubes
Square square;
GLfloat posC[]= {0, 0, 0};
GLfloat posCubes = 6*cube;
int cubeside =0;

//------------------------------------------------------------ Observador
GLfloat  rVisao=4*cube, aVisao=0.5*PI;
GLfloat  obsP[] ={rVisao*cos(aVisao),rVisao*cos(aVisao), rVisao*sin(aVisao)};

GLfloat  angZoom=90;
GLfloat  incZoom=3;

GLfloat random(GLfloat minimo, GLfloat maximo){	
	GLfloat y;
	y = rand()%1000;
	return (minimo+ 0.001*y*(maximo-minimo));
}


void desenhaTexto(char *string) {
	glRasterPos2f(-20, 35);
	while (*string)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
}


void randomColor(GLfloat color){

	if(color < 1){
		glColor4f(AZUL);
	}
	else if(color < 2){
		glColor4f(VERMELHO);
	}
	else if(color < 3){
		glColor4f(AMARELO);
	}
	else if(color < 4){
		glColor4f(VERDE);
	}
	else if(color < 5){
		glColor4f(LARANJA);
	}
	else if(color < 6){
		glColor4f(BLACK);
	}
	else if(color < 7){
		glColor4f(GRAY);
	}
}



GLfloat getSide(){
	GLfloat side = random(0, 3);
	if(side < 1)
		return -cube;
	else if(side< 2)
		return 0;
	else
		return cube;

}


void newCube(){//pos random de novo cubo
	//GLfloat lado = 3.9;
	GLfloat lado = random(0, 6);
	printf("lado %f\n", lado);
	if(lado < 3){
		if(lado<1){

			cubeside = 1;
			posC[0] = posCubes;
			posC[1] = getSide();
			posC[2] = getSide();
		}
		else if (lado<2){
			cubeside = 3;
			posC[1] = posCubes;
			posC[0] = getSide();
			posC[2] = getSide();
		}
		else{
			cubeside = 2;
			posC[2] = posCubes;
			posC[1] = getSide();
			posC[0] = getSide();
		}
	}
	else{
		if(lado<4){
			cubeside = 4;
			posC[0] = -posCubes;
			posC[1] = getSide();
			posC[2] = getSide();
		}
		else if (lado<5){
			cubeside = 6;
			posC[1] = -posCubes;
			posC[0] = getSide();
			posC[2] = getSide();
		}
		else{
			cubeside = 5;
			posC[2] = -posCubes;
			posC[1] = getSide();
			posC[0] = getSide();
		}
	}
	square.cubeside = lado;
	square.x = posC[0];
	square.y = posC[1];
	square.z = posC[2];
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

	glPushMatrix();
	glColor4f(LARANJA);
	glTranslatef(0, 0, -100);
	glBegin(GL_QUADS);
  		glVertex3f(-50, 0, -50);
 		glVertex3f(-50, 0, 50);
	  	glVertex3f(50, 0, 50);
  		glVertex3f(50, 0, -50);
  	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor4f(AZUL);
	glTranslatef(0, 0, -100);
	glBegin(GL_QUADS);
  		glVertex3f(-50, -50, 0);
 		glVertex3f(-50, 50, 0);
	  	glVertex3f(50, 50, 0);
  		glVertex3f(50,-50, 0);
  	glEnd();
	glPopMatrix();

		
}
void update(){
	square.move();
}

void timer(int) {
  update();
  glutPostRedisplay();
  glutTimerFunc(draw_interval, timer, 0);
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
	if(square.onAir == false)newCube();
	square.draw();
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
	glutTimerFunc(draw_interval, timer, 0);

	glutMainLoop();
	
	return 0;
}
