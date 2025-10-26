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
    SetWindowText("ŽO–Ú•À‚×");
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
        sprintf(timer_text, "ŽžŠÔ: %d", timer);
        drawText(DrawType::LEFT, 0, 0, 15, timer_text, COLOR_BLACK, COLOR_WHITE);

        switch (status){
        case GameStatus::WAITING:
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