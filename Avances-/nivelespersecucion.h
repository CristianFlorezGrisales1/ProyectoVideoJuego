#ifndef NIVELESPERSECUCION_H
#define NIVELESPERSECUCION_H

#include <QDialog>

namespace Ui {
class NivelesPersecucion;
}

class NivelesPersecucion : public QDialog
{
    Q_OBJECT

public:
    explicit NivelesPersecucion(QWidget *parent = nullptr);
    ~NivelesPersecucion();

private:
    Ui::NivelesPersecucion *ui;
};

#endif // NIVELESPERSECUCION_H
