#include <iostream>
#include <ctime>
#include "rlutil.h"
#include "funciones.h"
using namespace std;
int main()
{
    srand(time(NULL));
    rlutil::hidecursor();
    //VARIABLES
    string nombreUsuario;
    int vEstadisticasMayorPuntaje[5]={};
    string nombreMaximo[5]={};
    int puntajeJugador=0;
    int mayorPuntaje=0;
    bool jugar = true;
    int op = 1, y = 0;
    logo();
    do
    {
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::DARKGREY);
        rlutil::locate(40,10 );
        std::cout<< " JUGAR"<<std::endl;
        rlutil::locate(40,11);
        std::cout<< " ESTADISTICAS"<<std::endl;
        rlutil::locate(40,12);
        std::cout<< " CREDITOS "<<std::endl;
        rlutil::locate(40,13);
        std::cout<< " REGLAS DEL JUEGO"<<std::endl;
        rlutil::locate(40,14 );
        std::cout << " SALIR"<< std::endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(38,10+y);
        std::cout<<(char)175<< std::endl;
        switch(rlutil::getkey())
        {
        case 14: //UP
            rlutil::locate(38,10+y);
            cout << " " << endl;
            y--;
            if(y < 0)
            {
                y = 4;
            }
            break;
        case 15: //DOWN
            rlutil::locate(38,10+y);
            cout << " " << endl;
            y++;
            if(y > 4)
            {
                y = 0;
            }
            break;
        case 1: //ENTER
            switch(y+1)
            {
            case 1:
                rlutil::cls();
                do
                {
                    nombreUsuario = solicitarNombre();
                    confirmarNombre(nombreUsuario);
                }
                while(nombreUsuario == "");
                partida(nombreUsuario, vEstadisticasMayorPuntaje,  nombreMaximo);
                break;
            case 2:
                mostrarEstadisticas(vEstadisticasMayorPuntaje,nombreUsuario, nombreMaximo);
                break;
            case 3:
                rlutil::cls();
                mostrarCreditos();
                rlutil::cls();
                break;
            case 4:
                rlutil::cls();
                reglamento();
                rlutil::cls();
                break;
            case 5:
                op = 0;
                break;
            }
        default:
            break;
        }
    }
    while(op != 0);
    rlutil::setColor(0);
    return 0;
}
