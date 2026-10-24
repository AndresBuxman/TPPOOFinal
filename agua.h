#ifndef AGUA_H
#define AGUA_H

#include "elemento.h"

class Agua : public Elemento
{
public:
    explicit Agua(float energiaInicial = 100.0f);

    void atacar(Elemento& objetivo, const TablaDanio& tabla) override;
    void recibirDanio(float danio) override;
    void guardar(std::ostream& out) const override;
    void cargar(std::istream& in) override;
    std::string getTipoString() const override;
};

#endif // AGUA_H
