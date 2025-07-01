#include "header.h"

void mainPageLogo() {
    vector<string> logoLines = {
        "                                                                                                                   ",
        "                                                                                                                   ",
        "                               @@@ @       @@              @@@@@     @@@@       @                                  ",
        "                 @@@    @@@@     @@@        @@@@       @@     @@@@    @@@@   @@@@@        @@@@                     ",
        "      @@@@  @    @@@@     @@@    @@          @@@@      @@@    @@@     @@@@  @@@@ @    @     @@@@     @@@@   @@     ",
        "    @   @@@@@    @@@@     @@@@    @       @   @@@@     @@@@  @@      @ @@@@@@@@      @@      @@@@     @@@@  @@@    ",
        "    @@@           @@@      @@@@  @       @@   @@@@     @@@@   @@     @    @@    @   @@@@      @@@      @@@@  @@    ",
        "     @@@@@@@@@    @@@       @@@@        @@@@   @@@@    @@@@  @@@@    @@@      @@@    @@@@      @@   @   @@@@ @@    ",
        "           @@@@   @@@@         @@       @@@@    @@@@@  @@@@   @@@@@ @@@@     @@@@    @@@@@     @    @@  @@@@       ",
        "     @@@@@       @@@@                                                         @@      @@@@@        @@@   @@@@      ",
        "     @@@@@@@@@                                                                                      @@@      @     "
    };

    int rows, columns;
    GetConsoleSize(rows, columns);

    int logoHeight = logoLines.size();
    int logoStartY = (rows - logoHeight) / 2 - 2; // Centramos un poco más arriba
    int logoStartX;

    system("cls");

    // Mostrar el logo centrado
    for (int i = 0; i < logoLines.size(); ++i) {
        string line = logoLines[i];
        logoStartX = max(0, (columns - (int)line.length()) / 2);

        COORD coord;
        coord.X = logoStartX;
        coord.Y = logoStartY + i;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        cout << NEGRITA << line << RESET;
    }

    string message = "PRESS ANY KEY TO START";
    int messageX = max(0, (columns - (int)message.length()) / 2);
    int messageY = logoStartY + logoLines.size() + 2;

    vector<string> colores = {
        FG_RED, FG_YELLOW, FG_GREEN, FG_CYAN, FG_BLUE, FG_MAGENTA, FG_WHITE, FG_PINK
    };

    int colorIndex = 0;

    while (!_kbhit()) {
        COORD coord;
        coord.X = messageX;
        coord.Y = messageY;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        cout << colores[colorIndex % colores.size()] << FLICKERING << NEGRITA
             << message << RESET << flush;

        colorIndex++;
        sleep_for(300ms);
    }

    getch(); // Espera la tecla
}


void mostrarMenu(const vector<string>& MainMenu, int choice) {
    int rows, columns;
    GetConsoleSize(rows, columns);
    
    int BoxWide = 80;
    int BoxHeight = MainMenu.size() + 2;
    
    int x = (columns - BoxWide) / 2;
    int y = (rows - BoxHeight) / 2;

    system("cls");

    for (int i = 0; i < y; ++i) cout << endl;

    cout << string(x, ' ') << "+" << string(BoxWide - 2, '-') << "+" << endl;
    cout << string(x, ' ') << "|" << string(BoxWide - 2, ' ') << "|" << endl;

    for (int i = 0; i < MainMenu.size(); ++i) {
        string message = (i == choice ? "> " : "  ") + MainMenu[i];
        message += string(BoxWide - 2 - message.length(), ' ');

        cout << string(x, ' ') << "|";

        if (i == choice) {
            cout << BG_VIOLET << FG_WHITE << NEGRITA << message << RESET;
        } else {
            cout << BG_BLACK << FG_VIOLET << message << RESET;
        }

        cout << "|" << endl;
    }

    cout << string(x, ' ') << "|" << string(BoxWide - 2, ' ') << "|" << endl;
    cout << string(x, ' ') << "+" << string(BoxWide - 2, '-') << "+" << endl;
}
