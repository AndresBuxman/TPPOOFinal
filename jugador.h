#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include "elemento.h"

//El jugador es "dueño" de los elementos que posee,el gestiona esa parte de memoria.
class Jugador {
protected:
    std::string nombre;
    std::vector<Elemento*> elementos;
    int indiceActivo; // indice del elemento actualmente en combate,si es -1 es porque no hay ningun elemento activo.

public:
    explicit Jugador(const std::string& nombre);
    virtual ~Jugador();

    //Administracion de memoria.
    Jugador(const Jugador&) = delete;
    Jugador& operator=(const Jugador&) = delete;
    void agregarElemento(Elemento* elemento);

    virtual Elemento* seleccionarElemento();

    bool tieneElementosVivos() const;
    const std::vector<Elemento*>& getElementos() const;
    std::vector<Elemento*> getElementosVivos() const;

    const std::string& getNombre() const;
    Elemento* getElementoActivo() const;
    void avanzarAlSiguienteVivo(); // reemplaza al elemento activo cuando muere.
};

#endif // JUGADOR_H
