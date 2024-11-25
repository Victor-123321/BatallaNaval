#include <iostream>
#include "Juego.h"

using namespace std;
Juego::Juego(const string& nombreJugador1, const string& nombreJugador2)
    : jugador1(nombreJugador1), jugador2(nombreJugador2) {}


void Juego::IniciarPartida() {
    cout << "Iniciando partida..." << endl;
    jugador1.PonerNaves();
    jugador2.PonerNaves();
    system("cls");
}

void Juego::JugarTurno() {

    FinalizarPartida();

    static bool turnoJugador1 = true;
    Jugador& atacante = turnoJugador1 ? jugador1 : jugador2;
    Jugador& defensor = turnoJugador1 ? jugador2 : jugador1;

    cout << "\nLe toca a: " << atacante.getNombre() << endl;

    int fila, columna;
    cout << "\nIngresa la fila y columna para atacar (ejemplo: 3 4): ";
    cin >> fila >> columna;

    fila--;
    columna--;

    if (!referee.ValidarAtaque(fila, columna, defensor.getTablero())) {
        cout << "\n\nAtaque invalido! Intentalo de nuevo\n\n";
    }
    else {
        string resultado = defensor.Atacar(fila, columna, atacante);

        if (resultado == "impacto") {
            cout << "\n\nImpacto!\n\n" << endl;
        }
        else if (resultado == "hundido") {
            cout << "\n\nHundido!\n\n" << endl;
        }
        else if (resultado == "agua") {
            cout << "\n\nAgua! No pegas ni una\n\n" << endl;
        }
        else if (resultado == "repetido") {
            cout << "\n\nRepetido! No va a estar mas muerto que eso\n\n" << endl;
        } 

		turnoJugador1 = !turnoJugador1;

    }

}

Jugador Juego::getJugador1() const {
    return jugador1;
}

Jugador Juego::getJugador2() const {
    return jugador2;
}

void Juego::FinalizarPartida() {
    if (referee.VerificarDerrota(jugador1)) {
        cout << "\n\n" << jugador2.getNombre() << " HUMILLO a " << jugador1.getNombre() << "!\n\n " << endl;
        exit(0);
    }
    if (referee.VerificarDerrota(jugador2)) {
        cout << "\n\n" << jugador1.getNombre() << " HUMILLO a " << jugador2.getNombre() << "!\n\n " << endl;
        exit(0);
    }
}

