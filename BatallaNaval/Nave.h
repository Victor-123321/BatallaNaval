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
    vector<pair<int, int>> posiciones;

public:
    Nave(const string& tipo, int longitud);

    void EstablecerPosiciones(const std::vector<std::pair<int, int>>& coords);
    int getLongitud() const;
    string getTipo() const;
};

#endif 

