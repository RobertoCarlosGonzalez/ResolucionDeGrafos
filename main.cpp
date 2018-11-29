#include "graph.h"
#include "grafo.h"
#include "ingresar.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Graph w;
    GrafoND<int> Grafito;

    w.show();

    return a.exec();
}
