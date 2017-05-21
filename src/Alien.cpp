#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>

#include "globals.h" 	 
#include "Alien.h"



//precisa arrumar aqui ainda (shotManager*)
void Alien::update() {
	if(isActive()) {
		if(this->step  < 10) {
			setPosition(this->pos_x + 30, this->pos_y);
			this->step++;
		}
		else if(this->step >=10 && this->step < 20) {
			setPosition(this->pos_x - 30, this->pos_y);
			this->step++;
		}else {
			setPosition(this->pos_x, this->pos_y - 50);
			this->step = 0;
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
			