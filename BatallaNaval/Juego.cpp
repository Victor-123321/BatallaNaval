#include <iostream>
#include "Juego.h"

#include <sstream> // Para usar stringstream
using namespace std;
Juego::Juego(const string& nombreJugador1, const string& nombreJugador2)
    : jugador1(nombreJugador1), jugador2(nombreJugador2) {}


void Juego::IniciarPartida() {
    cout << "Iniciando partida..." << endl;
    jugador1.PonerNaves();
    system("cls");
    jugador2.PonerNaves();
    system("cls");
}

void Juego::JugarTurno() {

    system("cls");

    static bool turnoJugador1 = true;
    Jugador& atacante = turnoJugador1 ? jugador1 : jugador2;
    Jugador& defensor = turnoJugador1 ? jugador2 : jugador1;

    cout << "\nLe toca a: " << atacante.getNombre() << endl;

    int fila = -1, columna = -1;
    string input = "";

    // Validar entrada del usuario
    do {
        cout << "\nIngresa la fila y columna para atacar (ejemplo: 3 4 o 10 10): ";
        getline(cin, input);

        // Usar stringstream para separar y validar la entrada
        stringstream ss(input);
        if (ss >> fila >> columna && fila >= 1 && fila <= 10 && columna >= 1 && columna <= 10) {
            
        }
        else {
            cout << "\nEntrada inválida. Por favor, ingresa dos números entre 1 y 10 separados por un espacio (ej: 3 4).\n" << endl;
            fila = -1; // Reiniciar valores para repetir el bucle
            columna = -1;
        }
    } while (fila == -1 || columna == -1);

    // Validar ataque
    if (!referee.ValidarAtaque(fila, columna, defensor.getTablero())) {
        cout << "\n\n¡Ataque inválido! Inténtalo de nuevo.\n\n";
    }
    else {
        fila--; // Ajustar a índices de matriz (0-based)
        columna--;

        string resultado = defensor.Atacar(fila, columna, atacante);

        // Mostrar resultados
        if (resultado == "impacto") {
            cout << "\n\n¡Impacto!\n\n" << endl;
        }
        else if (resultado == "hundido") {
            cout << "\n\n¡Hundido!\n\n" << endl;
        }
        else if (resultado == "agua") {
            cout << "\n\n¡Agua! No pegas ni una.\n\n" << endl;
        }
        else if (resultado == "repetido") {
            cout << "\n\n¡Repetido! No va a estar más muerto que eso.\n\n" << endl;
        }

        turnoJugador1 = !turnoJugador1; // Cambiar turno
    }
}


Jugador Juego::getJugador1() const {
    return jugador1;
}

Jugador Juego::getJugador2() const {
    return jugador2;
}

bool Juego::FinalizarPartida() {
    if (referee.VerificarDerrota(jugador1)) {
        cout << "\n\n" << jugador2.getNombre() << " HUMILLO a " << jugador1.getNombre() << "!\n\n " << endl;
        return true;
    }
    if (referee.VerificarDerrota(jugador2)) {
        cout << "\n\n" << jugador1.getNombre() << " HUMILLO a " << jugador2.getNombre() << "!\n\n " << endl;
        return true;
    }
}

