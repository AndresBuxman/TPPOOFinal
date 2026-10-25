#include "partida.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "agua.h"
#include "fuego.h"
#include "tierra.h"

Partida::Partida(Jugador *jugador, IAJugador *iaJugador)
    : jugador(jugador),
    iaJugador(iaJugador),
    elementoActivoJugador(nullptr),
    elementoActivoIA(nullptr)
{
}

void Partida::iniciar()
{
    tablaDanio.configurarDanio(TipoElemento::AGUA, TipoElemento::FUEGO, 50.0f);
    tablaDanio.configurarDanio(TipoElemento::FUEGO, TipoElemento::AGUA, 20.0f);
    tablaDanio.configurarDanio(TipoElemento::TIERRA, TipoElemento::FUEGO, 20.0f);
    tablaDanio.configurarDanio(TipoElemento::FUEGO, TipoElemento::TIERRA, 40.0f);
    tablaDanio.configurarDanio(TipoElemento::AGUA, TipoElemento::TIERRA, 30.0f);
    tablaDanio.configurarDanio(TipoElemento::TIERRA, TipoElemento::AGUA, 20.0f);

    tablaDanio.configurarDanio(TipoElemento::AGUA, TipoElemento::AGUA, 15.0f);
    tablaDanio.configurarDanio(TipoElemento::TIERRA, TipoElemento::TIERRA, 15.0f);
    tablaDanio.configurarDanio(TipoElemento::FUEGO, TipoElemento::FUEGO, 15.0f);

    elementoActivoJugador = nullptr;
    elementoActivoIA = nullptr;
}

void Partida::aplicarCombate(Elemento &e1, Elemento &e2)
{
    e1.atacar(e2, tablaDanio);
    e2.atacar(e1, tablaDanio);
}

void Partida::ejecutarRonda()
{
    if(elementoActivoJugador == nullptr)
        return;

    if(!elementoActivoJugador->estaVivo())
    {
        jugador->avanzarAlSiguienteVivo();
        elementoActivoJugador = jugador->getElementoActivo();
    }

    if(elementoActivoJugador == nullptr)
        return;

    elementoActivoIA =
        iaJugador->seleccionarElementoIA(
            elementoActivoJugador,
            tablaDanio
            );

    if(elementoActivoIA == nullptr)
        return;

    std::cout << "\n===== NUEVA RONDA =====\n";

    std::cout << elementoActivoJugador->getNombre()
              << " VS "
              << elementoActivoIA->getNombre()
              << std::endl;

    aplicarCombate(*elementoActivoJugador,
                   *elementoActivoIA);

    std::cout << elementoActivoJugador->getNombre()
              << ": "
              << elementoActivoJugador->getEnergia()
              << "%\n";

    std::cout << elementoActivoIA->getNombre()
              << ": "
              << elementoActivoIA->getEnergia()
              << "%\n";
}

bool Partida::hayGanador() const
{
    return !jugador->tieneElementosVivos()
    || !iaJugador->tieneElementosVivos();
}

Jugador* Partida::getGanador() const
{
    if(!jugador->tieneElementosVivos())
        return iaJugador;

    if(!iaJugador->tieneElementosVivos())
        return jugador;

    return nullptr;
}

Jugador* Partida::getJugador() const
{
    return jugador;
}

IAJugador* Partida::getIA() const
{
    return iaJugador;
}

TablaDanio& Partida::getTablaDanio()
{
    return tablaDanio;
}

void Partida::setElementoActivoJugador(Elemento *elemento)
{
    elementoActivoJugador = elemento;
}

void Partida::setElementoActivoIA(Elemento *elemento)
{
    elementoActivoIA = elemento;
}

Elemento* Partida::getElementoActivoJugador() const
{
    return elementoActivoJugador;
}

Elemento* Partida::getElementoActivoIA() const
{
    return elementoActivoIA;
}

//Para "crearElementoDesdeTipo"
Elemento* Partida::crearElementoDesdeTipo(const std::string& tipo)
{
    if(tipo=="AGUA")
        return new Agua();
    else if (tipo=="FUEGO")
        return new Fuego();
    else if (tipo=="TIERRA")
        return new Tierra();
    return nullptr;
}

//Para guardar partida
void Partida::guardar(const std::string& archivo) const
{
    std::ofstream out(archivo);
    if (!out.is_open())
        return;

    //Para guardar jugador
    out << jugador->cantidadElementos() << '\n';
    for (int i = 0; i < jugador->cantidadElementos(); ++i) {
        jugador->getElemento(i)->guardar(out);
    }
    out << jugador->getIndiceElementoActivo() << '\n';

    //Para guardar IA
    out << iaJugador->cantidadElementos() << '\n';
    for (int i = 0; i < iaJugador->cantidadElementos(); ++i) {
        iaJugador->getElemento(i)->guardar(out);
    }
    out << iaJugador->getIndiceElementoActivo() << '\n';
}

//Para la carga de partida
void Partida::cargar(const std::string& archivo)
{
    std::ifstream in(archivo);
    if (!in.is_open()){
        std::cerr<<"No se pudo abrir el archivo guardado.\n";
        return;
    }
    std::vector<Elemento*> elementosJugador;
    std::vector<Elemento*> elementosIA;
    auto liberar=[](std::vector<Elemento*>& elementos){
        for(Elemento* e:elementos)
            delete e;
        elementos.clear();
    };
    int cantidad = 0;
    int indiceActivo = -1;
    int indiceIA= -1;
    std::string tipo;

    //Para leer elementos del jugador
    if (!(in>>cantidad)||cantidad<0||cantidad>5{
        std::cerr<<"La cantidad de elementos es inválida.\n";
        return;
    }
    for (int i = 0; i < cantidad; ++i) {
        if(!(in >> tipo)){
            liberar(elementosJugador);
            return;
    }
        Elemento* e = crearElementoDesdeTipo(tipo);
        if (e == nullptr){
            liberar(elementosJugador);
            std::cerr<<"El tipo de elemento es desconocido.\n";
            return;
        }
        e->cargar(in);
        if (!in){
            delete e;
            liberar(elementosJugador);
            return;
        }
        elementosJugador.push_back(e);
    }
    if (!(in>>indiceJugador)){
            liberar(elementosJugador);
            return;
    }
    //Para leer los elementos de IA
    if (!(in>>cantidad)||cantidad<0||cantidad>5){
            liberar(elementosJugador);
            return;
    }
    for (int i = 0; i < cantidad; ++i) {
        if(!(in >> tipo)){
            liberar(elementosJugador);
            liberar(elementosIA);
            return;
        }
        Elemento* e = crearElementoDesdeTipo(tipo);
        if (e == nullptr){
            liberar(elementosJugador);
            liberar(elementosIA);
            return;
        }
        e->cargar(in);
        if (!in){
            delete e;
            liberar(elementosJugador);
            liberar(elementosIA);
            return;
        }
        elementosIA.push_back(e);
    }
    if (!(in>>indiceIA)){
            liberar(elementosJugador);
            liberar(elementosIA);
            return;
        }
    //Verficar antes de reemplazar los equipos
    auto indiceValido=[](int indice,const std::vector<Elemento*>& elementos){
        return (indice==-1 || (indice>=0 && indice<static_cast<int>(elementos.size()) && elementos[indice]->estaVivo());
    };
    if(!indiceValido(indiceJugador, elementosJugador) || !indiceValido(indiceIA,elementosIA)){
        liberar(elementosJugador);
        liberar(elementosIA);
        std::cerr<<"El índice Activo es inválido en el archivo.\n";
        return;
    }
    //Para reemplazar equipos si la lectura es correcta
    jugador->limpiarElementos();
    iaJugador->limpiarElementos();
    for (Elemento* e: elementosJugador)
        jugador->agregarElementos(e);
    for (Elemento* e: elementosIA)
        jugador->agregarElementos(e);
    elementosJugador.clear();
    elementosIA.clear();
jugador->setIndiceElementoActivo(indiceJugador);
iaJugador->setIndiceElementoActivo(indiceIA);
elementoActivoJugador=jugador->getElementoActivo();
elementoActivoIA=iaJugador->getElementoActivo();
std::cout<<"La partida se cargó de forma correcta.\n";
}
