#include "GameStartMenu.h"
#include "dialogues.h"
#include "battle.h"
#include "HealthBar.h"
#include "Found.h"


bool no_repetir = true;


void GameStart() {
    SetConsoleOutputCP(CP_UTF8);
    if(no_repetir){
    RunCharacterMenu();
    }
    
    vector<vector<string>> FightBattles = {
        {"FirstBattle.txt", "FirstBattleDefeat.txt", "FirstBattleWin.txt", "FirstBattleWin.txt"},
        {"SecondBattle.txt", "SecondBattleDefeat.txt", "SecondBattleWin.txt", "SecondBattleWin.txt"},
        {"LeaguePresident.txt", "LeaguePresidentDefeat.txt", "LeaguePresidentWin.txt", "LeaguePresidentWin.txt"},
        {"SecretBoss.txt", "SecretBossDefeat.txt", "SecretBossNormalWin.txt", "SecretBossGoodWin.txt"},
        {"FinalBoss.txt", "FinalBossDefeat.txt", "FinalBossNormalWin.txt", "FinalBossGoodWin.txt"}
    };

    
    bool Defeat = false, NormalWin = false, GoodWin = false;
    //Battle basic structure
    for(int battle=0; battle < 5; battle++) {
        int IdEnemy1=3; // Change based on the enemy
        PrintBackgroundDialogue("TowerBackground.txt", TowerColorID, FightBattles[battle][0]);
        
        //FIGHT LOOKS
        bool siguen = true;
        float modificador = 0;
        float Enemy_modificador = 0;
        int maxTurns=0;
        int CantObjetos[4] = {3, 3, 3, 3};
        SivarmonDataBase Jugador = SivarmonesCall(SelecterCharacter);
        SivarmonDataBase Enemy = SivarmonesCall(IdEnemy1);
        int VidaOriginal1 = Jugador.vida;
        int EnemyOriginalLife = Enemy.vida; 
        PrintBattleEnemies(SelecterCharacter, IdEnemy1);
        int Seleccion;
        do
        {
           bool IsMove;
           if(maxTurns>20){
            NormalWin=1;
            Defeat=0;
            GoodWin=0;
            break;
        }
        maxTurns++;
        MovesMenu(SelecterCharacter, IdEnemy1, IsMove, Seleccion );
        PrintLifeBar(Jugador.vida, VidaOriginal1);
        PrintLifeEnemy(Enemy.vida, EnemyOriginalLife);
        // cout<<Seleccion << "HOla";
        Battlebucle(Seleccion, siguen, IsMove, modificador, Enemy_modificador,CantObjetos,
            Jugador, Enemy, Defeat, NormalWin, GoodWin, VidaOriginal1);
            PrintLifeBar(Jugador.vida, VidaOriginal1);
            PrintLifeEnemy(Enemy.vida, EnemyOriginalLife);
            
        } while (siguen && maxTurns<=19);
        
        //HERE GOES THE BATTLE CHANGES
        
        if(Defeat){
            system("cls");
            PrintBackgroundDialogue("YouWinBackground.txt", YourWinColorID, FightBattles[battle][1]);
            sleep_for(0.1s);
            return; //Go back to the main menu
        }
        else if(NormalWin){
            PrintBackgroundDialogue("ParadiseBackground.txt", ParadiseColorID, FightBattles[battle][2]);
            no_repetir= false;
        }
        else{
            PrintBackgroundDialogue("ParadiseBackground.txt", ParadiseColorID, FightBattles[battle][3]);
            no_repetir=false;
        }
        sleep_for(0.1s);
    }
    // call the found funtion to print the lost sprite
    FOUND_ED();
    vector<string> FinalEnd = {
        "Congratulation, you made it this far....",
        "thanks to you Sr.Cabani is finally found",
        "he will always remember you as the hero you are",
        "have a great day"
        "SIVARMON HERO"
    };
    cout<<endl<<endl;
    int rows, cols;
    GetConsoleSize(rows, cols);
    for(int i = 0;i < 4; i++) {
        string line= FinalEnd[i]; // print each line of the good bye text centered
        cout<<string((cols-line.size())/2, ' ');
        PrintTypewriter(line);
        getch();
        cout << "\r\033[K";
    }
    cout << string((cols-FinalEnd[4].size())/2, ' ') << NEGRITA << FG_ORANGE << FinalEnd[4] << RESET << endl;
    //print the last element different color
    sleep_for(1s);
    getch();
    
}

void About() {
    // we do the printing of the information of the game
    system("cls");
    int rows, cols;
    GetConsoleSize(rows, cols);
    PrintSivarMesagge(GameName);
    cout<<endl;
    string aboutG= "ABOUT THE GAME";
    //print the title
    cout<<string(cols/2 - aboutG.size()/2, ' ') << FG_ORANGE << aboutG << RESET << endl << endl;
    //a vector full of information and facts about the game
    vector<string> GameExplanation = {
        "Welcome to the world of Sivarmons!",
        "Once you choose your Sivarmon, your journey begins",
        "You will face three intense battles, each more challenging than the last",
        "In each fight, you can use powerful attacks or helpful items",
        "Choose your strategy wisely — your victory depends on it!",
        "If you win all three battles... something unexpected might happen",
        "A mysterious villain may reveal themselves when you least expect it",
        "Will you be strong enough to face the ultimate challenge?"
    };
    for(string line: GameExplanation){
        cout<<string(cols/2 - line.size()/2, ' '); // this is like padding to make centered the text
        cout<<line<<endl; //and print each line of the information
    }
    getch(); //wait for a key
}

void Credits() {
    //Center all the text and print all the name of the members of the group
    int rows, cols;
    GetConsoleSize(rows, cols);
    PrintSivarMesagge(GameName);
    for(int i=0;i<3;i++) cout<<endl;
    cout << string((cols/2)-(27/2), ' ') << BG_BLACK << FG_ORANGE << NEGRITA << "THIS GAME EXISTS THANKS TO" << RESET << endl;
    for(int i=0;i<2;i++) cout<<endl; //Leave spaces between text
    //Make the names strings to get the size easier
    string name1 = "Diego Armando Mata Cortez [00115025]\n";
    string name2 = "Manuel Tobar Garcia [00067423]\n";
    string name3 = "Andy Samuel Ochoa Gonzalez [00064825]\n";
    string name4 = "Claudia Sofia Pocasangre Peralta [00005225]\n";

    cout << string((cols)/2 - (name1.size())/2, ' ') << name1 <<endl; //print on the center with padding
    cout << string((cols)/2 - (name2.size())/2, ' ') << name2 <<endl;
    cout << string((cols)/2 - (name3.size())/2, ' ') << name3 <<endl;
    cout << string((cols)/2 - (name4.size())/2, ' ') << name4 <<endl;
    getch();
}
