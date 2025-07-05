#include <iostream>
#include <string>
#include <cstdlib>  
#include <ctime>   
#include "sprin.h"
using namespace std;


int main() {

    srand(time(0));

    int opcionJugador;

    cout << "Elige tu combatiente (1-3):\n";
    cout << "1:" << sprite1 << "\n";
    cout << "2:" << sprite2 << "\n";
    cout << "3:" << sprite3 << "\n";
    cout << "Tu elección: ";
    cin >> opcionJugador;

    // Validar entrada del jugador
    if (opcionJugador < 1 || opcionJugador > 3) {
        cout << "Opción inválida. Saliendo del juego.\n";
        return 1;
    }


    string sprites[] = {sprite1, sprite2, sprite3};

    string combatienteJugador = sprites[opcionJugador - 1];
    int opcionCPU = rand() % 3; 
    string combatienteCPU = sprites[opcionCPU];

    cout << "Jugador:\n" << combatienteJugador << endl;
    cout << "VS\n";
    cout << "CPU:\n" << combatienteCPU << endl;
    
    return 0;
}
