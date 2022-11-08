#pragma once
using  namespace std;

void ronda(int nroRonda, string nombre);
void asignarDesafio(int *user, int *cpu);
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
void mostrarEstadisticas (string nombre, int vEstadisticasJugador[], int vEstadisticasCPU[], string &ganadorPartida);
void mostrarGanador (bool &ganadorDesafioJugador, bool &ganadorDesafioCPU, bool &ganadorElementosJugador, bool &ganadorElementosCPU, string nombre, string &ganadorPartida, int vEstadisticasCPU[], int vEstadisticasJugador[]);
void verificarCondicionElementos(string nombre, string vCartasJugador[],string vCartasCPU[], int vEstadisticasCPU[],int vEstadisticasJugador[],bool &ganadorElementosCPU, bool &ganadorElementosJugador);
