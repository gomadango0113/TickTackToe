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
    SetWindowText("éOñ⁄ï¿Ç◊");
    SetGraphMode(WIDTH, HEIGHT, COLORBIT);
    ChangeWindowMode(true);

    if (DxLib_Init() == -1) {
        return -1;
    }
    SetBackgroundColor(0, 0, 0);
    SetDrawScreen(DX_SCREEN_BACK);
    initGame();

    while (true) {
        ClearDrawScreen();
        GetMousePoint(&mouseX, &mouseY);
        timer++;

        char timer_text[100];
        sprintf(timer_text, "éûä‘: %d", timer / 60);
        drawText(DrawType::LEFT, 0, 0, 15, timer_text, COLOR_BLACK, COLOR_WHITE);
        
        switch (status){
        case GameStatus::WAITING:

            //ècê¸
            for (int i = 0; i <= CELL_COUNT; i++) {
                int UpX = MAP_MARGIN_X + (CELL_SIZE * i);
                int UpY = MAP_MARGIN_Y;
                int DownX = UpX;
                int DownY = UpY + (CELL_SIZE * CELL_COUNT) + BOX_SIZE;

                DrawBox(UpX, UpY, DownX + BOX_SIZE, DownY, COLOR_WHITE, 1);
            }

            //â°ê¸
            for (int i = 0; i <= CELL_COUNT; i++) {
                int leftX = MAP_MARGIN_X;
                int leftY = MAP_MARGIN_Y + (CELL_SIZE * i);
                int rightX = leftX + (CELL_SIZE * CELL_COUNT) + BOX_SIZE;
                int rightY = leftY;
                DrawBox(leftX, leftY, rightX, rightY + BOX_SIZE, COLOR_WHITE, 1);
            }

            break;
        case GameStatus::RUNNING:
            break;
        case GameStatus::ENDING:
            break;
        }

        ScreenFlip();
        WaitTimer(1000 / FPS);
        if (ProcessMessage() == -1) {
            break;
        }
    }
    DxLib_End();
    return 0;
}