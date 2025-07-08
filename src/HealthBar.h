#include "header.h"

string GenerateHPBar(int currentHP, int maxHP) {
    SetConsoleOutputCP(CP_UTF8);
    //Set the health bar measures
    int barWidth = 20;
    float ratio = static_cast<float>(currentHP) / maxHP;
    int filled = (static_cast<int>(ratio * barWidth))%20;
    int empty = barWidth - filled;
    //Set an empty string as a health bar
    string bar = "";

    //Fill the health bar to the current HP 
    for (int i = 0; i < filled; i++){
        bar += " ";
    }
    //Fill the rest
    for (int i = 0; i < empty; i++){
        bar += ' ';
    }
    return bar; //Return the complete health bar
}

void PrintLifeBar (int HP, int maxHP) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (SHORT)1, (SHORT)5});
    //Set the position where the health life is going to be printed
    cout << NEGRITA << BG_WHITE << FG_ORANGE << " HP: " << RESET;
    cout << NEGRITA << BG_WHITE << FG_BLACK << "[" << RESET;
    //First print the beging
    string hpBar = GenerateHPBar(HP, maxHP);
    cout << BG_GREEN << FG_GREEN << hpBar << RESET; //Print the health bar
    cout << NEGRITA << BG_WHITE << FG_BLACK << "] " << HP << "/" << maxHP << RESET; //And print the current and total health diference
}

void PrintLifeEnemy(int HP, int maxHP) {
    //just as before but we are setting the bar to be on the right side of the console
    SetConsoleOutputCP(CP_UTF8);
    int rows, cols;
    GetConsoleSize(rows, cols);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (SHORT)(cols-30), (SHORT)5});
    cout << NEGRITA << BG_WHITE << FG_ORANGE << " HP: " << RESET;
    cout << NEGRITA << BG_WHITE << FG_BLACK << "[" << RESET;
    //First print the beging
    string hpBar = GenerateHPBar(HP, maxHP);
    cout << BG_RED << FG_RED << hpBar << RESET; //Print the health bar
    cout << NEGRITA << BG_WHITE << FG_BLACK << "] " << HP << "/" << maxHP << RESET;
}

