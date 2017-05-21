#ifndef SHOTMANAGER_H
#define SHOTMANAGER_H

#include "Shot.h"
#include <vector>

using namespace std;

class ShotManager
{
public:
	void newShot(ShotType shot_type, float x, float y);
	void draw();
	void update();

	vector<Shot> shotPlayer;
	vector<Shot> shotAlien;
};

#endif
