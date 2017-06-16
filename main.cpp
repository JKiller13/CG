#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include "render.hpp"

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
															
//------------------------------------------------------------ Observador
GLfloat  rVisao=4*cube, aVisao=0.5*PI;
GLfloat  obsP[] ={rVisao*cos(aVisao),rVisao*cos(aVisao), rVisao*sin(aVisao)};

GLfloat  angZoom=90;
GLfloat  incZoom=3;

//------------------------------------------------------------ Lights
GLfloat lightPos[4];
GLfloat ambientColor[4] = {0.2, 0.2, 0.2, 1.0};
GLfloat l_Amb[4] = {0.2, 0.2, 0.2, 1.0};
GLfloat l_Dif[4] = {1.0, 1.0, 1.0, 1.0};
GLfloat l_Esp[4] = {1.0, 1.0, 1.0, 1.0};
GLfloat constAt = 1.0f;		//atenuacao constante
GLfloat linAt = 0.05f;		//atenuacao linear
GLfloat quadAt = 0.0f;		//atenuacao quadratica

Render render;
bool night = false;
bool fog = false;

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
	//luzes
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	render.drawSkybox(100);
	//drawScene();
	glutSwapBuffers();

}

GLvoid resize(GLsizei width, GLsizei height) {
	wScreen=width;
	hScreen=height;
	drawScene();	
}

void initLights(){
	if(night){
		ambientColor[0] = 0.2f;
	    ambientColor[1] = 0.2f;
	    ambientColor[2] = 0.2f;
	}
	else{
	    ambientColor[0] = 0.8f;
	    ambientColor[1] = 0.8f;
	    ambientColor[2] = 0.8f;
	}
	ambientColor[3] = 1.0;

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	lightPos[0] = 50.0;
	lightPos[1] = 50.0;
	lightPos[2] = 25.0;
	lightPos[2] = 1.0;

	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, l_Amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, l_Dif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, l_Esp);
	glLightf(GL_LIGHT0,GL_CONSTANT_ATTENUATION,constAt);
    glLightf(GL_LIGHT0,GL_LINEAR_ATTENUATION,linAt);
    glLightf(GL_LIGHT0,GL_QUADRATIC_ATTENUATION,quadAt);

}

void init(void) {
	glClearColor(WHITE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	render.loadAllTextures();	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	srand(1);
	initLights();
	glEnable(GL_LIGHTING);
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
	glutCreateWindow ("Rubick Cube Project");
	
	init();
	glutSpecialFunc(teclasNotAscii); 
	glutReshapeFunc(resize);
	glutDisplayFunc(display); 
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	
	return 0;
}
