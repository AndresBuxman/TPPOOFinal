#ifndef PAR_H
#define PAR_H

#include "tipoelemento.h"

// Par:clave(tipo atacante, tipo defensor)usada por TablaDanio.
class Par {
private:
    TipoElemento atacante;
    TipoElemento defensor;

public:
    Par(TipoElemento atacante, TipoElemento defensor);

    TipoElemento getAtacante() const;
    TipoElemento getDefensor() const;

    bool operator<(const Par& otro) const;
    bool operator==(const Par& otro) const;
};

#endif // PAR_H
