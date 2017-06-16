#include "render.hpp"

Render::Render(){}

Render::~Render(){}

void Render::drawSkybox(int d){
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_LIGHTING);
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D,skyboxtex[1]); //back
  glColor3f(1.0,1.0,1.0);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glBegin(GL_POLYGON);
  glTexCoord2f(1.0f,0.0f);  glVertex3f(-d, -d, -d); 
  glTexCoord2f(0.0f,0.0f);  glVertex3f(-d, -d, d); 
  glTexCoord2f(0.0f,1.0f);  glVertex3f(-d, d, d); 
  glTexCoord2f(1.0f,1.0f);  glVertex3f(-d, d, -d); 
  glEnd();
  
  glDisable(GL_TEXTURE_2D);
  glEnable(GL_TEXTURE_2D);  
  glBindTexture(GL_TEXTURE_2D,skyboxtex[2]); //up
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glBegin(GL_POLYGON);
  glTexCoord2f(0.0,0.0);glVertex3f(d, d, -d);
  glTexCoord2f(1.0,0.0);glVertex3f(d, d, d);
  glTexCoord2f(1.0,1.0);glVertex3f(-d, d, d);
  glTexCoord2f(0.0,1.0);glVertex3f(-d, d, -d);
  glEnd();

  glDisable(GL_TEXTURE_2D);
  glEnable(GL_TEXTURE_2D);  
  glBindTexture(GL_TEXTURE_2D,skyboxtex[4]); //front
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glBegin(GL_POLYGON);
  glTexCoord2f(0.0f,0.0f);  glVertex3f(d, -d, -d);
  glTexCoord2f(1.0f,0.0f);  glVertex3f(d, -d, d);
  glTexCoord2f(1.0f,1.0f);  glVertex3f(d, d, d);
  glTexCoord2f(0.0f,1.0f);  glVertex3f(d, d, -d);
  glEnd();
  
  glDisable(GL_TEXTURE_2D);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,skyboxtex[3]); //right
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glBegin(GL_POLYGON);
  glTexCoord2f(1.0f,0.0f);glVertex3f(d, -d, -d);
  glTexCoord2f(1.0f,1.0f);glVertex3f(d, d, -d);
  glTexCoord2f(0.0f,1.0f);glVertex3f(-d, d, -d);
  glTexCoord2f(0.0f,0.0f);glVertex3f(-d, -d, -d);
  glEnd();
  glBindTexture(GL_TEXTURE_2D, 0);

  glDisable(GL_TEXTURE_2D);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,skyboxtex[0]); //left
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glBegin(GL_POLYGON);
  glTexCoord2f(0.0f,0.0f);glVertex3f(d, -d, d);
  glTexCoord2f(0.0f,1.0f);glVertex3f(d, d, d);
  glTexCoord2f(1.0f,1.0f);glVertex3f(-d, d, d);
  glTexCoord2f(1.0f,0.0f);glVertex3f(-d, -d, d);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  
  glPopMatrix();
}

void Render::loadAllTextures(){
  char bmpSkybox[5][30]={"skyrender0001.bmp","skyrender0002.bmp","skyrender0003.bmp","skyrender0004.bmp","skyrender0005.bmp"};
  char bmpText[8]={};
  int i;
  for(i=0;i<5;i++)
    loadSkyboxTexture(bmpSkybox[i],i,skyboxtex);
  /* outras texturas a inserir
  for(i=0;i<8;i++)
    loadTexture(bmpText[i],i);*/
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