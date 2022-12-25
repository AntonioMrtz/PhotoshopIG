#ifndef AJUSTE_ROJO_VERDE_AZUL_H
#define AJUSTE_ROJO_VERDE_AZUL_H

#include <QDialog>

namespace Ui {
class Ajuste_rojo_verde_azul;
}

class Ajuste_rojo_verde_azul : public QDialog
{
    Q_OBJECT

public:
    explicit Ajuste_rojo_verde_azul(int nfoto,QWidget *parent = nullptr);
    ~Ajuste_rojo_verde_azul();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

    void on_checkBox_stateChanged(int arg1);

    void on_Ajuste_rojo_verde_azul_rejected();

    void on_Ajuste_rojo_verde_azul_accepted();

private:
    Ui::Ajuste_rojo_verde_azul *ui;
    int nfoto;
    double rojo;
    double verde;
    double azul;
    void actualizar();
    int type[3];
};

#endif // AJUSTE_ROJO_VERDE_AZUL_H
