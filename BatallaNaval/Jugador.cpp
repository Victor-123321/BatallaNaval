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
    naves.push_back(Nave("Canoa", 2));

    for (auto& nave : naves) {
        int fila, columna;
        char orientacion;

        do {
            cout << "Colocando " << nave.getTipo() << " (longitud " << nave.getLongitud() << ")." << endl;
            cout << "Ingresa fila, columna y orientacion (H/V)\n ej: 2 3 V (fila 2, columna 3, vertical)\n:  ";
            cin >> fila >> columna >> orientacion;
        } while (!tablero.PonerNave(nave, fila, columna, orientacion));

        cout << "Barco colocado." << endl;
        cout << endl;
        tablero.MostrarTablero();
        cout << endl;
    }
}

string Jugador::Atacar(int fila, int columna, Jugador& atacante) {


    string resultado = tablero.RecibirAtaque(fila, columna);
    if (resultado == "impacto" || resultado == "hundido") {


        atacante.tableroRival.PonerEnCelda(fila, columna, 'X');
        return resultado;
    }
    atacante.tableroRival.PonerEnCelda(fila, columna, 'M');
        return resultado;
}

Tablero Jugador::getTablero(){
    return tablero;
}

Tablero Jugador::getTableroDisparos(){
    return tableroRival;
}

string Jugador::getNombre() const {
    return nombre;
}

