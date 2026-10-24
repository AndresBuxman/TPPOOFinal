#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <string>
#include "tipoelemento.h"

class TablaDanio;

class Elemento{
protected:
    std::string nombre;
    float energia;
    TipoElemento tipoelemento;
    //Logica de ataque y daño
    void ejecutarAtaque(Elemento& objetivo, const TablaDanio& tabla);
    void aplicarDanio(float danio);

public:
    Elemento(const std::string& nombre, TipoElemento tipo, float energiaInicial = 100.0f);
    virtual ~Elemento() = default;

    //Polimorfia de los elementos base.
    virtual void atacar(Elemento& objetivo, const TablaDanio& tabla) = 0;
    virtual void recibirDanio(float danio) = 0;
    virtual TipoElemento getTipoAtaque() const;
    virtual TipoElemento getTipoDefensa() const;

    //Para guardar y cargar
    virtual void guardar(std::ostream& out) const=0;
    virtual void cargar(std::istream& in) =0;

    //Para identificar el tipo de un elemento
    virtual std::string getTipoString() const=0;

    //getters y setters.
    const std::string& getNombre() const;
    float getEnergia() const;
    TipoElemento getTipoElemento() const;
    bool estaVivo() const;
};

#endif // ELEMENTO_H
