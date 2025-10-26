#pragma once
#include "main.h"

enum GameStatus {
	WAITING, //�Q�[���J�n�ҋ@��
	RUNNING, //�Q�[����
	ENDING //�Q�[���I���ς�
};

extern int timer; //���݂̎���
extern GameStatus status; //�Q�[���̏��

int getMapValue(int mouseX, int mouseY);

//�}�b�v���
const int CELL_SIZE = 100;	
const int CELL_COUNT = 3;
const int MAP_MARGIN_X = (WIDTH - (CELL_SIZE * CELL_COUNT)) / 2;
const int MAP_MARGIN_Y = (HEIGHT - (CELL_SIZE * CELL_COUNT)) / 2;
const int BOX_SIZE = 10;

void initGame(); //�Q�[��������������֐�