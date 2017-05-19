#include "ShotManager.h"
#include "Shot.h"
#include "globals.h"
#include <algorithm> 

#include <iostream>
using namespace std;

void ShotManager::newShot(bool player, double x, double y){
	int i;
	Shot sPlayer(PLAYER_SHOT);
	Shot sAlien;	

	// ativa possiveis tiros a serem inseridos
	sPlayer.activate(x - (SHIP_PLAYER_WIDTH/2) , y + SHIP_PLAYER_HEIGHT);
	sAlien.activate(x, y);
	
	// tiros do jogador
	if (player) {
		// cria tiro (insere no vetor)
		if (this->shotPlayer.size() < PLAYER_SHOT_COUNT)
			this->shotPlayer.push_back(sPlayer);

		// ativa tiro
		else
			// procura tiro desativado
			for (i=0; i < PLAYER_SHOT_COUNT; i++)
				if (!this->shotPlayer[i].isActive())
					this->shotPlayer[i].activate(x - (SHIP_PLAYER_WIDTH/2) , y + SHIP_PLAYER_HEIGHT);
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

	for (i=0; i < max(this->shotPlayer.size(), this->shotAlien.size()); i++){
		
		// draw player shot
		if (i < this->shotPlayer.size())	
			this->shotPlayer[i].draw();
		
		// draw alien shot
		if (i < this->shotAlien.size())
			this->shotAlien[i].draw();
	}
}

void ShotManager::update() {
	unsigned int i;

	for (i=0; i < max(this->shotPlayer.size(), this->shotAlien.size()); i++){
			
		// update player shot
		if (i < this->shotPlayer.size())
			this->shotPlayer[i].update();
	
		// update alien shot
		if (i < this->shotAlien.size())
			this->shotAlien[i].draw();
	}
}