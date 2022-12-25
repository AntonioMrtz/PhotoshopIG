#ifndef ROTAR_ESCALAR_H
#define ROTAR_ESCALAR_H

#include <QDialog>

namespace Ui {
class rotar_escalar;
}

class rotar_escalar : public QDialog
{
    Q_OBJECT

public:
    explicit rotar_escalar(int numfoto,QWidget *parent = nullptr);
    ~rotar_escalar();

private slots:
    void on_spinBox_valueChanged(int arg1);
    void actualizar();

    void on_spinBox_2_valueChanged(int arg1);

    void on_buttonBox_accepted();

private:
    Ui::rotar_escalar *ui;
    int nfoto;

};

#endif // ROTAR_ESCALAR_H
