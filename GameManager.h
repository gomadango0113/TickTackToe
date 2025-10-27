#pragma once
#include "main.h"

struct Location {
	int x;
	int y;
};

enum GameStatus {
	WAITING, //ゲーム開始待機中
	RUNNING, //ゲーム中
	ENDING //ゲーム終了済み
};

enum MapStatus {
	Invalid, //無効マス
	Circle, //○
	Cross //×
};

extern int timer; //現在の時間
extern GameStatus status; //ゲームの状態
extern int MAP[3][3];
extern int end_result;

Location getMapLocation();
int getMapValue();
void setMapValue(MapStatus status);
void drawMapValue();

//マップ情報
const int CELL_SIZE = 100;	
const int CELL_COUNT = 3;
const int MAP_MARGIN_X = (WIDTH - (CELL_SIZE * CELL_COUNT)) / 2;
const int MAP_MARGIN_Y = (HEIGHT - (CELL_SIZE * CELL_COUNT)) / 2;
const int BOX_SIZE = 10;

void initGame(); //ゲームを初期化する関数