#ifndef SHIP_H
#define SHIP_H

#include "globals.h"

class Ship
{
public:
	void update();
	void draw();

private:
	void checkControls();
	void checkCollision();
	void fire();

	int lives = 3;
	double pos_x = ORTHO_WIDTH / 2;
	double pos_y = PLAYER_HEIGHT / 2;
};

#endif
