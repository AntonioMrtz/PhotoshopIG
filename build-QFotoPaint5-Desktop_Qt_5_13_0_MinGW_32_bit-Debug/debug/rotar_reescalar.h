#ifndef ROTAR_REESCALAR_H
#define ROTAR_REESCALAR_H

#include <QDialog>

namespace Ui {
class Rotar_reescalar;
}

class Rotar_reescalar : public QDialog
{
    Q_OBJECT

public:
    explicit Rotar_reescalar(QWidget *parent = nullptr);
    ~Rotar_reescalar();

private:
    Ui::Rotar_reescalar *ui;
};

#endif // ROTAR_REESCALAR_H
