#ifndef NAVE_H
#define NAVE_H

#include <vector>
#include <string>

using namespace std;

class Nave {
private:
    string tipo;
    int longitud;
    char orientacion;
    vector<pair<int, int>> posiciones; // Coordenadas en el tablero
    vector<bool> impactos; // Marcar que partes fueron atacadas

public:
    Nave(const string& tipo, int longitud);

    void EstablecerPosiciones(const std::vector<std::pair<int, int>>& coords);
    int getLongitud() const;
    string getTipo() const;
    bool Impacto(int fila, int columna);
    bool EstaHundido() const;
};

#endif // NAVE_H

