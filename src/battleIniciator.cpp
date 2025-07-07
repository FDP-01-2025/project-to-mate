#include "battle.h"
#include <vector>
using namespace std;





void combate(SivarmonDataBase& J1, SivarmonDataBase& E1, vector<MovimientosDataBase>& J1_MoveSet,vector<MovimientosDataBase>& E_MoveSet,
    vector<ObjetosDataBase> Obj, int mov_used, int turno, float& modif, float& Emodif, bool& exterior, int cant[4]){
        
    bool J1Validacion = false;
    bool E1Validacion = false;
    int EnemyMove = randomNumber();
     int damage_modif = 0;
     int total_damage = 0;
 
     if (J1.velocidad > E1.velocidad)
    {
        switch (turno)
        {
        case 1:
            switch (J1_MoveSet[mov_used].accion) 
            {
            case 1:
                modif = modif + Efectividades(J1_MoveSet[mov_used].idTipo, E1.idTipo);
                
                damage_modif = J1_MoveSet[mov_used].numero+(J1_MoveSet[mov_used].numero*modif);
                total_damage = damage_modif - (damage_modif*E1.defensa);
                E1.vida = E1.vida - total_damage;
                modif = 0;
                break;
            case 2:
                modif = modif + J1_MoveSet[mov_used].numero;
            break;
            case 3:
                J1.defensa = J1.defensa + J1_MoveSet[mov_used].numero;
            break;
            case 4:
                J1.velocidad = J1.velocidad + (J1.velocidad*J1_MoveSet[mov_used].numero);
            break;
            case 5:
                if (Emodif > J1_MoveSet[mov_used].numero)
                {
                    Emodif = Emodif - J1_MoveSet[mov_used].numero;
                }else
                {
                    Emodif = 0;
                }
            break;
            case 6:
               if (E1.defensa > J1_MoveSet[mov_used].numero)
               {
                 E1.defensa = E1.defensa - J1_MoveSet[mov_used].numero;
               }else
               {
                E1.defensa = 0;
               }
                
            break;
            case 7:
                E1.velocidad = E1.velocidad - (E1.velocidad*J1_MoveSet[mov_used].numero);
            break;
            default:
            cout<<"Error?";
                break;
            }
        break;
        case 2:
        if(cant[mov_used] > 0){
        cant[mov_used]--;
        switch (Obj[mov_used].accion)
        {
        case 1:
            J1.vida = J1.vida + Obj[mov_used].numero;
        break;
        case 2:
            J1.defensa = J1.defensa + Obj[mov_used].numero;
        break;
        case 3:
            J1.velocidad = J1.velocidad + Obj[mov_used].numero;
        break;
        case 4:
            modif = modif + Obj[mov_used].numero;
        break;
        
        
        default:
        cout<<"ERror?";
            break;
            }
        }

        break;
        
        default:
        cout<<"ERror?";
            break;
        }
        if (EvaluarVida(E1.vida))
        {
            exterior = false;
            return;
        }
         switch (E_MoveSet[EnemyMove].accion) 
            {
            case 1:
                Emodif = Emodif + Efectividades(E_MoveSet[EnemyMove].idTipo, J1.idTipo);
                
                damage_modif = E_MoveSet[EnemyMove].numero+(E_MoveSet[EnemyMove].numero*Emodif);
                total_damage = damage_modif - (damage_modif*J1.defensa);
                J1.vida = J1.vida - total_damage;
                Emodif = 0;
                break;
            case 2:
                Emodif = Emodif + E_MoveSet[EnemyMove].numero;
            break;
            case 3:
                E1.defensa = E1.defensa + E_MoveSet[EnemyMove].numero;
            break;
            case 4:
                E1.velocidad = E1.velocidad + (E1.velocidad*E_MoveSet[EnemyMove].numero);
            break;
            case 5:
                if (modif > E_MoveSet[EnemyMove].numero)
                {
                    modif = modif - E_MoveSet[EnemyMove].numero;
                }else
                {
                    modif = 0;
                }
            break;
            case 6:
                 if (J1.defensa > E_MoveSet[EnemyMove].numero)
               {
                 J1.defensa = J1.defensa - E_MoveSet[EnemyMove].numero;
               }else
               {
                J1.defensa = 0;
               }
            break;
            case 7:
                J1.velocidad = J1.velocidad + (J1.velocidad*E_MoveSet[EnemyMove].numero);
            break;
            default:
            cout<<"Error?";
                break;
            }

     if (EvaluarVida(J1.vida))
        {
            exterior = false;
            return;
        }   


        
    }else
    {
        switch (E_MoveSet[EnemyMove].accion) 
            {
            case 1:
                Emodif = Emodif + Efectividades(E_MoveSet[EnemyMove].idTipo, J1.idTipo);
                
                damage_modif = E_MoveSet[EnemyMove].numero+(E_MoveSet[EnemyMove].numero*Emodif);
                total_damage = damage_modif - (damage_modif*J1.defensa);
                J1.vida = J1.vida - total_damage;
                Emodif = 0;
                break;
            case 2:
                Emodif = Emodif + E_MoveSet[EnemyMove].numero;
            break;
            case 3:
                E1.defensa = E1.defensa + E_MoveSet[EnemyMove].numero;
            break;
            case 4:
                E1.velocidad = E1.velocidad + (E1.velocidad*E_MoveSet[EnemyMove].numero);
            break;
            case 5:
                if (modif > E_MoveSet[EnemyMove].numero)
                {
                    modif = modif - E_MoveSet[EnemyMove].numero;
                }else
                {
                    modif = 0;
                }
            break;
            case 6:
                 if (J1.defensa > E_MoveSet[EnemyMove].numero)
               {
                 J1.defensa = J1.defensa - E_MoveSet[EnemyMove].numero;
               }else
               {
                J1.defensa = 0;
               }
            break;
            case 7:
                J1.velocidad = J1.velocidad + (J1.velocidad*E_MoveSet[EnemyMove].numero);
            break;
            default:
            cout<<"Error?";
                break;
            }

     if (EvaluarVida(J1.vida))
        {
            exterior = false;
            return;
        } 
         switch (turno)
        {
        case 1:
            switch (J1_MoveSet[mov_used].accion) 
            {
            case 1:
                modif = modif + Efectividades(J1_MoveSet[mov_used].idTipo, E1.idTipo);
                
                damage_modif = J1_MoveSet[mov_used].numero+(J1_MoveSet[mov_used].numero*modif);
                total_damage = damage_modif - (damage_modif*E1.defensa);
                E1.vida = E1.vida - total_damage;
                modif = 0;
                break;
            case 2:
                modif = modif + J1_MoveSet[mov_used].numero;
            break;
            case 3:
                J1.defensa = J1.defensa + J1_MoveSet[mov_used].numero;
            break;
            case 4:
                J1.velocidad = J1.velocidad + (J1.velocidad*J1_MoveSet[mov_used].numero);
            break;
            case 5:
                if (Emodif > J1_MoveSet[mov_used].numero)
                {
                    Emodif = Emodif - J1_MoveSet[mov_used].numero;
                }else
                {
                    Emodif = 0;
                }
            break;
            case 6:
               if (E1.defensa > J1_MoveSet[mov_used].numero)
               {
                 E1.defensa = E1.defensa - J1_MoveSet[mov_used].numero;
               }else
               {
                E1.defensa = 0;
               }
                
            break;
            case 7:
                E1.velocidad = E1.velocidad - (E1.velocidad*J1_MoveSet[mov_used].numero);
            break;
            default:
            cout<<"Error?";
                break;
            }
        break;
        case 2:
        if(cant[mov_used] > 0){
        cant[mov_used]--;
        switch (Obj[mov_used].accion)
        {
        case 1:
            J1.vida = J1.vida + Obj[mov_used].numero;
        break;
        case 2:
            J1.defensa = J1.defensa + Obj[mov_used].numero;
        break;
        case 3:
            J1.velocidad = J1.velocidad + Obj[mov_used].numero;
        break;
        case 4:
            modif = modif + Obj[mov_used].numero;
        break;
        
        
        default:
        cout<<"ERror?";
            break;
            }
        }

        break;
        
        default:
        cout<<"ERror?";
            break;
        }
        if (EvaluarVida(E1.vida))
        {
            exterior = false;
            return;
        }
    }
    
    
   
}

int main()
{   // Definir bien los los valores de mov used
    int eleccion;
    int Movimiento_o_Objeto = 3;

    //Definir fuera del bucle
    float modificador = 0;
    float Enemy_modificador = 0;
    bool siguen = true;
    int CantObjetos[4] = {3, 3, 3, 3};
    

    SivarmonDataBase Jugador = SivarmonesCall(1);
    SivarmonDataBase Enemy = SivarmonesCall(3);

    vector<MovimientosDataBase> Jugador_Movimientos(4);
    for (int i = 0; i < 4; i++)
    {
        Jugador_Movimientos[i] = MovimientosCall(Jugador.idMovimientos[i]);
    }

    vector<MovimientosDataBase> Enemy_Movimientos(4);
    for (int i = 0; i < 4; i++)
    {
        Enemy_Movimientos[i] = MovimientosCall(Enemy.idMovimientos[i]);
    }

    vector<ObjetosDataBase> Objetos(4);
    for (int i = 0; i < 4; i++)
    {
        Objetos[i] = ObjetosCall(i+1);
    }
    
    
    
    cout<<Jugador_Movimientos[3].accion;

    do
    {
        cout<<"Vaya compa: ";
        cin>> eleccion;
        cout<<endl;
        combate(Jugador, Enemy,Jugador_Movimientos, Enemy_Movimientos, Objetos,
        Movimiento_o_Objeto, eleccion, modificador, Enemy_modificador, siguen, CantObjetos);
        cout<<Enemy.vida<<endl;
    } while (siguen);

    cout<<"Goodbye jojo";
   
    

    

    return 0;
}
