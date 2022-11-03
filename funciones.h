#pragma once
using  namespace std;

string pedirNombre();
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
void condicionDeVictRonda(string cartasJugadas[], string nombre, string manoJugador[], string manoCPU[]);
void ganadorDeRonda(string cartasJugadas[], string manoGanadora[], bool ganoUsuario);


