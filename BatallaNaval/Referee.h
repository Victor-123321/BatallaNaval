#ifndef referee_H
#define referee_H

#include "Tablero.h"
#include "Jugador.h"

using namespace std;

class Referee {
private:
    vector<string>logs;
public:
    Referee();

    bool ValidarColocacion(const Nave& nave, int fila, int columna, char orientacion, const Tablero& tablero);

    bool ValidarAtaque(int fila, int columna, const Tablero& tablero) const;

    bool VerificarDerrota(Jugador& jugador) ;

};

#endif  

