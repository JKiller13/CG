#ifndef SQUARE_HPP
#define SQUARE_HPP


#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "RgbImage.h"

using namespace std;

#define AZUL     0.0, 0.0, 1.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0, 1.0
#define AMARELO  1.0, 1.0, 0.0, 1.0
#define VERDE    0.0, 1.0, 0.0, 1.0
#define LARANJA  0.8, 0.6, 0.1, 1.0
#define WHITE    1.0, 1.0, 1.0, 1.0
#define BLACK    0.0, 0.0, 0.0, 1.0
#define GRAY    0.2, 0.2, 0.2, 1.0
#define PI     3.14159




class Square {
public:
  Square();
  ~Square();
  bool onAir = false;
  bool rejected = false;
  GLfloat size = 3;////meter global
  GLfloat x = 15, y = 0, z = 0;
  GLfloat cx = 1, cy = 1, cz = 1, t=1;  
  GLfloat angX = 0, angY = 0, angZ = 0;


  int textn;
  bool exterior = false;
  GLfloat cubeside = 0;
  GLfloat faceside = 0;
  int texturesn = 8;
  char tpath[8][30] = {"cim.bmp", "wall2.bmp", "pista.bmp", "lava.bmp", "grass.bmp", "rocks.bmp", "ground.bmp", "images.bmp"};
  GLuint textures[8];
  RgbImage imag;
  void rotation(int side, GLfloat posCubeX, GLfloat posCubeY, GLfloat posCubeZ);
  void move(GLfloat posCubeX, GLfloat posCubeY, GLfloat posCubeZ);
  void update();
  void draw();
  void cubeMove(int side);
  void loadTexture(char path[], int pos, GLuint textures[]);
  void drawOneFace();
};

#endif