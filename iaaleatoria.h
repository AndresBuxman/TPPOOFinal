#ifndef IAALEATORIA_H
#define IAALEATORIA_H

#include "ia.h"

// Elige un elemento al azar. No tiene en cuenta ventajas y desventajas.
class IAAleatoria : public IA {
public:
    Elemento* seleccionarIA(const std::vector<Elemento*>& propios,const Elemento* oponenteActivo, const TablaDanio& tabla) override;
};

#endif // IAALEATORIA_H
