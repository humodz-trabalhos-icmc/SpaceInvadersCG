#include <algorithm>
#include <iostream>

#include "ShotManager.h"
#include "Shot.h"
#include "globals.h"

void ShotManager::newShot(ShotType shot_type, float x, float y){
	int i;
	Shot sPlayer(PLAYER_SHOT);
	Shot sAlien(ALIEN_SHOT);

	// ativa possiveis tiros a serem inseridos
	sPlayer.activate(x, y);
	sAlien.activate(x, y);

	// tiros do jogador
	if (shot_type == PLAYER_SHOT) {
		// cria tiro (insere no vetor)
		if (this->shotPlayer.size() < PLAYER_SHOT_COUNT)
			this->shotPlayer.push_back(sPlayer);
		// ativa tiro
		else
			// procura tiro desativado
			for (i=0; i < PLAYER_SHOT_COUNT; i++)
				if (!this->shotPlayer[i].isActive()){
					this->shotPlayer[i].activate(x, y);
					break;
				}
	}
	// tiros dos aliens
	else {
		// cria tiro (insere no vetor)
		if (this->shotAlien.size() < ALIEN_SHOT_COUNT)
			this->shotAlien.push_back(sAlien);

		// ativa tiro
		else
			// procura tiro desativado
			for (i=0; i < ALIEN_SHOT_COUNT; i++)
				if (!this->shotAlien[i].isActive())
					this->shotAlien[i].activate(x, y);
	}
}

void ShotManager::draw() {
	unsigned int i;

	for(i = 0; i < this->shotPlayer.size(); i++)
	{
		this->shotPlayer[i].draw();
	}
// implementação que nem todos os aliens atiram
	int rndAlien = rand() % this->shotAlien.size();
	this->shotAlien[rndAlien].draw();

// implementação que todos os aliens atiram
	// for(i = 0; i < this->shotAlien.size(); i++)
	// {
	// 	this->shotAlien[i].draw();
	// }
}

void ShotManager::update() {
	unsigned int i;

	for(i = 0; i < this->shotPlayer.size(); i++)
	{
		this->shotPlayer[i].update();
	}

	for(i = 0; i < this->shotAlien.size(); i++)
	{
		this->shotAlien[i].update();
	}
}
