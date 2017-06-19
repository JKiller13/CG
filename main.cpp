#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "square.hpp"
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


GLfloat draw_interval = 200;

GLfloat sizeprincipal[6][6]= {1.5*cube};

//small cubes


Square allsquares[100];
Square square;

int nsquares=0;
GLfloat posC[]= {0, 0, 0};
GLfloat posCubes = 6*cube;
int cubeside =0;

//------------------------------------------------------------ Observador
GLfloat  rVisao=4*cube, aVisao=0.5*PI;
GLfloat  obsP[] ={rVisao*cos(aVisao),rVisao*cos(aVisao), rVisao*sin(aVisao)};

GLfloat  angZoom=90;
GLfloat  incZoom=3;


//------------------------------------------------------------ Lights
GLfloat lightPos[4];
GLfloat light_pos[4]={0.0,-15.0,0.0,1.0};
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

void insertSquare() {
	allsquares[nsquares-1] = square;
	nsquares++;
}

int random(int minimo, int maximo){	
	int y;
	y = rand()%1000;
	return (minimo+ 0.001*y*(maximo-minimo));
}

GLint randomint (GLfloat minimo, GLfloat maximo){	
	GLfloat y;
	y = rand()%1000;
	return (minimo+y*(maximo-minimo));
}

void desenhaTexto(char *string) {
	glRasterPos2f(-20, 35);
	while (*string)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
}


int randomtexture(GLfloat color){

	if(color < 1){
		return 0;
	}
	else if(color < 2){
		return 1;
	}
	else if(color < 3){
		return 2;
	}
	else if(color < 4){
		return 3;
	}
	else if(color < 5){
		return 4;
	}
	else if(color < 6){
		return 5;
	}
}


GLfloat getSide(){
	GLfloat side = random(0, 3);
	if(side < 1)
		return -cube;
	else if(side < 2)
		return 0;
	else
		return cube;

}

void newSquare(){//pos random de novo cubo
	//GLfloat lado = 2.9;
	GLfloat lado = random(0, 6);
	GLfloat cube[3];

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

	square.textn = random(0, 6);
	//square.color = randomColor();
	square.cubeside = lado;
	square.x = posC[0];
	square.y = posC[1];
	square.z = posC[2];
}

void CubeRotation(int side){
	/*GLfloat ang, x = 0, y = 0, z = 0;
	if(side == 1){//torno z
		z = 1;
		ang = 90;
	}
	else if(side == 2){//torno z
		z = 1;
		ang = -90;
	
	}
	else if(side == 3){//torno y
		y = 1;
		ang = 90;	
	}
	else {//torno y
		y = 1;
		ang = -90;
	
	}*/

	for(int i = 0; i < nsquares-1; i++){
		allsquares[i].rotation(side, posC[0], posC[1], posC[2]);
	}

}

void cubeMove(int side){
	for(int i = 0; i < nsquares-1; i++){
		allsquares[i].cubeMove(side);
	}
}


void update(){

	square.move(posC[0], posC[1], posC[2]);
	//printf("move to %f %f %f\n",square.x, square.y, square.z );
}

void timer(int) {
  update();
  glutPostRedisplay();
  glutTimerFunc(draw_interval, timer, 0);
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

	lightPos[0] = -10.0;
	lightPos[1] = -10.0;
	lightPos[2] = 5.0;
	lightPos[3] = 1.0;

	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, l_Amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, l_Dif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, l_Esp);
	glLightf(GL_LIGHT0,GL_CONSTANT_ATTENUATION,constAt);
    glLightf(GL_LIGHT0,GL_LINEAR_ATTENUATION,linAt);
    glLightf(GL_LIGHT0,GL_QUADRATIC_ATTENUATION,quadAt);

    GLfloat direction[3]={0.0,1.0,0.0};
    glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, l_Amb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, l_Dif);
	glLightfv(GL_LIGHT1, GL_SPECULAR, l_Esp);
	glLightf(GL_LIGHT1,GL_CONSTANT_ATTENUATION,constAt);
    glLightf(GL_LIGHT1,GL_LINEAR_ATTENUATION,linAt);
    glLightf(GL_LIGHT1,GL_QUADRATIC_ATTENUATION,quadAt);
    glLightf(GL_LIGHT0,GL_SPOT_CUTOFF, 90);
  	glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION, direction);
  	glLightf(GL_LIGHT0,GL_SPOT_EXPONENT, 5.0);

    if(night)
    	glDisable(GL_LIGHT0);
    else
    	glEnable(GL_LIGHT0);

}

void display(void){
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glViewport (0, 0, wScreen, hScreen);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angZoom, (GLdouble) wScreen / hScreen, 1.0, 250.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(obsP[0], obsP[1], obsP[2], 0,0,0, 0,1,0);
	//render.drawBlend();
	render.drawSkybox(100);
	render.drawInitial(cube, posC[0], posC[1], posC[2]);
	//render.manualDraw(12);

	if(nsquares == 0 ){
		newSquare();
		nsquares++;
	}
	else if(square.onAir == false){
		if(!square.rejected) insertSquare();
		else square.rejected = false;
		newSquare();	
	}
	if(nsquares != 0 ){
		for(int i = 0; i < nsquares-1;i++){
			allsquares[i].draw();
		}
	}
	square.draw();

	GLfloat fogColor[3] = {0.7,0.7,0.7};
	initLights();
	glFogfv(GL_FOG_COLOR, fogColor); //Cor do nevoeiro
	glFogi(GL_FOG_MODE, GL_EXP); //Equacao do nevoeiro - linear
	glFogf(GL_FOG_START, 40.0); // Distancia a que tera inicio o nevoeiro
	glFogf(GL_FOG_END, 60.0); // Distancia a que o nevoeiro terminar
	glFogf (GL_FOG_DENSITY, 0.10);
	if(fog)
		glEnable(GL_FOG);
	else
		glDisable(GL_FOG);
	glutSwapBuffers();

}

GLvoid resize(GLsizei width, GLsizei height) {
	wScreen=width;
	hScreen=height;
	render.drawInitial(cube, posC[0], posC[1], posC[2]);	
}

void init(void) {
	glClearColor(WHITE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	render.loadAllTextures();
	for(int i= 0; i < square.texturesn; i++){
        square.loadTexture(square.tpath[i], i, square.textures);//aqui maybe not
    }
	glEnable(GL_NORMALIZE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	srand(1);
	initLights();
}

void keyboard(unsigned char key, int x, int y){
	
	
	switch (key) {
	//--------------------------- Zoom
		case '+':
		angZoom=angZoom+incZoom;
		if (angZoom>150)
			angZoom=150;
		glutPostRedisplay();
		break;

		case '-':
		angZoom=angZoom-incZoom;
		if (angZoom<10)
			angZoom=10;
		glutPostRedisplay();
		break;
	//--------------------------- Fog
		case 'f':
		case 'F':
			fog=!fog;
		break;
	//--------------------------- Night
		case 'n':
		case 'N':
			night=!night;
		break;
	//--------------------------- Cube rotation
		case 'q':
		posC[1] +=cube;
		cubeMove(1);
		break;

		case 'w':
		posC[1] -=cube;
		cubeMove(2);
		break;

		case 'a':
		posC[0] +=cube;
		cubeMove(3);
		break;

		case 's':
		posC[0] -=cube; 
		cubeMove(4);
		break;

		case 'x':
		posC[2] +=cube;
		cubeMove(5);
		break;

		case 'z':
		posC[2] -=cube; 
		cubeMove(6);
		break;

		case '5':
		CubeRotation(1);
		break;

		case '2':
		CubeRotation(2);
		break;

		case '1':
		CubeRotation(3);
		break;

		case '3':
		CubeRotation(4);
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
	glutTimerFunc(draw_interval, timer, 0);
	glutMainLoop();
	
	return 0;
}
