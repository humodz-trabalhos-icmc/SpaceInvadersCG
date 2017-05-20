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

void Ship::draw()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(pos_x, pos_y, 0.0);

	// TODO explain numbers

	GLfloat s = PLAYER_WIDTH / 10.0;
	glScalef(s, s, s);

	// TODO finish player model

	// collision box
	glBegin(GL_LINE_LOOP);
	{
		glColor3f(1.0, 1.0, 1.0);

		glVertex2f( 5.0, 5.0);
		glVertex2f(-5.0, 5.0);
		glVertex2f(-5.0,-5.0);
		glVertex2f( 5.0,-5.0);
	}
	glEnd();

	drawLeftSide();

	// Right side (reflection of left side)
	glScalef(-1.0, 1.0, 1.0);
	drawLeftSide();

	// Symmetric, not affected by reflection
	drawCenter();
}

void Ship::checkControls(ShotManager* shotManager)
{
	float delta_s = PLAYER_SPEED_MS * FRAME_TIME_MS;
	float min_x = ORTHO_LEFT + PLAYER_WIDTH / 2;
	float max_x = ORTHO_RIGHT - PLAYER_WIDTH / 2;

	// Movement
	if(gCtrl.isDown(KEY_LEFT))
	{
		this->pos_x -= delta_s;

		if(this->pos_x < min_x)
		{
			this->pos_x = min_x;
		}
	}
	else if(gCtrl.isDown(KEY_RIGHT))
	{
		this->pos_x += delta_s;

		if(this->pos_x > max_x)
		{
			this->pos_x = max_x;
		}
	}

	// Do not write "else if" here, the ship should fire even if it moves
	if(gCtrl.isDown(KEY_FIRE))
	{

		shotManager->newShot(PLAYER_SHOT, this->pos_x - PLAYER_WIDTH/2, this->pos_y + PLAYER_HEIGHT);
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

void Ship::drawLeftSide()
{
	glBegin(GL_TRIANGLES);
	{
		glColor3f(1.0, 1.0, 1.0);

		// Wing
		glVertex2f(-7.0, -4.0);
		glVertex2f(-1.0, -4.0);
		glVertex2f(-1.0, -1.0);

		// Tail wing
		glVertex2f(-3.0, -5.0);
		glVertex2f(-1.0, -5.0);
		glVertex2f(-1.0, -3.0);
	}
	glEnd();

	glBegin(GL_QUADS);
	{
		// Body side
		glVertex2f(-3.0, -3.0);
		glVertex2f(-1.0, -5.0);
		glVertex2f(-1.0, 5.0);
		glVertex2f(-1.5, 5.0);
	}
	glEnd();

}

void Ship::drawCenter()
{
	glBegin(GL_QUADS);
	{
		glVertex2f(-1.0, 0.0);
		glVertex2f(+1.0, 0.0);
		glVertex2f(+0.5, 2.0);
		glVertex2f(-0.5, 2.0);
	}
	glEnd();
}
