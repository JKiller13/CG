#include "square.hpp"
#include <stdio.h>

Square::Square(){}

Square::~Square(){}

void Square::loadTexture(){  
  glGenTextures(1, &texture); 
  glBindTexture(GL_TEXTURE_2D, texture); 
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
  imag.LoadBmpFile("sand.bmp"); 
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (int)imag.GetNumCols(), (int)imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, imag.ImageData());
}


void Square::move(){
    if(cubeside < 1){
        x = x-0.5;
        printf("x %d\n", x);
        if(x < 2*size){
            x = 2*size;
            onAir = false;
        }
    }
    else if(cubeside < 2){
        y = y-0.5;
        if(y < 2*size){
            y = 2*size;
            onAir = false;
        }
    }
    else if(cubeside < 3){
        z = z-0.5;
        if(z < 2*size){
            z = 2*size;
            onAir = false;
        }
    }
    else if(cubeside < 4){
        x = x+0.5;
        if(x > -2*size){
            x = -2*size;
            onAir = false;
        }
    }
    else if(cubeside < 5){
        y = y+0.5;
        if(y > -2*size){
            y = -2*size;
            onAir = false;
        }
    }
    else {
        z = z+0.5;
        if(z > -2*size){
            z = -2*size;
            onAir = false;
        }
    }


}


void Square::draw(){
  glPushMatrix();  
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture);
  glColor4f(LARANJA);
  glTranslatef(x,y,z);
  glutSolidCube(size);
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);

  onAir = true;
}


