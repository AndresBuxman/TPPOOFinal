#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <vector>

#include "partida.h"
#include "elemento.h"
#include "cartaelemento.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Partida *partida, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAtacar_clicked();
    void seleccionarCarta(CartaElemento *carta);

private:

    Ui::MainWindow *ui;

    Partida *partida;

    QFrame* crearCarta(Elemento* elemento);
    Elemento *elementoSeleccionado;
    void mostrarElementos(Jugador *jugador,QHBoxLayout *layout,bool seleccionable);
    CartaElemento *cartaSeleccionada;
    void actualizarCartas();

    std::vector<CartaElemento*> cartasJugador;
    std::vector<CartaElemento*> cartasIA;
};

#endif // MAINWINDOW_H
