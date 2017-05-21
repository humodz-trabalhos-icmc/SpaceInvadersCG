#ifndef ALIEN_H
#define ALIEN_H

#include "globals.h"
#include "ShotManager.h"

class Alien {
	public:

		void update(ShotManager *shotManager);
		void draw();

		void setPosition(float pos_x, float pos_y) {
			this->pos_x = pos_x;
			this->pos_y = pos_y;
		}
		bool isActive(){
			return is_active;
		}
	private:
		void checkCollision(ShotManager *shotManager);
		void fire();
		void drawLeftSide();
		void drawCenter();

		bool is_active = true;
		float pos_x;
		float pos_y;
};

#endif