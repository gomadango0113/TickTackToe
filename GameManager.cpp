#include <DxLib.h>
#include "GameManager.h"

void initGame();

int timer = 0; //���݂̎���
GameStatus status = GameStatus::WAITING; //�Q�[���̏��

void initGame() {
	timer = 0;
	status = GameStatus::WAITING;
}