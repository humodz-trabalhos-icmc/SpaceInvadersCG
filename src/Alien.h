#ifndef ALIEN_H
#define ALIEN_H

#include "globals.h"
#include "ShotManager.h"

#define MOVEMENT_X 30.0
#define MOVEMENT_Y 50.0

#define MAX_STEP 10
#define MOVE_TIME 40

class Alien {
	public:
		void update(ShotManager *shotManager);
		void draw();

		void setPosition(float pos_x, float pos_y) {
			this->pos_x = pos_x;
			this->pos_y = pos_y;
		}
		bool isActive() { return is_active; }
		void deactivate() { is_active = false; }

	private:
		void checkCollision(ShotManager *shotManager);
		void fire(ShotManager *shotManager);

		bool is_active = true;
		// canto inferior esquerdo do alien
		float pos_x;
		float pos_y;

		int timer = 0;
		int step = 5;

		float direction_x = 1.0;

};

#endif
