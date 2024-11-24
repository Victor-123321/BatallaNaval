#include "Nave.h"

Nave::Nave(const std::string& tipo, int longitud) : tipo(tipo), longitud(longitud) {}

void Nave::EstablecerPosiciones(const std::vector<std::pair<int, int>>& coords) {
    posiciones = coords;
    impactos.resize(coords.size(), false);
}

bool Nave::Impacto(int fila, int columna) {
    for (size_t i = 0; i < posiciones.size(); i++) {
        if (posiciones[i].first == fila && posiciones[i].second == columna) {
            impactos[i] = true;
            return true;
        }
    }
    return false;
}

int Nave::getLongitud() const {
    return longitud;
}
string Nave::getTipo() const {
    return tipo;
}

bool Nave::EstaHundido() const {
    for (bool impacto : impactos) {
        if (!impacto) return false;
    }
    return true;
}

