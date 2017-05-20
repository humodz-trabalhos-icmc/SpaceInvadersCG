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
	void checkCollision(ShotManager *shotManager);
	void fire();
	void drawLeftSide();
	void drawCenter();

	int lives = 3;
	float pos_x = ORTHO_WIDTH / 2;
	float pos_y = PLAYER_HEIGHT / 2;
};

#endif
