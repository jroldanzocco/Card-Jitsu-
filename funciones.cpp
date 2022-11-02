#include <iostream>
#include <ctime>
#include "rlutil.h"
#include "card.h"
#include "funciones.h"
using namespace std;

void ronda(int nroRonda){
    int desafioUsuario, desafioCPU;
    asignarDesafio(&desafioUsuario,&desafioCPU);
    int y = 0, op = 1;
    bool cartaRobada = false;
    rlutil::cls();
    do{

        if(!cartaRobada){
        rlutil::locate(5,5);
        cout << "VER CARTA DESAFIO" << endl;
        rlutil::locate(5,6);
        cout << "VER CARTAS DE ELEMENTOS" << endl;
        rlutil::locate(5,7);
        cout << "ROBAR CARTA ELEMENTO DE LA PILA" << endl;
        rlutil::locate(3,5+y);
        cout << (char)175 << endl;
        switch(rlutil::getkey()){
        case 14: //UP
            rlutil::locate(3,5+y);
            cout << " " << endl;
            y--;
            if(y < 0){
                y = 2;
            }
            break;
        case 15: //DOWN
            rlutil::locate(3,5+y);
            cout << " " << endl;
            y++;
            if(y > 2){
                y = 0;
            }
            break;
        case 1: //ENTER
            switch(y){
            case 0:
                rlutil::cls();
                rlutil::locate(5,5);
                cout << mostrarDesafio(desafioUsuario) << endl;
                rlutil::anykey();
                rlutil::cls();
                break;
            case 1:
                break;
            case 2:
                rlutil::locate(5,7);
                cout << "                               " << endl;
                cartaRobada = true;
                break;
            }
        }
   }else{
        rlutil::locate(5,5);
        cout << "VER CARTA DESAFIO" << endl;
        rlutil::locate(5,6);
        cout << "VER CARTAS DE ELEMENTOS" << endl;
        rlutil::locate(5,7);
        cout << "JUGAR UNA CARTA" << endl;
        rlutil::locate(3,5+y);
        cout << (char)175 << endl;
        switch(rlutil::getkey()){
        case 14: //UP
            rlutil::locate(3,5+y);
            cout << " " << endl;
            y--;
            if(y < 0){
                y = 2;
            }
            break;
        case 15: //DOWN
            rlutil::locate(3,5+y);
            cout << " " << endl;
            y++;
            if(y > 2){
                y = 0;
            }
            break;
        case 1: //ENTER
            switch(y){
            case 0:
                rlutil::cls();
                rlutil::locate(5,5);
                cout << mostrarDesafio(desafioUsuario) << endl;
                rlutil::anykey();
                rlutil::cls();
                break;
            case 1:
                break;
            case 2:
                cartaRobada = false;
                break;
            }
        }
   }
    }while(op == 1);

}

void asignarDesafio(int *user, int *cpu){

   do{
   *user = rand() %10+1;
   *cpu = rand()%10+1;

   }while(*user == *cpu);

}

string mostrarDesafio(int numero){

    string cartasDesafio[10] = {"GANAR UNA CARTA DE NIEVE.","GANAR UNA CARTA DE FUEGO.","GANAR UNA CARTA DE AGUA.",
    "GANAR DOS CARTAS ROJAS.", "GANAR DOS CARTAS AMARILLAS.","GANAR DOS CARTAS VERDES.","GANAR DOS CARTAS AZULES.",
    "GANAR UNA CARTA CON EL MISMO ELEMENTO QUE EL ADVERSARIO.","GANAR DOS CARTAS CON EL MISMO NÚMERO.","GANAR DOS RONDAS DE MANERA CONSECUTIVA."};

    return cartasDesafio[numero-1];
}

