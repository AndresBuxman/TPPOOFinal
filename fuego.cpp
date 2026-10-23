#include "fuego.h"

Fuego::Fuego(float energiaInicial)
    : Elemento("Fuego", TipoElemento::FUEGO, energiaInicial)
{
}

void Fuego::atacar(Elemento& objetivo, const TablaDanio& tabla)
{
    ejecutarAtaque(objetivo, tabla);
}

void Fuego::recibirDanio(float danio)
{
    aplicarDanio(danio);
}
