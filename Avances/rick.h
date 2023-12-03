#ifndef RICK_H
#define RICK_H

#include <QObject>
#include <QGraphicsObject>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include "Fisicas.h"



class Rick: public QGraphicsObject, public Fisicas {
    Q_OBJECT

public:
    explicit Rick(QObject *parent = nullptr);
    void cambiarDirrecion(int numero);

    int velocidad=15;
    int dirrecion;
    int masa=10; // Peso=masa por gravedad

signals:

public slots:
    void actualizacion();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;



private:
    QTimer *timer;
    QPixmap pixmap;
    int tecla;
    float filas;
    float columnas;
    float ancho;
    float alto;
};

#endif // RICK_H

