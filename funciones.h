#pragma once
using  namespace std;
void logo ();
void ronda(int nroRonda, string nombre, bool jugar);
int asignarDesafio(int desafioAnterior);
string mostrarDesafio(int numero);
void crearMazo(string mazo[]);
void mezclarMazo(string mazo[], int cantidadCartas);
void asignarCartas(string mazo[], string manoJugador[],string manoCPU[]);
void robarCarta(string mazo[], string manoJugador[], string manoCPU[]);
void eleccionCartaUsuario(string manoJugador[], string cartasJugadas[]);
void eleccionCartaCPU(string manoCPU[], string cartasJugadas[]);
int cantidadCartasEnMano(string mano[]);
void dibujarCartasDisponibles(string mano[]);
void ordenamientoDeManos(string manoGeneral[]);
void acomodarCartasEnPantalla(bool pos[][8], string mano[]);
void mostrarCartasJugadas(string cartasJugadas[], string nombre);
void condicionDeVictRonda(string cartasJugadas[], string nombre, string manoJugador[], string manoCPU[], int vEstadisticasCPU[],int vEstadisticasJugador[]);
void ganadorDeRonda(string cartasJugadas[], string manoGanadora[], bool ganoUsuario, int vEstadisticas[]);
void empate(string manoJugador[],string manoCPU[],string cartasJugadas[]);
void victDesafio(int desafio, string mano[], int completarDesafio[], char numeroConsecutivo[], int vEstadisticas[]);

void mostrarGanador (bool ganadorDesafioJugador, bool ganadorDesafioCPU, bool ganadorElementosJugador, bool ganadorElementosCPU, string nombre, string &ganadorPartida, int vEstadisticasCPU[], int vEstadisticasJugador[]);
void mostrarHitos (string nombre, int vEstadisticasJugador[], int vEstadisticasCPU[], string ganadorPartida);

bool combinacionGanadora(string mano[]);
string devolverElemento(string carta);
string devolverColor(string carta);
bool hayTresColores(string mano[], int tam);

void mostrarEstadisticas (int vEstadisticasMayorPuntaje[], int &mayorPuntaje, string nombre);
int definirMayorPuntaje (string nombre, int &acumuladorPuntosJugador, int vEstadisticasJugador[],int vEstadisticasMayorPuntaje[]);
