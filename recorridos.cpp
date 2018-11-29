#include "recorridos.h"
#include "ui_recorridos.h"
#include <QMessageBox>

recorridos::recorridos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recorridos)
{
    ui->setupUi(this);

    ui->nivel_txt->hide();
    ui->nivel_submit->hide();












}

recorridos::~recorridos()
{
    delete ui;
}
