#include "Shot.h"
#include <GL/glut.h>
#include <iostream>

// atualiza a posição do tiro
void Shot::update() {
	if(isActive()) {
		// move up
		if (this->type == PLAYER_SHOT) {
			this->pos_y += 0.2;
			if (this->pos_y > 2.1)
				deactivate();
		}
		// move down
		else
			this->pos_y -= 0.1;
	}
}

// desenha tiro na tela
void Shot::draw() {
	//std::cout << this->state << std::endl;
	// só desenha tiro ativo
	if (isActive()) {
		// desenha tiro do jogador
		if (this->type == PLAYER_SHOT) {
			glLineWidth(2.5);
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_LINES);
			{
				glVertex3f(this->pos_x, this->pos_y, 0.0);
				glVertex3f(this->pos_x, this->pos_y - 0.1, 0.0);
			}
			glEnd();
		}
		// desenha tiro do inimigo
		else { // this->type == ALIEN_SHOT
			glLineWidth(2.5);
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_LINES);
			{
				glVertex3f(this->pos_x - 0.25, this->pos_y, 0.0);
				glVertex3f(this->pos_x - 0.25, this->pos_y + 0.1, 0.0);
			}
			glEnd();
		}
	}
}

void Shot::activate(double x, double y) {
	is_active = true;
	this->pos_x = x;
	this->pos_y = y;
}
