#ifndef COLOR_FALSO_H
#define COLOR_FALSO_H

#include <QDialog>

namespace Ui {
class Color_falso;
}

class Color_falso : public QDialog
{
    Q_OBJECT

public:
    explicit Color_falso(int nfoto,QWidget *parent = nullptr);
    ~Color_falso();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

private:
    Ui::Color_falso *ui;
    int nfoto;
};

#endif // COLOR_FALSO_H
