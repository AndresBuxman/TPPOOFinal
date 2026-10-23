#include <QApplication>
#include "inicio.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    inicio w;
    w.show();

    return a.exec();
}
