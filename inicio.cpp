#include "inicio.h"
#include "ui_inicio.h"

#include "jugador.h"
#include "iajugador.h"
#include "superia.h"
#include "partida.h"
#include "iaaleatoria.h"
#include "iaestrategica.h"
#include "superia.h"

#include "fabricaelementos.h"

#include <cstdlib>
#include <ctime>
#include <QDebug>


inicio::inicio(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::inicio)
{
    ui->setupUi(this);

    setWindowTitle("VENTANA INICIO");
}
inicio::~inicio()
{
    delete ui;
}
void inicio::on_btnIniciar_clicked()
{
    QString nombre = ui->txtNombre->text();


    Jugador *jugador = new Jugador(
        nombre.toStdString()
        );


    for(int i = 0; i < 5; i++)
    {
        jugador->agregarElemento(
            FabricaElementos::crearElementoAleatorio()
            );
    }


    IA *estrategia = nullptr;

    switch(ui->cmbIA->currentIndex())
    {
    case 0:
        estrategia = new IAAleatoria();
        break;

    case 1:
        estrategia = new IAEstrategica();
        break;

    case 2:
    default:
        estrategia = new SuperIA();
        break;
    }

    IAJugador *cpu = new IAJugador(
        "CPU",
        estrategia
        );

    for(int i = 0; i < 5; i++)
    {
        cpu->agregarElemento(
            FabricaElementos::crearElementoAleatorio()
            );
    }


    Partida *partida = new Partida(jugador,cpu);


    ventanaJuego = new MainWindow(partida);

    ventanaJuego->show();

    this->hide();
}
