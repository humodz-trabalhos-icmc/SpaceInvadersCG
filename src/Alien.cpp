#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>

#include "globals.h" 	 
#include "Alien.h"


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
			