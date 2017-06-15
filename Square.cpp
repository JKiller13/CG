#include "square.hpp"

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
    if(cubeside < 4){
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
  glColor3f(1.0,0.0,0.0);
  glTranslatef(x,y,z);
  glutSolidCube(size);
  glPopMatrix();
  onAir = true;
}


