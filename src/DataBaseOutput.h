// Includes de librerias necesarias
#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
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

struct MovimientosDataBase{
    int id;
    string nombre;
    int idTipo;
    int accion;
    float numero;
    string descripcion;

};

struct TiposDataBase{
    int id;
    string nombre;
};

//Funcion para llamar informacion de un sivarmon especifica
SivarmonDataBase SivarmonesCall(int eleccion){
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
                sivarmons.close();
                return Salida;
            }
        }

        return SivarmonDataBase{};
        
    }else
    {
        cout<<"Error!";
        return SivarmonDataBase{};
    }
    
    return SivarmonDataBase{};
}

MovimientosDataBase MovimientosCall(int eleccion) {
    MovimientosDataBase Salida;
    ifstream movimientos("src/DataBase/Movimientos.txt");

    if (movimientos.is_open()) {
         while (movimientos >> Salida.id >> Salida.nombre >> Salida.idTipo >> Salida.accion >> Salida.numero) {
        movimientos.ignore(); // quitar el \n restante

        string linea, descripcionTotal;
        while (getline(movimientos, linea)) {
            if (linea.empty()) break; // línea vacía: fin de este bloque
            descripcionTotal += linea + '\n';
        }

        Salida.descripcion = descripcionTotal;

        if (Salida.id == eleccion) {
            movimientos.close();
            return Salida;
        }
    }

    cout << "No se encontró el movimiento con ID " << eleccion << endl;
    return {};
    }else
    {
        cout << "Error al abrir el archivo.\n";
        return {};
    }
    

   
}

TiposDataBase TiposCall(int seleccion){
    TiposDataBase Salida;
    ifstream Tipos("src/DataBase/Tipos.txt");
    while (Tipos >> Salida.id >> Salida.nombre)
    {
        if (seleccion == Salida.id)
        {
            return Salida;
        }
        
    }

    return TiposDataBase{};
    
}