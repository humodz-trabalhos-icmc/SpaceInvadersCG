#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include "globals.h"
#include "Alien.h"


// método que atualiza os objetos Alien (posição e checa por colisão)
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
// método que desenha naves de acordo com o modelo dela
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
// método para desenho do modelo 1
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

// método de desenho do modelo 2 da nave alien
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
// método de desenho do modelo 3
void Alien::model3()
{
	glColor3f(0.5, 0.5, 1.0);
	glBegin(GL_QUADS);
	{
		glVertex2f(12, 5);
		glVertex2f(28, 5);
		glVertex2f(28, 18);
		glVertex2f(12, 18);
	}
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
	{
		glVertex2f(0, TAM_ALIEN_Y/2);
		glVertex2f(15, 0);
		glVertex2f(20, TAM_ALIEN_Y/4);
	}
	glEnd();
	glBegin(GL_TRIANGLES);
	{
		glVertex2f(20, TAM_ALIEN_Y/4);
		glVertex2f(25, 0);
		glVertex2f(40, TAM_ALIEN_Y/2);
	}
	glEnd();
	GLfloat twicePi = 2.0f * 3.1415;
	int i;
	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= 100;i++) {
			glVertex2f(
			    20 + (2 * cos(i *  twicePi / 100)),
			    11.5 + (2* sin(i * twicePi / 100))
			);
		}
	glEnd();

}
// método de colisão para o tiro do player na nave alien
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

// método que faz o objeto Alien atirar (adiciona um novo shot via shotManager)
void Alien::fire(ShotManager *shotManager)
{

	float shot_x = this->pos_x;
	float shot_y = this->pos_y;

	if (rand() % 1000 == 0)
	{
		shotManager->newShot(ALIEN_SHOT, shot_x, shot_y);
	}
}
