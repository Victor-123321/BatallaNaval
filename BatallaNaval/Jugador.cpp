#include <iostream>
#include "Jugador.h"
#include "Referee.h"

using namespace std;

Jugador::Jugador(const string& nombre)
    : nombre(nombre), tablero(), tableroRival() {}

Referee referee;

void Jugador::PonerNaves() {
    cout << nombre << ", coloca tus naves." << endl;

    naves.push_back(Nave("Acorazado", 4));
    naves.push_back(Nave("Submarino", 3));
    naves.push_back(Nave("Lancha", 2));

    for (auto& nave : naves) {
        int fila, columna;
        char orientacion;

        do {
            cout << "Colocando " << nave.getTipo() << " (longitud " << nave.getLongitud() << ")." << endl;
            cout << "Ingresa fila, columna y orientación (H/V): ";
            cin >> fila >> columna >> orientacion;
        } while (!tablero.PonerNave(nave, fila, columna, orientacion));

        cout << "Barco colocado." << endl;
    }
}

bool Jugador::Atacar(int fila, int columna) {
    string resultado = tableroRival.RecibirAtaque(fila, columna);
    if (resultado == "impacto" || resultado == "hundido") {
        return true;
    }
    return false;
}

Tablero Jugador::getTablero() const{
    return tablero;
}

string Jugador::getNombre() const {
    return nombre;
}

