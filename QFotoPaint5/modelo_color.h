#ifndef MODELO_COLOR_H
#define MODELO_COLOR_H

#include <QDialog>

namespace Ui {
class Modelo_color;
}

class Modelo_color : public QDialog
{
    Q_OBJECT

public:
    explicit Modelo_color(int numfoto,QWidget *parent = nullptr);
    ~Modelo_color();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_Modelo_color_rejected();

private:
    Ui::Modelo_color *ui;
    int nfoto;
};

#endif // MODELO_COLOR_H
