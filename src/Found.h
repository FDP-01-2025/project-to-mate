#include "header.h"
#include "Utils.cpp"
#include "DataBaseOutput.h"

vector<string> FoundMessage = {
    "                                                                                ",
    "                                                                                ",
    "                                                                                ",
    "                      @@@@@      @@@@   @@@@    @@@@@  @@@     @@@@@            ",
    "       @@@@@@@@     @@@@@@@@@    @@@@   @@@@    @@@@@  @@@     @@@@@@@@@        ",
    "       @@@@@@@@    @@@@  @@@@    @@@@   @@@@    @@@@@  @@@     @@@@ @@@@@       ",
    "       @@@@        @@@@   @@@@   @@@@   @@@@    @@@@@  @@@     @@@@  @@@@       ",
    "       @@@@        @@@@   @@@@   @@@@   @@@@    @@@@@  @@@     @@@@  @@@@       ",
    "       @@@@@@@@    @@@@   @@@@   @@@@   @@@@    @@@@@@@@@@     @@@@  @@@@       ",
    "       @@@@@@@@     @@@   @@@@   @@@@   @@@@    @@@@ @@@@@    @@@@   @@@@       ",
    "        @@@         @@@   @@@@   @@@@   @@@@    @@@@ @@@@@    @@@@   @@@@       ",
    "        @@@@        @@@@  @@@@   @@@@   @@@@    @@@@ @@@@@    @@@@   @@@        ",
    "        @@@@        @@@@  @@@@    @@@@ @@@@     @@@@ @@@@@    @@@@  @@@@        ",
    "        @@@@         @@@@@@@@     @@@@@@@@      @@@  @@@@    @@@@@@@@@@         ",
    "        @@@@          @@@@@          @@@       @@@@  @@@@    @@@@@@@@@          "
};

map<char, int> FoundIDColor = {
    {'@', 196},
    {' ', 232}
};

void FoundBackground() {
    cout << BG_BLACK;
    cout << "\033[2J";
    cout << "\033[H";        
}

void printFoundMessage(){
    SetConsoleOutputCP(CP_UTF8);
    int rows, cols;
    GetConsoleSize(rows, cols);

    for (const string &line : FoundMessage) {
        int padding = (cols - (int)line.length()) / 2;
        if (padding < 0) padding = 0;
        cout << BG_BLACK << string(padding, ' ');
        cout << RESET;
        for (char ch : line) {
            int color = FoundIDColor.count(ch) ? FoundIDColor[ch] : 232;
            cout << "\033[48;5;" << FoundIDColor[ch] << "m "; 
        }
        cout << RESET << endl;
    }
    cout<<endl;
}

void PrintFoundSprite(){
    int rows, cols;
    GetConsoleSize(rows, cols);
    SetConsoleOutputCP(CP_UTF8);
    SivarmonDataBase  FOUND = SivarmonesCall (9);
    SpritesDataBase FoundSprite = SpritesCall (FOUND.idSprite);
    int spriteHeight = FoundSprite.Sprite.size();
    int startRow = FoundMessage.size() + 2;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // cout<<"ID del sprite: " << FOUND.idSprite << endl;
    if(FoundSprite.Sprite.size()==0) cout<<"NO LLEGA\n";

    for (int i = 0; i < spriteHeight; i++) {
        const string& line = FoundSprite.Sprite[i];
        int padding = 60;
        if (padding < 0) padding = 0;

        COORD pos = { (SHORT)padding, (SHORT)(startRow + i) };
        SetConsoleCursorPosition(hConsole, pos);
        for (char ch : line) {
            if (ch != ' ') {
                cout << ch;
            } else {
                cout << BG_BLACK << " "; 
            }
        }
    }
}

void FOUND_ED(){
    system("cls");
    FoundBackground();
    printFoundMessage();
    PrintFoundSprite();
   
}
