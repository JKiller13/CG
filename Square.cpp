#include "square.hpp"
#include <stdio.h>

Square::Square(){}

Square::~Square(){}

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
  glColor4f(LARANJA);
  glTranslatef(x,y,z);
  glutSolidCube(size);
  glPopMatrix();
  onAir = true;
}


