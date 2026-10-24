#include "jugador.h"
#include <iostream>

Jugador::Jugador(const std::string& nombre) : nombre(nombre), indiceActivo(-1) {}

Jugador::~Jugador() {
    for (Elemento* e : elementos) {
        delete e;
    }
}

void Jugador::agregarElemento(Elemento* elemento) {
    elementos.push_back(elemento);
    if (indiceActivo == -1 && elemento->estaVivo()) {
        indiceActivo = static_cast<int>(elementos.size()) - 1;
    }
}

void Jugador::limpiarElementos()
{
   for(Elemento* e:elementos){
        delete e;
   } 
    elementos.clear();
    indiceActivo=-1;
}

bool Jugador::tieneElementosVivos() const {
    for (const Elemento* e : elementos) {
        if (e->estaVivo()) return true;
    }
    return false;
}
const std::vector<Elemento*>& Jugador::getElementos() const
{
    return elementos;
}
std::vector<Elemento*> Jugador::getElementosVivos() const {
    std::vector<Elemento*> vivos;
    for (Elemento* e : elementos) {
        if (e->estaVivo()) vivos.push_back(e);
    }
    return vivos;
}
//Para la cantidad de elementos
int Jugador::cantidadElementos()const
{
    return static_cast<int>(elementos.size());
}
//Para getElemento
Elemento* Jugador::getElemento(int indice) const
{
    if(indice<0||indice>=static_cast<int>(elementos.size()))
        return NULL;
    return elementos[indice];   
}

Elemento* Jugador::seleccionarElemento()
{
    return getElementoActivo();
}

const std::string& Jugador::getNombre() const { return nombre; }

Elemento* Jugador::getElementoActivo() const {
    if (indiceActivo < 0 || indiceActivo >= static_cast<int>(elementos.size())) return nullptr;
    return elementos[indiceActivo];
}

//Para el indice del elementoActivo
int Jugador::getIndiceElementoActivo(int indice)
{
    if (indice<-1||indice>=static_cast<int>(elementos.size())){
        indiceActivo=-1;
        return;
    }
    indiceActivo=indice;
}

void Jugador::avanzarAlSiguienteVivo() {
    for (size_t i = 0; i < elementos.size(); ++i) {
        if (elementos[i]->estaVivo()) {
            indiceActivo = static_cast<int>(i);
            return;
        }
    }
    indiceActivo = -1;
}
