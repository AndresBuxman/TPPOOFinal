#include "iaaleatoria.h"
#include <cstdlib>

Elemento* IAAleatoria::seleccionarIA(const std::vector<Elemento*>& propios,const Elemento*,const TablaDanio&) {
    if (propios.empty()) return nullptr;
    size_t indice = static_cast<size_t>(std::rand()) % propios.size();
    return propios[indice];
}
