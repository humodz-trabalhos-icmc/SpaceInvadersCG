#include <algorithm>
#include <iostream>
#include <GL/glut.h>

#include "AlienManager.h"
#include "Alien.h"
#include "globals.h"

// atualiza o objeto Alien
void AlienManager::update(ShotManager *shotManager) {
	unsigned int i;

	unsigned int dead_count = 0;

	for(i = 0; i < this->aliens.size(); i++) {
		this->aliens[i].update(shotManager);

		if(this->aliens[i].isActive() == false)
		{
			dead_count ++;
		}
	}

	if(dead_count == this->aliens.size())
	{
		std::cout << "voce venceu!" << std::endl;
		exit(0);
	}
}

// reescreve o objeto draw
void AlienManager::draw() {
	unsigned int i;

	for(i = 0; i < this->aliens.size(); i++) {
		this->aliens[i].draw();
	}
}

// adiciona um novo alien a tela
void AlienManager::newAlienTroop(float x, float y) {
	//cria matrix 5x5 com os aliens
	int i, j;
	for(i = 0; i < y; i++) {
		for(j = 0; j < x; j++) {
			Alien alien;
			alien.setPosition(FIRST_ALIEN_X + ((TAM_ALIEN_X + ESPACAMENTO_ALIENS_X)*j
								+ ESPACAMENTO_ALIENS_X), FIRST_ALIEN_Y + ((TAM_ALIEN_Y
								+ ESPACAMENTO_ALIENS_Y)*i + ESPACAMENTO_ALIENS_Y));
			alien.setModel(i / 2 + 1);
			this->aliens.push_back(alien);
		}
	}
	draw();
}
