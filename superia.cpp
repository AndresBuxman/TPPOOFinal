#include "superia.h"

Elemento* SuperIA::seleccionarIA(const std::vector<Elemento*>& propios,
                                 const Elemento* oponenteActivo,
                                 const TablaDanio& tabla) {
    if (propios.empty()) return nullptr;
    if (!oponenteActivo) return propios.front();

    std::vector<Elemento*> rematadores;
    for (Elemento* candidato : propios) {
        float danio = tabla.getDanio(*candidato, *oponenteActivo);
        if (danio >= oponenteActivo->getEnergia()) {
            rematadores.push_back(candidato);
        }
    }

    if (!rematadores.empty()) {
        Elemento* elegido = rematadores.front();
        for (Elemento* candidato : rematadores) {
            if (candidato->getEnergia() < elegido->getEnergia()) {
                elegido = candidato;
            }
        }
        return elegido;
    }

    //Se comporta como IAEstrategic al no poder rematar.
    return mejorPorVentaja(propios, *oponenteActivo, tabla);
}
