#include "header.h"
using namespace std;

void enableANSIColors() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    if (GetConsoleMode(hOut, &mode)) {
        mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, mode);
    }
}

bool isInOval(int x, int y, int centerX, int centerY, int radiusX, int radiusY) {
    float dx = float(x - centerX) / radiusX;
    float dy = float(y - centerY) / radiusY;
    return (dx * dx + dy * dy) <= 1.0f;
}


void drawBackgroundWithOvals() {
    int rows, cols;
    GetConsoleSize(rows, cols);

    int half = rows / 2;
    int radiusX = min(rows, cols) / 3;
    int radiusY = min(rows, cols) / 16;

    int c1_x = cols / 4;
    int c2_x = 3 * cols / 4;

    int c1_y = half + half / 2 - 7;
    int c2_y = half + half / 2 - 7;


    for (int i = 0; i < rows; ++i) {    
        for (int j = 0; j < cols; ++j) {  
            if (i < half) {
                cout << BACK_BLUE << " ";    
            } else {
                if (isInOval(j, i, c1_x, c1_y, radiusX, radiusY) ||
                    isInOval(j, i, c2_x, c2_y, radiusX, radiusY)) {
                    cout << BG_WHITE << " "; 
                } else {
                    cout << BACK_GREEN << " "; 
                }
            }
        }
        cout << RESET << '\n';
    }
}
