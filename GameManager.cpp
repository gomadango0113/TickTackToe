#include <DxLib.h>
#include "GameManager.h"

void initGame();

int timer = 0; //Œ»İ‚ÌŠÔ
GameStatus status = GameStatus::WAITING; //ƒQ[ƒ€‚Ìó‘Ô

void initGame() {
	timer = 0;
	status = GameStatus::WAITING;
}