#ifndef FUEGO_H
#define FUEGO_H

#include "elemento.h"

class Fuego : public Elemento
{
public:
    explicit Fuego(float energiaInicial = 100.0f);

    void atacar(Elemento& objetivo, const TablaDanio& tabla) override;
    void recibirDanio(float danio) override;
};

#endif // FUEGO_H
