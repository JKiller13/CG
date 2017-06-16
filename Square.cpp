#include "square.hpp"
#include <stdio.h>

Square::Square(){}

Square::~Square(){}

void Square::move(){
    if(cubeside < 1){
    	x = x-0.5;
    	if(x < 1.5*cubeside){
    		printf("x < %f\n", x );
    		onAir = false;
    	}
    }
    else if(cubeside < 2){
    	y = y-0.5;
    	if(y < 1.5*cubeside){
    		printf("y < %f\n", y );
    		onAir = false;
    	}
    }
    else if(cubeside < 3){
    	z = z-0.5;
    	if(z < 1.5*cubeside){
    		printf("z < %f\n", z );
    		onAir = false;
    	}
    }
    else if(cubeside < 4){
    	x = x+0.5;
    	if(x > -1.5*cubeside){
    		printf("x > %f\n", x );
    		onAir = false;
    	}
    }
    else if(cubeside < 5){
    	y = y+0.5;
    	if(y > -1.5*cubeside){
    		printf("y > %f\n", y );
    		onAir = false;
    	}
    }
    else {
    	z = z+0.5;
    	if(z > -1.5*cubeside){
    		printf("z > %f\n", z );
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


