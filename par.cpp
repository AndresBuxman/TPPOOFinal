#include "par.h"
#include "tipoelemento.h"

Par::Par(TipoElemento atacante, TipoElemento defensor)
    : atacante(atacante), defensor(defensor) {}

TipoElemento Par::getAtacante() const { return atacante; }
TipoElemento Par::getDefensor() const { return defensor; }

bool Par::operator<(const Par& otro) const {
    if (atacante != otro.atacante) {
        return static_cast<int>(atacante) < static_cast<int>(otro.atacante);
    }
    return static_cast<int>(defensor) < static_cast<int>(otro.defensor);
}

bool Par::operator==(const Par& otro) const {
    return atacante == otro.atacante && defensor == otro.defensor;
}
