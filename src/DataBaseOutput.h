// Includes de librerias necesarias
#include <iostream>
#include <fstream>
using namespace std;

//Creacion de las estructuras necesarias
//Tambien en ese orden se introducen datos por fila en los txt
struct SivarmonDataBase
{
    int id;
    string nombre;
    int idTipo;
    int vida;
    float defensa;
    int velocidad;
    int idMovimientos[3];
    int idSprite;

};

//Funcion para llamar informacion de un sivarmon especifica
SivarmonDataBase Sivarmones(int eleccion){
    SivarmonDataBase Salida;
    ifstream sivarmons("src/DataBase/Sivarmones.txt");
    if (sivarmons.is_open())
    {
        while (sivarmons >> Salida.id >> Salida.nombre >> Salida.idTipo >> Salida.vida >>
             Salida.defensa >> Salida.velocidad >> Salida.idMovimientos[0] >> Salida.idMovimientos[1]
             >> Salida.idMovimientos[2] >> Salida.idMovimientos[3] >> Salida.idSprite)
        {
            if (Salida.id == eleccion)
            {
                return Salida;
            }
        }
        
    }else
    {
        cout<<"Error!";
    }
    
    return SivarmonDataBase{};
}
