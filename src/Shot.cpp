#include "Shot.h"
#include <GL/glut.h>
#include <iostream>

// atualiza a posição do tiro
void Shot::updatePos(){

	// move up
	if (this->shooter == 0){
		this->pos_y += 0.2;
		if (this->pos_y > 2.1)
			this->setState(false);
	}
	// move down
	else
		this->pos_y -= 0.1;
}

// desenha tiro na tela
void Shot::draw(){
	//std::cout << this->state << std::endl;

	// só desenha tiro ativo
	if (this->state == false)
		return;

	
	// atualiza tiro
	this->updatePos();

	// desenha tiro do jogador
	if (this->shooter == 0){
		glLineWidth(2.5); 
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
			glVertex3f(this->pos_x, this->pos_y, 0.0);
			glVertex3f(this->pos_x, this->pos_y - 0.1, 0.0);
		glEnd();
	}
	// desenha tiro do inimigo
	else {
		glLineWidth(2.5); 
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
			glVertex3f(this->pos_x - 0.25, this->pos_y, 0.0);
			glVertex3f(this->pos_x - 0.25, this->pos_y + 0.1, 0.0);
		glEnd();
	}
}

// seta a posição do tiro
void Shot::setPos(double x, double y){
	this->pos_x = x;
	this->pos_y = y;
}