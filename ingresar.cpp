
#include "ingresar.h"
#include "ui_ingresar.h"
#include "grafo.h"
#include "QMessageBox"
#include "QDebug"

Ingresar::Ingresar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ingresar)
{
    ui->setupUi(this);

/*    ui->Aristas_label->hide();
    ui->Aristas_textEdit->hide();
    ui->Aristas_Submit->hide();
    ui->Ingresar_vertices_label->hide();
    ui->VOrigen_label->hide();
    ui->V_origen_textEdit->hide();
    ui->V_destino_EditText->hide();
    ui->V_destino_label->hide();
    ui->Registrar_camino_submit->hide();
    ui->Go_to_solution->hide();
*/
    ui->anchura_pushButton->hide();
    ui->kruskal_pushButton->hide();
    ui->prim_pushButton->hide();
    ui->profundidad_pushButton->hide();
    ui->Respuesta->hide();

    this->setWindowTitle("INGRESAR");
/*    connect(ui->Aristas_Submit,SIGNAL(clicked()), this, SLOT());
    connect(ui->SubmitButton, SIGNAL(clicked()), this, SLOT(submitContact()));
    connect(ui->CancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    */
}


Ingresar::~Ingresar()
{
    delete ui;
}



void Ingresar::on_Aristas_Submit_clicked()
{
    QString Vertices = ui->Vertices_LineEdit->text();
    int N_vertices =Vertices.toInt();
    QString Aristas = ui->Aristas_textEdit->text();
    int NUM_A= Aristas.toInt();

    Grafito.set_aristas(NUM_A);
    Grafito.set_NumVer(N_vertices);

    qDebug()<<"cantidad de aristas"<<NUM_A;
    qDebug()<<"\nCantidad de vertices"<<N_vertices;


}


void Ingresar::on_Ingresar_Vertices_submit_clicked()
{
    int nombre_vertices,cont,vertices;
    cont = Grafito.get_cont();
    vertices = Grafito.get_NumVer();

    QString nom;
    nom = ui->Ingresa_Vertices_LineEdit->text();
    nombre_vertices = nom.toInt();

    Grafito.set_Vertices(cont, nombre_vertices);

    if(cont==vertices-1)
        ui->Ingresar_Vertices_submit->setDisabled(true);

    qDebug()<<"aristas: " << vertices;
    qDebug()<<"\nnombre vertices: " << nombre_vertices;

    Grafito.set_cont(cont+1);

    ui->Ingresa_Vertices_LineEdit->clear();
    ui->Aristas_textEdit->clear();

}

void Ingresar::on_Registrar_camino_submit_clicked()
{

    QString origen, destino, costo;
    int aristas, cont2, _origen, _destino, _costo;

    aristas = Grafito.get_aristas();
    cont2 = Grafito.get_cont2();

    //Extraccion de los datos
    origen = ui->V_origen_textEdit->text();
    destino = ui->V_destino_EditText->text();
    costo = ui->costo_lineEdit->text();
    //Conversion a entero
    _origen = origen.toInt();
    _destino = destino.toInt();
    _costo = costo.toInt();

    Grafito.set_Matriz_grafo(_origen , _destino , _costo);
    qDebug()<<"Origen"<<_origen;
    qDebug()<<"Destino"<<_destino;
    qDebug()<<"Costo"<<_costo;
    ui->V_origen_textEdit->clear();
    ui->V_destino_EditText->clear();
    ui->costo_lineEdit->clear();

    if(cont2==aristas-1){
        ui->Registrar_camino_submit->setDisabled(true);
        ui->Respuesta->show();
        ui->V_destino_EditText->setReadOnly(true);
        ui->V_origen_textEdit->setReadOnly(true);
        ui->costo_lineEdit->setReadOnly(true);

//      Grafito.Prim();

//      Obtencion de datos para impresion de Prim
//      QString Prim = Grafito.get_Imprime_Prim();
//      ui->Respuesta->setPlainText(Prim);
        ui->Respuesta->setReadOnly(true);
        ui->kruskal_pushButton->show();
        ui->prim_pushButton->show();
        ui->anchura_pushButton->show();
        ui->profundidad_pushButton->show();
    }
    Grafito.set_cont2(cont2+1);

}

void Ingresar::on_kruskal_pushButton_clicked()
{
    Grafito.Kruskal();
    QString kruskal = Grafito.get_Imprime_kruskal();
    ui->Respuesta->clear();
    ui->Respuesta->show();
    ui->Respuesta->setPlainText(kruskal);
    ui->Respuesta->setReadOnly(true);
}



void Ingresar::on_prim_pushButton_clicked()
{
    Grafito.Prim();
//   Obtencion de datos para impresion de Prim
    QString Prim = Grafito.get_Imprime_Prim();
    ui->Respuesta->clear();
    ui->Respuesta->setPlainText(Prim);
    ui->Respuesta->setReadOnly(true);
}
