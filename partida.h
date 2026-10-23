#ifndef PARTIDA_H
#define PARTIDA_H

#include "jugador.h"
#include "iajugador.h"
#include "tabladanio.h"

class Partida
{
private:
    Jugador* jugador;
    IAJugador* iaJugador;
    TablaDanio tablaDanio;

    Elemento* elementoActivoJugador;
    Elemento* elementoActivoIA;

public:
    Partida(Jugador* jugador, IAJugador* iaJugador);
    ~Partida() = default;

    void iniciar();
    void ejecutarRonda();
    void aplicarCombate(Elemento& e1, Elemento& e2);

    bool hayGanador() const;
    Jugador* getGanador() const;

    TablaDanio& getTablaDanio();

    Jugador* getJugador() const;
    IAJugador* getIA() const;

    // Elementos activos
    void setElementoActivoJugador(Elemento *elemento);
    void setElementoActivoIA(Elemento *elemento);

    Elemento* getElementoActivoJugador() const;
    Elemento* getElementoActivoIA() const;
};

#endif // PARTIDA_H
