#ifndef SHOTMANAGER_H
#define SHOTMANAGER_H

#include "Shot.h"
#include <vector>

using namespace std;

// objeto que gerencia o objeto shot (tiro)
class ShotManager
{
public:
	void newShot(ShotType shot_type, float x, float y);
	void draw();
	void update();

	//vetores de tiros da nave do player e dos aliens
	vector<Shot> shotPlayer;
	vector<Shot> shotAlien;
};

#endif
