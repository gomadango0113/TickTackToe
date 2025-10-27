#pragma once
#include "main.h"

struct Location {
	int x;
	int y;
};

enum GameStatus {
	WAITING, //�Q�[���J�n�ҋ@��
	RUNNING, //�Q�[����
	ENDING //�Q�[���I���ς�
};

enum MapStatus {
	Invalid, //�����}�X
	Circle, //��
	Cross //�~
};

extern int timer; //���݂̎���
extern GameStatus status; //�Q�[���̏��
extern int MAP[3][3];
extern int end_result;

Location getMapLocation();
int getMapValue();
void setMapValue(MapStatus status);
void drawMapValue();

//�}�b�v���
const int CELL_SIZE = 100;	
const int CELL_COUNT = 3;
const int MAP_MARGIN_X = (WIDTH - (CELL_SIZE * CELL_COUNT)) / 2;
const int MAP_MARGIN_Y = (HEIGHT - (CELL_SIZE * CELL_COUNT)) / 2;
const int BOX_SIZE = 10;

void initGame(); //�Q�[��������������֐�