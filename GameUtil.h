#include <DxLib.h>

enum DrawType {
    LEFT,
    CENTER,
    RIGHT
};

const int COLOR_WHITE = GetColor(255, 255, 255);
const int COLOR_BLACK = GetColor(0, 0, 0);
const int COLOR_RED = GetColor(220, 20, 60);
const int COLOR_BLUE = GetColor(0, 0, 140);

void drawText(DrawType type, int x, int y, int size, const char* text, unsigned int text_color, unsigned int edge_color);