#include "ingresar.h"
#include "ui_ingresar.h"
#include "grafo.h"


Ingresar::Ingresar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ingresar)
{
    ui->setupUi(this);

    ui->Aristas_label->hide();
    ui->Aristas_textEdit->hide();
    ui->Aristas_Submit->hide();
    ui->Ingresar_vertices_label->hide();
    ui->Ingresa_V_LineEdit->hide();
    ui->Ingresar_V_submit->hide();
    ui->VOrigen_label->hide();
    ui->V_origen_textEdit->hide();
    ui->V_destino_EditText->hide();
    ui->V_destino_label->hide();
    ui->Registrar_camino_submit->hide();
    ui->Go_to_solution->hide();

}

Ingresar::~Ingresar()
{
    delete ui;
}


int Ingresar::on_Vertices_Submit_clicked()
{
    QString cantidad = ui->Ingresa_V_LineEdit->text();
    int NUM_V= cantidad.toInt();
    return NUM_V;
}

int Ingresar::on_Aristas_Submit_clicked()
{
    QString cantidad = ui->Aristas_textEdit->text();
    int NUM_A= cantidad.toInt();
    return NUM_A;
}



void Ingresar::on_Ingresar_V_submit_clicked(int Vertices)
{

}

void Ingresar::on_Registrar_camino_submit_clicked()
{
    QString OR = ui->V_origen_textEdit->text();
    int Origen = OR.toInt();
    QString DE = ui->V_destino_EditText->text();
    int Destino = DE.toInt();


}
