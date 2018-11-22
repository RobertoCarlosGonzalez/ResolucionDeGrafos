#ifndef V_SOLUCION_H
#define V_SOLUCION_H

#include <QWidget>

namespace Ui {
class v_solucion;
}

class v_solucion : public QWidget
{
    Q_OBJECT

public:
    explicit v_solucion(QWidget *parent = nullptr);
    ~v_solucion();

private:
    Ui::v_solucion *ui;
};

#endif // V_SOLUCION_H
