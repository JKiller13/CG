#include "render.hpp"
#include "square.hpp"

#include <stdio.h>
#include <math.h>


Render::Render(){}

Render::~Render(){}

GLfloat randomm(int minimo, int maximo){ 
  GLfloat y;
  y = rand()%1000;
  return (minimo+ 0.001*y*(maximo-minimo));
}


void Render::quadrado(GLfloat size, GLfloat x, GLfloat y, GLfloat z, int t){
  glPushMatrix();
  glColor4f(randomm(0,1), randomm(0,1), randomm(0,1), 1);

  glTranslatef(x,y,z);
  if( t ==1){
    glBegin(GL_QUADS);
    glVertex3f(0, size/2, -size/2);
    glVertex3f(0, size/2, size/2);
    glVertex3f(0, -size/2, size/2);
    glVertex3f(0, -size/2, -size/2);
    glEnd();
  }
  else if( t ==2){

    glBegin(GL_QUADS);
    glVertex3f(size/2, 0, -size/2);
    glVertex3f(-size/2,0, -size/2);
    glVertex3f(-size/2,0, size/2);
    glVertex3f(size/2,0, size/2);
    glEnd();
  }
  else if( t ==3){

    glBegin(GL_QUADS);
    glVertex3f(size/2, size/2, 0);
    glVertex3f(-size/2, size/2, 0);
    glVertex3f(-size/2, -size/2, 0);
    glVertex3f(size/2, -size/2, 0);
    glEnd();
  }
  else if( t == 4){
    glBegin(GL_QUADS);
    glVertex3f(0, size/2, -size/2);
    glVertex3f(0, size/2, size/2);
    glVertex3f(0, -size/2, size/2);
    glVertex3f(0, -size/2, -size/2);
    glEnd();
  }
  else if( t == 5){
    glBegin(GL_QUADS);
    glVertex3f(size/2, 0, size/2);
    glVertex3f(-size/2, 0, size/2);
    glVertex3f(-size/2, 0, -size/2);
    glVertex3f(size/2, 0, -size/2);
    glEnd();
  }
  else {
    glBegin(GL_QUADS);
    glVertex3f(size/2, -size/2, 0);
    glVertex3f(-size/2, -size/2, 0);
    glVertex3f(-size/2, size/2, 0);
    glVertex3f(size/2, size/2, 0);
    glEnd();
  }
  glPopMatrix();
}

void drawCannon(GLfloat x, GLfloat y, GLfloat z){

 // quadrado(3, x, y, z);

}


void Render::doSquare(GLfloat x, GLfloat y, GLfloat z, GLfloat cx, GLfloat cy, GLfloat cz, int side, int pos, int face){

      outSquare[side][pos].x = x;
      outSquare[side][pos].y = y;
      outSquare[side][pos].z = z;
      outSquare[side][pos].cx = cx;
      outSquare[side][pos].cy = cy;
      outSquare[side][pos].cz = cz;
      outSquare[side][pos].size = 6;
      outSquare[side][pos].exterior = true;
      outSquare[side][pos].t = 0.5;
      outSquare[side][pos].cubeside = face;

      outSquare[side][pos].drawOneFace();

}


void Render::manualDraw(GLfloat size){

  //left
  int i =0;
  int cord = 18;
  GLfloat x = -cord;
  GLfloat y = -cord;
  GLfloat z = -cord;

  printf("x %f y%f z%f\n", x, y, x+size/2);
  for(int j = 0 ; j < 6; j++){//red
    z=x;
    for(int k = 0; k < 6; k++){
      doSquare(x, y, z, 1, 0, 0, 0, (j*6)+k, 1.1);
      z = z+size/2;
    }
    y = y+size/2;
  }

 // drawCannon();
    //dir2
  x = cord;
  y = -cord;
  z = -cord;
  for(int j = 0 ; j < 6; j++){
    z=-x;
    for(int k = 0; k < 6; k++){
      doSquare(x, y, z, 1, 0, 1, 1, (j*6)+k, 1.1);
      z = z+size/2;
    }
    y = y+size/2;

  }
  x = -cord;
  y = +cord;
  z = -cord;
  

  for(int j = 0 ; j < 6; j++){
    z=-y;
    for(int k = 0; k < 6; k++){

      doSquare(x, y, z, 1, 1, 0, 2, (j*6)+k, 3.1);
      z = z+size/2;
    }
    x = x+size/2;

  }
  x = -cord;
  y= -cord;
  z = -cord;
  for(int j = 0 ; j < 6; j++){
    z=y;
    for(int k = 0; k < 6; k++){
      doSquare(x, y, z, 0, 1, 0, 3, (j*6)+k, 3.4);
      z = z+size/2;
    }
    x = x+size/2;

  }
  x = -cord;
  y = -cord;
  z = +cord;
  for(int j = 0 ; j < 6; j++){
    y=-z;
    for(int k = 0; k < 6; k++){
      doSquare(x, y, z, 0, 1, 1, 4, (j*6)+k, 5.5);
      y = y+size/2;
    }
    x = x+size/2;
  }

  x = -cord;
  y = -cord;
  z = -cord;
  for(int j = 0 ; j < 6; j++){
    y=z;

    for(int k = 0; k < 6; k++){
      doSquare(x, y, z, 0, 0, 1, 5, (j*6)+k, 5.6);
      y = y+size/2;
    }
    x = x+size/2;

  }


}
void Render::drawS(){
    int limit = 6*6;

  for(int i = 0; i < 6; i++){
    for(int j = 0; j < limit; j++){
            outSquare[i][j].drawOneFace();


    }
  }
}

void Render::outCubeRotation(int axe, int h){
  int limit = 6*6;
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < limit; j++){
        if(axe == 1){
          if(outSquare[i][j].x == h){
  printf("esta\n");
            outSquare[i][j].rotation(1, 0,0,0);
          }
        }
        else if(axe == 2){
          if(outSquare[i][j].y == h){
            outSquare[i][j].rotation(3, 0,0,0);
          }
        }
        else{
          if(outSquare[i][j].z == h){
            outSquare[i][j].rotation(5, 0,0,0);
          }
        }
    }
  }

}

void Render::drawInitial(GLfloat cube, GLfloat x, GLfloat y, GLfloat z){
 /*
GLfloat xC = 16;
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
*/

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,textures[0]);
  glPushMatrix();
  glTranslatef(x, y, z);
  glTranslatef(0,-1.5*cube, 0);
  glBegin(GL_QUADS);
  glNormal3f(0.0,-1.0,0.0);
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
  glNormal3f(0.0,1.0,0.0);
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
  glNormal3f(0.0,0.0,1.0);
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
  glNormal3f(0.0,0.0,-1.0);
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
  glNormal3f(1.0,0.0,0.0);
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
  glNormal3f(-1.0,0.0,0.0);
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
  glColor3f(1.0,1.0,1.0);
  glPushMatrix();
  glBindTexture(GL_TEXTURE_2D,skyboxtex[3]); //right
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f);glVertex3f(-d, -d, -d);
  glTexCoord2f(1.0f,0.0f);glVertex3f(d, -d, -d);
  glTexCoord2f(1.0f,1.0f);glVertex3f(d, d, -d);
  glTexCoord2f(0.0f,1.0f);glVertex3f(-d, d, -d);
  glEnd();

  glBindTexture(GL_TEXTURE_2D,skyboxtex[4]); //front
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f);  glVertex3f(d, -d, -d);
  glTexCoord2f(1.0f,0.0f);  glVertex3f(d, -d, d);
  glTexCoord2f(1.0f,1.0f);  glVertex3f(d, d, d);
  glTexCoord2f(0.0f,1.0f);  glVertex3f(d, d, -d);
  glEnd();
  
  glBindTexture(GL_TEXTURE_2D,skyboxtex[0]); //left
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f);glVertex3f(d, -d, d);
  glTexCoord2f(1.0f,0.0f);glVertex3f(-d, -d, d);
  glTexCoord2f(1.0f,1.0f);glVertex3f(-d, d, d);
  glTexCoord2f(0.0f,1.0f);glVertex3f(d, d, d);
  glEnd();
  
  glBindTexture(GL_TEXTURE_2D,skyboxtex[1]); //back
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f,0.0f);  glVertex3f(-d, -d, d); 
  glTexCoord2f(1.0f,0.0f);  glVertex3f(-d, -d, -d); 
  glTexCoord2f(1.0f,1.0f);  glVertex3f(-d, d, -d); 
  glTexCoord2f(0.0f,1.0f);  glVertex3f(-d, d, d); 
  glEnd();

  glBindTexture(GL_TEXTURE_2D,skyboxtex[2]); //up
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
  char bmpText[8][30]={"cim.bmp", "lava.bmp", "pista.bmp", "wall2.bmp", "grass.bmp", "rocks.bmp", "ground.bmp"};
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


