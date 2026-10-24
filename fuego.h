#ifndef FUEGO_H
#define FUEGO_H

#include "elemento.h"
#include <ostream>
#include <istream>

class Fuego : public Elemento
{
public:
    explicit Fuego(float energiaInicial = 100.0f);

    void atacar(Elemento& objetivo, const TablaDanio& tabla) override;
    void recibirDanio(float danio) override;
    void guardar(std::ostream& out) const override;
    void cargar(std::istream& in) override;
    std::string getTipoString() const override;
};

#endif // FUEGO_H
