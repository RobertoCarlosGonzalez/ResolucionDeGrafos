#include "graph.h"
#include "ui_graph.h"
#include "respuesta.h"
#include "ingresar.h"

Graph::Graph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);
    this->setWindowTitle("SISTEMA DE SOLUCION DE GRAFOS");
}

Graph::~Graph()
{
    delete ui;
}

void Graph::on_introducir_clicked()
{
    Ingresar In;
    In.setModal(true);
    In.exec();
}

void Graph::on_Resolver_2_clicked()
{
    respuesta Respuesta;
    Respuesta.setModal(true);
    Respuesta.exec();
}
