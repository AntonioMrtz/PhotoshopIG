#ifndef MATSATLUM_H
#define MATSATLUM_H

#include <QDialog>

namespace Ui {
class Matsatlum;
}

class Matsatlum : public QDialog
{
    Q_OBJECT

public:
    explicit Matsatlum(int nfoto,QWidget *parent = nullptr);
    ~Matsatlum();

private slots:
    void on_dial_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_Matsatlum_accepted();

    void on_Matsatlum_rejected();

private:
    Ui::Matsatlum *ui;
    int nfoto;
    int matiz;
    double saturacion;
    double luminosidad;
};

#endif // MATSATLUM_H
