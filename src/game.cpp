#include "GameStartMenu.h"
#include "dialogues.h"
#include "BattleInterface.h"

void GameStart() {
    RunCharacterMenu();
    PrintBackgroundDialogue("TowerBackground.txt", TowerColorID, "FirstBattle.txt");
    int IdEnemy1=3;
    PrintBattleEnemies(SelecterCharacter, IdEnemy1);
    MovesMenu(SelecterCharacter, IdEnemy1);

}

void About() {
    cout << "How to play?\n\tAfter selecting a character, you will face game battles\nwhere you can attack, defend or just leave.\n";
    getch();
}

void Credits() {
    cout << BG_MAGENTA << FG_BLACK << NEGRITA << "THIS GAME EXISTS THANKS TO:\n" << RESET;
    cout << "Diego Armando Mata Cortez [00115025]\n";
    cout << "Manuel Tobar Garcia [00067423]\n";
    cout << "Andy Samuel Ochoa Gonzalez [00064825]\n";
    cout << "Claudia Sofia Pocasangre Peralta [00005225]\n";
    getch();
}
