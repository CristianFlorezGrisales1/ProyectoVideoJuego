#include "nivelespersecucion.h"
#include "ui_nivelespersecucion.h"

NivelesPersecucion::NivelesPersecucion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NivelesPersecucion)
{
    ui->setupUi(this);
}

NivelesPersecucion::~NivelesPersecucion()
{
    delete ui;
}
