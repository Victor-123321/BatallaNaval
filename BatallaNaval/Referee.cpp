#include <iostream>
#include "Referee.h"
#include "Tablero.h"

Referee::Referee() {}

bool Referee::ValidarColocacion(const Nave& nave, int fila, int columna, char orientacion, const Tablero& tablero) {
    int longitud = nave.getLongitud();

    // Validar si la nave cabe en los limites del tablero.
    if (orientacion == 'H') {
        if (columna + longitud > 10) return false;
        for (int i = 0; i < longitud; i++) {
            if (tablero.ObtenerCelda(fila, columna + i) != 'A') return false; // Verificar si hay espacio libre.
        }
    }
    else if (orientacion == 'V') {
        if (fila + longitud > 10) return false;
        for (int i = 0; i < longitud; i++) {
            if (tablero.ObtenerCelda(fila + i, columna) != 'A') return false; // Verificar si hay espacio libre.
        }
    }
    else {
        return false; // Orientacion invalida.
    }

    return true; // Si pasa todas las validaciones.
}

bool Referee::ValidarAtaque(int fila, int columna, const Tablero& tablero) const {
    // Verificar si la posicion esta dentro del rango del tablero.
    int dimensiones = 10;
    return fila > 0 && fila < dimensiones && columna > 0 && columna < dimensiones;
}

bool Referee::VerificarDerrota(Jugador& jugador) {
    // Si todas las naves estan hundidas, el jugador pierde.
    return jugador.getTablero().TodasNavesHundidas();
}
