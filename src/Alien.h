#ifndef ALIEN_H
#define ALIEN_H

#include "globals.h"
#include "ShotManager.h"

#define MOVEMENT_X 30.0 // translação no eixo x
#define MOVEMENT_Y 50.0 // translaçaõ no eixo y

#define MAX_STEP 10
#define MOVE_TIME 40 // tempo de delay

// objeto alien que representa a nave alienigena
class Alien {
	public:
		void update(ShotManager *shotManager);
		void draw();

		// setter que configura posiçaõ (x, y) da nave
		void setPosition(float pos_x, float pos_y) {
			this->pos_x = pos_x;
			this->pos_y = pos_y;
		}
		// getter que retorna disponibilidade da nave
		bool isActive() { return is_active; }
		// setter que configura a disponibilidade da nave
		void deactivate() { is_active = false; }
		// método que configura o modelo da nave
		void setModel(int m) { model = m; }
		void model1();
		void model2();
		void model3();

	private:
		void checkCollision(ShotManager *shotManager);
		void fire(ShotManager *shotManager);


		//
		//atributos
		//
		bool is_active = true; //se a nave está ativa para ser desenhada
		// canto inferior esquerdo do alien
		float pos_x;
		float pos_y;

		int model; // modelo da nave
		int timer = 0;  // contador para translaçao
		int step = 5;

		float direction_x = 1.0; //direçaõ no eixo x

};

#endif
