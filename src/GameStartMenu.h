#include "menu.h"
#include "utils.cpp"
int SelecterCharacter = 0;

void StartGameMenu(){
    system("cls");
    PrintSivarMesagge(GameName);
    int rows, cols;
    GetConsoleSize(rows, cols);

    string CharElection = "CHOOSE YOUR CHARACTER";

    COORD cursorPos;
    cursorPos.X = (cols - CharElection.size()) / 2;
    cursorPos.Y = (int)GameName.size();

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
    cout << FLICKERING << NEGRITA << BG_BLACK << FG_WHITE  << CharElection << RESET << flush;
    cout<<endl;

}

void NotFoundMessage(){
    int col, row;
    GetConsoleSize(row, col);
    string ErrorMessage="THE CURRENT CHARACTER CANNOT BE SELECTED O IS NOT FOUND, PLEASE CHOOSE ANOTHER ONE";
    cout<<string((col-ErrorMessage.size())/2, ' ')<< NEGRITA << FG_RED << ErrorMessage << RESET << endl;
    sleep_for(4s);
    system("cls");
}

void RunInteractiveMenu() {
    StartGameMenu();
    PrintSivarMapLeft();
    PrintMenuRight(SelecterCharacter, (int)SivarmonMap.size());

    while (true) {
        if (_kbhit()) {
            int key = _getch();
            if (key == 224) {
                key = _getch();
                if (key == 72) SelecterCharacter = (SelecterCharacter - 1 + (int)SivarMenu.size()) % SivarMenu.size(); // ARRIBA
                if (key == 80) SelecterCharacter = (SelecterCharacter + 1) % SivarMenu.size(); // ABAJO
            } else if (key == 13) {
                if (SelecterCharacter == 8) {
                    StartGameMenu(); 
                    NotFoundMessage();
                    StartGameMenu(); 
                    PrintSivarMapLeft();
                    PrintMenuRight(SelecterCharacter, (int)SivarmonMap.size());
                    continue;
                }
                SelecterCharacter++;
                return;
            }
            PrintMenuRight(SelecterCharacter, (int)SivarmonMap.size());
        }
    }
    SelecterCharacter++;
}

void RunCharacterMenu(){
    system("cls");
    FillColor();
    int col, row, Id=0;
    GetConsoleSize(row, col);
    for(int i=0;i<(row/2)-LoadingClock.size();i++) cout<<'\n';
    PrintSivarMesagge(LoadingClock);
    vector<string> GameStatus={"GAME STARTING", "LOADING"};
    for(int i=0;i<6;i++){
        Id^=1;
        cout << '\r' << string(col, ' ') << '\r'; 
        cout << string((col - GameStatus[Id].size()) / 2, ' ') << FG_WHITE << GameStatus[Id] << RESET << flush;

        sleep_for(1s);
        
    }
    StartGameMenu();
    RunInteractiveMenu();
    // cout<<"Aqui si llega\n";
    sleep_for(600ms);
    // system("cls");
}
