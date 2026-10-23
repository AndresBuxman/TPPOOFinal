#ifndef INICIO_H
#define INICIO_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class inicio;
}

class inicio : public QWidget
{
    Q_OBJECT

public:
    explicit inicio(QWidget *parent = nullptr);
    ~inicio();

private slots:
    void on_btnIniciar_clicked();
private:
    Ui::inicio *ui;

    MainWindow *ventanaJuego;
};

#endif // INICIO_H
