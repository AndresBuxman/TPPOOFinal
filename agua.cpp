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
//Para guardar el estado
void Agua::guardar(std::ostream& out)const
{
    out<<getTipoString() <<' '<<energia<<'\n';
}

//Para cargar el estado
void Agua::cargar(std::istream& in)
{
    in>>energia;
}

//Para el tipo
std::string Agua::getTipoString()const
{
    return "AGUA";
}
