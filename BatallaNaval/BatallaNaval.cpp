#include <iostream>
#include "Referee.h"
#include "Juego.h"

int main() {
    Juego juego("Jugador 1", "Jugador 2");
    Referee arbitro;

    juego.IniciarPartida();

    while (true) {
        juego.JugarTurno();

        // Verificar si algún jugador ha perdido.
    }

    return 0;
}

