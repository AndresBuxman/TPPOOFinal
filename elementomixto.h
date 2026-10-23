#ifndef ELEMENTOMIXTO_H
#define ELEMENTOMIXTO_H

#include "elemento.h"

//ElementoMixto es dueño de sus dos punteros y los libera
//en su destructor. No se permite copiar la clase.
class ElementoMixto : public Elemento {
private:
    Elemento* elementoAtacante; // define el tipo usado al atacar.
    Elemento* elementoDefensor; // define el tipo usado al defender.

public:
    ElementoMixto(const std::string& nombre, Elemento* atacante, Elemento* defensor,
                  float energiaInicial = 100.0f);
    ~ElementoMixto() override;

    ElementoMixto(const ElementoMixto&) = delete;
    ElementoMixto& operator=(const ElementoMixto&) = delete;

    void atacar(Elemento& objetivo, const TablaDanio& tabla) override;
    void recibirDanio(float danio) override;

    TipoElemento getTipoAtaque() const override;
    TipoElemento getTipoDefensa() const override;
};

#endif // ELEMENTOMIXTO_H
