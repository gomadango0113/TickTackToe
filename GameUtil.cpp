#include <DxLib.h>
#include <string>
#include "GameUtil.h"

void drawText(DrawType type, int x, int y, int size, const char* text, unsigned int text_color, unsigned int edge_color) {
    SetFontSize(size);
    ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
    int strWidth = GetDrawStringWidth(text, strlen(text));
    if (type == DrawType::LEFT) {
        //
    }
    else if (type == DrawType::RIGHT) {
        x -= strWidth;
    }
    else if (type == DrawType::CENTER) {
        x -= strWidth / 2;
        y -= size / 2;
    }


    DrawString(x, y, text, text_color, edge_color);
}