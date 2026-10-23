#include "elemento.h"
#include "tabladanio.h"
#include <algorithm>

Elemento::Elemento(const std::string& nombre, TipoElemento tipo, float energiaInicial)
    : nombre(nombre), energia(energiaInicial), tipoelemento(tipo) {}

void Elemento::ejecutarAtaque(Elemento& objetivo, const TablaDanio& tabla) {
    float danio = tabla.getDanio(*this, objetivo);
    objetivo.recibirDanio(danio);
}

void Elemento::aplicarDanio(float danio) {
    energia = std::max(0.0f, energia - danio);
}

TipoElemento Elemento::getTipoAtaque() const { return tipoelemento; }
TipoElemento Elemento::getTipoDefensa() const { return tipoelemento; }

const std::string& Elemento::getNombre() const { return nombre; }
float Elemento::getEnergia() const { return energia; }
TipoElemento Elemento::getTipoElemento() const { return tipoelemento; }
bool Elemento::estaVivo() const { return energia > 0.0f; }
