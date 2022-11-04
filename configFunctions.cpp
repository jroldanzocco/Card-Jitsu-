#include <iostream>
#include <ctime>
#include "rlutil.h"
#include "card.h"
#include "funciones.h"
#include "configFunctions.h"
using namespace std;

string solicitarNombre()
{
    string n = {};

    do{
        rlutil::setColor(15);
        rlutil::cls();
        rlutil::locate(5,5);
        cout << "Ingresa tu nombre: ";
        getline(cin, n);
    }while(n == "");
    return n;
}
void confirmarNombre(string nombre)
{
    rlutil::cls();
    int decision;
    int y=0;
    do
    {
        rlutil::setBackgroundColor(0);
        //rlutil::setColor(14);
        rlutil::locate(5,5);
        cout << "INGRESASTE '" << nombre << "'";
        rlutil::locate(5,6);
        cout << "EL NOMBRE ES CORRECTO???";
        rlutil::locate(5,8);
        cout << "--------------------";
        showItem("SI", 14, 9, y == 0);
        showItem("NO", 14, 10, y == 1);
        rlutil::locate(5,11);
        cout << "--------------------";
        ///MANEJO DE CURSOR
        switch(rlutil::getkey())
        {
        case 14: //UP
            Beep(1200,40);
            rlutil::locate(14,9+y);
            cout << " " << endl;
            y--;
            if (y<0)
            {
                y=0;
            }
            break;
        case 15: // DOWN
            Beep(1200,40);
            rlutil::locate(14,9+y);
            cout << " " << endl;
            y++;
            if (y>1)
            {
                y=1;
            }
            break;
        case 1: // ENTER
            switch(y)
            {
            case 0: // SI
                decision = 1;
                break;
            case 1: // NO
                nombre = solicitarNombre();
                rlutil::cls();
                break;
            }
            break;
        }
    }
    while(decision != 1);
    rlutil::cls();
}

void showItem(const char* text, int posx, int posy, bool selected)
{
    if (selected)
    {
        rlutil::setBackgroundColor(1);
        rlutil::locate(posx-4,posy);
    }
    else
    {
        rlutil::setBackgroundColor(0);
        rlutil::locate(posx-4,posy);
    }
    rlutil::locate(posx,posy);
    cout<< text << endl;
    rlutil::setBackgroundColor(0);
}
