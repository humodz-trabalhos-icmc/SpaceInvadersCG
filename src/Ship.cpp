#include <stdlib.h>
#include <GL/glut.h>

#include "globals.h"
#include "Ship.h"
#include "Controller.h"

void Ship::update()
{
	checkControls();
	checkCollision();
}

void Ship::draw()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(pos_x, pos_y, 0.0);

	GLfloat s = PLAYER_WIDTH / 2;
	glScalef(s, s, s);

	// the rest of the function uses normalized coordinates -1 .. 1

	// collision box
	glBegin(GL_QUADS);
	{
		glColor3f(1.0, 1.0, 1.0);

		glVertex2f( 1, 1);
		glVertex2f(-1, 1);
		glVertex2f(-1,-1);
		glVertex2f( 1,-1);

		glColor3f(0.5, 0.5, 0.5);


	}
	glEnd();

	glBegin(GL_TRIANGLES);
	{
		glVertex2f(0.0, 0.0);
		glVertex2f(-1.2, -1.0);
		glVertex2f( 1.2, -1.0);


	}
	glEnd();

}

void Ship::checkControls(){

	// move left
	if (gCtrl.isDown(KEY_LEFT)){
		this->pos_x -= PLAYER_SPEED_MS * FRAME_TIME_MS;

		if (this->pos_x < ORTHO_LEFT)
			this->pos_x = ORTHO_LEFT;
	}
	//move right
	else if (gCtrl.isDown(KEY_RIGHT)){
		this->pos_x += PLAYER_SPEED_MS * FRAME_TIME_MS;

		if (this->pos_x > ORTHO_RIGHT)
			this->pos_x = ORTHO_RIGHT;
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
