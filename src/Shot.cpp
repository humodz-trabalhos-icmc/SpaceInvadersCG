#include "Shot.h"
#include <GL/glut.h>

void Shot::updatePos(){

	// move up
	if (this->shooter == 0){
		this->pos_y += 0.2;
		if (this->pos_y > 2)
			this->setState(false);
	}
	// move down
	else
		this->pos_y -= 0.1;
}

void Shot::draw(){
	// só desenha tiros ativos
	if (this->state == false)
		return;

	// atualiza tiros que já estavam desenhados
	this->updatePos();

	// shot by player
	if (this->shooter == 0){
		//glLineWidth(2.5); 
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
			glVertex3f(this->pos_x, this->pos_y, 0.0);
			glVertex3f(this->pos_x, this->pos_y - 0.1, 0.0);
		glEnd();
	}
	// shot by enemys
	else {
		//glLineWidth(2.5); 
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
			glVertex3f(this->pos_x - 0.25, this->pos_y, 0.0);
			glVertex3f(this->pos_x - 0.25, this->pos_y + 0.1, 0.0);
		glEnd();
	}
}

void Shot::setPos(double x, double y){
	this->pos_x = x;
	this->pos_y = y;
}

void Shot::setState(bool state){
	this->state = state;
}