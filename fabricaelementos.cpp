#include "fabricaelementos.h"

#include <cstdlib>

#include "agua.h"
#include "tierra.h"
#include "fuego.h"
#include "elementomixto.h"

Elemento* FabricaElementos::crearElementoAleatorio()
{
    int tipo = rand() % 4;

    switch(tipo)
    {
    case 0:
        return new Agua();

    case 1:
        return new Tierra();

    case 2:
        return new Fuego();

    default:
        return new ElementoMixto(
            "Barro",
            new Agua(),
            new Tierra()
            );
    }
}
