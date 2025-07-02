#include "DataBaseOutput.h"
using namespace std;

int main()
{
    //Prueba de que funciona
    int prueba = 21;
    cin>>prueba;

    SivarmonDataBase Jugador = Sivarmones(prueba);

    cout<<" --- " << Jugador.id << " - " << Jugador.nombre << " - " << Jugador.idTipo<< " - "
    << Jugador.vida << " - " << Jugador.defensa << " - " << Jugador.velocidad << " - "
    << Jugador.idMovimientos[0] << ", " << Jugador.idMovimientos[1] << ", " << Jugador.idMovimientos[2]
    << " - " << Jugador.idSprite;


    return 0;
}
