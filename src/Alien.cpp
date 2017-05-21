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
		glVertex2f(x+35, y);
		glVertex2f(x + TAM_ALIEN_X, y);
		glVertex2f(x + TAM_ALIEN_X+35, y + TAM_ALIEN_Y);
		glVertex2f(x, y + TAM_ALIEN_Y);
	glEnd();
}

void Alien::checkCollision(ShotManager *shotManager)
{
	(void) shotManager;
	for (auto shotPlayer : shotManager->shotPlayer) {
		auto shotX = shotPlayer.getX();
		auto shotY = shotPlayer.getY();

		// TODO: não consegui debugar isso ainda
		bool colX = shotX > TAM_ALIEN_X - this->pos_x &&
			shotX < TAM_ALIEN_X  + this->pos_x;
		bool colY = shotY > TAM_ALIEN_Y - this->pos_y &&
			shotY < TAM_ALIEN_Y + this->pos_y;

		if (colX && colY) {
			shotPlayer.deactivate();
			this->is_active = false;
			break;
		}
	}
}

void Alien::fire(ShotManager *shotManager)
{

// TODO: ver se um delay é realmente necessário

	float shot_x = this->pos_x;
	float shot_y = this->pos_y + TAM_ALIEN_Y/4; // TAM_ALIEN_Y/4 igual player
	if (rand() % 1000 == 0) shotManager->newShot(ALIEN_SHOT, shot_x, shot_y);
}
