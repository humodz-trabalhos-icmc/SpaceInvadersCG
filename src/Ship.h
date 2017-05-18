#ifndef SHIP_H
#define SHIP_H

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
	double pos_x = 0.25;
	double pos_y = 0;
};

#endif
