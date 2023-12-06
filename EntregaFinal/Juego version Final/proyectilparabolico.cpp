// proyectilparabolico.cpp
#include "proyectilparabolico.h"

ProyectilParabolico::ProyectilParabolico(QObject *parent)
{
    setFlag(ItemIsSelectable);



}

QRectF ProyectilParabolico::boundingRect() const
{
    return QRectF(0, 0, 10, 10);
}

void ProyectilParabolico::movimientoParabolico()
{
    QTimer* timer=new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ProyectilParabolico::moverParabolico);
    timer->start(50);
      // Reinicia el tiempo para cada nuevo disparo
}

void ProyectilParabolico::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::darkRed);
    painter->drawEllipse(boundingRect());
}


void ProyectilParabolico::moverParabolico()
{


    // Calcula el desplazamiento horizontal y vertical
    float dx = velocidadInicial * qCos(qDegreesToRadians(70)) * tiempo;
    float dy = velocidadInicial * qSin(qDegreesToRadians(70)) * tiempo - 0.5 * gravedad * (tiempo * tiempo);  // Cambio el signo de la velocidad vertical

    setPos(x()+ dx, y() - dy);

    tiempo+=0.1;
}

