#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H

#include <GL/glut.h>

struct Point2D
{
	GLfloat x;
	GLfloat y;
};

class CollisionBox
{
public:
	Point2D center;
	GLfloat width;
	GLfloat height;

	CollisionBox(Point2D c = {0, 0}, GLfloat w = 0, GLfloat h = 0):
		center(c), width(w), height(h) { }

	// Copy constructor
	CollisionBox(const CollisionBox &that):
		center(that.center),
		width(that.width),
		height(that.height) { }

	// Check if two boxes are touching each other
	bool collidesWith(const CollisionBox &that);

	// Draw a rectangle where the box is
	void renderOutline();
};

#endif
