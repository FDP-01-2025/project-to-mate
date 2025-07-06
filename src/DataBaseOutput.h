// Includes de librerias necesarias
#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <vector>
#include <string>
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

struct SpritesDataBase{
    int id;
    vector<string> Sprite;
};

struct ObjetosDataBase{
    int id;
    string nombre;
    int accion; // 1= heal, 2= buff defense, 3= buff speed, 4= buff attack.
    float numero;
    string descripcion;

};

//Funcion para llamar informacion de un sivarmon especifica
SivarmonDataBase SivarmonesCall(int eleccion){
    SivarmonDataBase Salida;
    ifstream sivarmons("src/DataBase/Sivarmons.txt");
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
    ifstream movimientos("src/DataBase/Movements.txt");

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
    ifstream Tipos("src/DataBase/Types.txt");
   if (Tipos.is_open())
   {
     while (Tipos >> Salida.id >> Salida.nombre)
    {
        if (seleccion == Salida.id)
        {
            return Salida;
        }
        
    }

    cout<<"No se encontro el movimiento. ";
     return TiposDataBase{};


   }else
   {
    cout<<"Erorr! el archivo no se abrio.";
     return TiposDataBase{};
   }
   
   

    return TiposDataBase{};
    
}

SpritesDataBase SpritesCall(int seleccion){
    SpritesDataBase Salida;
    ifstream Sprites("src/DataBase/Sprites.txt");
    if (Sprites.is_open())
    {
        
        string linea;
        string lineaGuardada;
        bool usarGuardada = false;

        while (true) {
            if (!usarGuardada) {
                if (!getline(Sprites, linea)) break;
            } else {
                linea = lineaGuardada;
                usarGuardada = false;
            }

            if (!linea.empty() && linea.find_first_not_of("0123456789") == string::npos)
            {
                int idObtenido = stoi(linea);
                vector<string> spriteTemporal;

                while (getline(Sprites, linea))
                {
                    if (linea.empty())
                    {
                        break;
                    }

                    if (!linea.empty() && linea.find_first_not_of("0123456789") == string::npos)
                    {
                       lineaGuardada = linea;
                        usarGuardada = true;
                        break;
                    }

                     spriteTemporal.push_back(linea);
                    
                }

                if (seleccion == idObtenido)
                {
                    Salida.id = idObtenido;
                    Salida.Sprite = spriteTemporal;
                    break;
                }
                

                             
            }
            
        }

        return Salida;


        
    }else
    {
        cout<<"No se abrio archivo";
        return SpritesDataBase{};
    }    
}

ObjetosDataBase ObjetosCall(int seleccion){
    ObjetosDataBase Salida;
    ifstream Objetos("src/DataBase/Objets.txt");

    if (Objetos.is_open()) {
         while (Objetos >> Salida.id >> Salida.nombre >> Salida.accion >> Salida.numero) {
        Objetos.ignore(); // quitar el \n restante

        string linea, descripcionTotal;
        while (getline(Objetos, linea)) {
            if (linea.empty()) break; // línea vacía: fin de este bloque
            descripcionTotal += linea + '\n';
        }

        Salida.descripcion = descripcionTotal;

        if (Salida.id == seleccion) {
            Objetos.close();
            return Salida;
        }
    }

    cout << "No se encontró el movimiento con ID " << seleccion << endl;
    return {};
    }else
    {
        cout << "Error al abrir el archivo.\n";
        return {};
    }

}

