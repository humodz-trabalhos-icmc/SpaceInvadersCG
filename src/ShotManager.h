#ifndef SHOTMANAGER_H
#define SHOTMANAGER_H

#include "Shot.h"
#include <vector>

using namespace std;

class ShotManager {

public:
	void newShot(bool player, double x, double y);
	void draw();
	void update();

private:
	vector<Shot> shotPlayer;
	vector<Shot> shotAlien;
	int test = 0;

};

#endif