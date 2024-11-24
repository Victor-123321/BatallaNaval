#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include "Tablero.h"
#include "Nave.h"

using namespace std;

class Jugador {
private:
    string nombre;
    Tablero tablero;
    Tablero tableroRival; // Para registrar ataques al enemigo
    vector<Nave> naves;

public:
    Jugador(const string& nombre);

    void PonerNaves();
    string getNombre() const;
    bool Atacar(int fila, int columna);
    Tablero getTablero() const;
};

#endif // JUGADOR_H

