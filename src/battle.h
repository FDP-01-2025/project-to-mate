#include "DataBaseOutput.h"
#include <map>
#include <random>
using namespace std;

float Efectividades(int ataque, int defensa){
     map<pair<int, int>, float> efectividad = {
        {{2, 3}, 1.5f},  // agua vs fuego
        {{2, 4}, 0.5f},  // agua vs planta
        {{2, 5}, 0.3f},  // agua vs psiquico
        {{3, 2}, 0.5f},  // fuego vs agua
        {{3, 4}, 1.5f},  // fuego vs planta
        {{3, 5}, 0.3f},  // fuego vs psiquico
        {{4, 2}, 1.5f},  // planta vs agua
        {{4, 3}, 0.5f},  // planta vs fuego
        {{4, 5}, 0.3f},  // planta vs psiquico
        {{5, 2}, 1.3f},  // psiquico vs agua
        {{5, 3}, 1.3f},  // psiquico vs fuego
        {{5, 4}, 1.3f},  // psiquico vs planta
        
    };

    auto it  = efectividad.find({ataque, defensa});

    if (ataque != 1 || defensa != 1)
    {
        if (it != efectividad.end())
        {
            return it->second;
        }
        
    }else
    {
        return 0.0f;
    }   

    return 0.0f;
}

int randomNumber(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis1(1, 4);
    return dis1(gen);
}

bool EvaluarVida(int vida){
   if (vida < 1)
    {
        return true;
    }else
    {
        return false;
    }
}