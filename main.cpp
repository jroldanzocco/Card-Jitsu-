#include <iostream>
#include <ctime>
#include "rlutil.h"
#include "card.h"
#include "funciones.h"
using namespace std;;
int main()
{
   srand(time(NULL));
    rlutil::hidecursor();

   int op = 1, y = 0;
    do{


        rlutil::locate(5,5);
        cout << "JUGAR" << endl;
        rlutil::locate(5,6);
        cout << "ESTADISTICAS" << endl;
        rlutil::locate(5,7);
        cout << "CREDITOS" << endl;
        rlutil::locate(5,8);
        cout << "REGLAS DEL JUEGO" << endl;
        rlutil::locate(5,9);
        cout << "SALIR" << endl;
        rlutil::locate(3,5+y);
        cout << (char)175 << endl;

        switch(rlutil::getkey()){
        case 14: //UP
            rlutil::locate(3,5+y);
            cout << " " << endl;
            y--;
            if(y < 0){
                y = 4;
            }
            break;
        case 15: //DOWN
            rlutil::locate(3,5+y);
            cout << " " << endl;
            y++;
            if(y > 4){
                y = 0;
            }
            break;
        case 1: //ENTER
            switch(y+1){
            case 1:
                rlutil::cls();
                ronda(1, pedirNombre());

                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                op = 0;
                break;

            }
        default:
            break;
        }



    }while(op != 0);


    return 0;
}

