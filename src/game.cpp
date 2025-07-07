#include "GameStartMenu.h"
#include "dialogues.h"
#include "BattleInterface.h"

void GameStart() {
    RunCharacterMenu();
    
    vector<vector<string>> FightBattles = {
        {"FirstBattle.txt", "FirstBattleDefeat.txt", "FirstBattleWin.txt", "FirstBattleWin.txt"},
        {"SecondBattle.txt", "SecondBattleDefeat.txt", "SecondBattleWin.txt", "SecondBattleWin"},
        {"FinalBoss.txt", "FinalBossDefeat.txt", "FinalBossNormalWin.txt, FinalBossGoodWin.txt"},
        {"SecretBoss.txt", "SecretBossDefeat.txt", "SecretBossNormalWin.txt", "SecretBossGoodWin.txt"},
        {"LeguePresident.txt", "LeaguePresidentDefeat.txt", "LeaguePresidentWin.txt", "LeguePresidentWin.cpp"}
    };
    
    bool Defeat = false, NormalWin = false, GoodWin = false;
    //Battle basic structure
    for(int battle=0; battle < 5; battle++) {
        int IdEnemy1=3; // Change based on the enemy
        PrintBackgroundDialogue("TowerBackground.txt", TowerColorID, FightBattles[battle][0]);
        
        //FIGHT LOOKS
        PrintBattleEnemies(SelecterCharacter, IdEnemy1);
        MovesMenu(SelecterCharacter, IdEnemy1);
        
        //HERE GOES THE BATTLE CHANGES

        if(defeat){
            PrintBackgroundDialogue("YouWin.txt", YourWinColorID, FightBattles[battle][1]);
            return; //Go back to the main menu
        }
        else if(NormalWin){
            PrintBackgroundDialogue("Paradise.txt", ParadiseColorID, FightBattles[battle][2]);
        }
        else{
            PrintBackgroundDialogue("Paradise.txt", TowerColorID, FightBattles[battle][3]);
        }
    }
    
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
