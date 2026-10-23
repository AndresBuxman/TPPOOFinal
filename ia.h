#ifndef IA_H
#define IA_H

#include <vector>
#include "elemento.h"
#include "tabladanio.h"

// IA es la clase abstracta,de ella nacen los distinton tipos de IA que compiten contra el jugador.
class IA {
public:
    virtual ~IA() = default;

    // Recibe los elementos vivos del jugador y el elemento activo del oponente, y
    // retorna el elemento elegido para combatir.
    virtual Elemento* seleccionarIA(const std::vector<Elemento*>& propios,  const Elemento* oponenteActivo,const TablaDanio& tabla) = 0;
};

#endif // IA_H
