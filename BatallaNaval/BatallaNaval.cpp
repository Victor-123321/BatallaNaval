#include <iostream>
#include "Referee.h"
#include "Juego.h"

using namespace std;

bool jugador = true;

void mostrarMenu() {
    string player = jugador ? "Jugador 1" : "Jugador 2";
    cout << "\n\n";
    cout << "===" << player << "===\n";
    cout << "1. Ver tu tablero\n";
    cout << "2. Ver tablero de disparos\n";
    cout << "3. Realizar ataque\n";
    cout << "4. Salir\n";
    cout << "Selecciona una opcion: ";
}

int main() {
    Juego juego("Jugador 1", "Jugador 2");
    Referee arbitro;

    juego.IniciarPartida();
    cout << "-----------------------------------------------------------" << endl;
    cout << "Ambos jugadores han colocado sus naves! Que gane el mejor." << endl;
    cout << "-----------------------------------------------------------" << endl;

    // true = 1 , false = 2

    while (true) {

        while (true) {
            mostrarMenu();
            int opcion;
            cin >> opcion;

            switch (opcion) {
            case 1:
                cout << "Tu Tablero:\n";
                if (jugador) {
                    juego.getJugador1().getTablero().MostrarTablero();
                }
                else {
                    juego.getJugador2().getTablero().MostrarTablero();
                }

                break;
            case 2:
                cout << "Tablero de Disparos:\n";
                if (jugador) {
                    juego.getJugador1().getTableroDisparos().MostrarTablero();
                }
                else {
                    juego.getJugador2().getTableroDisparos().MostrarTablero();
                }
                break;
            case 3: {
                juego.JugarTurno();
                jugador = !jugador;
                break;
            }
            case 4:
                cout << "Saliendo del juego...\n";
                return 0;
            default:
                cout << "Opcion invalida.\n";
                break;
            }
        }


        juego.JugarTurno();
        jugador = !jugador;
        // Verificar si algun jugador ha perdido.
    }

    return 0;
}

