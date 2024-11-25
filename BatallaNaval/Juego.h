#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "Referee.h"

using namespace std;

class Juego {
private:
    Jugador jugador1;
    Jugador jugador2;
    Referee referee;

public:
    Juego(const string& nombreJugador1, const string& nombreJugador2);

    void IniciarPartida();
    void JugarTurno();
    void FinalizarPartida();

    Jugador getJugador1() const;
    Jugador getJugador2() const;
};

#endif // JUEGO_H

