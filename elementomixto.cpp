#include "elementomixto.h"

ElementoMixto::ElementoMixto(const std::string& nombre, Elemento* atacante, Elemento* defensor,
                             float energiaInicial)
    : Elemento(nombre, atacante->getTipoElemento(), energiaInicial),
    elementoAtacante(atacante), elementoDefensor(defensor) {}

ElementoMixto::~ElementoMixto() {
    delete elementoAtacante;
    delete elementoDefensor;
}

void ElementoMixto::atacar(Elemento& objetivo, const TablaDanio& tabla) {
    ejecutarAtaque(objetivo, tabla);
}

void ElementoMixto::recibirDanio(float danio) {
    aplicarDanio(danio);
}

TipoElemento ElementoMixto::getTipoAtaque() const {
    return elementoAtacante->getTipoAtaque();
}

TipoElemento ElementoMixto::getTipoDefensa() const {
    return elementoDefensor->getTipoDefensa();
}
