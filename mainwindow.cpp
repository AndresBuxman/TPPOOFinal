#include "mainwindow.h"
#include "elemento.h"
#include <QFrame>
#include "ui_mainwindow.h"
#include <QLabel>
#include <QMessageBox>
#include <QDebug>


MainWindow::MainWindow(Partida *partida, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    partida(partida),
    elementoSeleccionado(nullptr),
    cartaSeleccionada(nullptr)
{
    ui->setupUi(this);;

    ui->layoutJugador->setSpacing(20);
    ui->layoutIA->setSpacing(20);

    setWindowTitle("Partida de cartas");

    partida->iniciar();


    mostrarElementos(
        partida->getJugador(),
        ui->layoutJugador,
        true
    );


    mostrarElementos(
        partida->getIA(),
        ui->layoutIA,
        false
        );
}

MainWindow::~MainWindow()
{
    delete ui;
}

QFrame* MainWindow::crearCarta(Elemento *elemento)
{
    return new CartaElemento(elemento);
}
void MainWindow::mostrarElementos(Jugador *jugador,
                                  QHBoxLayout *layout,
                                  bool seleccionable)
{
    layout->setSpacing(15);

    for (Elemento *elemento : jugador->getElementos())
    {
        CartaElemento *carta =
            static_cast<CartaElemento*>(crearCarta(elemento));

        if(seleccionable)
        {
            connect(carta,
                    &CartaElemento::cartaSeleccionada,
                    this,
                    &MainWindow::seleccionarCarta);

            cartasJugador.push_back(carta);
        }
        else
        {
            cartasIA.push_back(carta);
        }

        layout->addWidget(carta);
    }

    layout->addStretch();
}
void MainWindow::actualizarCartas()
{
    // Cartas del jugador
    for (CartaElemento *carta : cartasJugador)
    {
        carta->actualizar();

        if (!carta->getElemento()->estaVivo())
        {
            carta->hide();

            // Si era la carta seleccionada, quitar la selección
            if (carta == cartaSeleccionada)
            {
                cartaSeleccionada = nullptr;
                elementoSeleccionado = nullptr;
            }
        }
        else
        {
            carta->show();
        }
    }

    // Cartas de la IA
    for (CartaElemento *carta : cartasIA)
    {
        carta->actualizar();

        if (!carta->getElemento()->estaVivo())
        {
            carta->hide();
        }
        else
        {
            carta->show();
        }
    }

    // Mostrar la carta activa de la IA
    Elemento *ia = partida->getElementoActivoIA();

    if (ia != nullptr)
    {
        ui->lblCartaIA->setText(
            "IA juega: " +
            QString::fromStdString(ia->getNombre())
            );
    }
    else
    {
        ui->lblCartaIA->setText("IA juega: -");
    }

    // Mostrar la carta seleccionada por el jugador
    if (elementoSeleccionado != nullptr)
    {
        ui->lblCartaJugador->setText(
            "Jugador juega: " +
            QString::fromStdString(elementoSeleccionado->getNombre())
            );
    }
    else
    {
        ui->lblCartaJugador->setText("Jugador juega: -");
    }

    // Si terminó la partida
    if (partida->hayGanador())
    {
        QMessageBox::information(
            this,
            "Fin de la partida",
            QString::fromStdString(
                partida->getGanador()->getNombre()
                ) + " ha ganado la partida."
            );

        ui->btnAtacar->setEnabled(false);
    }
}
void MainWindow::seleccionarCarta(CartaElemento *carta)
{
    // Quitar el borde rojo de la carta anterior
    if (cartaSeleccionada != nullptr)
    {
        cartaSeleccionada->setStyleSheet(
            "border:1px solid black;"
            );
    }

    cartaSeleccionada = carta;
    elementoSeleccionado = carta->getElemento();

    // Marcar la nueva carta
    cartaSeleccionada->setStyleSheet(
        "border:3px solid red;"
        );

    qDebug() << "Seleccionaste:"
             << QString::fromStdString(elementoSeleccionado->getNombre());


}
void MainWindow::on_btnAtacar_clicked()
{
    if(elementoSeleccionado == nullptr)
    {
        QMessageBox::information(
            this,
            "Atención",
            "Seleccione un elemento para atacar."
            );
        return;
    }

    // El jugador usará la carta seleccionada
    partida->setElementoActivoJugador(elementoSeleccionado);

    // Ejecuta el turno completo
    partida->ejecutarRonda();

    // Actualizar la interfaz
    actualizarCartas();

    // Mostrar la carta que eligió la IA
    Elemento *ia = partida->getElementoActivoIA();

    if(ia)
    {
        ui->lblCartaIA->setText(
            QString::fromStdString(ia->getNombre())
            );
    }

    if(partida->hayGanador())
    {
        QMessageBox::information(
            this,
            "Fin del juego",
            QString::fromStdString(
                partida->getGanador()->getNombre()
                ) + " ganó la partida."
            );

        ui->btnAtacar->setEnabled(false);
    }
}
