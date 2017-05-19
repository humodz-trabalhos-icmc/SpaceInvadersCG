#include <GL/glut.h>

#include "Shot.h"
#include "globals.h"

// atualiza a posição do tiro
void Shot::update() {
	
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
void Shot::draw() {

	// só desenha tiro ativo
	if (isActive()) {
		// desenha tiro do jogador
		if (this->type == PLAYER_SHOT) {
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_LINES);
			{
				glVertex3f(this->pos_x, this->pos_y, 0.0);
				glVertex3f(this->pos_x, this->pos_y - 5, 0.0);
			}
			glEnd();
		}
		// desenha tiro do inimigo
		else { // this->type == ALIEN_SHOT
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_LINES);
			{
				glVertex3f(this->pos_x, this->pos_y, 0.0);
				glVertex3f(this->pos_x, this->pos_y + 5, 0.0);
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
