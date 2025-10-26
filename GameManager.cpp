#include <DxLib.h>
#include "GameManager.h"
#include "GameUtil.h"

void initGame();

int timer = 0; //現在の時間
GameStatus status = GameStatus::WAITING; //ゲームの状態

int MAP[3][3] = {
	{0, 0, 0},
	{0, 0, 0},
	{0, 0, 0}
};

void initGame() {
	timer = 0;
	status = GameStatus::WAITING;
}

Location getMapLocation() {
	int x = mouseX - MAP_MARGIN_X, y = mouseY - MAP_MARGIN_Y;
	int map_indexX = x / CELL_SIZE, map_indexY = y / CELL_SIZE;
	if (x >= 0 && y >= 0 && map_indexX < CELL_COUNT && map_indexY < CELL_COUNT) {
		return Location{map_indexX, map_indexY};
	}
	else {
		return Location{-1, -1};
	}
}

int getMapValue() {
	Location location = getMapLocation();
	if (location.x == -1 || location.y == -1) {
		return -1;
	}
	else {
		return MAP[location.y][location.x];
	}
}

void setMapValue(MapStatus status) {
	if (status != MapStatus::Invalid) {
		Location location = getMapLocation();
		if (location.x != -1 && location.y != -1) {
			MAP[location.y][location.x] = status;
		}
	}
}

void drawMapValue() {
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			//今いる場所の左と右の座標を割り出す
			int leftX = MAP_MARGIN_X + (CELL_SIZE * x), leftY = MAP_MARGIN_Y + (CELL_SIZE * y);
			int rightX = leftX + CELL_SIZE, rightY = leftY + CELL_SIZE;

			//センター
			int centerX = leftX + (CELL_SIZE / 2) + (BOX_SIZE / 2), centerY = leftY + (CELL_SIZE / 2) + (BOX_SIZE / 2);

			if (MAP[y][x] == MapStatus::Circle) {
				drawText(DrawType::CENTER, centerX, centerY, 50, "○", COLOR_WHITE, COLOR_BLACK);
			}
			else if (MAP[y][x] == MapStatus::Cross) {
				drawText(DrawType::CENTER, centerX, centerY, 50, "×", COLOR_WHITE, COLOR_BLACK);
			}
		}
	}
}