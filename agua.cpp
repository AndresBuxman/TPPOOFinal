#include "agua.h"

Agua::Agua(float energiaInicial)
    : Elemento("Agua", TipoElemento::AGUA, energiaInicial)
{
}

void Agua::atacar(Elemento& objetivo, const TablaDanio& tabla)
{
    ejecutarAtaque(objetivo, tabla);
}

void Agua::recibirDanio(float danio)
{
    aplicarDanio(danio);
}
