#include <iostream>
#include "Juego.h"

using namespace std;
Juego::Juego(const string& nombreJugador1, const string& nombreJugador2)
    : jugador1(nombreJugador1), jugador2(nombreJugador2) {}

void Juego::IniciarPartida() {
    cout << "Iniciando partida..." << endl;
    jugador1.PonerNaves();
    jugador2.PonerNaves();
    cout << "¡Ambos jugadores han colocado sus naves! Que gane el mejor." << endl;
}

void Juego::JugarTurno() {
    static bool turnoJugador1 = true;
    Jugador& atacante = turnoJugador1 ? jugador1 : jugador2;
    Jugador& defensor = turnoJugador1 ? jugador2 : jugador1;

    cout << "Le toca a: " << atacante.getNombre() << endl;

    int fila, columna;
    cout << "Ingresa la fila y columna para atacar (ejemplo: 3 4): ";
    cin >> fila >> columna;

    if (defensor.Atacar(fila, columna)) {
        cout << "¡Impacto!" << endl;
    }
    else {
        cout << "¡Agua! No pegas ni una" << endl;
    }

    turnoJugador1 = !turnoJugador1;
}

void Juego::FinalizarPartida() {
    if (referee.VerificarDerrota(jugador1)) {
        cout << "¡" << jugador2.getNombre() << " HUMILLÓ a " << jugador1.getNombre() << "! " << endl;
        exit(0);
    }
    if (referee.VerificarDerrota(jugador2)) {
        cout << "¡" << jugador1.getNombre() << " HUMILLÓ a " << jugador2.getNombre() << "! " << endl;
        exit(0);
    }
}

