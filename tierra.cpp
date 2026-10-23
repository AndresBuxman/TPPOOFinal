#include "tierra.h"

Tierra::Tierra(float energiaInicial)
    : Elemento("Tierra", TipoElemento::TIERRA, energiaInicial)
{
}

void Tierra::atacar(Elemento& objetivo, const TablaDanio& tabla)
{
    ejecutarAtaque(objetivo, tabla);
}

void Tierra::recibirDanio(float danio)
{
    aplicarDanio(danio);
}
