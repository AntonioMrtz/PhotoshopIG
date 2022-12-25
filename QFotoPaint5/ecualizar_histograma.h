#ifndef ECUALIZAR_HISTOGRAMA_H
#define ECUALIZAR_HISTOGRAMA_H

#include <QDialog>

namespace Ui {
class Ecualizar_histograma;
}

class Ecualizar_histograma : public QDialog
{
    Q_OBJECT

public:
    explicit Ecualizar_histograma(int nfoto,int primerlibre,QWidget *parent = nullptr);
    ~Ecualizar_histograma();

private slots:
    void on_Ecualizar_histograma_accepted();

private:
    Ui::Ecualizar_histograma *ui;
    int nfoto;
    int primerlibre;
};

#endif // ECUALIZAR_HISTOGRAMA_H
