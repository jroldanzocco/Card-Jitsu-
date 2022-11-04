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

void mostrarCreditos()
{

    int x=60;
    rlutil::cls();
    rlutil::setColor(10);
    rlutil::locate(x,5);
    cout << "MMk.     lWMMMMX;      :NMMMMNc     .OMM" << endl;
    rlutil::locate(x,6);
    cout << "MM0,     '0MMMMX;      :NMMMMO'     ;KMM" << endl;
    rlutil::locate(x,7);
    cout << "MMWo.     ,OWMMX;      :NMMWO,     .dWMM" << endl;
    rlutil::locate(x,8);
    cout << "MMMXc      .l0WX;      :XW0c.      lNMMM" << endl;
    rlutil::locate(x,9);
    cout << "MMMMXl.      .;c.      .c,.      .lXMMMM" << endl;
    rlutil::locate(x,10);
    cout << "MMMMMNx'                        ,kWMMMMM" << endl;
    rlutil::locate(x,11);
    cout << "MMMMMMMXx;.                  .;xNMMMMMMM" << endl;
    rlutil::locate(x,12);
    cout << "MMWNNNNNNKkl,.            .,lkXNNNNNNWMM" << endl;
    rlutil::locate(x,13);
    cout << "MWk                                  kMM" << endl;
    rlutil::locate(x,14);
    cout << "MWo                                  dMM" << endl;
    rlutil::locate(x,15);
    cout << "MWd                                  dMM" << endl;
    rlutil::locate(x,16);
    cout << "MMKxdddddddl,.             ;ldddddddxKMM" << endl;
    rlutil::locate(x,17);
    cout << "MMMMMMMMNkc'                'cONMMMMMMMM" << endl;
    rlutil::locate(x,18);
    cout << "MMMMMMXx,                      ,xNMMMMMM" << endl;
    rlutil::locate(x,19);
    cout << "MMMMWO;        .        .        :0WMMMM" << endl;
    rlutil::locate(x,20);
    cout << "MMMWk.      .ckO;      ;Ok:.      'OWMMM" << endl;
    rlutil::locate(x,21);
    cout << "MMMO'     .cKWMX;      :NMW0c.     ,0MMM" << endl;
    rlutil::locate(x,22);
    cout << "MMX:     .dNMMMX;      :NMMMNo.     cNMM" << endl;
    rlutil::locate(x,23);
    cout << "MMO.     :XMMMMX;      :NMMMMX;     '0MM" << endl;
    rlutil::locate(x,24);
    cout << "MMx.     oWMMMMX:      cNMMMMWl     .kMM" << endl;
    x = 10;
    rlutil::locate(3,22);
    cout << "PRESIONA CUALQUIER TECLA PARA REGRESAR AL MENU" << endl;
    rlutil::setColor(15);
    rlutil::locate(x,10);
    cout << "---------CREADO POR------------" << endl;
    rlutil::locate(15,12);
    cout << "'CODEDESTROYERS666'" << endl;
    rlutil::locate(x,14);
    cout << "INTEGRANTES:" << endl;
    rlutil::locate(x,16);
    cout << "Juan Sarmiento" << endl;
    rlutil::locate(x,17);
    cout << "Jeremias Roldan Zocco" << endl;
    rlutil::locate(x,18);
    cout << "Fiorella Acosta" << endl;
    rlutil::locate(x,19);
    cout << "Juan Manuel Escobar" << endl;

    rlutil::anykey();
    rlutil::cls();
}


