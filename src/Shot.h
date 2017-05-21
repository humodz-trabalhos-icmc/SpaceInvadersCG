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
	void activate(float x, float y);

	float getX() { return pos_x; }
	float getY() { return pos_y; }

private:
	ShotType type  = ALIEN_SHOT;
	bool is_active = false;
	float pos_x   = 0;
	float pos_y   = 0;
};

#endif
