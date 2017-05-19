#include <stdlib.h>
#include <GL/glut.h>

#include "globals.h"
#include "Ship.h"
#include "Controller.h"

void Ship::update(ShotManager* shotManager)
{
	checkControls(shotManager);
	checkCollision();
}

void Ship::draw(){
	// desenha nave
	glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f( this->pos_x,					 0);
		glVertex2f( this->pos_x - SHIP_PLAYER_WIDTH, 0);
		glVertex2f( this->pos_x - SHIP_PLAYER_WIDTH, SHIP_PLAYER_HEIGHT);
		glVertex2f( this->pos_x,					 SHIP_PLAYER_HEIGHT);
	glEnd();
}

void Ship::checkControls(ShotManager* shotManager){

	// move left
	if (gCtrl.isDown(KEY_LEFT)){
		this->pos_x -= 10;

		if (this->pos_x < SHIP_PLAYER_WIDTH)
			this->pos_x = SHIP_PLAYER_WIDTH;
	}
	//move right
	else if (gCtrl.isDown(KEY_RIGHT)){
		this->pos_x += 10;

		if (this->pos_x > ORTHO_RIGHT)
			this->pos_x = ORTHO_RIGHT;
	}

	if(gCtrl.isDown(KEY_FIRE)){
		shotManager->newShot(true, this->pos_x - SHIP_PLAYER_WIDTH/2, this->pos_y + SHIP_PLAYER_HEIGHT);
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