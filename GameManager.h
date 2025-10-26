#pragma once

enum GameStatus {
	WAITING, //ゲーム開始待機中
	RUNNING, //ゲーム中
	ENDING //ゲーム終了済み
};

extern int timer; //現在の時間
extern GameStatus status; //ゲームの状態

void initGame(); //ゲームを初期化する関数