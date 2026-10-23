#ifndef SUPERIA_H
#define SUPERIA_H

#include "iaestrategica.h"

//Reutiliza la logica de IAEstrategica:antes de maximizar la ventaja, revisa si puede rematar al oponente en este turno.Si hay varios elementos capaces
//de rematar, elige el que tiene menos energia, priorizando­ los elementos mas sanos para turnos futuros. Si nadie puede rematar, se comporta
//como IAEstrategica.
class SuperIA : public IAEstrategica {
public:
    Elemento* seleccionarIA(const std::vector<Elemento*>& propios,const Elemento* oponenteActivo,const TablaDanio& tabla) override;
};

#endif // SUPERIA_H
