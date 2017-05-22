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

	if (this->isActive()) {
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(pos_x, pos_y, 0.0);

		if(model == 1) model1();
		else if(model == 2) model2();
		else if(model == 3) model3();

	}
}

void Alien::model1()
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	{
		glVertex2f(7.5, 0);
		glVertex2f(10, 0);
		glVertex2f(10, TAM_ALIEN_Y/2);
		glVertex2f(7.5, TAM_ALIEN_Y/2);
	}
	glBegin(GL_QUADS);
	{
		glVertex2f(35, 0);
		glVertex2f(32.5, 0);
		glVertex2f(32.5, TAM_ALIEN_Y/2);
		glVertex2f(35, TAM_ALIEN_Y/2);
	}
	glBegin(GL_QUADS);
	{
		glVertex2f(0, TAM_ALIEN_Y/2);
		glVertex2f(15, 20);
		glVertex2f(25, 20);
		glVertex2f(40, TAM_ALIEN_Y/2);
	}
	glBegin(GL_QUADS);
	{
		glVertex2f(0, TAM_ALIEN_Y/2);
		glVertex2f(15, 0);
		glVertex2f(25, 0);
		glVertex2f(40, TAM_ALIEN_Y/2);
	}
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	{
		glVertex2f(0, TAM_ALIEN_Y/2 + 1);
		glVertex2f(0, TAM_ALIEN_Y/2 - 1);
		glVertex2f(40, TAM_ALIEN_Y/2 - 1);
		glVertex2f(40, TAM_ALIEN_Y/2 + 1);
	}
	glEnd();
}

void Alien::model2()
{
	// 40 por 20
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.75, 0.75, 0.75);

		glVertex2f(0, 10);
		glVertex2f(10, 0);
		glVertex2f(10, 10);

		glVertex2f(30, 10);
		glVertex2f(30, 0);
		glVertex2f(40, 10);

		glVertex2f(10, 5);
		glVertex2f(10, 0);
		glVertex2f(15, 2.5);

		glVertex2f(25, 2.5);
		glVertex2f(30, 0);
		glVertex2f(30, 5);
	}
	glEnd();

	glBegin(GL_QUADS);
	{
		glColor3f(0.0, 1.0, 0.0);

		glVertex2f(0, 15);
		glVertex2f(0, 10);
		glVertex2f(15, 5);
		glVertex2f(15, 20);

		glVertex2f(15, 20);
		glVertex2f(15, 5);
		glVertex2f(25, 5);
		glVertex2f(25, 20);

		glVertex2f(25, 20);
		glVertex2f(25, 5);
		glVertex2f(40, 10);
		glVertex2f(40, 15);


	}
	glEnd();

	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0, 0.0, 0.0);

		glVertex2f(10, 10);
		glVertex2f(15, 10);
		glVertex2f(10, 15);

		glVertex2f(25, 10);
		glVertex2f(30, 10);
		glVertex2f(30, 15);
	}
	glEnd();

}

void Alien::model3()
{
	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_QUADS);
	{
		glVertex2f(0, 0);
		glVertex2f(TAM_ALIEN_X, 0);
		glVertex2f(TAM_ALIEN_X, TAM_ALIEN_Y);
		glVertex2f(0, TAM_ALIEN_Y);
	}
	glEnd();

}

void Alien::checkCollision(ShotManager *shotManager)
{
	if(pos_y < 5)
	{
		std::cout << "os aliens venceram!" << std::endl;
		exit(0);
	}

	for (auto &shotPlayer : shotManager->shotPlayer) {
		if(shotPlayer.isActive())
		{
			auto shotX = shotPlayer.getX();
			auto shotY = shotPlayer.getY();

			bool withinX = (shotX > pos_x) && (shotX < pos_x + TAM_ALIEN_X);
			bool withinY = (shotY > pos_y) && (shotY < pos_y + TAM_ALIEN_Y);

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
