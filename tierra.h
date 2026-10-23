#ifndef TIERRA_H
#define TIERRA_H

#include "elemento.h"

class Tierra : public Elemento
{
public:
    explicit Tierra(float energiaInicial = 100.0f);

    void atacar(Elemento& objetivo, const TablaDanio& tabla) override;
    void recibirDanio(float danio) override;
};

#endif // TIERRA_H
