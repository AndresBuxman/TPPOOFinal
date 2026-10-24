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

//Para guardar el estado
void Fuego::guardar(std::ostream& out)const
{
    out<<getTipoString() <<' '<<energia<<'\n';
}

//Para cargar el estado
void Fuego::cargar(std::istream& in)
{
    in>>energia;
}

//Para el tipo
std::string Fuego::getTipoString()const
{
    return "FUEGO";
}
