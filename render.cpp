#include "render.hpp"
#include <stdio.h>
#include <math.h>

Render::Render(){}

Render::~Render(){}


void Render::quadrado(GLfloat size, GLfloat x, GLfloat y, GLfloat z, int t){
  glEnable(GL_TEXTURE_2D);
  glPushMatrix();
  glColor3f(1, 1, 0);
  glTranslatef(x,y,z);
  glBindTexture(GL_TEXTURE_2D, textures[t]);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f); glVertex3f(size/2, size/2, -size/2);
  glTexCoord2f(1.0f,0.0f);glVertex3f(size/2, size/2, size/2);
  glTexCoord2f(1.0f,1.0f);glVertex3f(size/2, -size/2, size/2);
  glTexCoord2f(0.0f,1.0f); glVertex3f(size/2, -size/2, -size/2);
  glEnd();



  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f);glVertex3f(size/2, size/2, -size/2);
  glTexCoord2f(1.0f,0.0f);glVertex3f(-size/2, size/2, -size/2);
  glTexCoord2f(1.0f,1.0f);glVertex3f(-size/2, size/2, size/2);
  glTexCoord2f(0.0f,1.0f);glVertex3f(size/2, size/2, size/2);
  glEnd();

  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f);glVertex3f(size/2, size/2, size/2);
  glTexCoord2f(1.0f,0.0f);glVertex3f(-size/2, size/2, size/2);
  glTexCoord2f(1.0f,1.0f);glVertex3f(-size/2, -size/2, size/2);
  glTexCoord2f(0.0f,1.0f);glVertex3f(size/2, -size/2, size/2);
  glEnd();

  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f); glVertex3f(-size/2, size/2, -size/2);
  glTexCoord2f(1.0f,0.0f);glVertex3f(-size/2, size/2, size/2);
  glTexCoord2f(1.0f,1.0f);glVertex3f(-size/2, -size/2, size/2);
  glTexCoord2f(0.0f,1.0f);glVertex3f(-size/2, -size/2, -size/2);

  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f);glVertex3f(size/2, -size/2, size/2);
  glTexCoord2f(1.0f,0.0f);glVertex3f(-size/2, -size/2, size/2);
  glTexCoord2f(1.0f,1.0f);glVertex3f(-size/2, -size/2, -size/2);
  glTexCoord2f(0.0f,1.0f); glVertex3f(size/2, -size/2, -size/2);
  glEnd();

  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f);glVertex3f(size/2, -size/2, -size/2);
  glTexCoord2f(1.0f,0.0f);glVertex3f(-size/2, -size/2, -size/2);
  glTexCoord2f(1.0f,1.0f);glVertex3f(-size/2, size/2, -size/2);
  glTexCoord2f(0.0f,1.0f);glVertex3f(size/2, size/2, -size/2);
  glEnd();

  glDisable(GL_TEXTURE_2D);
  glRotatef(90, 1, 0, 0);
  glPopMatrix();
}


void Render::manualDraw(GLfloat size){
  //left
  GLfloat x = -size*3;
  GLfloat y = -size*3;
  GLfloat z = -size*3;
  for(int j = 0 ; j < 6; j++){
    z=x;
    for(int k = 0; k < 6; k++){
      quadrado(size, x, y, z, 5);
      z = z+size;
    }
    y = y+size;

  }
    //dir
  x = size*3;
  y = -size*3;
  z = -size*3;
  for(int j = 0 ; j < 6; j++){
    z=-x;
    for(int k = 0; k < 6; k++){
      quadrado(size, x, y, z, 5);
      z = z+size;
    }
    y = y+size;

  }
  x = -size*3;
  y = +size*3;
  z = -size*3;
  for(int j = 0 ; j < 6; j++){
    z=-y;
    for(int k = 0; k < 6; k++){
      quadrado(size, x, y, z, 5);
      z = z+size;
    }
    x = x+size;

  }
  x = -size*3;
  y = -size*3;
  z = -size*3;
  for(int j = 0 ; j < 6; j++){
    z=y;
    for(int k = 0; k < 6; k++){
      quadrado(size, x, y, z, 5);
      z = z+size;
    }
    x = x+size;

  }
  x = -size*3;
  y = -size*3;
  z = +size*3;
  for(int j = 0 ; j < 6; j++){
    y=-z;
    for(int k = 0; k < 6; k++){
      quadrado(size, x, y, z, 5);
      y = y+size;
    }
    x = x+size;
  }

  x = -size*3;
  y = -size*3;
  z = -size*3;
  for(int j = 0 ; j < 6; j++){
    y=z;
    for(int k = 0; k < 6; k++){
      quadrado(size, x, y, z, 5);
      y = y+size;
    }
    x = x+size;

  }


}

void Render::drawInitial(GLfloat cube, GLfloat x, GLfloat y, GLfloat z){
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,textures[0]);
  glPushMatrix();
  glTranslatef(x, y, z);
  glTranslatef(0,-1.5*cube, 0);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f);glVertex3f(-1.5*cube, 0, -1.5*cube);
  glTexCoord2f(3.0f,0.0f);glVertex3f(-1.5*cube, 0, 1.5*cube);
  glTexCoord2f(3.0f,3.0f);glVertex3f(1.5*cube, 0, 1.5*cube);
  glTexCoord2f(0.0f,3.0f);glVertex3f(1.5*cube, 0, -1.5*cube);
  glEnd();
  glPopMatrix();


  glPushMatrix();
  glTranslatef(x, y, z);
  glTranslatef(0,1.5*cube, 0);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f);glVertex3f(-1.5*cube, 0, -1.5*cube);
  glTexCoord2f(3.0f,0.0f);glVertex3f(-1.5*cube, 0, 1.5*cube);
  glTexCoord2f(3.0f,3.0f);glVertex3f(1.5*cube, 0, 1.5*cube);
  glTexCoord2f(0.0f,3.0f); glVertex3f(1.5*cube, 0, -1.5*cube);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(x, y, z);
  glTranslatef(0,0,1.5*cube);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f);glVertex3f(-1.5*cube, -1.5*cube, 0);
  glTexCoord2f(3.0f,0.0f);glVertex3f(-1.5*cube, 1.5*cube, 0);
  glTexCoord2f(3.0f,3.0f);glVertex3f(1.5*cube, 1.5*cube, 0);
  glTexCoord2f(0.0f,3.0f);glVertex3f(1.5*cube, -1.5*cube, 0);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(x, y, z);
  glTranslatef(0,0,-1.5*cube);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f);glVertex3f(-1.5*cube, -1.5*cube, 0);
  glTexCoord2f(3.0f,0.0f);glVertex3f(-1.5*cube, 1.5*cube, 0);
  glTexCoord2f(3.0f,3.0f);glVertex3f(1.5*cube, 1.5*cube, 0);
  glTexCoord2f(0.0f,3.0f);glVertex3f(1.5*cube, -1.5*cube, 0);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(x, y, z);
  glTranslatef(1.5*cube,0,0);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f); glVertex3f(0, -1.5*cube, -1.5*cube);
  glTexCoord2f(3.0f,0.0f);glVertex3f(0,-1.5*cube, 1.5*cube);
  glTexCoord2f(3.0f,3.0f);glVertex3f(0, 1.5*cube, 1.5*cube);
  glTexCoord2f(0.0f,3.0f);glVertex3f(0, 1.5*cube, -1.5*cube); 
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(x, y, z);
  glTranslatef(-1.5*cube, 0, 0);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f); glVertex3f(0, -1.5*cube, -1.5*cube);
  glTexCoord2f(3.0f,0.0f);glVertex3f(0, -1.5*cube, 1.5*cube);
  glTexCoord2f(3.0f,3.0f);glVertex3f(0, 1.5*cube, 1.5*cube);
  glTexCoord2f(0.0f,3.0f); glVertex3f(0, 1.5*cube, -1.5*cube);
  glEnd();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);

}


void Render::drawSkybox(int d){
  d/=2;
  glEnable(GL_TEXTURE_2D);
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D,skyboxtex[3]); //right
  glColor3f(1.0,1.0,1.0);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f);glVertex3f(-d, -d, -d);
  glTexCoord2f(1.0f,0.0f);glVertex3f(d, -d, -d);
  glTexCoord2f(1.0f,1.0f);glVertex3f(d, d, -d);
  glTexCoord2f(0.0f,1.0f);glVertex3f(-d, d, -d);
  glEnd();

  glBindTexture(GL_TEXTURE_2D,skyboxtex[4]); //front
  glColor3f(1.0,1.0,1.0);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f);  glVertex3f(d, -d, -d);
  glTexCoord2f(1.0f,0.0f);  glVertex3f(d, -d, d);
  glTexCoord2f(1.0f,1.0f);  glVertex3f(d, d, d);
  glTexCoord2f(0.0f,1.0f);  glVertex3f(d, d, -d);
  glEnd();
  
  glBindTexture(GL_TEXTURE_2D,skyboxtex[0]); //left
  glColor3f(1.0,1.0,1.0);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f);glVertex3f(d, -d, d);
  glTexCoord2f(1.0f,0.0f);glVertex3f(-d, -d, d);
  glTexCoord2f(1.0f,1.0f);glVertex3f(-d, d, d);
  glTexCoord2f(0.0f,1.0f);glVertex3f(d, d, d);
  glEnd();
  
  glBindTexture(GL_TEXTURE_2D,skyboxtex[1]); //back
  glColor3f(1.0,1.0,1.0);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f);  glVertex3f(-d, -d, d); 
  glTexCoord2f(1.0f,0.0f);  glVertex3f(-d, -d, -d); 
  glTexCoord2f(1.0f,1.0f);  glVertex3f(-d, d, -d); 
  glTexCoord2f(0.0f,1.0f);  glVertex3f(-d, d, d); 
  glEnd();

  glBindTexture(GL_TEXTURE_2D,skyboxtex[2]); //up
  glColor3f(1.0,1.0,1.0);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0,0.0);glVertex3f(d, d, -d);
  glTexCoord2f(1.0,0.0);glVertex3f(d, d, d);
  glTexCoord2f(1.0,1.0);glVertex3f(-d, d, d);
  glTexCoord2f(0.0,1.0);glVertex3f(-d, d, -d);
  glEnd();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}

void Render::loadAllTextures(){
  char bmpSkybox[5][30]={"skyrender0001.bmp","skyrender0002.bmp","skyrender0003.bmp","skyrender0004.bmp","skyrender0005.bmp"};
  char bmpText[8][30]={"cim.bmp", "wall2.bmp", "pista.bmp", "lava.bmp", "grass.bmp", "rocks.bmp", "ground.bmp"};
  int i;
  for(i=0;i<5;i++)
    loadSkyboxTexture(bmpSkybox[i],i,skyboxtex);
   //outras texturas a inserir
  for(i=0;i<7;i++)
    loadTexture(bmpText[i],i, textures);
}

void loadSkyboxTexture(char path[], int pos, GLuint skyboxtex[]){
  RgbImage imag;
  glGenTextures(1, &skyboxtex[pos]); 
  glBindTexture(GL_TEXTURE_2D, skyboxtex[pos]); 
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
  imag.LoadBmpFile(path); 
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (int)imag.GetNumCols(), (int)imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, imag.ImageData());
}

void loadTexture(char path[], int pos, GLuint textures[]){
  RgbImage imag;
  glGenTextures(1, &textures[pos]); 
  glBindTexture(GL_TEXTURE_2D, textures[pos]); 
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
  imag.LoadBmpFile(path); 
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (int)imag.GetNumCols(), (int)imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, imag.ImageData());
}