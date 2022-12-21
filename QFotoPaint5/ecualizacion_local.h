#ifndef ECUALIZACION_LOCAL_H
#define ECUALIZACION_LOCAL_H

#include <QDialog>

namespace Ui {
class Ecualizacion_local;
}

class Ecualizacion_local : public QDialog
{
    Q_OBJECT

public:
    explicit Ecualizacion_local(int nfoto,QWidget *parent = nullptr);
    ~Ecualizacion_local();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Ecualizacion_local *ui;
    int nfoto;
};

#endif // ECUALIZACION_LOCAL_H
