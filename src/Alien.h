#ifndef ALIEN_H
#define ALIEN_H

#include "globals.h"
#include "ShotManager.h"

class alien {
	public:
		void update(ShotManager *shotManager);
		void draw();
		void setPosition(float pos_x, float pos_y) {
			this.pos_x = pos_x;
			this.pos_y = pos_y;
		}
	private:
		void checkCollision(ShotManager *showManager);
		void fire();
		void drawLeftSide();
		void drawCenter();

		float pos_x;
		float pos_y; 
};

#endif