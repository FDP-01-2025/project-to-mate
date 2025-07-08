#include "FightBackground.h"
#include "DataBaseOutput.h"

int lines, bottomline;

void PrintBattleEnemies(int SivarmonSelected, int Enemy){
    SetConsoleOutputCP(CP_UTF8);
    enableANSIColors();                      
    system("cls");           
    drawBackgroundWithOvals();  
    SpritesDataBase OP_SPRITE = SpritesCall(SivarmonSelected);
    SpritesDataBase CPU_SPRITE = SpritesCall(Enemy);

    SetConsoleOutputCP(CP_UTF8);

    int consoleRows, consoleCols;
    GetConsoleSize(consoleRows, consoleCols);

    int maxLeftWidth = 0, maxRightWidth = 0;
    for (const auto& line : OP_SPRITE.Sprite){
        maxLeftWidth = max(maxLeftWidth, (int)line.size());
    }
    for (const auto& line : CPU_SPRITE.Sprite){
        maxRightWidth = max(maxRightWidth, (int)line.size());
    }
    //Oval coordenates declared on  fight background
    int half = consoleRows / 2;
    int c1_x = half + half / 2; 
    int c1_y = consoleCols / 4; 
    int c2_x = c1_x;             
    int c2_y = 3 * consoleCols / 4;
    int centerY = half + half / 2 - 7;

    int centerX1 = consoleCols / 3;
    int ovalRightStartX = c2_y; 

    int centerX2 = ovalRightStartX;

    int offsetY = -1;
    int offsetX = 10; 

    int sprite1_height = OP_SPRITE.Sprite.size();
    int sprite2_height = CPU_SPRITE.Sprite.size();

    int leftStartX = centerX1 - maxLeftWidth / 2 + offsetX;
    int leftStartY = centerY - sprite1_height + 1 + offsetY;

    int spacing = 5; 
    int rightStartX = leftStartX + maxLeftWidth + spacing;

    int rightStartY = centerY - sprite2_height + 1 + offsetY;

    int lines = max(sprite1_height, sprite2_height);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < lines; i++) {
        if (i < sprite1_height) {
            const string& line = OP_SPRITE.Sprite[i];
            COORD pos = { (SHORT)leftStartX, (SHORT)(leftStartY + i) };
            SetConsoleCursorPosition(hConsole, pos);
            for (char ch : line) {
                if (ch != ' ') {
                    cout << ch;
                } else {
                    cout << "\033[C";
                }
            }
        }

        if (i < sprite2_height) {
            const string& line = CPU_SPRITE.Sprite[i];
            COORD pos = { (SHORT)rightStartX, (SHORT)(rightStartY + i) };
            SetConsoleCursorPosition(hConsole, pos);
            for (char ch : line) {
                if (ch != ' ') {
                    cout << ch;
                } else {
                    cout << "\033[C";
                }
            }
        }
    }
    int leftEndY = leftStartY + sprite1_height;
    int rightEndY = rightStartY + sprite2_height;
    bottomline = max(leftEndY, rightEndY);
}


int PrintSelectionMenu(const vector<string>& names, const vector<string>& typeNames, int boxLeftCol, int boxTopRow, int boxWidth) {
    int consoleRows, consoleCols;
    GetConsoleSize(consoleRows, consoleCols);

    int dialogueHeight = 10;
    int selectedIndex = 0;
    int startCol = boxLeftCol + 4;
    int startRow = boxTopRow + 2;
    int colSpacing = 25;
    int rowSpacing = 3;

    auto printOptions = [&]() {
        for (int i = 0; i < names.size(); i++) {
            int row = startRow + (i / 2) * rowSpacing;
            int col = startCol + (i % 2) * colSpacing;
            cout << "\033[" << row << ";" << col << "H";

            string name = names[i].substr(0, 25); 
            int padding = max(0, 14 - (int)name.size());
            string paddedName = name + string(padding, ' ');

            if (i == selectedIndex)
                cout << BG_GREEN << FG_WHITE << "> " << paddedName << RESET;
            else
                cout << BG_WHITE << FG_BLACK << "  " << paddedName << RESET;
        }
    };

    printOptions();

    while (true) {
        // Imprimir descripción del tipo a la derecha
        int typeBoxCol = boxLeftCol + boxWidth + 60;
        if (typeBoxCol + 30 >= consoleCols) {
            typeBoxCol = consoleCols - 30;
        }
        int typeBoxRow = boxTopRow;

        for (int i = 0; i < dialogueHeight; i++) {
            cout << "\033[" << (typeBoxRow + i) << ";" << typeBoxCol << "H";
            cout << BG_WHITE << string(28, ' ') << RESET;
        }

        cout << "\033[" << (typeBoxRow + 2) << ";" << (typeBoxCol + 2) << "H";
        cout << BG_WHITE << FG_BLACK << "TYPE: " << typeNames[selectedIndex] << RESET;

        int key = _getch();
        if (key == 224) {
            int arrow = _getch();
            if (arrow == 72 && selectedIndex >= 2) selectedIndex -= 2;
            else if (arrow == 80 && selectedIndex + 2 < names.size()) selectedIndex += 2;
            else if (arrow == 75 && selectedIndex % 2 == 1) selectedIndex--;
            else if (arrow == 77 && selectedIndex % 2 == 0 && selectedIndex + 1 < names.size()) selectedIndex++;
        } else if (key == '\r') {
            break;
        }

        printOptions();
    }

    return selectedIndex;
}


void MovesMenu(int SivarmonSelected, int Enemy, bool& que, int& seleccion) {
    TiposDataBase OP_TYPES = TiposCall(SivarmonSelected);
    MovimientosDataBase OP_MOVES = MovimientosCall(SivarmonSelected);
    SivarmonDataBase OP_INFO = SivarmonesCall(SivarmonSelected);
    int consoleRows, consoleCols;
    GetConsoleSize(consoleRows, consoleCols);

    int dialogueHeight = 10;
    int boxTopRow = bottomline + 7; 
    int optionBoxWidth = 20;
    int maxLineLength = consoleCols - 35;
    int totalBoxWidth = maxLineLength + optionBoxWidth;
    int boxLeftCol = (consoleCols - totalBoxWidth) / 2;

    for(int i = 0; i < dialogueHeight; i++){
        cout << "    " << RESET << "\033[" << (boxTopRow + i) << ";" << boxLeftCol << "H";
        cout << RESET << BG_WHITE << string(maxLineLength, ' ') << RESET;
    }

    cout << "\033[" << (boxTopRow + 5) << ";" << (boxLeftCol + 3 )<< "H";
    cout << BG_WHITE << FG_BLACK << "What will "<< OP_INFO.nombre << " do?" << RESET;

    vector<string> options = { "ATTACK", "OBJECT" };
    int selected = 0;

    int optionBoxCol = boxLeftCol + maxLineLength;

    for (int i = 0; i < dialogueHeight; i++) {
        cout << "\033[" << (boxTopRow + i) << ";" << optionBoxCol << "H";
        cout << BG_WHITE << string(optionBoxWidth, ' ') << RESET;
    }

    int optionStartCol = optionBoxCol;
    int optionStartRow = boxTopRow;

    auto printOptions = [&]() {
        for (int i = 0; i < dialogueHeight; i++) {
            cout << "\033[" << (optionStartRow + i) << ";" << optionStartCol << "H";
            if (i < options.size()) {
                if (i == selected)
                    cout << BG_GREEN << FG_WHITE << "> " << options[i] << RESET;
                else
                    cout << BG_WHITE << FG_BLACK << "  " << options[i] << RESET;
            } else {
                cout << BG_WHITE << string(optionBoxWidth - 1, ' ') << RESET;
            }
        }
    };

    printOptions();

    while (true) {
        int key = _getch();
        if (key == 224) { 
            int arrow = _getch();
            if (arrow == 72) {
                selected = (selected - 1 + options.size()) % options.size();
            }
            else if (arrow == 80) {
                selected = (selected + 1) % options.size();
            }
        }
        else if (key == '\r') { 
            break;
        }
        printOptions();
    }
    
    for(int i = 0; i < dialogueHeight; i++){
       cout << "    " << RESET << "\033[" << (boxTopRow + i) << ";" << boxLeftCol << "H";
       cout << RESET << BG_WHITE << string(maxLineLength, ' ') << RESET;
    }
    cout << "\033[" << (boxTopRow + 5) << ";" << (boxLeftCol + 3 )<< "H";

    for (int i = 0; i < dialogueHeight; i++) {
        cout << "\033[" << (boxTopRow + i) << ";" << optionBoxCol << "H";
        cout << BG_WHITE << string(optionBoxWidth, ' '); 
    }
    int moveBoxLeftCol = boxLeftCol;
    int moveBoxTopRow = boxTopRow;
    int moveBoxWidth = maxLineLength;

    if (selected == 0) { 
        vector<string> moveNames;
        vector<string> moveTypeNames;

        for (int i = 0; i < 4; i++) {
            MovimientosDataBase move = MovimientosCall(OP_INFO.idMovimientos[i]);
            moveNames.push_back(move.nombre);

            TiposDataBase typeInfo = TiposCall(move.idTipo);
            moveTypeNames.push_back(typeInfo.nombre);
        }

        int selectedMoveIndex = PrintSelectionMenu(moveNames, moveTypeNames, moveBoxLeftCol, moveBoxTopRow, moveBoxWidth);
        seleccion = selectedMoveIndex;
        que = true;

    }
    else {
        int ObjectsID[4] = {1, 2, 3, 4};
        vector<string> ObjectNames;
        vector<string> ObjectDamage;
        map<int, string> ObjectNameType = {
            {1 , "HEAL"},
            {2 , "BUFF DEFENSE"},
            {3 , "BUFF SPEED"},
            {4, "BUFF ATACK"}
        };

        for(int i=0;i<4;i++){
            ObjetosDataBase OP_OBJ = ObjetosCall(ObjectsID[i]);
            ObjectNames.push_back(OP_OBJ.nombre);
            ObjectDamage.push_back(ObjectNameType[OP_OBJ.accion]);
        }
        int selectedObjectIndex = PrintSelectionMenu(ObjectNames, ObjectDamage, moveBoxLeftCol, moveBoxTopRow, moveBoxWidth);
        seleccion = selectedObjectIndex;
        que = false;
    }
}

// int main(){
//     PrintBattleEnemies(1, 3);
//     MovesMenu(1, 3);
//     return 0;
// }
