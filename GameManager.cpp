#include <DxLib.h>
#include "GameManager.h"

void initGame();

int timer = 0; //Œ»Ý‚ÌŽžŠÔ
GameStatus status = GameStatus::WAITING; //ƒQ[ƒ€‚Ìó‘Ô

int MAP[3][3] = {
	{0, 1, 2},
	{3, 4, 5},
	{6, 7, 8}
};

void initGame() {
	timer = 0;
	status = GameStatus::WAITING;
}

int getMapValue(int mouseX, int mouseY) {
	int x = mouseX - MAP_MARGIN_X, y = mouseY - MAP_MARGIN_Y;
	int map_indexX = x / CELL_SIZE, map_indexY = y / CELL_SIZE;
	if (x >= 0 && y >= 0 && map_indexX < CELL_COUNT && map_indexY < CELL_COUNT) {
		return MAP[map_indexY][map_indexX];
	}
	else {
		return -1;
	}
}