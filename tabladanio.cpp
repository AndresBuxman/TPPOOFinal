#include "tabladanio.h"
#include "elemento.h"
#include "tipoelemento.h"

void TablaDanio::configurarDanio(TipoElemento atacante, TipoElemento defensor, float porcentajeDanio) {
    tabla[Par(atacante, defensor)] = porcentajeDanio;
}

float TablaDanio::getDanio(TipoElemento atacante, TipoElemento defensor) const {
    Par clave(atacante, defensor);
    auto it = tabla.find(clave);
    return (it != tabla.end()) ? it->second : 0.0f;
}

float TablaDanio::getDanio(const Elemento& atacante, const Elemento& defensor) const {
    return getDanio(atacante.getTipoAtaque(), defensor.getTipoDefensa());
}

bool TablaDanio::tieneRegla(TipoElemento atacante, TipoElemento defensor) const {
    return tabla.find(Par(atacante, defensor)) != tabla.end();
}

bool TablaDanio::esMayor(float ventajaA, float ventajaB) const {
    return ventajaA > ventajaB;
}
