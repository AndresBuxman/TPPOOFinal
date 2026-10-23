#ifndef TABLADANIO_H
#define TABLADANIO_H

#include <map>
#include "par.h"
#include "tipoelemento.h"
class Elemento;

class TablaDanio {
private:
    std::map<Par, float> tabla;

public:
    TablaDanio() = default;

    // Configuracion del daño del atacaquen al defensor.
    void configurarDanio(TipoElemento atacante, TipoElemento defensor, float porcentajeDanio);

    //Devuelve el daño.
    float getDanio(const Elemento& atacante, const Elemento& defensor) const;
    float getDanio(TipoElemento atacante, TipoElemento defensor) const;

    bool tieneRegla(TipoElemento atacante, TipoElemento defensor) const;

    //Comparacion de daño para la IA.
    bool esMayor(float ventajaA, float ventajaB) const;
};

#endif // TABLADANIO_H
