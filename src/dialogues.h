#include "header.h"

map<char, int> ParadiseColorID = {
    {'|', 249},
    {'=', 110},
    {'-', 153},
    {'.', 251},
    {'$', 254},
    {'@', 15},
    {'a', 142},
    {'b', 136},
    {'&', 150},
    {'+', 70},
    {'x', 28},
    {'o', 22},
    {'h', 94},
    {'*', 12},
    {'%', 75},
    {'#', 251}
};

map<char, int> TowerColorID = {
    {'+', 153},
    {'%', 173},
    {'&', 69},
    {'*', 8},
    {'=', 7},
    {'-', 240},
    {'#', 196},
    {':', 2},
    {'.', 121},
    {'@', 15},
    {'&', 160},
    {'o', 14}, 
    {'x', 33},  
    {'h', 10}, 
    {'%', 94},
    {'$', 250},
    {'=', 248},
    {'|', 249} 
};

map<char, int> YourWinColorID = {
    {'%', 55},
    {'*', 98},
    {'+', 141},
    {'-', 183},
    {'.', 15}
};

void PrintTypewriter(const string& text) {
    for (char ch : text) {
        cout << ch << flush;
        sleep_for(30ms);
    }
}

void PrintBackgroundDialogue(const string& filename, const map<char, int>& ColorMap, const string& dialogueName){
    system("cls");
    int rows, columns;
    GetConsoleSize(rows, columns);
    string NewFileName= "src/"+filename;
    ifstream file(NewFileName);
    string line;
    int backgroundLines = 0, maxLineLength=0;

    if (file.is_open()) {
        while (file >> line) {
            backgroundLines++;
            if ((int)line.length() > maxLineLength) {
                maxLineLength = line.length();
            }
            int padding = (columns - (int)line.length()) / 2;
            if (padding < 0) padding = 0;
            cout << string(padding, ' ');
            for (char ch : line) {
                int color = ColorMap.count(ch) ? ColorMap.at(ch) : 16;
                cout << "\033[48;5;" << color << "m "; 
            }
            cout << RESET << endl;
        }
        file.close();
    }
    else {
        // cout<<"ERROR\n";
    }

    vector<string> dialogue;
    string DialogueFile = "src/BattleDialogues/" + dialogueName;
    ifstream fila (DialogueFile);

    if (fila.is_open()) {
        while (getline(fila, line)) {
            dialogue.push_back(line);
        }
        fila.close();
    } else{
        // cout<<"ERROR\n";
    }

    int currentRow = backgroundLines + 2;
    int dialogueHeight = 4;
    int boxTopRow = backgroundLines + 1;
    int boxLeftCol = (columns - maxLineLength) / 2 + 1;
    int textRow = boxTopRow + 1;
    int promptRow = boxTopRow + 2;
    int promptCol = boxLeftCol + maxLineLength - 3;

    for (const string& line : dialogue) {

        for(int i = 0; i < dialogueHeight; i++){
            cout << "\033[" << (boxTopRow + i) << ";" << boxLeftCol << "H";
            cout << RESET << BG_WHITE << string(maxLineLength, ' ') << RESET;
        }

        int linePadding = (maxLineLength - (int)line.length()) / 2;
        if (linePadding < 0) linePadding = 0;

        cout << "\033[" << textRow << ";" << (boxLeftCol + linePadding) << "H";
        cout << BG_WHITE << FG_BLACK << NEGRITA;
        PrintTypewriter(line);
        cout << RESET << flush;

        for (;;) {
            cout << "\033[" << promptRow << ";" << promptCol << "H"
                << BG_WHITE << FG_BLACK << ">>" << RESET << flush;
            this_thread::sleep_for(500ms);

            cout << "\033[" << promptRow << ";" << promptCol << "H"
                << BG_WHITE << "  " << RESET << flush;
            this_thread::sleep_for(500ms);

            if (_kbhit()) {
                _getch();
                break;
            }
        }

        for (int i = 0; i < dialogueHeight; i++) {
            cout << "\033[" << (boxTopRow + i) << ";" << boxLeftCol << "H"
                << BG_WHITE << string(maxLineLength, ' ') << RESET;
        }
    }
    sleep_for(1s);
    system("cls");
}


