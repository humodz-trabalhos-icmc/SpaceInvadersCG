#include <iostream>
#include <GL/glut.h>

#include "Shot.h"
#include "globals.h"

// atualiza a posição do tiro
void Shot::update()
{
	if(isActive()) {
		// move up
		if (this->type == PLAYER_SHOT) {
			this->pos_y += 10;
			if (this->pos_y > ORTHO_UP)
				this->deactivate();
		}
		// move down
		else {
			this->pos_y -= 10;
			if (this->pos_y < 0)
				this->deactivate();
		}
	}
}

// desenha tiro na tela
void Shot::draw()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLfloat cx = this->pos_x;
	GLfloat cy = this->pos_y;

	if (isActive()) {
		if (this->type == PLAYER_SHOT) {
			glColor3f(0.0, 0.0, 1.0);
		}
		else { // this->type == ALIEN_SHOT
			glColor3f(0.0, 1.0, 0.0);
		}

		glBegin(GL_QUADS);
		{
			glVertex2f(cx - 2.5, cy - 5.0);
			glVertex2f(cx + 2.5, cy - 5.0);
			glVertex2f(cx + 2.5, cy + 5.0);
			glVertex2f(cx - 2.5, cy + 5.0);
		}
		glEnd();
	}
}

void Shot::activate(float x, float y)
{
	is_active = true;
	this->pos_x = x;
	this->pos_y = y;
}
