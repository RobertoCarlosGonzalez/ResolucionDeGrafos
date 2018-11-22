#include "respuesta.h"
#include "ui_respuesta.h"
#include "grafo.h"
#include "recorridos.h"

respuesta::respuesta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::respuesta)
{
    ui->setupUi(this);
    ui->textEdit->hide();
    ui->label->hide();

}

respuesta::~respuesta()
{
    delete ui;
}


void respuesta::on_recorrerButton_clicked()
{
        recorridos AN;
        AN.exec();
}
