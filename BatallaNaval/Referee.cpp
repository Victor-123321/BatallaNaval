#include <iostream>
#include "Referee.h"
#include "Tablero.h"

Referee::Referee() {}

bool Referee::ValidarColocacion(const Nave& nave, int fila, int columna, char orientacion, const Tablero& tablero) {
    int longitud = nave.getLongitud();

    // Validar si la nave cabe en los límites del tablero.
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
        return false; // Orientación inválida.
    }

    return true; // Si pasa todas las validaciones.
}

bool Referee::ValidarAtaque(int fila, int columna, const Tablero& tablero) const {
    // Verificar si la posición está dentro del rango del tablero.
    int dimensiones = 10;
    return fila >= 0 && fila < dimensiones && columna >= 0 && columna < dimensiones;
}

bool Referee::VerificarDerrota(const Jugador& jugador) const {
    // Si todas las naves están hundidas, el jugador pierde.
    return jugador.getTablero().TodasNavesHundidas();
}

void Referee::RegistrarAccion(const std::string& accion) {
    logs.push_back(accion);
    std::cout << "Accion registrada: " << accion << std::endl;
}

