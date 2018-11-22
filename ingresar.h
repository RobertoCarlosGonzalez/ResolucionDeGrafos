#ifndef INGRESAR_H
#define INGRESAR_H

#include <QDialog>

namespace Ui {
class Ingresar;
}

class Ingresar : public QDialog
{
    Q_OBJECT

public:
    explicit Ingresar(QWidget *parent = nullptr);
    ~Ingresar();

private slots:
    int on_Vertices_Submit_clicked();

    int on_Aristas_Submit_clicked();

    void on_Ingresar_V_submit_clicked(int);

    void on_Registrar_camino_submit_clicked();

private:
    Ui::Ingresar *ui;
};

#endif // INGRESAR_H
