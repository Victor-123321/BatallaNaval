#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include <string>
#include "Nave.h"

using namespace std;

class Tablero {
private:
    vector<vector<char>> celdas; // 'A' = agua, 'B' = barco, 'X' = impacto

public:
    Tablero();
    void MostrarTablero() const;
    bool PonerNave(const Nave& nave, int fila, int columna, char orientacion);
    bool TodasNavesHundidas() const;
    string RecibirAtaque(int fila, int columna);
    char ObtenerCelda(int fila, int columna) const;
};

#endif // TABLERO_H

