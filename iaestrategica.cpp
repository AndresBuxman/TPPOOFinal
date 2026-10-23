#include "iaestrategica.h"
#include "tabladanio.h"

float IAEstrategica::calcularVentaja(const Elemento& candidato, const Elemento& oponente,
                                     const TablaDanio& tabla) const {
    float infligido = tabla.getDanio(candidato, oponente);
    float recibido = tabla.getDanio(oponente, candidato);
    return infligido - recibido;
}

Elemento* IAEstrategica::mejorPorVentaja(const std::vector<Elemento*>& propios, const Elemento& oponente, const TablaDanio& tabla) const {
    if (propios.empty()) return nullptr;

    Elemento* mejor = propios.front();
    float mejorVentaja = calcularVentaja(*mejor, oponente, tabla);

    for (size_t i = 1; i < propios.size(); ++i) {
        float ventaja = calcularVentaja(*propios[i], oponente, tabla);
        if (tabla.esMayor(ventaja, mejorVentaja)) {
            mejor = propios[i];
            mejorVentaja = ventaja;
        }
    }
    return mejor;
}

Elemento* IAEstrategica::seleccionarIA(const std::vector<Elemento*>& propios,const Elemento* oponenteActivo, const TablaDanio& tabla) {
    if (propios.empty()) return nullptr;
    if (!oponenteActivo) return propios.front();
    return mejorPorVentaja(propios, *oponenteActivo, tabla);
}
