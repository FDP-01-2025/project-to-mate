#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <map> 
#include <vector>
#include <string.h>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;

// Funtions
void GetConsoleSize(int &rows, int &columns);
void mainPageLogo();
void mostrarMenu(const vector<string>& MainMenu, int choice);
void GameStart();
void About();
void Credits();
void StartGameMenu();
void PrintTypewriter(const string& text);
void NotFoundMessage();
void PrintBackgroundDialogue(const string& filename, const map<char, int>& ColorMap, const string& dialogueName);


// RESET and styles
const string RESET    = "\033[0m";
const string NEGRITA  = "\033[1m";
const string SUBRAYADO = "\033[4m";
const string INVERSO  = "\033[7m";
const string FLICKERING = "\033[5m";
const string CLEAR_LINE = "\r\033[K";

// Text colors (foreground)
const string FG_BLACK   = "\033[38;5;232m";
const string FG_RED    = "\033[31m";
const string FG_GREEN   = "\033[32m";
const string FG_YELLOW= "\033[33m";
const string FG_BLUE    = "\033[34m";
const string FG_MAGENTA = "\033[35m";
const string FG_CYAN    = "\033[36m";
const string FG_WHITE  = "\033[38;5;15m";
const string FG_VIOLET = "\033[38;5;128m";
const string FG_PINK = "\033[38;5;163m";
const string FG_LIGHTBLUE = "\033[38;5;111m";
const string FG_ORANGE ="\033[38;5;216m";
const string FG_DEEP_BLUE ="\033[38;5;17m";
// BackgroundColors(background)
const string BG_BLACK = "\033[48;5;232m";
const string BG_RED = "\033[41m";
const string BG_GREEN = "\033[42m";
const string BG_YELLOW = "\033[43m";
const string BG_BLUE = "\033[44m";
const string BG_MAGENTA = "\033[45m";
const string BG_CYAN = "\033[46m";
const string BG_WHITE = "\033[48;5;15m";
const string BG_VIOLET = "\033[48;5;128m";
const string BG_PINK = "\033[48;5;163m";
const string BG_LIGHTBLUE = "\033[48;5;111m";
const string BG_ORANGE ="\033[48;5;216m";
const string BG_DEEP_BLUE ="\033[48;5;17m";
#endif
