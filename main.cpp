#define _CRT_SECURE_NO_WARNINGS
#include <DxLib.h>
#include "main.h"
#include "GameManager.h"
#include "GameUtil.h"

int mouseX = 0, mouseY = 0;

int WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd) {
    SetWindowText("三目並べ");
    SetGraphMode(WIDTH, HEIGHT, COLORBIT);
    ChangeWindowMode(true);

    if (DxLib_Init() == -1) {
        return -1;
    }
    SetBackgroundColor(245, 245, 245);
    SetDrawScreen(DX_SCREEN_BACK);
    initGame();

    int math = 0;

    while (true) {
        ClearDrawScreen();
        GetMousePoint(&mouseX, &mouseY);
        timer++;

        bool area = (0 < mouseX - MAP_MARGIN_X && MAP_MARGIN_X + (CELL_SIZE * CELL_COUNT) > mouseX);
        char left_side[200];
        sprintf(left_side, "時間: %d \n マウス：(%d,%d) 、マップの座標（マップ内[1]/外[0]: %d）：（%d, %d）\n インデックス：%d \n Center: ()",
            timer / 60,
            mouseX, mouseY, area, mouseX - MAP_MARGIN_X, mouseY - MAP_MARGIN_Y,
            getMapValue());
        drawText(DrawType::LEFT, 0, 0, 15, left_side, COLOR_WHITE, COLOR_BLACK);

        int backgound_startX = MAP_MARGIN_X, backgound_startY = MAP_MARGIN_Y;
        int backgound_endX = MAP_MARGIN_X + (CELL_SIZE * CELL_COUNT) + BOX_SIZE, backgound_endY = MAP_MARGIN_Y + (CELL_SIZE * CELL_COUNT) + BOX_SIZE;

        switch (status) {
        case GameStatus::WAITING:
            if (timer % 100 < 50) {
                drawText(DrawType::CENTER, WIDTH * 0.5, HEIGHT * 0.4, 30, "三目並べ", COLOR_WHITE, COLOR_BLACK);
                drawText(DrawType::CENTER, WIDTH * 0.5, HEIGHT * 0.5, 30, "ゲームを開始するにはスペースキーを押してください", COLOR_WHITE, COLOR_BLACK);
                // drawText(DrawType::CENTER, WIDTH * 0.5, HEIGHT * 0.6, 30, "CPUモードは「1」、2プレイヤーモードは「2」を押してください", COLOR_WHITE, COLOR_BLACK);
            }

            if (CheckHitKey(KEY_INPUT_SPACE)) {
                status = GameStatus::RUNNING;
                timer = 0;
            }

            break;
        case GameStatus::RUNNING:
            if (getMapValue() == 0) {
                if (GetMouseInput() & MOUSE_INPUT_LEFT) {
                    setMapValue(MapStatus::Circle);
                }
                else if (GetMouseInput() & MOUSE_INPUT_RIGHT) {
                    setMapValue(MapStatus::Cross);
                }
            }

            //背景
            DrawBox(backgound_startX, backgound_startY, backgound_endX, backgound_endY, GetColor(176, 196, 222), 1);

            //縦線
            for (int i = 0; i <= CELL_COUNT; i++) {
                int UpX = MAP_MARGIN_X + (CELL_SIZE * i);
                int UpY = MAP_MARGIN_Y;
                int DownX = UpX;
                int DownY = UpY + (CELL_SIZE * CELL_COUNT) + BOX_SIZE;

                DrawBox(UpX, UpY, DownX + BOX_SIZE, DownY, COLOR_BLACK, 1);
            }

            //横線
            for (int i = 0; i <= CELL_COUNT; i++) {
                int leftX = MAP_MARGIN_X;
                int leftY = MAP_MARGIN_Y + (CELL_SIZE * i);
                int rightX = leftX + (CELL_SIZE * CELL_COUNT) + BOX_SIZE;
                int rightY = leftY;
                DrawBox(leftX, leftY, rightX, rightY + BOX_SIZE, COLOR_BLACK, 1);
            }

            drawMapValue();

            //優勝判定
            for (int x = 0; x < CELL_COUNT; x++) {
                if (MAP[0][x] == MapStatus::Circle && MAP[1][x] == MapStatus::Circle && MAP[2][x] == MapStatus::Circle) {
                    drawText(DrawType::LEFT, 0, 60, 15, "〇-縦 優勝", COLOR_BLACK, COLOR_WHITE);
                    end_result = 0;
                    status = GameStatus::ENDING;
                    timer = 0;
                }
                if (MAP[0][x] == MapStatus::Cross && MAP[1][x] == MapStatus::Cross && MAP[2][x] == MapStatus::Cross) {
                    drawText(DrawType::LEFT, 0, 60, 15, "×-縦 優勝", COLOR_BLACK, COLOR_WHITE);
                    end_result = 1;
                    status = GameStatus::ENDING;
                    timer = 0;
                }
            }
            for (int y = 0; y < CELL_COUNT; y++) {
                if (MAP[y][0] == MapStatus::Circle && MAP[y][1] == MapStatus::Circle && MAP[y][2] == MapStatus::Circle) {
                    drawText(DrawType::LEFT, 0, 120, 15, "〇-横 優勝", COLOR_BLACK, COLOR_WHITE);
                    end_result = 2;
                    status = GameStatus::ENDING;
                    timer = 0;
                }
                if (MAP[y][0] == MapStatus::Cross && MAP[y][1] == MapStatus::Cross && MAP[y][2] == MapStatus::Cross) {
                    drawText(DrawType::LEFT, 0, 120, 15, "×-横 優勝", COLOR_BLACK, COLOR_WHITE);
                    end_result = 3;
                    status = GameStatus::ENDING;
                    timer = 0;
                }
            }

            break;
        case GameStatus::ENDING:
            drawText(DrawType::CENTER, WIDTH * 0.5, HEIGHT * 0.4, 30, "ゲーム終了!", COLOR_RED, COLOR_WHITE);
            if (end_result == 0 || end_result == 2) {
                drawText(DrawType::CENTER, WIDTH * 0.5, HEIGHT * 0.5, 30, "○ の優勝です!", COLOR_RED, COLOR_WHITE);
            }
            else if (end_result == 1 || end_result == 3) {
                drawText(DrawType::CENTER, WIDTH * 0.5, HEIGHT * 0.5, 30, "× の優勝です!", COLOR_BLUE, COLOR_WHITE);
            }
            drawText(DrawType::CENTER, WIDTH * 0.5, HEIGHT * 0.6, 30, "タイトル画面に戻るにはESCキーを押してください", COLOR_WHITE, COLOR_BLACK);

            if (timer % 200 == 0 || CheckHitKey(KEY_INPUT_ESCAPE)) {
                initGame();
            }

            break;
        }

        DxLib::ScreenFlip();
        DxLib::WaitTimer(1000 / FPS);
        if (ProcessMessage() == -1) {
            break;
        }
    }
    DxLib::DxLib_End();
    return 0;
}