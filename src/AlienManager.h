#ifndef ALIENMANAGER_H
#define ALIENMANAGER_H

#include "Alien.h"
#include <vector>

using namespace std;

class AlienManager {

	public:
		void newAlienTroop(float x, float y);
		void draw();
		void update(ShotManager *shotManager);

		vector<Alien> aliens;
};

#endif
