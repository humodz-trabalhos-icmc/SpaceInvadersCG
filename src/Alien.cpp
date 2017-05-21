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
	if(pos_y == 0)
	{
		std::cout << "os aliens venceram!" << std::endl;
		exit(0);
	}

	for (auto &shotPlayer : shotManager->shotPlayer) {
		if(shotPlayer.isActive())
		{
			auto shotX = shotPlayer.getX();
			auto shotY = shotPlayer.getY();

			bool withinX = shotX > pos_x && shotX < pos_x + TAM_ALIEN_X;
			bool withinY = shotY > pos_y && shotX < pos_y + TAM_ALIEN_Y;

			if (withinX && withinY) {
				shotPlayer.deactivate();
				this->is_active = false;
				break;
			}
		}

	}
}

void Alien::fire(ShotManager *shotManager)
{

// TODO: ver se um delay é realmente necessário

	float shot_x = this->pos_x;
	float shot_y = this->pos_y;

	if (rand() % 1000 == 0)
	{
		shotManager->newShot(ALIEN_SHOT, shot_x, shot_y);
	}
}
