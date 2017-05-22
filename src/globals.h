#ifndef GLOBALS_H
#define GLOBALS_H

// largura e altura da tela
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400

// medidas ortogonais
#define ORTHO_LEFT  0.0
#define ORTHO_RIGHT 599.0
#define ORTHO_DOWN  0.0
#define ORTHO_UP    399.0

// tiros máximos do player e do alien
#define PLAYER_SHOT_COUNT 1
#define ALIEN_SHOT_COUNT 5

// quantidade de frame para renderização
#define FRAME_RATE 30

// constantes ortogonais
const int ORTHO_WIDTH  = ORTHO_RIGHT - ORTHO_LEFT + 1;
const int ORTHO_HEIGHT = ORTHO_UP - ORTHO_DOWN + 1;
const int FRAME_TIME_MS = 1000 / FRAME_RATE;
const float PLAYER_SPEED_MS = ORTHO_WIDTH / (5.0 * 1000);

// Dimensoes da caixa de colisao do jogador
#define PLAYER_HEIGHT 50.0
#define PLAYER_WIDTH  25.0

// posicao do primeiro alien (canto inferior direito)
#define FIRST_ALIEN_X 150
#define FIRST_ALIEN_Y 200

//dimensoes do alien e o espaçamento entre eles
#define TAM_ALIEN_X 40
#define TAM_ALIEN_Y 20
#define ESPACAMENTO_ALIENS_X 10
#define ESPACAMENTO_ALIENS_Y 10

#endif
