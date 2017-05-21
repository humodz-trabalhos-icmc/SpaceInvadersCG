#include <stdlib.h>
#include <GL/glut.h>
#include "globals.h"

#include "Alien.h"


void Alien::update(ShotManager *shotManager) {
	if(isActive()) {
		if
	}
}

void Alien::draw() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(0.0, 1.0, 0.0);

	glBegin(GL_QUADS);
		glVertex2f(ORTHO_LEFT, ORTHO_DOWN);
		glVertex2f(20, ORTHO_DOWN);
		glVertex2f(20, 20);
		glVertex2f(ORTHO_LEFT, 20);
	glEnd();

}		
			