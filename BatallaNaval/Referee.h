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
    // Valida si una posición y orientación son válidas para colocar una nave en el tablero.
    bool ValidarColocacion(const Nave& nave, int fila, int columna, char orientacion, const Tablero& tablero);

    // Valida si un disparo está dentro del rango del tablero.
    bool ValidarAtaque(int fila, int columna, const Tablero& tablero) const;

    // Verifica si un jugador ha perdido (todas las naves hundidas).
    bool VerificarDerrota(const Jugador& jugador) const;

    // Agregar al registro una acción (opcional para debug o historial).
    void RegistrarAccion(const std::string& accion);
};

#endif // referee_H

