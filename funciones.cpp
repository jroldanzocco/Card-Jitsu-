#include <iostream>
#include <ctime>
#include "rlutil.h"
#include "funciones.h"
using namespace std;
void partida(string nombre, int vEstadisticasMayorPuntaje[],  string nombreMaximo[])
{
    bool jugar = true;
    int numeroRonda=1;
    string mazo[60], manoJugador[60], manoCPU[60], cartasJugadas[2];
    int desafioUsuario = asignarDesafio(0);
    int desafioCPU = asignarDesafio(desafioUsuario);
    string ganadorPartida;
    bool ganadorElementosCPU = false, ganadorElementosJugador = false, ganadorDesafioJugador = false, ganadorDesafioCPU = false;
    bool auxCombinacionGanadoraJugador=false;
    bool auxCombinacionGanadoraCPU=false;
    int vEstadisticasCPU[5]= {};
    int vEstadisticasJugador[5]= {};
    crearMazo(mazo);
    mezclarMazo(mazo, 60);
    asignarCartas(mazo, manoJugador, manoCPU);
    int contadorDesafioUsuario[2]= {};
    int contadorDesafioCPU[2] = {};
    char numeroDesafioNueve[5] = {};
    int y = 0;
    bool cartaRobada = false;
    ///--------------------
    rlutil::cls();
    do
    {
        rlutil::locate(5,1);
        cout << nombre << " VS. CPU" << endl;
        rlutil::locate(35,1);
        cout << "RONDA #" << numeroRonda << endl;
        rlutil::locate(1,3);
        cout << "---------------------------------------------" << endl;
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
                    condicionDeVictRonda(cartasJugadas, nombre, manoJugador, manoCPU, vEstadisticasCPU, vEstadisticasJugador);
                    victDesafioJugador(desafioUsuario, manoJugador, contadorDesafioUsuario, numeroDesafioNueve, vEstadisticasCPU);
                    victDesafioCPU(desafioCPU,manoCPU, contadorDesafioCPU, numeroDesafioNueve, vEstadisticasJugador);
                    ordenamientoDeManos(manoJugador);
                    ordenamientoDeManos(manoCPU);
                    ganadorElementosJugador = combinacionGanadora(manoJugador);
                    ganadorElementosCPU = combinacionGanadora(manoCPU);
                    if(contadorDesafioUsuario[0] == true && contadorDesafioUsuario[1] == true && !ganadorDesafioJugador)
                    {
                        ganadorDesafioJugador = true;
                        vEstadisticasCPU[2]-=1;
                        contadorDesafioUsuario[2]= {};
                        contadorDesafioCPU[2] = {};
                    }
                    if(contadorDesafioCPU[0] && contadorDesafioCPU[1])
                    {
                        ganadorDesafioCPU = true;
                        vEstadisticasJugador[2]-=1;
                    }

                    if(combinacionGanadora(manoCPU)&&!auxCombinacionGanadoraCPU)
                    {
                        vEstadisticasJugador[1]-=1;
                        auxCombinacionGanadoraCPU=true;
                    }
                    if(combinacionGanadora(manoJugador)&&!auxCombinacionGanadoraJugador)
                    {
                        vEstadisticasCPU[1]-=1;
                        auxCombinacionGanadoraJugador=true;
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
                numeroRonda++;
            }
        }
    }
    while(jugar);
    mostrarGanador (ganadorDesafioJugador,ganadorDesafioCPU,ganadorElementosJugador,ganadorElementosCPU,nombre,ganadorPartida,vEstadisticasCPU,vEstadisticasJugador, vEstadisticasMayorPuntaje,nombreMaximo);
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

    int repartidoPlayer = 0, repartidoCPU = 0;
    for(int i = 0; i < 60 ; i++)
    {
        if(mazo[i] != "" && repartidoPlayer == 0)
        {
            for(int j = 0; j < 60; j++)
            {
                if(manoJugador[j] == "" && repartidoPlayer == 0)
                {
                    manoJugador[j] = mazo[i];
                    rlutil::locate (5,10);
                    cout << "ROBASTE LA CARTA" << endl;
                    drawCard(mazo[i][0],mazo[i].back(),5,12,mazo[i][3]);
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
    int x;
    if(ganoUsuario)
    {
        manoGanadora[58] = cartasJugadas[0];
        manoGanadora[59] = cartasJugadas[1];
        vEstadisticas[3]+=1;
        for (x=0; x<1; x++)
        {
            if (cartasJugadas[x].find("FUEGO")!=std::string::npos && cartasJugadas[x+1].find("FUEGO")!=std::string::npos)
            {
                vEstadisticas[4]+=5;
            }
            else if (cartasJugadas[x].find("AGUA")!=std::string::npos && cartasJugadas[x+1].find("AGUA")!=std::string::npos)
            {
                vEstadisticas[4]+=5;
            }
            else if (cartasJugadas[x].find("NIEVE")!=std::string::npos && cartasJugadas[x+1].find("NIEVE")!=std::string::npos)
            {
                vEstadisticas[4]+=5;
            }
        }

    }
    else
    {
        manoGanadora[58] = cartasJugadas[1];
        manoGanadora[59] = cartasJugadas[0];
        vEstadisticas[3]+=1;
        for (x=0; x<1; x++)
        {
            if (cartasJugadas[x].find("FUEGO")!=std::string::npos && cartasJugadas[x+1].find("FUEGO")!=std::string::npos)
            {
                vEstadisticas[4]+=5;
            }
            else if (cartasJugadas[x].find("AGUA")!=std::string::npos && cartasJugadas[x+1].find("AGUA")!=std::string::npos)
            {
                vEstadisticas[4]+=5;
            }
            else if (cartasJugadas[x].find("NIEVE")!=std::string::npos && cartasJugadas[x+1].find("NIEVE")!=std::string::npos)
            {
                vEstadisticas[4]+=5;
            }
        }
    }
}


void empate(string manoJugador[],string manoCPU[],string cartasJugadas[])
{
    manoJugador[58] = cartasJugadas[0];
    manoCPU[58] = cartasJugadas[1];
}
void victDesafioJugador(int desafio, string manoJugador[], int completarDesafioUsuario[], char numeroConsecutivo[], int vEstadisticas[])
{
    int numActual = (int)manoJugador[59][0] - 49;
    switch(desafio)
    {
    case 1:
        if (manoJugador[59].find("NIEVE") != std::string::npos)
        {
            completarDesafioUsuario[0] = true;
            completarDesafioUsuario[1] = true;
        }
        break;
    case 2:
        if (manoJugador[59].find("FUEGO") != std::string::npos)
        {
            completarDesafioUsuario[0] = true;
            completarDesafioUsuario[1] = true;
        }
        break;
    case 3:
        if (manoJugador[59].find("AGUA") != std::string::npos)
        {
            completarDesafioUsuario[0] = true;
            completarDesafioUsuario[1] = true;
        }
        break;
    case 4:
        if(manoJugador[59][3] == 'O' && manoJugador[59] != "")
        {
            if(!completarDesafioUsuario[0])
            {
                completarDesafioUsuario[0] = true;
            }
            else
            {
                completarDesafioUsuario[1] = true;
            }
        }
        break;
    case 5:
        if(manoJugador[59][3] == 'M' && manoJugador[59] != "")
        {
            if(!completarDesafioUsuario[0])
            {
                completarDesafioUsuario[0] = true;
            }
            else
            {
                completarDesafioUsuario[1] = true;
            }
        }
        break;
    case 6:
        if(manoJugador[59][3] == 'E' && manoJugador[59] != "")
        {
            if(!completarDesafioUsuario[0])
            {
                completarDesafioUsuario[0] = true;
            }
            else
            {
                completarDesafioUsuario[1] = true;
            }
        }
        break;
    case 7:
        if(manoJugador[59][3] == 'Z' && manoJugador[59] != "")
        {
            if(!completarDesafioUsuario[0])
            {
                completarDesafioUsuario[0] = true;
            }
            else
            {
                completarDesafioUsuario[1] = true;
            }
        }
        break;
    case 8:
        if (manoJugador[59] != "" && manoJugador[58].back() == manoJugador[59].back())
        {
            completarDesafioUsuario[0] = true;
            completarDesafioUsuario[1] = true;
        }
        break;
    case 9:
        if(manoJugador[59] != "")
        {
            if(numeroConsecutivo[numActual] == '\0')
            {
                numeroConsecutivo[numActual] = manoJugador[59][0];
            }
            else
            {
                completarDesafioUsuario[0] = true;
                completarDesafioUsuario[1] = true;
            }
        }
        break;
    case 10:
        if(manoJugador[59] != "" && !completarDesafioUsuario[0])
        {
            completarDesafioUsuario[0] = true;
        }
        else if(manoJugador[59] == "" && completarDesafioUsuario[0])
        {
            completarDesafioUsuario[0] = false;
        }
        else if(manoJugador[59] != "" && completarDesafioUsuario[0])
        {
            completarDesafioUsuario[1] = true;
        }
        break;
    }
}
void victDesafioCPU(int desafio, string manoCPU[], int completarDesafioCPU[], char numeroConsecutivo[], int vEstadisticasCPU[])
{
    int numActual = (int)manoCPU[59][0] - 49;
    switch(desafio)
    {
    case 1:
        if (manoCPU[59].find("NIEVE") != std::string::npos)
        {
            completarDesafioCPU[0] = true;
            completarDesafioCPU[1] = true;
        }
        break;
    case 2:
        if (manoCPU[59].find("FUEGO") != std::string::npos)
        {
            completarDesafioCPU[0] = true;
            completarDesafioCPU[1] = true;
        }
        break;
    case 3:
        if (manoCPU[59].find("AGUA") != std::string::npos)
        {
            completarDesafioCPU[0] = true;
            completarDesafioCPU[1] = true;
        }
        break;
    case 4:

        if(manoCPU[59][3] == 'O' && manoCPU[59] != "")
        {
            if(!completarDesafioCPU[0])
            {
                completarDesafioCPU[0] = true;
            }
            else
            {
                completarDesafioCPU[1] = true;
            }
        }
        break;
    case 5:
        if(manoCPU[59][3] == 'M' && manoCPU[59] != "")
        {
            if(!completarDesafioCPU[0])
            {
                completarDesafioCPU[0] = true;
            }
            else
            {
                completarDesafioCPU[1] = true;
            }
        }
        break;
    case 6:
        if(manoCPU[59][3] == 'E' && manoCPU[59] != "")
        {
            if(!completarDesafioCPU[0])
            {
                completarDesafioCPU[0] = true;
            }
            else
            {
                completarDesafioCPU[1] = true;
            }
        }
        break;
    case 7:
        if(manoCPU[59][3] == 'Z' && manoCPU[59] != "")
        {
            if(!completarDesafioCPU[0])
            {
                completarDesafioCPU[0] = true;
            }
            else
            {
                completarDesafioCPU[1] = true;
            }
        }
        break;
    case 8:
        if (manoCPU[59] != "" && manoCPU[58].back() == manoCPU[59].back())
        {
            completarDesafioCPU[0] = true;
            completarDesafioCPU[1] = true;
        }
        break;
    case 9:
        if(manoCPU[59] != "")
        {
            if(numeroConsecutivo[numActual] == '\0')
            {
                numeroConsecutivo[numActual] = manoCPU[59][0];
            }
            else
            {
                completarDesafioCPU[0] = true;
                completarDesafioCPU[1] = true;
            }
        }
        break;
    case 10:
        if(manoCPU[59] != "" && !completarDesafioCPU[0])
        {
            completarDesafioCPU[0] = true;;
        }
        else if(manoCPU[59] == "" && completarDesafioCPU[0])
        {
            completarDesafioCPU[0] = false;
        }
        else if(manoCPU[59] != "" && completarDesafioCPU[0])
        {
            completarDesafioCPU[1] = true;
        }
        break;
    }
}
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
    if ((contadorColorAzul >= 1 && contadorColorAmarillo >= 1 && contadorColorRojo >= 1) || (contadorColorAmarillo >= 1 && contadorColorRojo >= 1 &&
            contadorColorVerde >= 1) || (contadorColorVerde >= 1 && contadorColorRojo >= 1 && contadorColorAzul >= 1) || (contadorColorVerde >= 1 && contadorColorAmarillo >= 1 &&
                    contadorColorAzul >= 1))
    {
        return true;
    }
    return false;
}
void mostrarHitos (string nombre, int vEstadisticasJugador[], int vEstadisticasCPU[], string ganadorPartida, int vEstadisticasMayorPuntaje[], string nombreMaximo[])
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
        guardarEstadisticas(acumulador2, vEstadisticasMayorPuntaje, nombre, nombreMaximo);
    }
}
void mostrarGanador (bool ganadorDesafioJugador, bool ganadorDesafioCPU, bool ganadorElementosJugador, bool ganadorElementosCPU, string nombre, string &ganadorPartida, int vEstadisticasCPU[], int vEstadisticasJugador[], int vEstadisticasMayorPuntaje[], string nombreMaximo[])
{
    if (ganadorDesafioCPU && ganadorElementosCPU)
    {
        cout << "CPU GANO LA PARTIDA"<< endl;
        vEstadisticasCPU[0]+=3;
        ganadorPartida="CPU";
        mostrarHitos ( nombre, vEstadisticasJugador,vEstadisticasCPU, ganadorPartida, vEstadisticasMayorPuntaje, nombreMaximo);
    }
    else if (ganadorDesafioJugador && ganadorElementosJugador)
    {
        cout << "FELICIDADES "<< nombre<< " GANASTE LA PARTIDA"<< endl;
        vEstadisticasJugador[0]+=3;
        ganadorPartida=nombre;
        mostrarHitos (nombre, vEstadisticasJugador, vEstadisticasCPU, ganadorPartida, vEstadisticasMayorPuntaje, nombreMaximo);
    }
}
void guardarEstadisticas(int acumulador2, int vEstadisticasMayorPuntaje[], string nombre, string nombreMaximo[])
{
    int aux;
    string aux2;
    for (int i=0; i<5; i++)
    {
        if (acumulador2 > vEstadisticasMayorPuntaje[i])
        {
            vEstadisticasMayorPuntaje[4] = acumulador2;
            nombreMaximo[4] = nombre;
            i=5;
        }
    }
    for (int j=0; j<5; j++)
    {
        for (int i=0; i<4; i++)
        {
            if (vEstadisticasMayorPuntaje[i]<vEstadisticasMayorPuntaje[i+1])
            {
                aux=vEstadisticasMayorPuntaje[i+1];
                vEstadisticasMayorPuntaje[i+1]=vEstadisticasMayorPuntaje[i];
                vEstadisticasMayorPuntaje[i]=aux;
                aux2=nombreMaximo[i+1];
                nombreMaximo[i+1]=nombreMaximo[i];
                nombreMaximo[i]=aux2;
            }
        }
    }
}
void mostrarEstadisticas (int vEstadisticasMayorPuntaje[], string nombre, string nombreMaximo[])
{
    rlutil::cls();
    cout << "MAYORES PUNTAJES                                   JUGADOR" << endl;
    cout << "--------------------------------------------------------------"<<endl;
    for (int i=0; i<5; i++)
    {
        if (vEstadisticasMayorPuntaje[i] != 0)
        {
            cout << vEstadisticasMayorPuntaje[i] << " PDV                                          " << nombreMaximo[i] << endl;
            cout << "--------------------------------------------------------------"<<endl;
        }
    }
    rlutil::locate(1,15);
    rlutil::setColor(8);
    cout << "PRESIONA UNA TECLA PARA VOLVER" << endl;
    rlutil::setColor(15);
    rlutil::anykey();
    rlutil::cls();
}
string solicitarNombre()
{
    string n = {};
    do
    {
        rlutil::setColor(15);
        rlutil::cls();
        rlutil::locate(5,5);
        cout << "Ingresa tu nombre: ";
        getline(cin, n);
    }
    while(n == "");
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
            rlutil::locate(14,9+y);
            cout << " " << endl;
            y--;
            if (y<0)
            {
                y=0;
            }
            break;
        case 15: // DOWN
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
    cout << "Juan Sarmiento - 27543" << endl;
    rlutil::locate(x,17);
    cout << "Jeremias Roldan Zocco - 27609" << endl;
    rlutil::locate(x,18);
    cout << "Fiorella Milagros Acosta - 27503" << endl;
    rlutil::locate(x,19);
    cout << "Juan Manuel Escobar - 27569" << endl;
    rlutil::anykey();
}
void reglamento()
{
rlutil::setBackgroundColor(0);
rlutil::cls();

rlutil::setColor(5);
rlutil::locate (55,1);
cout<<"Card Jitsu ++ "<<endl;
rlutil::locate (40,2);
cout<<"*************************************************"<<endl<<endl<<endl;
rlutil::setColor(15);
cout<<">>El objetivo general del juego es lograr una combinacion de cartas de elementos"<<endl;
cout<<"y cumplir con la carta desafio obtenida al comienzo de la partida. El primer jugador"<<endl;
cout<<"en cumplir ambos objetivos es quien ganara el juego."<<endl<<endl;

rlutil::locate (55,30);
cout<<"Presione una tecla para continuar";
rlutil::anykey();
rlutil::cls();

rlutil::setColor(5);
rlutil::locate (55,1);
cout<<"Cartas desafio"<<endl;
rlutil::locate (40,2);
cout<<"*************************************************"<<endl<<endl<<endl;
rlutil::setColor(15);
cout<<">> En total existen diez cartas en el mazo de desafios,cada una con un desafio distinto a cumplir."<<endl;
cout<<"A cada jugador se le asigna una de estas cartas por partida."<<endl << endl;
cout<<"los diez desafios existentes son :"<<endl<<endl;

cout<<"1 - Ganar una carta de Nieve."<<endl;
cout<<"2 - Ganar una carta de Fuego."<<endl;
cout<<"3 - Ganar una carta de Agua."<<endl;
cout<<"4 - Ganar dos cartas rojas."<<endl;
cout<<"5 - Ganar dos cartas amarillas."<<endl;
cout<<"6 - Ganar dos cartas verdes."<<endl;
cout<<"7 - Ganar dos cartas azules."<<endl;
cout<<"8 - Ganar una carta con el mismo elemento que el adversario."<<endl;
cout<<"9 - Ganar dos cartas con el mismo numero."<<endl;
cout<<"10 - Ganar dos rondas de manera consecutiva."<<endl;

rlutil::locate (55,30);
cout<<"Presione una tecla para continuar";
rlutil::anykey();
rlutil::cls();

rlutil::setColor(5);
rlutil::locate (55,1);
cout<<"Cartas de elementos"<<endl;
rlutil::locate (40,2);
cout<<"-------------------------------------------------"<<endl<<endl<<endl;
rlutil::setColor(15);

cout<<">> Estas cartas se caracterizan por tener un elemento (fuego, nieve o agua), un color"<<endl;
cout<<"(rojo, amarillo, verde y azul) y un número (de 1 a 5). En total son 60 naipes."<<endl;
cout<<"Estas cartas son necesarias para jugar en las rondas de elementos."<<endl;

drawCard('1','O',40,10,'O');
drawCard('1','E',50,10,'Z');
drawCard('1','A',60,10,'M');

rlutil::locate (55,30);
cout<<"Presione una tecla para continuar";
rlutil::anykey();
rlutil::cls();

rlutil::setColor(5);
rlutil::locate (55,1);
cout<<"Como se juega?"<<endl;
rlutil::locate (40,2);
cout<<"-------------------------------------------------"<<endl<<endl<<endl;
rlutil::setColor(15);
cout<<"-Cada uno de los dos jugadores debera tomar una carta de la pila de cartas desafios y guardarla."<<endl;
cout<<"-Cada jugador comienza la partida con tres cartas elemento."<<endl;
cout<<"-Cada jugador juega una carta de elementos de su preferencia y se determina quien gana esa ronda."<<endl;
cout<<"-Un jugador nunca puede tener menos de tres cartas en su mano."<<endl;


rlutil::locate (55,30);
cout<<"Presione una tecla para continuar";
rlutil::anykey();
rlutil::cls();

rlutil::setColor(5);
rlutil::locate (50,1);
cout<<"¿Como se gana una ronda?"<<endl;
rlutil::locate (40,2);
cout<<"-------------------------------------------------"<<endl<<endl<<endl;
rlutil::setColor(15);
cout<<">> Para determinar esto se siguen las siguientes reglas:"<<endl<<endl;
cout<<"-El fuego vence a la nieve."<<endl;
cout<<"-La nieve vence al agua."<<endl;
cout<<"-El agua vence al fuego."<<endl;
cout << endl;
cout<<"-Si se enfrentan cartas del mismo elemento,gana la que tenga mayor numero."<<endl;
cout<<"-Si ambos numeros son iguales la ronda se declara un empate y las cartas vuelven a sus manos"<<endl;

rlutil::locate (55,30);
cout<<"Presione una tecla para continuar";
rlutil::anykey();
rlutil::cls();

rlutil::setColor(5);
rlutil::locate (42,1);
cout<<"Obtener una combinacion de elementos ganadora"<<endl;
rlutil::locate (40,2);
cout<<"-------------------------------------------------"<<endl<<endl<<endl;
rlutil::setColor(15);
cout<<">> Para obtener una combinacion de elementos ganadora, un jugador debe lograr alguna de las siguientes situaciones:"<<endl<<endl;
cout<<"-Tener tres cartas de distinto elemento y distinto color."<<endl;
cout<<"-Tener tres cartas del mismo elemento."<<endl;

drawCard('5','O',10,10,'O');
drawCard('2','E',20,10,'Z');
drawCard('3','A',30,10,'M');

drawCard('1','O',50,10,'O');
drawCard('3','O',60,10,'O');
drawCard('4','O',70,10,'M');

rlutil::locate (55,30);
cout<<"Presione una tecla para continuar";
rlutil::anykey();
rlutil::cls();
rlutil::setColor(5);
rlutil::locate (55,1);
cout<<"Valor de los puntos"<<endl;
rlutil::locate (40,2);
cout<<"-------------------------------------------------"<<endl<<endl<<endl;
rlutil::setColor(15);
cout<<">> Una vez finalizada la partida, se determinan los puntos de victoria de la misma. Los mismos se calculan";
cout<<"de la siguiente manera:"<<endl<<endl;
cout<<"+3 PDV por haber ganado la partida."<<endl;
cout<<"-1 PDV si el contrario obtuvo una combinacion de elementos ganadora."<<endl;
cout<<"-1 PDV si el contrario cumplio el objetivo de su carta desafio."<<endl;
cout<<"+1 PDV por cada ronda ganada en el juego al adversario."<<endl;
cout<<"+5 PDV por cada ronda ganada en el juego con un elemento igual al del adversario."<<endl;
rlutil::locate (40,30);
cout<<"Presione una tecla para continuar";
rlutil::anykey();
rlutil::cls();
rlutil::setColor(5);
rlutil::locate (50,14);
cout<<"Empecemos a jugar :)";
rlutil::anykey();
rlutil::setColor(rlutil::WHITE);

}
void logo (bool animado)
{
    int xcolumna;
    rlutil::hidecursor();
    ///letra C
    rlutil::locate(30, 3);
    cout<< "******"<<std::endl;
    rlutil::locate(30, 4);
    cout<< "**"<<std::endl;
    rlutil::locate(30, 5);
    cout<< "**"<<std::endl;
    rlutil::locate(30, 6);
    cout<< "**"<<std::endl;
    rlutil::locate(30, 7);
    cout<< "******"<<std::endl;
    ///LETRA A
    rlutil::locate(37, 3);
    cout<< "******"<<std::endl;
    rlutil::locate(37, 4);
    cout<< "**"<<std::endl;
    rlutil::locate(37, 5);
    cout<< "*"<<std::endl;
    rlutil::locate(38, 5);
    cout<< "*****"<<std::endl;
    rlutil::locate(37, 6);
    cout<< "**"<<std::endl;
    rlutil::locate(37, 7);
    cout<< "**"<<std::endl;
    rlutil::locate(41, 3);
    cout<< "**"<<std::endl;
    rlutil::locate(41, 4);
    cout<< "**"<<std::endl;
    rlutil::locate(41, 5);
    cout<< "*"<<std::endl;
    rlutil::locate(41, 6);
    cout<< "**"<<std::endl;
    rlutil::locate(41, 7);
    cout<< "**"<<std::endl;
    ///LETRA R
    rlutil::locate(44, 3);
    cout<< "****"<<std::endl;
    rlutil::locate(44, 4);
    cout<< "**"<<std::endl;
    rlutil::locate(44, 5);
    cout<< "**"<<std::endl;
    rlutil::locate(44, 5);
    cout<< "***"<<std::endl;
    rlutil::locate(44, 6);
    cout<< "**"<<std::endl;
    rlutil::locate(44, 7);
    cout<< "**"<<std::endl;
    rlutil::locate(46, 3);
    cout<< "**"<<std::endl;
    rlutil::locate(47, 3);
    cout<< " *"<<std::endl;
    rlutil::locate(47, 4);
    cout<< " *"<<std::endl;
    rlutil::locate(47, 5);
    cout<< "*"<<std::endl;
    rlutil::locate(47, 6);
    cout<< " *"<<std::endl;
    rlutil::locate(47, 7);
    cout<< " *"<<std::endl;
    ///LETRA D
    rlutil::locate(50, 3);
    cout<< "****"<<std::endl;
    rlutil::locate(50, 4);
    cout<< "**"<<std::endl;
    rlutil::locate(50, 5);
    cout<< "**"<<std::endl;
    rlutil::locate(50, 5);
    cout<< "**"<<std::endl;
    rlutil::locate(50, 6);
    cout<< "**"<<std::endl;
    rlutil::locate(50, 7);
    cout<< "**"<<std::endl;
    rlutil::locate(50, 7);
    cout<< "**"<<std::endl;
    rlutil::locate(52, 3);
    cout<< "**"<<std::endl;
    rlutil::locate(53, 4);
    cout<< " *"<<std::endl;
    rlutil::locate(53, 5);
    cout<< " *"<<std::endl;
    rlutil::locate(53, 6);
    cout<< " *"<<std::endl;
    rlutil::locate(52, 7);
    cout<< "*"<<std::endl;
    ///LETRA J
    rlutil::locate(60, 3);
    cout<< "*****"<<std::endl;
    rlutil::locate(63, 4);
    cout<< "**"<<std::endl;
    rlutil::locate(63, 5);
    cout<< "**"<<std::endl;
    rlutil::locate(63, 5);
    cout<< "**"<<std::endl;
    rlutil::locate(63, 6);
    cout<< "**"<<std::endl;
    rlutil::locate(60, 7);
    cout<< "*****"<<std::endl;
    rlutil::locate(63, 5);
    cout<< "*"<<std::endl;
    ///LETRA I
    rlutil::locate(66, 3);
    cout<< "*****"<<std::endl;
    rlutil::locate(68, 4);
    cout<< "*"<<std::endl;
    rlutil::locate(68, 5);
    cout<< "*"<<std::endl;
    rlutil::locate(68, 5);
    cout<< "*"<<std::endl;
    rlutil::locate(68, 6);
    cout<< "*"<<std::endl;
    rlutil::locate(66, 7);
    cout<< "*****"<<std::endl;
    //LETRA T
    rlutil::locate(72, 3);
    cout<< "******"<<std::endl;
    rlutil::locate(74, 4);
    cout<< "**"<<std::endl;
    rlutil::locate(74, 5);
    cout<< "**"<<std::endl;
    rlutil::locate(74, 5);
    cout<< "**"<<std::endl;
    rlutil::locate(74, 6);
    cout<< "**"<<std::endl;
    rlutil::locate(74, 7);
    cout<< "**"<<std::endl;
    ///LETRA S
    rlutil::locate(79, 3);
    cout<< "*****"<<std::endl;
    rlutil::locate(79, 4);
    cout<< "**"<<std::endl;
    rlutil::locate(79, 5);
    cout<< "**"<<std::endl;
    rlutil::locate(79, 5);
    cout<< "*****"<<std::endl;
    rlutil::locate(82, 6);
    cout<< " *"<<std::endl;
    rlutil::locate(79, 7);
    cout<< "*****"<<std::endl;
    ///LETRA U
    rlutil::locate(85, 3);
    cout<< "**"<<std::endl;
    rlutil::locate(85, 4);
    cout<< "**"<<std::endl;
    rlutil::locate(85, 5);
    cout<< "**"<<std::endl;
    rlutil::locate(85, 5);
    cout<< "**"<<std::endl;
    rlutil::locate(85, 6);
    cout<< "**"<<std::endl;
    rlutil::locate(85, 7);
    cout<< "*******"<<std::endl;
    rlutil::locate(90, 3);
    cout<< "**"<<std::endl;
    rlutil::locate(90, 4);
    cout<< "**"<<std::endl;
    rlutil::locate(90, 5);
    cout<< "**"<<std::endl;
    rlutil::locate(90, 5);
    cout<< "**"<<std::endl;
    rlutil::locate(90, 6);
    cout<< "**"<<std::endl;
    rlutil::setColor(rlutil::WHITE);
    for (xcolumna=22; xcolumna<=105; xcolumna++)
    {
        if(animado){
        rlutil::msleep(7);
        }
        rlutil::locate (xcolumna,2);
        cout<<(char)242;
        rlutil::locate (xcolumna,8);
        cout<<(char)242;
    }
    rlutil::locate (96,3);
    cout<< (char)179<<std::endl;
    rlutil::locate (96,4);
    cout<< (char)197<<std::endl;
    rlutil::locate (96,5);
    cout<< (char)179<<std::endl;
    rlutil::locate (94,4);
    cout<< (char)196<<std::endl;
    rlutil::locate (98,4);
    cout<< (char)196<<std::endl;
    rlutil::locate (100,5);
    cout<< (char)179<<std::endl;
    rlutil::locate (100,6);
    cout<< (char)197<<std::endl;
    rlutil::locate (100,7);
    cout<< (char)179<<std::endl;
    rlutil::locate (98,6);
    cout<< (char)196<<std::endl;
    rlutil::locate (102,6);
    cout<< (char)196<<std::endl;
}
void box(int x,int y,int width, int height)
{
    width--;
    height--;
    for(int posx = x; posx <= x + width; posx++)
    {
        rlutil::locate(posx, y);
        cout << (char)205;
        rlutil::locate(posx,y+height);
        cout << (char)205;
    }
    for(int posy = y; posy <= y + height; posy++)
    {
        rlutil::locate(x, posy);
        cout << (char)186;
        rlutil::locate(x+width, posy);
        cout << (char)186;
    }
    rlutil::locate(x,y);
    cout << (char)201;
    rlutil::locate(x+width, y);
    cout << (char)187;
    rlutil::locate(x,y+height);
    cout << (char)200;
    rlutil::locate(x+width,y+height);
    cout << (char)188;
}
void setColor(char color)
{
    switch(color)
    {
    case 'Z':
        rlutil::setColor(9);
        break;
    case 'M':
        rlutil::setColor(6);
        break;
    case 'O':
        rlutil::setColor(4);
        break;
    case 'E':
        rlutil::setColor(10);
        break;
    }
}
void drawCard(char number, char type, int x, int y, char color)
{
    setColor(color);
    box(x,y,7,5);
    rlutil::locate(x + 1, y + 1);
    cout << number;
    rlutil::locate(x + 5, y + 3);
    cout << number;
    rlutil::locate(x + 3, y + 2);
    switch(type)
    {
    case 'O':
        cout << "F";
        break;
    case 'E':
        cout << "N";
        break;
    case 'A':
        cout << "A";
        break;
    }
    rlutil::setColor(15);
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

int confirmarSalir(int op)
{
    int y = 0;
    rlutil::cls();
    do
    {
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::DARKGREY);
        rlutil::locate(40,12);
        std::cout<< " SEGURO DESEA SALIR??? "<<std::endl;
        rlutil::locate(40,13);
        std::cout<< " NO"<<std::endl;
        rlutil::locate(40,14 );
        std::cout << " SI"<< std::endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(38,13+y);
        std::cout<<(char)175<< std::endl;
        switch(rlutil::getkey())
        {
        case 14: //UP
            rlutil::locate(38,13+y);
            cout << " " << endl;
            y--;
            if(y < 0)
            {
                y = 1;
            }
            break;
        case 15: //DOWN
            rlutil::locate(38,13+y);
            cout << " " << endl;
            y++;
            if(y > 1)
            {
                y = 0;
            }
            break;
        case 1: //ENTER
            switch(y+1)
            {
            case 1:
                rlutil::cls();
                return 1;
                break;
            case 2:
                rlutil::cls();
                rlutil::locate(40,13);
                cout << "¡¡¡ GRACIAS POR JUGAR CON NOSOTROS !!!";
                return 0;
                break;
            }
        default:
            break;
        }
    }
    while(op != 0);
}
