#include "graph.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Graph w;
 /*   w.setMinimumHeight(280);
    w.setMinimumWidth(400);
    w.setMaximumHeight(560);
    w.setMaximumWidth(800);*/
    w.show();

    return a.exec();
}
