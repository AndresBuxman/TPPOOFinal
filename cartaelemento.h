#ifndef CARTAELEMENTO_H
#define CARTAELEMENTO_H

#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>

class Elemento;

class CartaElemento : public QFrame
{
    Q_OBJECT

public:
    explicit CartaElemento(Elemento *elemento, QWidget *parent = nullptr);

    Elemento* getElemento() const;

    void actualizar();

signals:
    void cartaSeleccionada(CartaElemento *carta);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Elemento *elemento;

    QLabel *lblNombre;
    QLabel *lblVida;
};

#endif // CARTAELEMENTO_H
