#include "cartaelemento.h"
#include "elemento.h"

#include <QMouseEvent>

CartaElemento::CartaElemento(Elemento *elemento, QWidget *parent)
    : QFrame(parent),
    elemento(elemento)
{
    setFrameShape(QFrame::Box);
    setFixedSize(100,130);

    QVBoxLayout *layout = new QVBoxLayout(this);

    lblNombre = new QLabel(this);
    lblVida = new QLabel(this);

    lblNombre->setAlignment(Qt::AlignCenter);
    lblVida->setAlignment(Qt::AlignCenter);

    layout->addWidget(lblNombre);
    layout->addWidget(lblVida);

    actualizar();
}

Elemento* CartaElemento::getElemento() const
{
    return elemento;
}

void CartaElemento::actualizar()
{
    lblNombre->setText(
        QString::fromStdString(elemento->getNombre())
        );

    lblVida->setText(
        "Vida: " +
        QString::number(elemento->getEnergia()) +
        "%"
        );
}

void CartaElemento::mousePressEvent(QMouseEvent *event)
{
    emit cartaSeleccionada(this);

    QFrame::mousePressEvent(event);
}
