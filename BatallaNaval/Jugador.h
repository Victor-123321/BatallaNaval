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
    vector<Nave> naves;
    Tablero tableroRival; // Para registrar ataques al enemigo

public:
    Jugador(const string& nombre);

    void PonerNaves();
    string getNombre() const;
    string Atacar(int fila, int columna, Jugador& jugador);
    Tablero getTablero();
    Tablero getTableroDisparos();
};

#endif // JUGADOR_H

