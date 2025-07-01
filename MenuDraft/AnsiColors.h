#include <iostream>
using namespace std;

// RESET y estilos
const string RESET    = "\033[0m";
const string NEGRITA  = "\033[1m";
const string SUBRAYADO = "\033[4m";
const string INVERSO  = "\033[7m";
const string FLICKERING = "\033[5m";

// Colores de texto (foreground)
const string FG_BLACK   = "\033[30m";
const string FG_RED    = "\033[31m";
const string FG_GREEN   = "\033[32m";
const string FG_YELLOW= "\033[33m";
const string FG_BLUE    = "\033[34m";
const string FG_MAGENTA = "\033[35m";
const string FG_CYAN    = "\033[36m";
const string FG_WHITE  = "\033[37m";
const string FG_VIOLET = "\033[38;5;128m";
const string FG_PINK = "\033[38;5;163m";
const string FG_LIGHTBLUE = "\033[38;5;111m";
const string FG_ORANGE ="\033[38;5;216m";

// Colores de fondo (background)
const string BG_BLACK = "\033[30m";
const string BG_RED = "\033[41m";
const string BG_GREEN = "\033[42m";
const string BG_YELLOW = "\033[43m";
const string BG_BLUE = "\033[44m";
const string BG_MAGENTA = "\033[45m";
const string BG_CYAN = "\033[46m";
const string BG_WHITE = "\033[47m";
const string BG_VIOLET = "\033[48;5;128m";
const string BG_PINK = "\033[48;5;163m";
const string BG_LIGHTBLUE = "\033[48;5;111m";
const string BG_ORANGE ="\033[48;5;216m";

//Modelo para el cout
// cout << [ESTILO] << [COLOR_FG] << [COLOR_BG] << "Texto" << RESET;
