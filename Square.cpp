#include "square.hpp"
#include <stdio.h>
#include "math.h"

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


void Square::move(GLfloat posCubeX, GLfloat posCubeY, GLfloat posCubeZ){
    if(cubeside < 1){
        x = x-0.5;
        if(x < 2*size+posCubeX){
            if(posCubeY-size > y ||posCubeY+size < y || posCubeZ-size > z || posCubeZ+size < z){
                rejected = true;
            }
            x = 2*size+posCubeX;
            onAir = false;
        }
    }
    else if(cubeside < 2){
        y = y-0.5;
        if(y < 2*size+posCubeY){//ok
            if(posCubeZ-size > z ||posCubeZ+size < z || posCubeX-size > x || posCubeX+size < x){
                rejected = true;
            }
            onAir = false;
            y = 2*size+posCubeY;
        }
    }
    else if(cubeside < 3){
        z = z-0.5;
        if(z < 2*size+posCubeZ){
            if(posCubeX-size > x ||posCubeX*size < x || posCubeY*size > y || posCubeY+size < y){
                rejected = true;
            }
            z = 2*size+posCubeZ;
            onAir = false;
        }
    }
    else if(cubeside < 4){
        x = x+0.5;
        if(x > -2*size+posCubeX){
            if(posCubeY-size > y ||posCubeY+size < y || posCubeZ-size > z || posCubeZ+size < z){
                rejected = true;
            }
            x = -2*size+posCubeX;
            onAir = false;
        }
    }
    else if(cubeside < 5){
        y = y+0.5;
        if(y > -2*size+posCubeY){
            if(posCubeZ-size > z ||posCubeZ+size < z || posCubeX-size > x || posCubeX+size < x){
                rejected = true;
            }
            y = -2*size+posCubeY;
            onAir = false;
        }
    }
    else {
        z = z+0.5;
        if(z > -2*size+posCubeZ){
            if(posCubeX-size > x ||posCubeX+size < x || posCubeY-size > y || posCubeY+size < y){
                rejected = true;
            }
            z = -2*size+posCubeZ;
            onAir = false;
        }
    }
}

void Square::cubeMove(int side){
    if(side == 1){
        y = y+size;  
    }
    else if(side == 2){
        y = y-size;  
    }
    else if(side == 3){
        x = x+size;  
    }
    else if(side == 4){
        x = x-size;      
    }
    else if(side == 5){
        z = z+size;
    }
    else if(side == 6){
        z = z-size;      
    }
}




void Square::rotation(int side, GLfloat posCubeX, GLfloat posCubeY, GLfloat posCubeZ){
    GLfloat aux;
    if(side == 1){//torno z
        aux = z;
        z = -y;
        y = aux;

        if(cubeside < 1){
            cubeside = 0.9;//dir
        }
        else if(cubeside < 2){//tras
            cubeside = 5.9;
        }
        else if(cubeside < 3){
            cubeside = 1.9;//cima
        } 
        else if(cubeside < 4){
            cubeside = 3.9;//esq

        }
        else if(cubeside < 5){
            cubeside = 2.9;//frente

        }
        else {
            cubeside = 4.9;//baixo
        }
    }
    else if(side == 2){//torno z
        aux = -z;
        z = y;
        y = aux;

        if(cubeside < 1){
            cubeside = 0.9;//dir
        }
        else if(cubeside < 2){
            cubeside = 2.9;//frente
        }
        else if(cubeside < 3){
            cubeside = 4.9;//baixo
        } 
        else if(cubeside < 4){
            cubeside = 3.9;//esq

        }
        else if(cubeside < 5){
            cubeside = 5.9;

        }
        else {
            cubeside = 1.9;//cima
        }

    }
    else if(side == 3){//torno y
        aux = -z;
        z = x;
        x = aux;   

        if(cubeside < 1){
            cubeside = 2.9;//frente
        }
        else if(cubeside < 2){
            cubeside = 1.9;//cima
        }
        else if(cubeside < 3){
            cubeside = 3.9;//esq
        } 
        else if(cubeside < 4){
            cubeside = 5.9;//tras
        }
        else if(cubeside < 5){
            cubeside = 4.9;//baixo
        }
        else {
            cubeside = 0.9;//dir
        }
    }
    else {//torno y
        aux = z;
        z = -x;
        x = aux;  
        if(cubeside < 1){
            cubeside = 5.9;//tras
        }
        else if(cubeside < 2){
            cubeside = 1.9;//cima
        }
        else if(cubeside < 3){
            cubeside = 0.9;//dir
        } 
        else if(cubeside < 4){
            cubeside = 2.9;//frente
        }
        else if(cubeside < 5){
            cubeside = 4.9;//baixo
        }
        else {
            cubeside = 3.9;//esq
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


