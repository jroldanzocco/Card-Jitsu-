#ifndef AFD_H_INCLUDED
#define AFD_H_INCLUDED
using  namespace std;
void logo ();
void partida(string nombre, int vEstadisticasMayorPuntaje[],  string nombreMaximo[]);
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
void condicionDeVictRonda(string cartasJugadas[], string nombre, string manoJugador[], string manoCPU[], int vEstadisticasCPU[], int vEstadisticasJugador[]);
void ganadorDeRonda(string cartasJugadas[], string manoGanadora[], bool ganoUsuario, int vEstadisticas[]);
void empate(string manoJugador[],string manoCPU[],string cartasJugadas[]);
void victDesafioJugador(int desafio, string manoJugador[], int contadorDesafioUsuario[], char numeroConsecutivo[], int vEstadisticas[]);
void victDesafioCPU(int desafio, string manoJugador[], int contadorDesafioUsuarioCPU[], char numeroConsecutivo[], int vEstadisticas[]);
void mostrarGanador (bool ganadorDesafioJugador, bool ganadorDesafioCPU, bool ganadorElementosJugador, bool ganadorElementosCPU, string nombre, string &ganadorPartida, int vEstadisticasCPU[], int vEstadisticasJugador[], int vEstadisticasMayorPuntaje[],  string nombreMaximo[]);
void mostrarHitos (string nombre, int vEstadisticasJugador[], int vEstadisticasCPU[], string ganadorPartida, int vEstadisticasMayorPuntaje[], string nombreMaximo[]);
void guardarEstadisticas(int acumulador2, int vEstadisticasMayorPuntaje[], string nombre,  string nombreMaximo[]);
bool combinacionGanadora(string mano[]);
string devolverElemento(string carta);
string devolverColor(string carta);
int devolverNumero(string carta);
bool hayTresColores(string mano[], int tam);
void mostrarEstadisticas (int vEstadisticasMayorPuntaje[], string nombre, string nombreMaximo[]);
int definirMayorPuntaje (string nombre, int &acumuladorPuntosJugador, int vEstadisticasJugador[],int vEstadisticasMayorPuntaje[]);
string solicitarNombre();
void confirmarNombre(string nombre);
void mostrarCreditos();
void reglamento();
void box(int x,int y ,int width, int height);
void drawCard(char number, char type, int x, int y, char color);
void showItem(const char* text, int posx, int posy, bool selected);
#endif // AFD_H_INCLUDED
