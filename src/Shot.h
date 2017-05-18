#ifndef SHOT_H
#define SHOT_H

enum ShotType { PLAYER_SHOT, ALIEN_SHOT };

class Shot
{
public:
	Shot() { }
	Shot(ShotType t) { type = t; }

	void update();
	void draw();

	bool isActive()   { return is_active; }
	void deactivate() { is_active = false; }
	// activate the shot and place it at (x, y)
	void activate(double x, double y);

private:
	ShotType type  = ALIEN_SHOT;
	bool is_active = false;
	double pos_x   = 0;
	double pos_y   = 0;
};

#endif