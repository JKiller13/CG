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
  GLfloat size = 3;////meter global
  GLfloat x = 15, y = 0, z = 0;
  int textn;
  GLfloat cubeside = 0;
  GLfloat faceside = 0;
  int texturesn = 7;
  char tpath[7][30] = {"cim.bmp", "wall2.bmp", "pista.bmp", "lava.bmp", "grass.bmp", "rocks.bmp", "ground.bmp"};
  GLuint textures[7];
  RgbImage imag;

  void move();
  void update();
  void draw();
  void loadTexture(char path[], int pos, GLuint textures[]);
};

#endif