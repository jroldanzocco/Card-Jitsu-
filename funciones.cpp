#include <iostream>
#include <ctime>
#include "rlutil.h"
#include "card.h"
#include "funciones.h"
#include "configFunctions.h"
using namespace std;

void logo ()
{

    int xcolumna;
    rlutil::hidecursor();

    rlutil::setBackgroundColor(rlutil::BLACK);

    rlutil::setColor(rlutil::WHITE);

    ///letra C
    rlutil::locate(30, 3);
    std::cout<< "******"<<std::endl;
    //std::cout<< " "<<std::endl;
    rlutil::locate(30, 4);
    //std::cout<< " "<<std::endl;
    std::cout<< "**"<<std::endl;
    //std::cout<< " "<<std::endl;
    rlutil::locate(30, 5);
    //std::cout<< " "<<std::endl;
    std::cout<< "**"<<std::endl;
    rlutil::locate(30, 6);
    // std::cout<< " "<<std::endl;
    std::cout<< "**"<<std::endl;
    rlutil::locate(30, 7);
    // std::cout<< " "<<std::endl;
    std::cout<< "******"<<std::endl;

    ///LETRA A
    rlutil::locate(37, 3);
    std::cout<< "******"<<std::endl;
    rlutil::locate(37, 4);
    std::cout<< "**"<<std::endl;
    rlutil::locate(37, 5);
    std::cout<< "*"<<std::endl;
    rlutil::locate(38, 5);
    std::cout<< "*****"<<std::endl;
    rlutil::locate(37, 6);
    std::cout<< "**"<<std::endl;
    rlutil::locate(37, 7);
    std::cout<< "**"<<std::endl;
    rlutil::locate(41, 3);
    std::cout<< "**"<<std::endl;
    rlutil::locate(41, 4);
    std::cout<< "**"<<std::endl;
    rlutil::locate(41, 5);
    std::cout<< "*"<<std::endl;
    rlutil::locate(41, 6);
    std::cout<< "**"<<std::endl;
    rlutil::locate(41, 7);
    std::cout<< "**"<<std::endl;

    ///LETRA R
    rlutil::locate(44, 3);
    std::cout<< "****"<<std::endl;
    rlutil::locate(44, 4);
    std::cout<< "**"<<std::endl;
    rlutil::locate(44, 5);
    std::cout<< "**"<<std::endl;
    rlutil::locate(44, 5);
    std::cout<< "***"<<std::endl;
    rlutil::locate(44, 6);
    std::cout<< "**"<<std::endl;
    rlutil::locate(44, 7);
    std::cout<< "**"<<std::endl;
    rlutil::locate(46, 3);
    std::cout<< "**"<<std::endl;
    rlutil::locate(47, 3);
    std::cout<< " *"<<std::endl;
    rlutil::locate(47, 4);
    std::cout<< " *"<<std::endl;
    rlutil::locate(47, 5);
    std::cout<< "*"<<std::endl;
    rlutil::locate(47, 6);
    std::cout<< " *"<<std::endl;
    rlutil::locate(47, 7);
    std::cout<< " *"<<std::endl;

    ///LETRA D
    rlutil::locate(50, 3);
    std::cout<< "****"<<std::endl;
    rlutil::locate(50, 4);
    std::cout<< "**"<<std::endl;
    rlutil::locate(50, 5);
    std::cout<< "**"<<std::endl;
    rlutil::locate(50, 5);
    std::cout<< "**"<<std::endl;
    rlutil::locate(50, 6);
    std::cout<< "**"<<std::endl;
    rlutil::locate(50, 7);
    std::cout<< "**"<<std::endl;
    rlutil::locate(50, 7);
    std::cout<< "**"<<std::endl;
    rlutil::locate(52, 3);
    std::cout<< "**"<<std::endl;
    rlutil::locate(53, 4);
    std::cout<< " *"<<std::endl;
    rlutil::locate(53, 5);
    std::cout<< " *"<<std::endl;
    rlutil::locate(53, 6);
    std::cout<< " *"<<std::endl;
    rlutil::locate(52, 7);
    std::cout<< "*"<<std::endl;

    ///LETRA J
    rlutil::locate(60, 3);
    std::cout<< "*****"<<std::endl;
    rlutil::locate(63, 4);
    std::cout<< "**"<<std::endl;
    rlutil::locate(63, 5);
    std::cout<< "**"<<std::endl;
    rlutil::locate(63, 5);
    std::cout<< "**"<<std::endl;
    rlutil::locate(63, 6);
    std::cout<< "**"<<std::endl;
    rlutil::locate(60, 7);
    std::cout<< "*****"<<std::endl;
    rlutil::locate(63, 5);
    std::cout<< "*"<<std::endl;


    ///LETRA I
    rlutil::locate(66, 3);
    std::cout<< "*****"<<std::endl;
    rlutil::locate(68, 4);
    std::cout<< "*"<<std::endl;
    rlutil::locate(68, 5);
    std::cout<< "*"<<std::endl;
    rlutil::locate(68, 5);
    std::cout<< "*"<<std::endl;
    rlutil::locate(68, 6);
    std::cout<< "*"<<std::endl;
    rlutil::locate(66, 7);
    std::cout<< "*****"<<std::endl;

    //LETRA T
    rlutil::locate(72, 3);
    std::cout<< "******"<<std::endl;
    rlutil::locate(74, 4);
    std::cout<< "**"<<std::endl;
    rlutil::locate(74, 5);
    std::cout<< "**"<<std::endl;
    rlutil::locate(74, 5);
    std::cout<< "**"<<std::endl;
    rlutil::locate(74, 6);
    std::cout<< "**"<<std::endl;
    rlutil::locate(74, 7);
    std::cout<< "**"<<std::endl;

    ///LETRA S
    rlutil::locate(79, 3);
    std::cout<< "*****"<<std::endl;
    rlutil::locate(79, 4);
    std::cout<< "**"<<std::endl;
    rlutil::locate(79, 5);
    std::cout<< "**"<<std::endl;
    rlutil::locate(79, 5);
    std::cout<< "*****"<<std::endl;
    rlutil::locate(82, 6);
    std::cout<< " *"<<std::endl;
    rlutil::locate(79, 7);
    std::cout<< "*****"<<std::endl;
    ///LETRA U
    rlutil::locate(85, 3);
    std::cout<< "**"<<std::endl;
    rlutil::locate(85, 4);
    std::cout<< "**"<<std::endl;
    rlutil::locate(85, 5);
    std::cout<< "**"<<std::endl;
    rlutil::locate(85, 5);
    std::cout<< "**"<<std::endl;
    rlutil::locate(85, 6);
    std::cout<< "**"<<std::endl;
    rlutil::locate(85, 7);
    std::cout<< "*******"<<std::endl;
    rlutil::locate(90, 3);
    std::cout<< "**"<<std::endl;
    rlutil::locate(90, 4);
    std::cout<< "**"<<std::endl;
    rlutil::locate(90, 5);
    std::cout<< "**"<<std::endl;
    rlutil::locate(90, 5);
    std::cout<< "**"<<std::endl;
    rlutil::locate(90, 6);
    std::cout<< "**"<<std::endl;



    rlutil::setColor(rlutil::LIGHTCYAN);
    rlutil::locate (96,3);
    std::cout<< (char)179<<std::endl;
    rlutil::locate (96,4);
    std::cout<< (char)197<<std::endl;
    rlutil::locate (96,5);
    std::cout<< (char)179<<std::endl;
    rlutil::locate (94,4);
    std::cout<< (char)196<<std::endl;
    rlutil::locate (98,4);
    std::cout<< (char)196<<std::endl;



    rlutil::locate (100,5);
    std::cout<< (char)179<<std::endl;
    rlutil::locate (100,6);
    std::cout<< (char)197<<std::endl;
    rlutil::locate (100,7);
    std::cout<< (char)179<<std::endl;
    rlutil::locate (98,6);
    std::cout<< (char)196<<std::endl;
    rlutil::locate (102,6);
    std::cout<< (char)196<<std::endl;

    rlutil::setColor(rlutil::LIGHTCYAN);
    for (xcolumna=22; xcolumna<=105; xcolumna++)
    {
        Sleep(20);
        rlutil::locate (xcolumna,2);
        std::cout<<(char)242;
        rlutil::locate (xcolumna,8);
        std::cout<<(char)242;
    }
}




void ronda(int nroRonda, string nombre)
{
    string mazo[60], manoJugador[60], manoCPU[60], cartasJugadas[2];
    bool ganadorDesafioCPU=false, ganadorDesafioJugador=false;
    string ganadorPartida=" ";
    int desafioUsuario, desafioCPU;
    int vEstadisticasCPU[5]= {};
    int vEstadisticasJugador[5]= {};
    int mayorPuntaje;
    crearMazo(mazo);
    mezclarMazo(mazo, 60);
    asignarCartas(mazo, manoJugador, manoCPU);
    asignarDesafio(&desafioUsuario,&desafioCPU);
    int y = 0, op = 1;
    bool cartaRobada = false;
    bool ganadorElementosCPU=false;
    bool ganadorElementosJugador=false;
    rlutil::cls();
    do
    {

        if(!cartaRobada)
        {
            rlutil::locate(5,5);
            cout << "VER CARTA DESAFIO" << endl;
            rlutil::locate(5,6);
            cout << "VER CARTAS DE ELEMENTOS" << endl;
            rlutil::locate(5,7);
            cout << "ROBAR CARTA ELEMENTO DE LA PILA" << endl;
            rlutil::locate(3,5+y);
            cout << (char)175 << endl;
            switch(rlutil::getkey())
            {
            case 14: //UP
                rlutil::locate(3,5+y);
                cout << " " << endl;
                y--;
                if(y < 0)
                {
                    y = 2;
                }
                break;
            case 15: //DOWN
                rlutil::locate(3,5+y);
                cout << " " << endl;
                y++;
                if(y > 2)
                {
                    y = 0;
                }
                break;
            case 1: //ENTER
                switch(y+1)
                {
                case 1:
                    rlutil::cls();
                    rlutil::locate(5,5);
                    cout << mostrarDesafio(desafioUsuario) << endl;
                    rlutil::locate(5, 10);
                    cout << "Presione una tecla para volver...";
                    rlutil::anykey();
                    rlutil::cls();
                    break;
                case 2:
                    rlutil::cls();
                    rlutil::locate(5, 4);
                    cout << "Presione una tecla para volver...";
                    dibujarCartasDisponibles(manoJugador);
                    rlutil::anykey();
                    rlutil::cls();
                    break;
                case 3:
                    rlutil::locate(5,7);
                    cout << "                               " << endl;
                    robarCarta(mazo,manoJugador, manoCPU);
                    cartaRobada = true;
                    break;
                }
            }
        }
        else
        {
            rlutil::locate(5,5);
            cout << "VER CARTA DESAFIO" << endl;
            rlutil::locate(5,6);
            cout << "VER CARTAS DE ELEMENTOS" << endl;
            rlutil::locate(5,7);
            cout << "JUGAR UNA CARTA" << endl;
            rlutil::locate(3,5+y);
            cout << (char)175 << endl;
            switch(rlutil::getkey())
            {
            case 14: //UP
                rlutil::locate(3,5+y);
                cout << " " << endl;
                y--;
                if(y < 0)
                {
                    y = 2;
                }
                break;
            case 15: //DOWN
                rlutil::locate(3,5+y);
                cout << " " << endl;
                y++;
                if(y > 2)
                {
                    y = 0;
                }
                break;
            case 1: //ENTER
                switch(y+1)
                {
                case 1:
                    rlutil::cls();

                    rlutil::locate(5,5);
                    cout << mostrarDesafio(desafioUsuario) << endl;
                    rlutil::locate(5, 10);
                    cout << "Presione una tecla para volver...";
                    rlutil::anykey();
                    rlutil::cls();
                    break;
                case 2:
                    rlutil::cls();
                    rlutil::locate(5, 4);
                    cout << "Presione una tecla para volver...";
                    dibujarCartasDisponibles(manoJugador);
                    rlutil::anykey();
                    rlutil::cls();
                    break;
                case 3:
                    rlutil::cls();
                    eleccionCartaUsuario(manoJugador,cartasJugadas);
                    eleccionCartaCPU(manoCPU, cartasJugadas);
                    mostrarCartasJugadas(cartasJugadas,nombre);
                    condicionDeVictRonda(cartasJugadas,nombre,manoJugador,manoCPU, vEstadisticasCPU, vEstadisticasJugador);
                    verificarCondicionElementos(nombre, manoJugador,manoCPU, vEstadisticasCPU,vEstadisticasJugador,ganadorElementosCPU, ganadorElementosJugador);
                    mostrarGanador (ganadorDesafioJugador,ganadorDesafioCPU, ganadorElementosJugador, ganadorElementosCPU, nombre, ganadorPartida, vEstadisticasCPU,  vEstadisticasJugador);
                    mayorPuntaje=definirMayorPuntaje (nombre, puntajeJugador, mayorPuntaje,  vEstadisticasJugador,vEstadisticasMayorPuntaje);
                    ordenamientoDeManos(manoJugador);
                    ordenamientoDeManos(manoCPU);
                    rlutil::anykey();
                    rlutil::cls();
                    cartaRobada = false;
                    break;
                }
            }
        }
    }
    while(op == 1);

}

void asignarDesafio(int* user, int* cpu)
{

    do
    {
        *user = rand() %10+1;
        *cpu = rand()%10+1;

    }
    while(*user == *cpu);

}

string mostrarDesafio(int numero)
{

    string cartasDesafio[10] = {"GANAR UNA CARTA DE NIEVE.","GANAR UNA CARTA DE FUEGO.","GANAR UNA CARTA DE AGUA.",
                                "GANAR DOS CARTAS ROJAS.", "GANAR DOS CARTAS AMARILLAS.","GANAR DOS CARTAS VERDES.","GANAR DOS CARTAS AZULES.",
                                "GANAR UNA CARTA CON EL MISMO ELEMENTO QUE EL ADVERSARIO.","GANAR DOS CARTAS CON EL MISMO NUMERO.","GANAR DOS RONDAS DE MANERA CONSECUTIVA."
                               };

    return cartasDesafio[numero-1];
}

void crearMazo(string mazo[])
{
    string numero[5] = {"1","2","3","4","5"};
    string elemento[3] = {"FUEGO","NIEVE","AGUA"};
    string color[4] = {"ROJO","AZUL","VERDE","AMARILLO"};
    const int NUMEROS = 5, COLORES = 4, ELEMENTOS = 3;
    int l = 59;
    for(int i = 0; i < ELEMENTOS; i++)
    {
        for(int j = 0; j < COLORES; j++)
        {
            for(int x = 0; x < NUMEROS; x++)
            {
                mazo[l] = numero[x] + " " + color[j] + " " + elemento[i];
                l--;
            }
        }
    }
}

void mezclarMazo(string mazo[], int cantidadCartas)
{
    for(int i = 0; i < cantidadCartas; i++)
    {
        string aux;
        int j = rand() % cantidadCartas;
        aux = mazo[i];
        mazo[i] = mazo[j];
        mazo[j] = aux;
    }
}

void asignarCartas(string mazo[], string manoJugador[],string manoCPU[])
{
    const int CARTASINICIALES = 3;
    int repartido = 0;
    for(int i = 0; i < CARTASINICIALES; i++)
    {
        manoJugador[i] = mazo[repartido];
        mazo[repartido] = "";
        manoCPU[i] = mazo[repartido + 1];
        mazo[repartido+1] = "";
        repartido+=2;
    }
}

void robarCarta(string mazo[], string manoJugador[], string manoCPU[])
{
    int repartidoPlayer = 0, repartidoCPU = 0;
    for(int i = 0; i < 60 ; i++)
    {
        if(mazo[i] != "" && repartidoPlayer == 0)
        {
            for(int j = 0; j < 60; j++)
            {
                if(manoJugador[j] == "")
                {
                    manoJugador[j] = mazo[i];
                    mazo[i] = "";
                    repartidoPlayer ++;
                }
            }
        }
        else if(mazo[i] != "" && repartidoCPU == 0)
        {
            for(int j = 0; j < 60; j++)
            {
                if(manoCPU[j] == "")
                {
                    manoCPU[j] = mazo[i];
                    mazo[i] = "";
                    repartidoCPU++;
                    break;
                }
            }
        }
    }
}
void eleccionCartaUsuario(string manoJugador[], string cartasJugadas[])
{
    bool posiciones[8][8] = {};
    acomodarCartasEnPantalla(posiciones, manoJugador);
    int op = 0;
    int x = 0, y = 0, posX = 0, posY = 0;
    int eleccion = 0, aux;
    dibujarCartasDisponibles(manoJugador);


    do
    {
        rlutil::locate(8+x,5+y);
        cout << (char)88;
        switch(rlutil::getkey())
        {
        case 16: //LEFT
            rlutil::locate(8+x,5+y);
            cout << " " << endl;
            aux = eleccion;
            eleccion--;
            x-=10;
            posX--;
            if(posX < 0)
            {
                posX = 0;
                x = 0;
                eleccion = aux;
            }
            break;
        case 17: //RIGHT
            rlutil::locate(8+x,5+y);
            cout << " " << endl;
            if(posiciones[posY][posX+1] && posX < 7)
            {
                eleccion++;
                x+=10;
                posX++;
            }


            break;
        case 14: //UP
            rlutil::locate(8+x,5+y);
            cout << " " << endl;
            aux = eleccion;
            eleccion-=8;
            y-=6;
            posY--;
            if(y < 0)
            {
                y = 0;
                posY = 0;
                eleccion = aux;

            }
            break;

        case 15: // DOWN
            rlutil::locate(8+x,5+y);
            cout << " " << endl;
            aux = eleccion;

            if(posiciones[posY+1][posX] && posY < 7)
            {
                eleccion+=8;
                y+=6;
                posY++;
            }
            break;
        case 1:  //ENTER
            cartasJugadas[0] = manoJugador[eleccion];
            manoJugador[eleccion] = "";
            rlutil::cls();
            op = 1;
            break;
        }
    }
    while(op == 0);


}

int cantidadCartasEnMano(string mano[])
{
    string auxiliar[60];
    int i = 0;
    while(mano[i] != "")
    {
        i++;
    }
    return i;
}


void dibujarCartasDisponibles(string mano[])
{
    int cartas = cantidadCartasEnMano(mano);
    int posX = 5;
    int y = 6;
    for(int i = 0; i < cartas; i++)
    {
        if(i == 56)
        {
            y = 48;
            posX = 5;
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }
        else if(i > 56)
        {
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }
        else if(i == 48)
        {
            y = 42;
            posX = 5;
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }
        else if(i > 48)
        {
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }
        else if(i == 40)
        {
            y = 36;
            posX = 5;
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }
        else if(i > 40)
        {
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }
        else if(i == 32)
        {
            y = 30;
            posX = 5;
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }
        else if(i > 32)
        {
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }
        else if( i == 24)
        {
            y = 24;
            posX = 5;
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }
        else if(i > 24)
        {
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }
        else if(i == 16)
        {
            y = 18;
            posX = 5;
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }
        else if(i > 16)
        {
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }
        else if(i == 8)
        {
            y = 12;
            posX = 5;
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }
        else if(i > 8)
        {
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }
        else
        {
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }
    }
}

void eleccionCartaCPU(string manoCPU[], string cartasJugadas[])
{
    const int limiteCartas = 60;
    int contadorCartas = 0;
    int jugadaRandom;
    for(int i = 0; i < limiteCartas; i++)
    {
        if(manoCPU[i] != "")
        {
            contadorCartas++;
        }
    }
    jugadaRandom = rand() % contadorCartas;
    cartasJugadas[1] = manoCPU[jugadaRandom];
    manoCPU[jugadaRandom] = "";

}

void ordenamientoDeManos(string manoGeneral[])
{
    string auxiliar[60];
    int indiceaux = 0;
    for( int i = 0; i < 60; i++)
    {
        if(manoGeneral[i] != "")
        {
            auxiliar[indiceaux] = manoGeneral[i];
            indiceaux++;
        }
    }
    for(int i = 0; i < 60; i++)
    {
        manoGeneral[i] = "";
    }
    for(int i = 0; i <= indiceaux; i++)
    {
        manoGeneral[i] = auxiliar[i];
    }
}

void acomodarCartasEnPantalla(bool pos[][8], string mano[])
{
    int maximoX = 8;
    int maximoY = 8;
    int conteoCartas = 0;
    for(int i = 0; i < maximoY; i++)
    {
        for(int j = 0; j < maximoX; j++)
        {
            if(mano[conteoCartas] != "")
            {
                pos[i][j] = true;
                conteoCartas++;
            }
        }
    }
}
void mostrarCartasJugadas(string cartasJugadas[], string nombre)
{
    rlutil::cls();
    rlutil::locate(20,3);
    cout << nombre << " JUEGA" << endl;
    drawCard(cartasJugadas[0][0],cartasJugadas[0].back(),21,6,cartasJugadas[0][3]);
    rlutil::locate(60,3);
    cout << "CPU JUEGA" << endl;
    drawCard(cartasJugadas[1][0],cartasJugadas[1].back(),61,6,cartasJugadas[1][3]);
}

void condicionDeVictRonda(string cartasJugadas[], string nombre, string manoJugador[], string manoCPU[], int vEstadisticasCPU[],int vEstadisticasJugador[])
{
    rlutil::locate(25,13);
    if(cartasJugadas[0].find("FUEGO") != std::string::npos && cartasJugadas[1].find("NIEVE") != std::string::npos)
    {
        ganadorDeRonda(cartasJugadas, manoJugador, 1,vEstadisticasJugador);
        cout << "GANA "<< nombre << " PORQUE EL FUEGO DERRITE LA NIEVE"<<  endl;
    }
    else if(cartasJugadas[0].find("NIEVE") != std::string::npos && cartasJugadas[1].find("AGUA") != std::string::npos)
    {
        ganadorDeRonda(cartasJugadas, manoJugador, 1, vEstadisticasJugador);
        cout << "GANA " << nombre  << " PORQUE LA NIEVE CONGELA EL AGUA"<<  endl;
    }
    else if(cartasJugadas[0].find("AGUA") != std::string::npos && cartasJugadas[1].find("FUEGO") != std::string::npos)
    {
        ganadorDeRonda(cartasJugadas, manoJugador, 1, vEstadisticasJugador);
        cout << "GANA " << nombre << " PORQUE EL AGUA APAGA EL FUEGO"<<  endl;
    }
    else if(cartasJugadas[0].find("NIEVE") != std::string::npos && cartasJugadas[1].find("FUEGO") != std::string::npos)
    {
        ganadorDeRonda(cartasJugadas, manoCPU, 0,vEstadisticasCPU);
        cout << "GANA CPU" << " PORQUE EL FUEGO DERRITE LA NIEVE"<<  endl;
    }
    else if(cartasJugadas[0].find("AGUA") != std::string::npos && cartasJugadas[1].find("NIEVE") != std::string::npos)
    {
        ganadorDeRonda(cartasJugadas, manoCPU, 0,vEstadisticasCPU);
        cout << "GANA CPU" << " PORQUE LA NIEVE CONGELA EL AGUA"<<  endl;
    }
    else if(cartasJugadas[0].find("FUEGO") != std::string::npos && cartasJugadas[1].find("AGUA") != std::string::npos)
    {
        ganadorDeRonda(cartasJugadas, manoCPU, 0,vEstadisticasCPU);
        cout << "GANA CPU" << " PORQUE EL AGUA APAGA EL FUEGO"<<  endl;
    }
    else
    {
        if(cartasJugadas[0][0] > cartasJugadas[1][0])
        {
            ganadorDeRonda(cartasJugadas, manoJugador, 1,vEstadisticasJugador);
            cout << "GANA " << nombre << " PORQUE SU NUMERO DE CARTA ES MAYOR"<<  endl;
        }
        else if(cartasJugadas[0][0] < cartasJugadas[1][0])
        {
            ganadorDeRonda(cartasJugadas, manoCPU, 0,vEstadisticasCPU);
            cout << "GANA CPU" << " PORQUE SU NUMERO DE CARTA ES MAYOR"<<  endl;
        }
        else
        {
            cout << "EMPATE" << " PORQUE TANTO LOS ELEMENTOS COMO LOS NUMEROS DE CARTA SON IGUALES"<<  endl;
        }
    }
}

void ganadorDeRonda(string cartasJugadas[], string manoGanadora[], bool ganoUsuario, int vEstadisticas[])
{
    if(ganoUsuario)
    {
        manoGanadora[58] = cartasJugadas[0];
        manoGanadora[59] = cartasJugadas[1];
        vEstadisticas[3]+=1;
    }
    else
    {
        manoGanadora[58] = cartasJugadas[1];
        manoGanadora[59] = cartasJugadas[0];
        vEstadisticas[3]+=1;
    }
}
void verificarCondicionElementos(string nombre, string vCartasJugador[],string vCartasCPU[], int vEstadisticasCPU[],int vEstadisticasJugador[],bool &ganadorElementosCPU, bool &ganadorElementosJugador)
{
    int x,i;
    int contadorColorRojo=0;
    int contadorColorAmarillo=0;
    int contadorColorAzul=0;
    int contadorColorVerde=0;
    int contadorElementoFuego=0;
    int contadorElementoAgua=0;
    int contadorElementoNieve=0;
    bool combinacionGanadora=false;



    for (x=0; x<60; x++)
    {
        if (vCartasJugador[x]!=" " )
        {
            if (vCartasJugador[x].find("fuego")!=string::npos)
            {
                contadorElementoFuego+=1;
            }
            else if (vCartasJugador[x].find("agua")!=string::npos)
            {
                contadorElementoAgua+=1;

            }
            else if (vCartasJugador[x].find("nieve")!=string::npos)
            {
                contadorElementoNieve+=1;
            }


            if (vCartasJugador[x].find("verde")!=string::npos)
            {
                contadorColorVerde+=1;
            }
            else if (vCartasJugador[x].find("amarillo")!=string::npos)
            {
                contadorColorAmarillo+=1;

            }
            else if (vCartasJugador[x].find("azul")!=string::npos)
            {
                contadorColorAzul+=1;
            }
            else if (vCartasJugador[x].find("rojo")!=string::npos)
            {
                contadorColorRojo+=1;
            }

        }

    }
    if (contadorColorAzul==1 && contadorColorAmarillo==1 && contadorColorRojo==1 || contadorColorAmarillo==1 && contadorColorRojo==1 && contadorColorVerde==1 ||contadorColorVerde==1 && contadorColorRojo==1 && contadorColorAzul==1 || contadorColorVerde==1 && contadorColorAmarillo==1 && contadorColorAzul==1 && contadorElementoAgua==1 && contadorElementoFuego==1 && contadorElementoNieve==1)
    {
        cout<< "FELICIDADES "<<nombre<< " OBTUVISTE UNA COMBINACION DE ELEMENTOS GANADORA"<< endl;
        vEstadisticasCPU[1]-=1;

        ganadorElementosJugador=true;


    }
    else
    {
        if (contadorElementoAgua==3 || contadorElementoFuego==3 || contadorElementoNieve==3)
        {

            cout<< "FELICIDADES "<<nombre<< " OBTUVISTE UNA COMBINACION DE ELEMENTOS GANADORA"<< endl;
            vEstadisticasCPU[1]-=1;

            ganadorElementosJugador=true;

        }
    }


    contadorColorRojo=0;
    contadorColorAmarillo=0;
    contadorColorAzul=0;
    contadorColorVerde=0;
    contadorElementoFuego=0;
    contadorElementoAgua=0;
    contadorElementoNieve=0;

    for (x=0; x<60; x++)
    {
        if (vCartasCPU[x]!=" " )
        {
            if (vCartasCPU[x].find("fuego")!=string::npos)
            {
                contadorElementoFuego+=1;
            }
            else if (vCartasCPU[x].find("agua")!=string::npos)
            {
                contadorElementoAgua+=1;

            }
            else if (vCartasCPU[x].find("nieve")!=string::npos)
            {
                contadorElementoNieve+=1;

            }


            else if (vCartasCPU[x].find("verde")!=string::npos)
            {
                contadorColorVerde+=1;
            }
            else if (vCartasCPU[x].find("amarillo")!=string::npos)
            {
                contadorColorAmarillo+=1;

            }
            else if (vCartasCPU[x].find("azul")!=string::npos)
            {
                contadorColorAzul+=1;
            }
            else if (vCartasCPU[x].find("rojo")!=string::npos)
            {
                contadorColorRojo+=1;
            }
        }

    }
    if (contadorColorAzul==1 && contadorColorAmarillo==1 && contadorColorRojo==1 || contadorColorAmarillo==1 && contadorColorRojo==1 && contadorColorVerde==1 ||contadorColorVerde==1 && contadorColorRojo==1 && contadorColorAzul==1 || contadorColorVerde==1 && contadorColorAmarillo==1 && contadorColorAzul==1 && contadorElementoAgua==1 && contadorElementoFuego==1 && contadorElementoNieve==1)
    {

        cout<< "CPU OBTUVO UNA COMBINACION DE ELEMENTOS GANADORA"<< endl;
        vEstadisticasJugador[1]-=1;
        ganadorElementosCPU=true;
    }
    else
    {
        if (contadorElementoAgua==3 || contadorElementoFuego==3 || contadorElementoNieve==3)
        {

            cout<< "CPU OBTUVO UNA COMBINACION DE ELEMENTOS GANADORA"<< endl;
            vEstadisticasJugador[1]-=1;

            ganadorElementosCPU=true;

        }
    }

}
int definirMayorPuntaje (string nombre, int &acumuladorPuntosJugador, int acumuladorMayorPuntaje, int vEstadisticasJugador[],int vEstadisticasMayorPuntaje[])
{
    int x;

    for (x=0; x<5; x++)
    {


        if (acumuladorMayorPuntaje==0)
        {
            vEstadisticasMayorPuntaje[x]=vEstadisticasJugador[x];
            acumuladorMayorPuntaje=acumuladorPuntosJugador;
        }
        else
        {
            if (acumuladorPuntosJugador>acumuladorMayorPuntaje)
            {
                vEstadisticasMayorPuntaje[x]=vEstadisticasJugador[x];
                acumuladorMayorPuntaje=acumuladorPuntosJugador;
            }
        }
    }
    return acumuladorMayorPuntaje;

}

void mostrarHitos (string nombre, int vEstadisticasJugador[], int vEstadisticasCPU[], string &ganadorPartida)
{
    int i;
    int acumulador;
    int acumuladorPuntosJugador=0;
    int acumuladorPuntosCPU=0;
    if (ganadorPartida=="JUGADOR")
    {
        for (i=0; i<5; i++)
        {

            acumulador= vEstadisticasJugador[i];
            acumuladorPuntosJugador+=acumulador;

        }
        cout << "HITO "<<endl;
        cout << "-----------------------------------------------------------------------------------------------------"<<endl;
        cout << "GANADOR DE LA PARTIDA                                           " << vEstadisticasJugador[0]<< " PDV"<<endl;
        cout << "COMBINACION DE ELEMENTOS CUMPLIDOS POR EL CONTRARIO             " << vEstadisticasJugador[1]<< " PDV"<<endl;
        cout << "CARTA DESAFIO CUMPLIDO POR EL CONTRARIO                         " << vEstadisticasJugador[2]<< " PDV "<<endl;
        cout << "RONDAS GANADAS AL ADVERSARIO                                    " << vEstadisticasJugador[3]<< " PDV "<<endl;
        cout << "RONDAS GANADAS AL ADVERSARIO CON IGUAL ELEMENTO                 " << vEstadisticasJugador[4]<< " PDV "<<endl;
        cout << "-----------------------------------------------------------------------------------------------------"<<endl;
        cout << "TOTAL                                                             "<< acumuladorPuntosJugador<<" PDV"<<endl;


        cout<< "GANADOR "<< nombre << " CON "<< acumuladorPuntosJugador<< " PUNTOS DE VICTORIA "<<endl;

    }

    else if (ganadorPartida=="CPU")
    {

        for (i=0; i<5; i++)
        {
            acumulador= vEstadisticasCPU[i];
            acumuladorPuntosCPU+=acumulador;


        }
        cout << "HITO "<<endl;
        cout << "-----------------------------------------------------------------------------------------------------"<<endl;
        cout << "GANADOR DE LA PARTIDA                                           " << vEstadisticasCPU[0]<< " PDV"<<endl;
        cout << "COMBINACION DE ELEMENTOS CUMPLIDOS POR EL CONTRARIO             " << vEstadisticasCPU[1]<< " PDV"<<endl;
        cout << "CARTA DESAFIO CUMPLIDO POR EL CONTRARIO                         " << vEstadisticasCPU[2]<< " PDV "<<endl;
        cout << "RONDAS GANADAS AL ADVERSARIO                                    " << vEstadisticasCPU[3]<< " PDV "<<endl;
        cout << "RONDAS GANADAS AL ADVERSARIO CON IGUAL ELEMENTO                 " << vEstadisticasCPU[4]<< " PDV "<<endl;
        cout << "-----------------------------------------------------------------------------------------------------"<<endl;
        cout << "TOTAL                                                           "<< acumuladorPuntosCPU<<" PDV"<<endl;


        cout<< "GANADOR CPU CON "<< acumuladorPuntosCPU<< " PUNTOS DE VICTORIA "<<endl;
    }

}

void mostrarGanador (bool &ganadorDesafioJugador, bool &ganadorDesafioCPU, bool &ganadorElementosJugador, bool &ganadorElementosCPU, string nombre, string &ganadorPartida, int vEstadisticasCPU[], int vEstadisticasJugador[])
{

    if (ganadorDesafioCPU==true && ganadorElementosCPU==true)
    {
        cout << "CPU GANO LA PARTIDA"<< endl;
        vEstadisticasCPU[0]+=3;
        ganadorPartida="CPU";
        mostrarHitos ( nombre, vEstadisticasJugador,vEstadisticasCPU, ganadorPartida);
    }


    else if (ganadorDesafioJugador==true && ganadorElementosJugador==true)
    {
        cout << "FELICIDADES"<< nombre<< " GANASTE LA PARTIDA"<< endl;
        vEstadisticasJugador[0]+=3;
        ganadorPartida=nombre;
        mostrarHitos (nombre, vEstadisticasJugador, vEstadisticasCPU, ganadorPartida);

    }

}
void mostrarEstadisticas (int vEstadisticasMayorPuntaje[], int &mayorPuntaje, string nombre)
{
    int x;

    cout << "MAYOR PUNTAJE HISTORICO                                                       JUGADOR: "<<nombre<<endl;
    cout << "-----------------------------------------------------------------------------------------------------"<<endl;
    cout << "GANADOR DE LA PARTIDA                                           " << vEstadisticasMayorPuntaje[0]<< " PDV"<<endl;
    cout << "COMBINACION DE ELEMENTOS CUMPLIDOS POR EL CONTRARIO             " << vEstadisticasMayorPuntaje[1]<< " PDV"<<endl;
    cout << "CARTA DESAFIO CUMPLIDO POR EL CONTRARIO                         " << vEstadisticasMayorPuntaje[2]<< " PDV "<<endl;
    cout << "RONDAS GANADAS AL ADVERSARIO                                    " << vEstadisticasMayorPuntaje[3]<< " PDV "<<endl;
    cout << "RONDAS GANADAS AL ADVERSARIO CON IGUAL ELEMENTO                 " << vEstadisticasMayorPuntaje[4]<< " PDV "<<endl;
    cout << "-----------------------------------------------------------------------------------------------------"<<endl;
    cout << "TOTAL                                                             "<<mayorPuntaje<<" PDV"<<endl;
}


