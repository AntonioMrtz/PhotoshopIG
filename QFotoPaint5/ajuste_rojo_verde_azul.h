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

    void on_spinBox_valueChanged(const QString &arg1);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

private:
    Ui::Ajuste_rojo_verde_azul *ui;
    int nfoto;
    double suma;
    double multiplica;
    void actualizar();
};

#endif // AJUSTE_ROJO_VERDE_AZUL_H
