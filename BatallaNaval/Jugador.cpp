#include <iostream>
#include "Jugador.h"
#include "Referee.h"
#include <sstream> // Para usar stringstream


Jugador::Jugador(const string& nombre)
    : nombre(nombre), tablero(), tableroRival() {}

Referee referee;

using namespace std;

void Jugador::PonerNaves() {
    cout << nombre << ", coloca tus naves." << endl;

    naves.push_back(Nave("Acorazado", 4));
    naves.push_back(Nave("Submarino", 3));
    naves.push_back(Nave("Lancha", 2));
    naves.push_back(Nave("Chalupa", 2));

    for (auto& nave : naves) {
        int fila = -1, columna = -1;
        char orientacion = ' ';
        string input;

        do {
            cout << "Colocando " << nave.getTipo() << " (longitud " << nave.getLongitud() << ")." << endl;
            cout << "Ingresa fila, columna y orientacion (H/V)\nEjemplo: 10 10 V (fila 10, columna 10, vertical): ";

            getline(cin, input);

            // Usar stringstream para separar la entrada
            stringstream ss(input);
            if (ss >> fila >> columna >> orientacion && (orientacion == 'H' || orientacion == 'V' || orientacion == 'h' || orientacion == 'v')) {
                orientacion = toupper(orientacion); // Convertir a mayúscula

                // Validar si fila y columna están dentro del rango y si la posición es válida
                if (fila >= 1 && fila <= 10 && columna >= 1 && columna <= 10 ) {
                }
                else {
                    cout << "\n\nCoordenadas inválidas. Asegúrate de ingresar valores entre 1 y 10.\n\n" << endl;
                    fila = -1;
                    columna = -1;
                    orientacion = ' ';
                    continue;
                }
            }
            else {
                cout << "\n\nEntrada inválida. Por favor usa el formato: numero numero letra (ej: 10 10 V).\n\n" << endl;
                fila = -1;
                columna = -1;
                orientacion = ' ';
                continue;
            }

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

