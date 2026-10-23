#include "partida.h"
#include <iostream>

Partida::Partida(Jugador *jugador, IAJugador *iaJugador)
    : jugador(jugador),
    iaJugador(iaJugador),
    elementoActivoJugador(nullptr),
    elementoActivoIA(nullptr)
{
}

void Partida::iniciar()
{
    tablaDanio.configurarDanio(TipoElemento::AGUA, TipoElemento::FUEGO, 50.0f);
    tablaDanio.configurarDanio(TipoElemento::FUEGO, TipoElemento::AGUA, 20.0f);
    tablaDanio.configurarDanio(TipoElemento::TIERRA, TipoElemento::FUEGO, 20.0f);
    tablaDanio.configurarDanio(TipoElemento::FUEGO, TipoElemento::TIERRA, 40.0f);
    tablaDanio.configurarDanio(TipoElemento::AGUA, TipoElemento::TIERRA, 30.0f);
    tablaDanio.configurarDanio(TipoElemento::TIERRA, TipoElemento::AGUA, 20.0f);

    tablaDanio.configurarDanio(TipoElemento::AGUA, TipoElemento::AGUA, 15.0f);
    tablaDanio.configurarDanio(TipoElemento::TIERRA, TipoElemento::TIERRA, 15.0f);
    tablaDanio.configurarDanio(TipoElemento::FUEGO, TipoElemento::FUEGO, 15.0f);

    elementoActivoJugador = nullptr;
    elementoActivoIA = nullptr;
}

void Partida::aplicarCombate(Elemento &e1, Elemento &e2)
{
    e1.atacar(e2, tablaDanio);
    e2.atacar(e1, tablaDanio);
}

void Partida::ejecutarRonda()
{
    if(elementoActivoJugador == nullptr)
        return;

    if(!elementoActivoJugador->estaVivo())
    {
        jugador->avanzarAlSiguienteVivo();
        elementoActivoJugador = jugador->getElementoActivo();
    }

    if(elementoActivoJugador == nullptr)
        return;

    elementoActivoIA =
        iaJugador->seleccionarElementoIA(
            elementoActivoJugador,
            tablaDanio
            );

    if(elementoActivoIA == nullptr)
        return;

    std::cout << "\n===== NUEVA RONDA =====\n";

    std::cout << elementoActivoJugador->getNombre()
              << " VS "
              << elementoActivoIA->getNombre()
              << std::endl;

    aplicarCombate(*elementoActivoJugador,
                   *elementoActivoIA);

    std::cout << elementoActivoJugador->getNombre()
              << ": "
              << elementoActivoJugador->getEnergia()
              << "%\n";

    std::cout << elementoActivoIA->getNombre()
              << ": "
              << elementoActivoIA->getEnergia()
              << "%\n";
}

bool Partida::hayGanador() const
{
    return !jugador->tieneElementosVivos()
    || !iaJugador->tieneElementosVivos();
}

Jugador* Partida::getGanador() const
{
    if(!jugador->tieneElementosVivos())
        return iaJugador;

    if(!iaJugador->tieneElementosVivos())
        return jugador;

    return nullptr;
}

Jugador* Partida::getJugador() const
{
    return jugador;
}

IAJugador* Partida::getIA() const
{
    return iaJugador;
}

TablaDanio& Partida::getTablaDanio()
{
    return tablaDanio;
}

void Partida::setElementoActivoJugador(Elemento *elemento)
{
    elementoActivoJugador = elemento;
}

void Partida::setElementoActivoIA(Elemento *elemento)
{
    elementoActivoIA = elemento;
}

Elemento* Partida::getElementoActivoJugador() const
{
    return elementoActivoJugador;
}

Elemento* Partida::getElementoActivoIA() const
{
    return elementoActivoIA;
}
