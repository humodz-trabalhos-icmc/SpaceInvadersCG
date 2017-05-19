#ifndef SHIP_H
#define SHIP_H

#include "globals.h"
#include "ShotManager.h"


class Ship
{
public:
	void update(ShotManager* shotManager);
	void draw();

private:
	void checkControls(ShotManager* shotManager);
	void checkCollision();
	void fire();

	int lives = 3;
	double pos_x = ORTHO_RIGHT/2 + SHIP_PLAYER_WIDTH/2;
	double pos_y = 0;
};

#endif
