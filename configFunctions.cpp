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
}

void reglamento()
{
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "Una partida de Card Jitsu ++ debe jugarse con una serie de cartas especiales. " << endl;
        cout << "El mismo dispone de dos tipos de mazos distintos que intervienen en distintas etapas del juego: " << endl;
        cout << "uno de ellos es el mazo de cartas desafío y el otro es el mazo de cartas de elementos." << endl;
        cout << "Las cartas desafío simplemente contienen un texto con el desafío a cumplir. En total existen " << endl;
        cout << "diez cartas en el mazo de desafíos. Antes de comenzar una partida, cada jugador debe robar una carta del " << endl;
        cout << "mazo de desafío y plantearse como objetivo cumplirlo cuanto antes." << endl;
        cout << "Las cartas de elementos son las que hacen posible el transcurso de la partida. En primer lugar, " << endl;
        cout << "son las que pueden marcar un desafío como cumplido y, por otro lado, son las que permiten transcurridas las diferentes " << endl;
        cout << "manos del juego cumplir el segundo hito que finalice la partida." << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;

        cout << "PRESIONA ENTER PARA CONTINUAR" << endl;
        if (rlutil::getkey()==1)
        {
            Beep(500,30);
            rlutil::cls();
            rlutil::setColor(11);
            cout << "Mazo de cartas desafío" << endl;
            cout << "El mazo de cartas desafío consta de diez cartas que deben ser robadas al comenzar la partida por cada jugador.  Cada carta desafío contiene uno de los dos hitos que el jugador debe completar para ganar la partida. El mazo contiene las siguientes cartas:" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "1 - Ganar una carta de Nieve." << endl;
            cout << "2 - Ganar una carta de Fuego." << endl;
            cout << "3 - Ganar una carta de Agua." << endl;
            cout << "4 - Ganar dos cartas rojas." << endl;
            cout << "5 - Ganar dos cartas amarillas." << endl;
            cout << "6 - Ganar dos cartas verdes." << endl;
            cout << "7 - Ganar dos cartas azules." << endl;
            cout << "8 - Ganar una carta con el mismo elemento que el adversario." << endl;
            cout << "9 -Ganar dos cartas con el mismo número." << endl;
            cout << "10 - Ganar dos rondas de manera consecutiva." << endl;
            cout << "Ejemplo de una carta desafío" << endl;
            cout << "Los desafíos de las diez cartas desafío" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "Las cartas desafío son elegidas al comenzar la partida por cada jugador. Cada jugador conocerá únicamente su carta desafío y cumplirlo será excluyente para ganar la partida. " << endl;
            cout << "" << endl;
            rlutil::setColor(12);
            rlutil::locate(70,40);
            cout << "PRESIONA ENTER PARA CONTINUAR" << endl;
            if (rlutil::getkey()==1)
            {
                Beep(500,30);
                rlutil::cls();
                rlutil::setColor(12);
                cout << "Mazo de cartas de elementos" << endl;
                cout << "Otra parte del juego requiere el uso de este mazo de cartas. Estas cartas se caracterizan por tener un elemento (fuego, nieve o agua), un color (rojo, amarillo, verde y azul) y un número (de 1 a 5). En total son 60 naipes." << endl;
                cout << "Estas cartas son necesarias para jugar en las rondas de elementos. " << endl;
                cout << "" << endl;
                cout << "" << endl;
                cout << "" << endl;
                cout << "Carta roja de fuego #5" << endl;
                cout << "Carta azul de nieve #3" << endl;
                cout << "Carta amarilla de agua #3" << endl;
                cout << "" << endl;
                cout << "" << endl;
                cout << "Cada jugador comienza la partida con tres cartas de elementos repartidas al azar. Y podrá robar una de la pila en cada ronda. También, en cada ronda deberá jugar una para competir con la juegue su adversario. Esto quiere decir que puede recuperar la carta jugada y ganar la del adversario o bien perderla." << endl;
                cout << "" << endl;
                rlutil::setColor(13);
                rlutil::locate(70,40);
                cout << "PRESIONA ENTER PARA CONTINUAR" << endl;
                if (rlutil::getkey()==1)
                {
                    Beep(500,30);
                    rlutil::cls();
                    rlutil::setColor(13);
                    cout << "Transcurso del juego" << endl;
                    cout << "El juego comienza con la etapa denominada Etapa de desafíos. Aquí, cada uno de los dos jugadores deberá tomar una carta de la pila de cartas desafíos y guardarla." << endl;
                    cout << "Luego, comienza la etapa denominada Etapa de elementos. Esta etapa no tiene una cantidad exacta de rondas sino que finaliza cuando uno de los jugadores logra cumplir dos circunstancias de juego:" << endl;
                    cout << "Lograr lo que su carta desafío indica" << endl;
                    cout << "Obtener una combinación de elementos ganadora" << endl;
                    cout << "" << endl;
                    cout << "Al comenzar la etapa de elementos, a cada jugador se le reparten tres cartas de la pila de cartas de elementos." << endl;
                    cout << "Luego, y en cada una de las rondas de esta etapa, los jugadores roban una carta de la pila de naipes de elementos. A continuación cada jugador juega una carta de elementos de su preferencia y se determina quien gana esa ronda. Para determinar esto se siguen las siguientes reglas:" << endl;
                    cout << "El fuego vence a la nieve" << endl;
                    cout << "La nieve vence al agua" << endl;
                    cout << "El agua vence al fuego" << endl;
                    cout << "" << endl;
                    cout << "Las anteriores reglas se cumplen indistintamente del color y número que tenga el naipe. Por ejemplo, cualquier carta de fuego #1 vence a cualquier carta de nieve #5." << endl;
                    cout << "Si las cartas jugadas en la ronda son del mismo elemento, se resuelve el ganador de la ronda con el valor numérico más alto. Por ejemplo, la carta de fuego #4 vence a la carta de fuego #2." << endl;
                    cout << "Luego de determinar el ganador de la ronda, ambas cartas pasan a ser parte de la mano del jugador que ganó. Esto significa que un jugador puede llegar a tener muchas cartas en su mano si gana muchas rondas. No obstante, un jugador nunca puede tener menos de tres cartas en su mano." << endl;
                    cout << "" << endl;
                    cout << "" << endl;
                    cout << "" << endl;
                    rlutil::setColor(14);
                    rlutil::locate(70,40);
                    cout << "PRESIONA ENTER PARA CONTINUAR" << endl;
                    if (rlutil::getkey()==1)
                    {
                        Beep(500,30);
                        rlutil::cls();
                        rlutil::setColor(14);
                        cout << "Obtener una combinación de elementos ganadora" << endl;
                        cout << "Para obtener una combinación de elementos ganadora, un jugador debe lograr alguna de las siguientes situaciones:" << endl;
                        cout << "Tener tres cartas de distinto elemento y distinto color." << endl;
                        cout << "Tener tres cartas del mismo elemento." << endl;
                        cout << "" << endl;
                        cout << "Por ejemplo, las siguientes situaciones logran una combinación ganadora de elementos:" << endl;
                        cout << "Nieve #2 verde" << endl;
                        cout << "Nieve #1 azul" << endl;
                        cout << "Agua #3 azul" << endl;
                        cout << "Fuego #5 amarillo" << endl;
                        cout << "Nieve #2 verde" << endl;
                        cout << "Nieve #3 amarillo" << endl;
                        cout << "Fuego #4 azul" << endl;
                        cout << "Fuego #2 azul" << endl;
                        cout << "Agua #1 rojo" << endl;
                        cout << "Nieve #1 azul" << endl;
                        cout << "" << endl;
                        cout << "" << endl;
                        cout << "Obtener una combinación de elementos ganadora, sin embargo, no es sinónimo de haber ganado la partida. Para ganar la partida es necesario también cumplir el objetivo de la carta desafío. El primer jugador en obtener una combinación de elementos ganadora y cumplir el objetivo de su carta desafío gana la partida." << endl;
                        cout << "" << endl;
                        cout << "Una vez finalizada la partida, se determinan los puntos de victoria de la misma. Los mismos se calculan de la siguiente manera:" << endl;
                        cout << "" << endl;
                        cout << "+3 PDV por haber ganado la partida" << endl;
                        cout << "-1 PDV si el contrario obtuvo una combinación de elementos ganadora" << endl;
                        cout << "-1 PDV si el contrario cumplió el objetivo de su carta desafío" << endl;
                        cout << "+1 PDV por cada ronda ganada en el juego al adversario" << endl;
                        cout << "+5 PDV por cada ronda ganada en el juego con un elemento igual al del adversario" << endl;
                        rlutil::setColor(2);
                        rlutil::locate(70,40);
                        cout << "PRESIONA ENTER PARA CONTINUAR" << endl;
                        rlutil::setColor(15);
                        rlutil::anykey();
                    }
                    }
                }
            }
        }

