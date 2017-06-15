#include "square.hpp"
#include <stdio.h>

Square::Square(){}

Square::~Square(){}

void Square::move(){
    if(cubeside < 1){
    	x = x-0.5;
    	if(x < 2.5*cubeside){
    		onAir = false;
    	}
    }
    else if(cubeside < 2){
    	y = y-0.5;
    	if(y < 2.5*cubeside){
    		onAir = false;
    	}
    }
    else if(cubeside < 3){
    	z = z-0.5;
    	if(z < 2.5*cubeside){
    		onAir = false;
    	}
    }
    else if(cubeside < 4){
    	x = x+0.5;
    	if(x > -2.5*cubeside){
    		onAir = false;
    	}
    }
    else if(cubeside < 5){
    	y = y+0.5;
    	if(y > -2.5*cubeside){
    		onAir = false;
    	}
    }
    else {
    	z = z+0.5;
    	if(z > -2.5*cubeside){
    		onAir = false;
    	}
    }


}


void Square::draw(){
  glPushMatrix();
	if(cubeside < 1){
  		glColor4f(AZUL);
    	
    }
    else if(cubeside < 2){
    	glColor4f(AMARELO);
    }
    else if(cubeside < 3){
    	glColor4f(LARANJA);
    }
    if(cubeside < 4){
    	glColor4f(VERMELHO);
    }
    else if(cubeside < 5){
    	glColor4f(VERDE);
    }
    else {
    	glColor4f(BLACK);
    }
  glTranslatef(x,y,z);
  glutSolidCube(size);
  glPopMatrix();
  onAir = true;
}


