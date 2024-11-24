#include <iostream>
#include "Tablero.h"

using namespace std;

Tablero::Tablero() : celdas(10, std::vector<char>(10, 'A')) {}

void Tablero::MostrarTablero() const {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
                cout << celdas[i][j] << " ";
        }
        cout << endl;
    }
}

bool Tablero::PonerNave(const Nave& nave, int fila, int columna, char orientacion) {
    int longitud = nave.getLongitud();

    if (orientacion == 'H') {
        if (columna + longitud > 10) return false;
        for (int i = 0; i < longitud; i++) {
            if (celdas[fila][columna + i] != 'A') return false;
        }
        for (int i = 0; i < longitud; i++) {
            celdas[fila][columna + i] = 'B';
        }
    }
    else if (orientacion == 'V') {
        if (fila + longitud > 10) return false;
        for (int i = 0; i < longitud; i++) {
            if (celdas[fila + i][columna] != 'A') return false;
        }
        for (int i = 0; i < longitud; i++) {
            celdas[fila + i][columna] = 'B';
        }
    }
    else {
        return false;
    }
    return true;
}

char Tablero::ObtenerCelda(int fila, int columna) const {
    return celdas[fila][columna];
}

string Tablero::RecibirAtaque(int fila, int columna) {
    if (celdas[fila][columna] == 'B') {
        celdas[fila][columna] = 'X';
        return "impacto";
    }
    else {
        return "agua";
    }
}

bool Tablero::TodasNavesHundidas() const {
    for (const auto& fila : celdas) {
        for (const char celda : fila) {
            if (celda == 'B') return false;
        }
    }
    return true;
}
