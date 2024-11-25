#include <iostream>
#include "Tablero.h"

using namespace std;

Tablero::Tablero() : celdas(10, std::vector<char>(10, '~')) {}

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

    columna--;
    fila--;

    if (orientacion == 'H') {
        if (columna + longitud > 10) return false;
        for (int i = 0; i < longitud; i++) {
            if (celdas[fila][columna + i] != '~') return false;
        }
        for (int i = 0; i < longitud; i++) {
            celdas[fila][columna + i] = nave.getTipo()[0];
        }
    }
    else if (orientacion == 'V') {
        if (fila + longitud > 10) return false;
        for (int i = 0; i < longitud; i++) {
            if (celdas[fila + i][columna] != '~') return false;
        }
        for (int i = 0; i < longitud; i++) {
            celdas[fila + i][columna] = nave.getTipo()[0];
        }
    }
    else {
        return false;
    }
    return true;
}

void Tablero::PonerEnCelda(int fila, int columna, char caracter) {

    celdas[fila][columna] = caracter;
}

char Tablero::ObtenerCelda(int fila, int columna) const {
    return celdas[fila][columna];
}

string Tablero::RecibirAtaque(int fila, int columna) {

    if (fila < 0 || fila >= 10 || columna < 0 || columna >= 10) {
        return "invalido";
    }

    char& celda = celdas[fila][columna];

    if (celda == 'X') {
        return "repetido";
    }

    if (celda == '~') {
        return "agua";
    }

    char barco = celda;
    celda = 'X';

    bool barcoHundido = true;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int nuevaFila = fila + i;
            int nuevaColumna = columna + j;

            if (nuevaFila >= 0 && nuevaFila < 10 && nuevaColumna >= 0 && nuevaColumna < 10) {
                if (celdas[nuevaFila][nuevaColumna] == barco) {
                    barcoHundido = false; 
                }
            }
        }
    }

    if (barcoHundido) {
        return "hundido";
    }

    return "impacto";
}


bool Tablero::TodasNavesHundidas() const {
    for (const auto& fila : celdas) {
        for (const char celda : fila) {
            if (celda != '~') return false;
        }
    }
    return true;
}
