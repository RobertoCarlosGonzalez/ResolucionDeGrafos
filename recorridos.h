#ifndef RECORRIDOS_H
#define RECORRIDOS_H

#include "grafo.h"
#include <QDialog>




namespace Ui {
class recorridos;
}

class recorridos : public QDialog
{
    Q_OBJECT

public:
    explicit recorridos(QWidget *parent = nullptr);
    ~recorridos();

private:
    Ui::recorridos *ui;

public slots:

};

#endif // RECORRIDOS_H
