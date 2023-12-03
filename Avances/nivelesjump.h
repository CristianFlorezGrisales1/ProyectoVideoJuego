#ifndef NIVELESJUMP_H
#define NIVELESJUMP_H

#include <QDialog>
#include <QGuiApplication>
#include <QGraphicsItem>
#include <QRectF>
#include <QDebug>
#include <QScreen>
#include <QPainter>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "rick.h"
#include "plataformas.h"

namespace Ui {
class NivelesJump;
}

class NivelesJump : public QDialog
{
    Q_OBJECT

public:
    explicit NivelesJump(QWidget *parent = nullptr);

    void keyPressEvent(QKeyEvent *event);

    void AgregarPlataforma();

    ~NivelesJump();

private:
    Ui::NivelesJump *ui;
    QGraphicsScene *scene;
    Rick *rick;
   // Plataformas *plataforma;
    float x, y, ancho, alto;
};

#endif // NIVELESJUMP_H
