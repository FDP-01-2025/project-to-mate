#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include "AnsiColors.h"  

using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;


void GetConsoleSize(int &rows, int &columns) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void mainPageLogo(){

    vector<string> logoLines={
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

    // Encontrar la línea más larga del logo
    int maxLength = 0;
    for (int i=0; i<logoLines.size();i++) {
        string line=logoLines[i];
        if (line.length() > maxLength) maxLength = line.length();
    }

    for (int i=0; i<logoLines.size();i++) {
        string line=logoLines[i];
        int padding = max(0, (columns - (int)line.length()) / 2);
        cout << string(padding, ' ') << NEGRITA << line << RESET << endl;
    }

    string message = "CLICK ANY KEY TO START";
    int messagePadding = max(0, (columns - (int)message.length()) / 2);
    cout << endl << string(messagePadding, ' ') << FLICKERING << FG_PINK << NEGRITA << message << RESET << endl;
    for(int i=0;i<10;i++){
        cout<<endl;
    }
    cout<<FG_BLUE<<NEGRITA<<"2025 TO->MATE INC"<<RESET<<endl;

    getch(); 
}

void GameStart(){
    //Llamar el archivo del juego xd
}

void Options(){
    cout<<"How to play?\n\tAfter selecting a character, you will face game battles where\n you can atack, defend or just leave :v\n";
}

void Credits(){
    cout<<BG_MAGENTA<<FG_BLACK<<NEGRITA<<"THIS GAME EXIST THANKS TO:\n"<<RESET;
    cout<<"Diego Armando Mata Cortez [00115025]\nManuel Tobar Garcia [00067423]\nAndy Samuel Ochoa Gonzalez [00064825]\nClaudia Sofia Pocasangre Peralta [00005225]\n";
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

        // Si esta seleccionado
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

int main() {
    system("chcp 850 > nul");
    vector<string> MainMenu = {
        "Start game",
        "Options",
        "Credits",
        "Leave"
    };

    int choice = 0;
    char key;
    mainPageLogo();
    // apretar cualquier tecla
    system("cls");
    while (true) {
        mostrarMenu(MainMenu, choice);
        key = getch();

        if (key == -32) {
            key = getch();
            if (key == 72) choice = (choice - 1 + MainMenu.size()) % MainMenu.size(); // ↑
            if (key == 80) choice = (choice + 1) % MainMenu.size(); // ↓
        } else if (key == 'w' || key == 'W') {
            choice = (choice - 1 + MainMenu.size()) % MainMenu.size();
        } else if (key == 's' || key == 'S') {
            choice = (choice + 1) % MainMenu.size();
        } else if (key == '\r') {
            system("cls");
            cout << "choiceaste: " << MainMenu[choice] << endl;
            switch(choice){
                case 0:
                    GameStart();
                    break;
                case 1:
                    Options();
                    break;
                case 2:
                    Credits();
                    break;
                case 3:
                    cout<<"bye bye\n";
                    break;
                default:
                    break;
            }
            break;
        }
    }
    sleep_for(std::chrono::milliseconds(5000));
    system("cls");

    return 0;
}
