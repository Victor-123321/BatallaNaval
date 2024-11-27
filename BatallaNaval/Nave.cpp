#include "Nave.h"

Nave::Nave(const std::string& tipo, int longitud) : tipo(tipo), longitud(longitud) {}

void Nave::EstablecerPosiciones(const std::vector<std::pair<int, int>>& coords) {
    posiciones = coords;
}

int Nave::getLongitud() const {
    return longitud;
}
string Nave::getTipo() const {
    return tipo;
}
