#include "iajugador.h"

IAJugador::IAJugador(const std::string& nombre, IA* modo) : Jugador(nombre), modo(modo) {}

IAJugador::~IAJugador() {
    delete modo;
}

Elemento* IAJugador::seleccionarElementoIA(const Elemento* oponenteActivo, const TablaDanio& tabla) {
    std::vector<Elemento*> vivos = getElementosVivos();
    return modo->seleccionarIA(vivos, oponenteActivo, tabla);
}

Elemento* IAJugador::seleccionarElemento() {
    std::vector<Elemento*> vivos = getElementosVivos();
    return vivos.empty() ? nullptr : vivos.front();
}
