#include <iostream>
#include <ctime>
#include "rlutil.h"
#include "card.h"
#include "funciones.h"
#include "configFunctions.h"
using namespace std;

void ronda(int nroRonda, string nombre, bool jugar)
{
    string mazo[60], manoJugador[60], manoCPU[60], cartasJugadas[2];
    int desafioUsuario = asignarDesafio(0);
    int desafioCPU = asignarDesafio(desafioUsuario);

    //
    string ganadorPartida;
    //

    int contadorDesafioUsuario[2], contadorDesafioCPU[2];
    char numeroDesafioNueve[5] = {};

    //
    int vEstadisticasJugador[5]= {};
    int vEstadisticasCPU[5]= {};
    bool ganadorElementosCPU = false, ganadorElementosJugador = false, ganadorDesafioJugador = false, ganadorDesafioCPU = false;;
    //

    crearMazo(mazo);
    mezclarMazo(mazo, 60);
    asignarCartas(mazo, manoJugador, manoCPU);
    int y = 0;
    bool cartaRobada = false;
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

                    victDesafio(desafioUsuario,manoJugador, contadorDesafioUsuario, numeroDesafioNueve, vEstadisticasCPU);
                    victDesafio(desafioCPU,manoCPU, contadorDesafioCPU, numeroDesafioNueve, vEstadisticasJugador);
                    ordenamientoDeManos(manoJugador);
                    ordenamientoDeManos(manoCPU);
                    ganadorElementosJugador = combinacionGanadora(manoJugador);
                    ganadorElementosCPU = combinacionGanadora(manoCPU);
                    if(contadorDesafioUsuario[0] == true && contadorDesafioUsuario[1] == true)
                    {
                        ganadorDesafioJugador = true;
                        vEstadisticasCPU[2]-=1;
                    }
                    if(contadorDesafioCPU[0] && contadorDesafioCPU[1])
                    {
                        ganadorDesafioCPU = true;
                        vEstadisticasJugador[2]-=1;
                    }

                    if(combinacionGanadora(manoCPU))
                    {
                        vEstadisticasJugador[1]-=1;
                    }
                    if(combinacionGanadora(manoJugador))
                    {
                        vEstadisticasCPU[1]-=1;
                    }
                    rlutil::anykey();
                    if((ganadorDesafioJugador && ganadorElementosJugador) || (ganadorDesafioCPU && ganadorElementosCPU))
                    {

                        jugar = false;
                    }
                    rlutil::cls();
                    cartaRobada = false;
                    break;
                }
            }
        }
    }
    while(jugar);
    mostrarGanador (ganadorDesafioJugador,ganadorDesafioCPU,ganadorElementosJugador,ganadorElementosCPU,nombre,ganadorPartida,vEstadisticasCPU,vEstadisticasJugador);
    rlutil::anykey();
    rlutil::cls();
}

int asignarDesafio(int desafioAnterior)
{
    int desafio;
    do
    {
        desafio = rand() % 10+1;
    }
    while(desafio == desafioAnterior);
    return desafio;
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
    bool banderaRobar=false;
    int repartidoPlayer = 0, repartidoCPU = 0;
    for(int i = 0; i < 60 ; i++)
    {
        if(mazo[i] != "" && repartidoPlayer == 0)
        {
            for(int j = 0; j < 60; j++)
            {
                if(manoJugador[j] == "" && banderaRobar==false)
                {
                    manoJugador[j] = mazo[i];
                    rlutil::locate (5,10);
                    cout << "ROBASTE LA CARTA" << endl;
                    drawCard(mazo[i][0],mazo[i].back(),5,12,mazo[i][3]);
                    mazo[i] = "";
                    repartidoPlayer ++;
                    banderaRobar=true;
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
        ganadorDeRonda(cartasJugadas, manoJugador, 1,vEstadisticasJugador);
        cout << "GANA " << nombre  << " PORQUE LA NIEVE CONGELA EL AGUA"<<  endl;
    }
    else if(cartasJugadas[0].find("AGUA") != std::string::npos && cartasJugadas[1].find("FUEGO") != std::string::npos)
    {
        ganadorDeRonda(cartasJugadas, manoJugador, 1,vEstadisticasJugador);
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
            empate(manoJugador, manoCPU, cartasJugadas);
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
/*
void juego(){
    int nroRonda = 1;
    string nombreUsuario;
    do{
        nombreUsuario = solicitarNombre();
        confirmarNombre(nombreUsuario);
    }while(nombreUsuario == "");

    ronda(nroRonda,nombreUsuario);


}*/

void empate(string manoJugador[],string manoCPU[],string cartasJugadas[])
{
    manoJugador[58] = cartasJugadas[0];
    manoCPU[58] = cartasJugadas[1];
}
//En estadisticas debe ir la mano del adversario, es decir, para comprobar desafio usuario se utiliza estadisticasCPU
//y viceversa
void victDesafio(int desafio, string mano[], int completarDesafio[], char numeroConsecutivo[], int vEstadisticas[])
{
    int numActual = (int)mano[59][0] - 49;
    switch(desafio)
    {
    case 1:
        if (mano[59].find("NIEVE") != std::string::npos)
        {
            completarDesafio[0] = true;
            completarDesafio[1] = true;
        }
        break;
    case 2:
        if (mano[59].find("FUEGO") != std::string::npos)
        {
            completarDesafio[0] = true;
            completarDesafio[1] = true;
        }
        break;
    case 3:
        if (mano[59].find("AGUA") != std::string::npos)
        {
            completarDesafio[0] = true;
            completarDesafio[1] = true;
        }
        break;
    case 4:

        if(mano[59][3] == 'O')
        {
            if(!completarDesafio[0])
            {
                completarDesafio[0] = true;
            }
            else
            {
                completarDesafio[1] = true;
            }
        }
        break;
    case 5:
        if(mano[59][3] == 'M')
        {
            if(!completarDesafio[0])
            {
                completarDesafio[0] = true;
            }
            else
            {
                completarDesafio[1] = true;
            }
        }
        break;
    case 6:
        if(mano[59][3] == 'E')
        {
            if(!completarDesafio[0])
            {
                completarDesafio[0] = true;
            }
            else
            {
                completarDesafio[1] = true;
            }
        }
        break;
    case 7:
        if(mano[59][3] == 'Z')
        {
            if(!completarDesafio[0])
            {
                completarDesafio[0] = true;
            }
            else
            {
                completarDesafio[1] = true;
            }
        }
        break;
    case 8:
        if (mano[58] != "" && mano[58].back() == mano[59].back())
        {
            completarDesafio[0] = true;
            completarDesafio[1] = true;
        }
        break;
    case 9:
        if(mano[59] != "")
        {
            if(numeroConsecutivo[numActual] == '\0')
            {
                numeroConsecutivo[numActual] = mano[59][0];
            }
            else
            {
                completarDesafio[0] = true;
                completarDesafio[1] = true;
            }
        }
        break;
    case 10:
        if(mano[59] != "" && !completarDesafio[0])
        {
            completarDesafio[0] = true;;
        }
        else if(mano[59] == "" && completarDesafio[0])
        {
            completarDesafio[0] = false;
        }
        else if(mano[59] != "" && completarDesafio[0])
        {
            completarDesafio[1] = true;
        }
        break;
    }

}
//Mismo que desafio, se pasan como parametro las estadisticas contrarias
bool combinacionGanadora(string mano[])
{
    //Tener tres cartas del mismo elemento
    int fuego = 0, nieve = 0, agua = 0;
    int i = 0;
    while(mano[i] != "")
    {
        if(devolverElemento(mano[i]) == "FUEGO")
        {
            fuego++;
        }
        else if(devolverElemento(mano[i]) == "NIEVE")
        {
            nieve++;
        }
        else if(devolverElemento(mano[i]) == "AGUA")
        {
            agua++;
        }
        i++;
    }
    if(fuego >= 3 || nieve >= 3 || agua >= 3)
    {

        return true;
    }
    //Tener tres cartas de distinto elemento y distinto color.
    if(fuego >= 1 && nieve >= 1 && agua >= 1 && hayTresColores(mano, i))
    {
        return true;
    }
    return false;
}



string devolverElemento(string carta)
{
    string elemento;
    if(carta.find("FUEGO") != std::string::npos)
    {
        elemento = "FUEGO";
    }
    else if(carta.find("NIEVE") != std::string::npos)
    {
        elemento = "NIEVE";
    }
    else if(carta.find("AGUA") != std::string::npos)
    {
        elemento = "AGUA";
    }
    return elemento;
}


string devolverColor(string carta)
{
    string color;
    if(carta.find("AMARILLO") != std::string::npos)
    {
        color = "AMARILLO";
    }
    else if(carta.find("AZUL") != std::string::npos)
    {
        color = "AZUL";
    }
    else if(carta.find("VERDE") != std::string::npos)
    {
        color = "VERDE";
    }
    else if(carta.find("ROJO") != std::string::npos)
    {
        color = "ROJO";
    }
    return color;
}

bool hayTresColores(string mano[], int tam)
{
    int contadorColorRojo=0;
    int contadorColorAmarillo=0;
    int contadorColorAzul=0;
    int contadorColorVerde=0;
    for(int i = 0; i < tam; i++)
    {
        if (devolverColor(mano[i]) == "VERDE")
        {
            contadorColorVerde+=1;
        }
        else if (devolverColor(mano[i]) == "AMARILLO")
        {
            contadorColorAmarillo+=1;

        }
        else if (devolverColor(mano[i]) == "AZUL")
        {
            contadorColorAzul+=1;
        }
        else if (devolverColor(mano[i]) == "ROJO")
        {
            contadorColorRojo+=1;
        }
    }
    if ((contadorColorAzul==1 && contadorColorAmarillo==1 && contadorColorRojo==1) || (contadorColorAmarillo==1 && contadorColorRojo==1 &&
            contadorColorVerde==1) || (contadorColorVerde==1 && contadorColorRojo==1 && contadorColorAzul==1) || (contadorColorVerde==1 && contadorColorAmarillo==1 &&
                    contadorColorAzul==1))
    {
        return true;
    }
    return false;
}

void mostrarHitos (string nombre, int vEstadisticasJugador[], int vEstadisticasCPU[], string ganadorPartida)
{
    int i;
    int acumulador=0, acumulador2=0;

    if (ganadorPartida=="CPU")
    {

        for (i=0; i<5; i++)
        {
            acumulador+= vEstadisticasCPU[i];

            acumulador2+=vEstadisticasJugador[i];



        }
        cout << "HITO "<<endl;
        cout << "-----------------------------------------------------------------------------------------------------"<<endl;
        cout << "GANADOR DE LA PARTIDA                                           " << vEstadisticasCPU[0]<< " PDV"<<endl;
        cout << "COMBINACION DE ELEMENTOS CUMPLIDOS POR EL CONTRARIO             " << vEstadisticasCPU[1]<< " PDV"<<endl;
        cout << "CARTA DESAFIO CUMPLIDO POR EL CONTRARIO                         " << vEstadisticasCPU[2]<< " PDV "<<endl;
        cout << "RONDAS GANADAS AL ADVERSARIO                                    " << vEstadisticasCPU[3]<< " PDV "<<endl;
        cout << "RONDAS GANADAS AL ADVERSARIO CON IGUAL ELEMENTO                 " << vEstadisticasCPU[4]<< " PDV "<<endl;
        cout << "-----------------------------------------------------------------------------------------------------"<<endl;
        cout << "TOTAL                                                           "<< acumulador<<" PDV"<<endl;


        cout<< "GANADOR CPU CON "<< acumulador<< " PUNTOS DE VICTORIA "<<endl;

        cout<< endl << endl;
        cout << "HITO JUGADOR"<< endl;
        cout << "-----------------------------------------------------------------------------------------------------"<<endl;
        cout << "GANADOR DE LA PARTIDA                                           " << vEstadisticasJugador[0]<< " PDV"<<endl;
        cout << "COMBINACION DE ELEMENTOS CUMPLIDOS POR EL CONTRARIO             " << vEstadisticasJugador[1]<< " PDV"<<endl;
        cout << "CARTA DESAFIO CUMPLIDO POR EL CONTRARIO                         " << vEstadisticasJugador[2]<< " PDV "<<endl;
        cout << "RONDAS GANADAS AL ADVERSARIO                                    " << vEstadisticasJugador[3]<< " PDV "<<endl;
        cout << "RONDAS GANADAS AL ADVERSARIO CON IGUAL ELEMENTO                 " << vEstadisticasJugador[4]<< " PDV "<<endl;
        cout << "-----------------------------------------------------------------------------------------------------"<<endl;
        cout << "TOTAL                                                             "<< acumulador2<<" PDV"<<endl;

    }
    else
    {
        for (i=0; i<5; i++)
        {

            acumulador+= vEstadisticasCPU[i];

            acumulador2+=vEstadisticasJugador[i];

        }
        cout << "HITO "<<endl;
        cout << "-----------------------------------------------------------------------------------------------------"<<endl;
        cout << "GANADOR DE LA PARTIDA                                           " << vEstadisticasJugador[0]<< " PDV"<<endl;
        cout << "COMBINACION DE ELEMENTOS CUMPLIDOS POR EL CONTRARIO             " << vEstadisticasJugador[1]<< " PDV"<<endl;
        cout << "CARTA DESAFIO CUMPLIDO POR EL CONTRARIO                         " << vEstadisticasJugador[2]<< " PDV "<<endl;
        cout << "RONDAS GANADAS AL ADVERSARIO                                    " << vEstadisticasJugador[3]<< " PDV "<<endl;
        cout << "RONDAS GANADAS AL ADVERSARIO CON IGUAL ELEMENTO                 " << vEstadisticasJugador[4]<< " PDV "<<endl;
        cout << "-----------------------------------------------------------------------------------------------------"<<endl;
        cout << "TOTAL                                                             "<< acumulador2<<" PDV"<<endl;


        cout<< "GANADOR "<< nombre << " CON "<< acumulador2<< " PUNTOS DE VICTORIA "<<endl;

        cout<<endl<<endl;
        cout << "HITO CPU "<<endl;
        cout << "-----------------------------------------------------------------------------------------------------"<<endl;
        cout << "GANADOR DE LA PARTIDA                                           " << vEstadisticasCPU[0]<< " PDV"<<endl;
        cout << "COMBINACION DE ELEMENTOS CUMPLIDOS POR EL CONTRARIO             " << vEstadisticasCPU[1]<< " PDV"<<endl;
        cout << "CARTA DESAFIO CUMPLIDO POR EL CONTRARIO                         " << vEstadisticasCPU[2]<< " PDV "<<endl;
        cout << "RONDAS GANADAS AL ADVERSARIO                                    " << vEstadisticasCPU[3]<< " PDV "<<endl;
        cout << "RONDAS GANADAS AL ADVERSARIO CON IGUAL ELEMENTO                 " << vEstadisticasCPU[4]<< " PDV "<<endl;
        cout << "-----------------------------------------------------------------------------------------------------"<<endl;
        cout << "TOTAL                                                           "<< acumulador<<" PDV"<<endl;


    }

}

void mostrarGanador (bool ganadorDesafioJugador, bool ganadorDesafioCPU, bool ganadorElementosJugador, bool ganadorElementosCPU, string nombre, string &ganadorPartida, int vEstadisticasCPU[], int vEstadisticasJugador[])
{

    if (ganadorDesafioCPU && ganadorElementosCPU)
    {
        cout << "CPU GANO LA PARTIDA"<< endl;
        vEstadisticasCPU[0]+=3;
        ganadorPartida="CPU";
        mostrarHitos ( nombre, vEstadisticasJugador,vEstadisticasCPU, ganadorPartida);
    }


    else if (ganadorDesafioJugador && ganadorElementosJugador)
    {
        cout << "FELICIDADES "<< nombre<< " GANASTE LA PARTIDA"<< endl;
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
