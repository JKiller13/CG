#include "square.hpp"
#include <stdio.h>

Square::Square(){}

Square::~Square(){}

void Square::loadTexture(char path[], int pos, GLuint textures[]){
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

    for(int i= 0; i < texturesn; i++){
        loadTexture(tpath[i], i, textures);//aqui maybe not
    }
    bool check = false;

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(x,y,z);
    if(cubeside < 1 && check !=true){//ok
        glBindTexture(GL_TEXTURE_2D,textures[textn]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f); glVertex3f(size/2, size/2, -size/2);
        glTexCoord2f(1.0f,0.0f);glVertex3f(size/2, size/2, size/2);
        glTexCoord2f(1.0f,1.0f);glVertex3f(size/2, -size/2, size/2);
        glTexCoord2f(0.0f,1.0f); glVertex3f(size/2, -size/2, -size/2);
        glEnd();
        check =true;

    }
    else{
        glBindTexture(GL_TEXTURE_2D,textures[6]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f); glVertex3f(size/2, size/2, -size/2);
        glTexCoord2f(1.0f,0.0f);glVertex3f(size/2, size/2, size/2);
        glTexCoord2f(1.0f,1.0f);glVertex3f(size/2, -size/2, size/2);
        glTexCoord2f(0.0f,1.0f); glVertex3f(size/2, -size/2, -size/2);
        glEnd();
    }

    if(cubeside < 2 && check !=true){//ok
        glBindTexture(GL_TEXTURE_2D,textures[textn]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f);glVertex3f(size/2, size/2, -size/2);
        glTexCoord2f(1.0f,0.0f);glVertex3f(-size/2, size/2, -size/2);
        glTexCoord2f(1.0f,1.0f);glVertex3f(-size/2, size/2, size/2);
        glTexCoord2f(0.0f,1.0f);glVertex3f(size/2, size/2, size/2);
        check =true;
        glEnd();
    }
    else{
        glBindTexture(GL_TEXTURE_2D,textures[6]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f);glVertex3f(size/2, size/2, -size/2);
        glTexCoord2f(1.0f,0.0f);glVertex3f(-size/2, size/2, -size/2);
        glTexCoord2f(1.0f,1.0f);glVertex3f(-size/2, size/2, size/2);
        glTexCoord2f(0.0f,1.0f);glVertex3f(size/2, size/2, size/2);
        glEnd();
    }
    if(cubeside < 3 && check !=true){//ok
        glBindTexture(GL_TEXTURE_2D,textures[textn]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f);glVertex3f(size/2, size/2, size/2);
        glTexCoord2f(1.0f,0.0f);glVertex3f(-size/2, size/2, size/2);
        glTexCoord2f(1.0f,1.0f);glVertex3f(-size/2, -size/2, size/2);
        glTexCoord2f(0.0f,1.0f);glVertex3f(size/2, -size/2, size/2);
        check =true;
        glEnd();
    }
    else{
        glBindTexture(GL_TEXTURE_2D,textures[6]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f);glVertex3f(size/2, size/2, size/2);
        glTexCoord2f(1.0f,0.0f);glVertex3f(-size/2, size/2, size/2);
        glTexCoord2f(1.0f,1.0f);glVertex3f(-size/2, -size/2, size/2);
        glTexCoord2f(0.0f,1.0f);glVertex3f(size/2, -size/2, size/2);
        glEnd();
    }    
    if(cubeside < 4 && check !=true){//mal
        glBindTexture(GL_TEXTURE_2D,textures[textn]);
        glBegin(GL_QUADS);//lado esq
        glTexCoord2f(0.0f,0.0f); glVertex3f(-size/2, size/2, -size/2);
        glTexCoord2f(1.0f,0.0f);glVertex3f(-size/2, size/2, size/2);
        glTexCoord2f(1.0f,1.0f);glVertex3f(-size/2, -size/2, size/2);
        glTexCoord2f(0.0f,1.0f);glVertex3f(-size/2, -size/2, -size/2);
        check =true;
        glEnd();
    }
    else{
        glBindTexture(GL_TEXTURE_2D,textures[6]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f); glVertex3f(-size/2, size/2, -size/2);
        glTexCoord2f(1.0f,0.0f);glVertex3f(-size/2, size/2, size/2);
        glTexCoord2f(1.0f,1.0f);glVertex3f(-size/2, -size/2, size/2);
        glTexCoord2f(0.0f,1.0f);glVertex3f(-size/2, -size/2, -size/2);
        glEnd();
    }    
    if(cubeside < 5 && check !=true){//mal
        glBindTexture(GL_TEXTURE_2D,textures[textn]);
        glBegin(GL_QUADS);//lado dir
        glTexCoord2f(0.0f,0.0f);glVertex3f(size/2, -size/2, size/2);
        glTexCoord2f(1.0f,0.0f);glVertex3f(-size/2, -size/2, size/2);
        glTexCoord2f(1.0f,1.0f);glVertex3f(-size/2, -size/2, -size/2);
        glTexCoord2f(0.0f,1.0f); glVertex3f(size/2, -size/2, -size/2);
        check =true;
        glEnd();
    }
    else{
        glBindTexture(GL_TEXTURE_2D,textures[6]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f);glVertex3f(size/2, -size/2, size/2);
        glTexCoord2f(1.0f,0.0f);glVertex3f(-size/2, -size/2, size/2);
        glTexCoord2f(1.0f,1.0f);glVertex3f(-size/2, -size/2, -size/2);
        glTexCoord2f(0.0f,1.0f); glVertex3f(size/2, -size/2, -size/2);
        glEnd();
    }    
    if(cubeside < 6 && check !=true){
        glBindTexture(GL_TEXTURE_2D,textures[textn]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f);glVertex3f(size/2, -size/2, -size/2);
        glTexCoord2f(1.0f,0.0f);glVertex3f(-size/2, -size/2, -size/2);
        glTexCoord2f(1.0f,1.0f);glVertex3f(-size/2, size/2, -size/2);
        glTexCoord2f(0.0f,1.0f);glVertex3f(size/2, size/2, -size/2);
        check =true;
        glEnd();
    }
    else{
        glBindTexture(GL_TEXTURE_2D,textures[6]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f);glVertex3f(size/2, -size/2, -size/2);
        glTexCoord2f(1.0f,0.0f);glVertex3f(-size/2, -size/2, -size/2);
        glTexCoord2f(1.0f,1.0f);glVertex3f(-size/2, size/2, -size/2);
        glTexCoord2f(0.0f,1.0f);glVertex3f(size/2, size/2, -size/2);
        glEnd();
    }












    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    onAir = true;
}


