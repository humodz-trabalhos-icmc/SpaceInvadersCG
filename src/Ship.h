#ifndef SHIP_H
#define SHIP_H

class Ship {

public:
	double getPos()	{ return pos_x;	}
	void updatePos();
	void updateLive();
	void draw();

private:
	int lives = 3;
	double pos_x = 0.25;
	double pos_y;
};

#endif
