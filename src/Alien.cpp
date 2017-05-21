#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>

#include "globals.h"
#include "Alien.h"



void Alien::update(ShotManager *shotManager) {

	if(isActive())
	{
		checkCollision(shotManager);
		fire(shotManager);

		if(timer < MOVE_TIME)
		{
			timer++;
		}
		else
		{
			timer = 0;
			if(step < MAX_STEP)
			{
				// Anda horizontalmente
				this->pos_x += direction_x * MOVEMENT_X;
				step++;
			}
			else
			{
				// Anda verticalmente
				this->pos_y -= MOVEMENT_Y;
				direction_x *= -1;
				step = 0;
			}
		}
	}
}

void Alien::draw() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLfloat x = this->pos_x;
	GLfloat y = this->pos_y;

	glColor3f(0.0, 1.0, 0.0);

	glBegin(GL_QUADS);
		glVertex2f(x, y);
		glVertex2f(x + TAM_ALIEN_X, y);
		glVertex2f(x + TAM_ALIEN_X, y + TAM_ALIEN_Y);
		glVertex2f(x, y + TAM_ALIEN_Y);
	glEnd();
}

void Alien::checkCollision(ShotManager *shotManager)
{
	(void) shotManager;
	bool got_hit = false;
	for (auto shotPlayer : shotManager->shotPlayer) {
		auto shotX = shotPlayer.getX();
		auto shotY = shotPlayer.getY();

		//TODO: não consegui debugar isso ainda
		bool colX = this->pos_x + PLAYER_WIDTH/2 >= shotX;
		bool colY = this->pos_y + PLAYER_HEIGHT/2 >= shotY;

		colX && colY ? got_hit = true : got_hit = false;
	}
}

void Alien::fire(ShotManager *shotManager)
{

}
