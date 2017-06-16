#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "RgbImage.h"

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
};