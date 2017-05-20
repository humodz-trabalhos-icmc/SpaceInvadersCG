#include <stdlib.h>
#include <GL/glut.h>

#include "globals.h"
#include "Ship.h"
#include "Controller.h"

void Ship::update(ShotManager* shotManager)
{
	checkControls(shotManager);
	checkCollision(shotManager);
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
	/*glBegin(GL_LINE_LOOP);
	{
		glColor3f(1.0, 1.0, 1.0);

		glVertex2f( 5.0, 5.0);
		glVertex2f(-5.0, 5.0);
		glVertex2f(-5.0,-5.0);
		glVertex2f( 5.0,-5.0);
	}
	glEnd();*/

	drawCenter();
	drawLeftSide();

	// Right side (reflection of left side)
	glScalef(-1.0, 1.0, 1.0);
	drawLeftSide();

	// Symmetric, not affected by reflection
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
		float shot_x = this->pos_x - PLAYER_WIDTH / 2;
		float shot_y = this->pos_y + PLAYER_HEIGHT / 4;

		shotManager->newShot(PLAYER_SHOT, shot_x, shot_y);
		gCtrl.reset(KEY_FIRE);
	}
}

void Ship::checkCollision(ShotManager *shotManager)
{
	(void) shotManager;
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
		// Wing
		glColor3f(0.75, 0.75, 0.75);

		glVertex2f(-7.0, -4.0);
		glVertex2f(-1.0, -4.0);
		glVertex2f(-1.0, -1.0);

		// Tail wing
		glColor3f(1.0, 0.0, 0.0);

		glVertex2f(-4.0, -5.0);
		glVertex2f(-1.0, -5.0);
		glVertex2f(-1.0, -3.0);

		// Wing Stripe
		glColor3f(1.0, 0.0, 0.0);

		glVertex2f(-7.0, -4.0);
		glVertex2f(-1.0, -1.0);
		glVertex2f(-1.0, -2.0);
	}
	glEnd();

	glBegin(GL_QUADS);
	{
		// Body side
		glColor3f(0.5, 0.5, 0.5);

		glVertex2f(-3.0, -3.0);
		glVertex2f(-1.0, -5.0);
		glVertex2f(-1.0,  5.0);
		glVertex2f(-1.5,  5.0);

		// Body stripe
		glColor3f(1.0, 0.0, 0.0);

		glVertex2f(-3.0, -3.0);
		glVertex2f(-1.0,  3.0);
		glVertex2f(-1.0,  5.0);
		glVertex2f(-1.5,  5.0);

	}
	glEnd();

/*	glBegin(GL_LINES);
	{
		glColor3f(0.25, 0.25, 0.25);

		// Body side
		glVertex2f(-3.0, -3.0);
		glVertex2f(-1.0, -5.0);
	}
	glEnd();
*/
}

void Ship::drawCenter()
{
	glBegin(GL_QUADS);
	{
		glColor3f(0.75, 0.75, 0.75);

		glVertex2f(-1.0, 0.0);
		glVertex2f(+1.0, 0.0);
		glVertex2f(+0.5, 2.0);
		glVertex2f(-0.5, 2.0);

		glVertex2f(-1.0, 0.0);
		glVertex2f(+1.0, 0.0);
		glVertex2f(+1.0,-4.0);
		glVertex2f(-1.0,-4.0);

		// Exhaust
		glColor3f(0.25, 0.25, 0.25);

		glVertex2f(-1.0, -4.0);
		glVertex2f(+1.0, -4.0);
		glVertex2f(+0.5, -5.0);
		glVertex2f(-0.5, -5.0);

		// Cockpit
		glColor3f(0.0, 0.0, 0.0);

		glVertex2f(-0.25, 1.0);
		glVertex2f(+0.25, 1.0);
		glVertex2f(+0.5,-1.0);
		glVertex2f(-0.5,-1.0);
	}
	glEnd();
}
