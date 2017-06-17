#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "RgbImage.h"


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
  
	void loadAllTextures();
  	void drawSkybox(int d);
  	void drawInitial(GLfloat cube);
};

