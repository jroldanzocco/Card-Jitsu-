#include <iostream>
#include <ctime>
#include "rlutil.h"
#include "card.h"
#include "funciones.h"
using namespace std;

void ronda(int nroRonda, string nombre){
    string mazo[60], manoJugador[60], manoCPU[60], cartasJugadas[2];
    crearMazo(mazo);
    mezclarMazo(mazo, 60);
    asignarCartas(mazo, manoJugador, manoCPU);
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
            switch(y+1){
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
            switch(y+1){
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
                condicionDeVictRonda(cartasJugadas,nombre,manoJugador,manoCPU);
                ordenamientoDeManos(manoJugador);
                ordenamientoDeManos(manoCPU);
                rlutil::anykey();
                rlutil::cls();
                cartaRobada = false;
                break;
            }
        }
   }
    }while(op == 1);

}

void asignarDesafio(int* user, int* cpu){

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

void crearMazo(string mazo[]){
    string numero[5] = {"1","2","3","4","5"};
    string elemento[3] = {"FUEGO","NIEVE","AGUA"};
    string color[4] = {"ROJO","AZUL","VERDE","AMARILLO"};
    const int NUMEROS = 5, COLORES = 4, ELEMENTOS = 3;
    int l = 59;
    for(int i = 0; i < ELEMENTOS; i++){
        for(int j = 0; j < COLORES; j++){
            for(int x = 0; x < NUMEROS; x++){
                mazo[l] = numero[x] + " " + color[j] + " " + elemento[i];
                l--;
            }
        }
    }
}

void mezclarMazo(string mazo[], int cantidadCartas){
   for(int i = 0; i < cantidadCartas; i++){
        string aux;
        int j = rand() % cantidadCartas;
        aux = mazo[i];
        mazo[i] = mazo[j];
        mazo[j] = aux;
    }
}

void asignarCartas(string mazo[], string manoJugador[],string manoCPU[]){
    const int CARTASINICIALES = 3;
    int repartido = 0;
    for(int i = 0; i < CARTASINICIALES; i++){
        manoJugador[i] = mazo[repartido];
        mazo[repartido] = "";
        manoCPU[i] = mazo[repartido + 1];
        mazo[repartido+1] = "";
        repartido+=2;
    }
}

void robarCarta(string mazo[], string manoJugador[], string manoCPU[]){
    int repartidoPlayer = 0, repartidoCPU = 0;
    for(int i = 0; i < 60 ; i++){
        if(mazo[i] != "" && repartidoPlayer == 0){
            for(int j = 0; j < 60; j++){
                if(manoJugador[j] == ""){
                    manoJugador[j] = mazo[i];
                    mazo[i] = "";
                    repartidoPlayer ++;
                }
            }
        }else if(mazo[i] != "" && repartidoCPU == 0){
            for(int j = 0; j < 60; j++){
                if(manoCPU[j] == ""){
                    manoCPU[j] = mazo[i];
                    mazo[i] = "";
                    repartidoCPU++;
                    break;
                }
            }
        }
    }
}
void eleccionCartaUsuario(string manoJugador[], string cartasJugadas[]){
    bool posiciones[8][8] = {};
    acomodarCartasEnPantalla(posiciones, manoJugador);
    int op = 0;
    int x = 0, y = 0, posX = 0, posY = 0;
    int eleccion = 0, aux;
    dibujarCartasDisponibles(manoJugador);


    do{
            rlutil::locate(8+x,5+y);
            cout << (char)88;
    switch(rlutil::getkey()){
    case 16: //LEFT
        rlutil::locate(8+x,5+y);
            cout << " " << endl;
            aux = eleccion;
            eleccion--;
            x-=10;
            posX--;
            if(posX < 0){
                posX = 0;
                x = 0;
                eleccion = aux;
            }
        break;
    case 17: //RIGHT
        rlutil::locate(8+x,5+y);
            cout << " " << endl;
            if(posiciones[posY][posX+1] && posX < 7){
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
            if(y < 0){
                y = 0;
                posY = 0;
                eleccion = aux;

            }
        break;

    case 15: // DOWN
        rlutil::locate(8+x,5+y);
            cout << " " << endl;
            aux = eleccion;

                if(posiciones[posY+1][posX] && posY < 7){
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
    }while(op == 0);


}

int cantidadCartasEnMano(string mano[]){
    string auxiliar[60];
    int i = 0;
    while(mano[i] != ""){
        i++;
    }
    return i;
}


void dibujarCartasDisponibles(string mano[]){
    int cartas = cantidadCartasEnMano(mano);
    int posX = 5;
    int y = 6;
    for(int i = 0; i < cartas; i++){
        if(i == 56){
            y = 48;
            posX = 5;
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }else if(i > 56){
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }else if(i == 48){
            y = 42;
            posX = 5;
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }else if(i > 48){
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }else if(i == 40){
            y = 36;
            posX = 5;
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }else if(i > 40){
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }else if(i == 32){
            y = 30;
            posX = 5;
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }else if(i > 32){
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }else if( i == 24){
            y = 24;
            posX = 5;
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }else if(i > 24){
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }else if(i == 16){
            y = 18;
            posX = 5;
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }else if(i > 16){
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }else if(i == 8){
            y = 12;
            posX = 5;
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }else if(i > 8){
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }else{
            drawCard(mano[i][0],mano[i].back(),posX,y,mano[i][3]);
            posX+=10;
        }
    }
}

void eleccionCartaCPU(string manoCPU[], string cartasJugadas[]){
    const int limiteCartas = 60;
    int contadorCartas = 0;
    int jugadaRandom;
    for(int i = 0; i < limiteCartas; i++){
        if(manoCPU[i] != ""){
            contadorCartas++;
        }
    }
    jugadaRandom = rand() % contadorCartas;
    cartasJugadas[1] = manoCPU[jugadaRandom];
    manoCPU[jugadaRandom] = "";

    }

void ordenamientoDeManos(string manoGeneral[]){
    string auxiliar[60];
    int indiceaux = 0;
    for( int i = 0; i < 60; i++){
        if(manoGeneral[i] != ""){
            auxiliar[indiceaux] = manoGeneral[i];
            indiceaux++;
        }
    }
    for(int i = 0; i < 60; i++){
        manoGeneral[i] = "";
    }
    for(int i = 0; i <= indiceaux; i++){
        manoGeneral[i] = auxiliar[i];
    }
}

void acomodarCartasEnPantalla(bool pos[][8], string mano[]){
    int maximoX = 8;
    int maximoY = 8;
    int conteoCartas = 0;
    for(int i = 0; i < maximoY; i++){
        for(int j = 0; j < maximoX; j++){
            if(mano[conteoCartas] != ""){
                pos[i][j] = true;
                conteoCartas++;
            }
        }
    }
}

string pedirNombre(){
    string nombre = {};

    do{
        rlutil::cls();
        rlutil::locate(5,5);
        cout << "Ingresa tu nombre: ";
        getline(cin, nombre);
    }while(nombre == "");
    return nombre;
}

void mostrarCartasJugadas(string cartasJugadas[], string nombre){
    rlutil::cls();
    rlutil::locate(20,3);
    cout << nombre << " JUEGA" << endl;
    drawCard(cartasJugadas[0][0],cartasJugadas[0].back(),21,6,cartasJugadas[0][3]);
    rlutil::locate(60,3);
    cout << "CPU JUEGA" << endl;
    drawCard(cartasJugadas[1][0],cartasJugadas[1].back(),61,6,cartasJugadas[1][3]);
}

void condicionDeVictRonda(string cartasJugadas[], string nombre, string manoJugador[], string manoCPU[]){
    rlutil::locate(25,13);
    if(cartasJugadas[0].find("FUEGO") != std::string::npos && cartasJugadas[1].find("NIEVE") != std::string::npos){
        ganadorDeRonda(cartasJugadas, manoJugador, 1);
        cout << "GANA "<< nombre << " PORQUE EL FUEGO DERRITE LA NIEVE"<<  endl;
    }else if(cartasJugadas[0].find("NIEVE") != std::string::npos && cartasJugadas[1].find("AGUA") != std::string::npos){
        ganadorDeRonda(cartasJugadas, manoJugador, 1);
        cout << "GANA " << nombre  << " PORQUE LA NIEVE CONGELA EL AGUA"<<  endl;
    }else if(cartasJugadas[0].find("AGUA") != std::string::npos && cartasJugadas[1].find("FUEGO") != std::string::npos){
        ganadorDeRonda(cartasJugadas, manoJugador, 1);
        cout << "GANA " << nombre << " PORQUE EL AGUA APAGA EL FUEGO"<<  endl;
    }else if(cartasJugadas[0].find("NIEVE") != std::string::npos && cartasJugadas[1].find("FUEGO") != std::string::npos){
        ganadorDeRonda(cartasJugadas, manoCPU, 0);
        cout << "GANA CPU" << " PORQUE EL FUEGO DERRITE LA NIEVE"<<  endl;
    }else if(cartasJugadas[0].find("AGUA") != std::string::npos && cartasJugadas[1].find("NIEVE") != std::string::npos){
        ganadorDeRonda(cartasJugadas, manoCPU, 0);
        cout << "GANA CPU" << " PORQUE LA NIEVE CONGELA EL AGUA"<<  endl;
    }else if(cartasJugadas[0].find("FUEGO") != std::string::npos && cartasJugadas[1].find("AGUA") != std::string::npos){
        ganadorDeRonda(cartasJugadas, manoCPU, 0);
        cout << "GANA CPU" << " PORQUE EL AGUA APAGA EL FUEGO"<<  endl;
    }else{
        if(cartasJugadas[0][0] > cartasJugadas[1][0]){
            ganadorDeRonda(cartasJugadas, manoJugador, 1);
            cout << "GANA " << nombre << " PORQUE SU NUMERO DE CARTA ES MAYOR"<<  endl;
        }else if(cartasJugadas[0][0] < cartasJugadas[1][0]){
            ganadorDeRonda(cartasJugadas, manoCPU, 0);
            cout << "GANA CPU" << " PORQUE SU NUMERO DE CARTA ES MAYOR"<<  endl;
        }else{
            cout << "EMPATE" << " PORQUE TANTO LOS ELEMENTOS COMO LOS NUMEROS DE CARTA SON IGUALES"<<  endl;
        }
    }
}

void ganadorDeRonda(string cartasJugadas[], string manoGanadora[], bool ganoUsuario){
    if(ganoUsuario){
    manoGanadora[58] = cartasJugadas[0];
    manoGanadora[59] = cartasJugadas[1];
    }else{
        manoGanadora[58] = cartasJugadas[1];
        manoGanadora[59] = cartasJugadas[0];
    }
}
