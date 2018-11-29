#ifndef RESPUESTA_H
#define RESPUESTA_H

#include <QDialog>
#include "grafo.h"

namespace Ui {
class respuesta;
}

class respuesta : public QDialog
{
    Q_OBJECT

public:
    explicit respuesta(QWidget *parent = nullptr);
    ~respuesta();

private slots:

    void on_recorrerButton_clicked();

private:
    Ui::respuesta *ui;
};

#endif // RESPUESTA_H
