#include <stdlib.h>
#include <GL/glut.h>

#include "Ship.h"
#include "Controller.h"

void Ship::update()
{
	checkControls();
	checkCollision();
}

void Ship::draw(){
	// desenha nave
	glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f( this->pos_x,	 -1.5);
		glVertex2f( this->pos_x-0.5, -1.5);
		glVertex2f( this->pos_x-0.5, -2.0);
		glVertex2f( this->pos_x,	 -2.0);
	glEnd();
}

void Ship::checkControls(){

	// move left
	if (gCtrl.isDown(KEY_LEFT)){
		this->pos_x -= 0.1;

		if (this->pos_x < -2.5)
			this->pos_x = -2.5;
	}
	//move right
	else if (gCtrl.isDown(KEY_RIGHT)){
		this->pos_x += 0.1;

		if (this->pos_x > 3)
			this->pos_x = 3;
	}

	if(gCtrl.isDown(KEY_FIRE))
	{
		fire();
		gCtrl.reset(KEY_FIRE);
	}
}

void Ship::checkCollision(){
	// TODO collision check
	bool got_hit = false;

	if(got_hit)
		this->lives--;

	// termina o jogo
	if (this->lives == 0)
		exit(0);
}

void Ship::fire()
{
	// TODO
}
