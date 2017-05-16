#include "CollisionBox.h"

bool CollisionBox::collidesWith(const CollisionBox &that)
{
	(void) that;

	// TODO

	return false;
}

void CollisionBox::renderOutline()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(center.x, center.y, 0);

	GLfloat xpos = width / 2;
	GLfloat ypos = height / 2;

	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_LINE_LOOP);
	{
		glVertex2f( xpos,  ypos);
		glVertex2f(-xpos,  ypos);
		glVertex2f(-xpos, -ypos);
		glVertex2f( xpos, -ypos);
	}
	glEnd();
}
