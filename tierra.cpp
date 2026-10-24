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

//Para guardar el estado
void Tierra::guardar(std::ostream& out)const
{
    out<<getTipoString() <<' '<<energia<<'\n';
}

//Para cargar el estado
void Tierra::cargar(std::istream& in)
{
    in>>energia;
}

//Para el tipo
std::string Tierra::getTipoString()const
{
    return "TIERRA";
}
