#ifndef INGRESAR_H
#define INGRESAR_H
#define MAX 20

#include <QDialog>
#include "grafo.h"

/*-----------------------------------------------------------------------
 * -----------------------------------------------------------------------
 * ---------------------------------------------------------------------
 * ------------------------REVISAR EL CODIGO-----------------------------
 * -----------------------------------------------------------------------
 * TENGO LA SOSPECHA QUE DEBERIA AGREGAR LA CLASE EN CADA UNO DE LOS ARCHIVOS
 * .H PARA QUE FUNCIONE; DADO QUE SERA MAS COMPLICADO ACCEDER A ELLOS MEDIANTE
 * ARCHIVOS APARTE Y EL TIEMPO ESTA CORRIENDO T-9---------------------------
 * ------------------------------------------------------------------------
 * -----------------------------------------------------------------------*/
#include <QMultiMap>

namespace Ui {
class Ingresar;
}

class Ingresar : public QDialog
{
    Q_OBJECT


public:
    explicit Ingresar(QWidget *parent = nullptr);

    ~Ingresar();
public slots:

  //  void Introducir_matriz();


private slots:

    void on_Aristas_Submit_clicked();



    void on_Ingresar_Vertices_submit_clicked();

    void on_Registrar_camino_submit_clicked();

    void on_kruskal_pushButton_clicked();

    void on_prim_pushButton_clicked();

private:
    Ui::Ingresar *ui;

    GrafoND<int> Grafito;



};

#endif // INGRESAR_H
