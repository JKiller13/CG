#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "RgbImage.h"
#include "square.hpp"


#define AZUL     0.0, 0.0, 1.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0, 1.0
#define AMARELO  1.0, 1.0, 0.0, 1.0
#define VERDE    0.0, 1.0, 0.0, 1.0
#define LARANJA  0.8, 0.6, 0.1, 1.0
#define WHITE    1.0, 1.0, 1.0, 1.0
#define BLACK    0.0, 0.0, 0.0, 1.0
#define GRAY    0.2, 0.2, 0.2, 1.0
#define PI     3.14159


using namespace std;

void loadSkyboxTexture(char path[], int pos, GLuint skyboxtex[]);
void loadTexture(char path[], int pos, GLuint textures[]);

class Render {
public:
	Render();
	~Render();
	GLuint textures[8];
	GLuint skyboxtex[5];
  	Square outSquare[6][6*6];
	void drawBlend();
	void loadAllTextures();
  	void drawSkybox(int d);
  	void drawS();
  	void manualDraw(GLfloat size);
  	void drawInitial(GLfloat cube, GLfloat x, GLfloat y, GLfloat z);
  	void quadrado(GLfloat size, GLfloat x, GLfloat y, GLfloat z, int text);
  	void doSquare(GLfloat x, GLfloat y, GLfloat z, GLfloat cx, GLfloat cy, GLfloat cz, int side, int pos, int face);
	void outCubeRotation(int axe, int h);
};

