// nivelespersecucion.cpp
#include "nivelespersecucion.h"

NivelesPersecucion::NivelesPersecucion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NivelesPersecucion),
    morty(new Morty()),
    enemigos(new Enemigos()),
    myScene(new QGraphicsScene),
    x(0),
    y(0),
    ancho(0),
    alto(0)
{
    ui->setupUi(this);

    //dimensiones de la pantalla
    QRect desktop = QGuiApplication::primaryScreen()->geometry();
    x = desktop.x();
    y = desktop.y();
    ancho = desktop.width() - 100;
    alto = desktop.height() - 100;

    //escena gráfica con las dimensiones obtenidas
    myScene->setSceneRect(0, 0, ancho, alto);
    ui->graphicsView->setScene(myScene);

    myScene->addItem(morty);
    morty->setPos(200, 700);

    // QVBoxLayout para organizar los widgets dentro del QDialog
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(ui->graphicsView);  // Agrega el QGraphicsView al layout
    setLayout(layout);

    QTimer *enemigoTimer = new QTimer(this);

    enemigoTimer->start(500);
    connect(enemigoTimer, &QTimer::timeout, this, &NivelesPersecucion::agregarEnemigo);
}


void NivelesPersecucion::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        //posición actual de 'morty'
        QPointF mortyPos = morty->pos();

        // Crea el ProyectilParabolico en la posición de 'morty'
        ProyectilParabolico *disparo = new ProyectilParabolico;

        // Establece la posición inicial
        disparo->setPos(mortyPos);

        // Agrega el ProyectilParabolico a la escena
        myScene->addItem(disparo);

        // Inicia el movimiento parabólico
        disparo->movimientoParabolico();
    }
}

void NivelesPersecucion::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A && morty->x() > 0)
    {
        morty->cambiarDirrecion(100);  // Mover a la derecha
    }

    if (event->key() == Qt::Key_D && morty->y() > 0)
    {
        morty->cambiarDirrecion(200);  // Mover hacia arriba
    }
}

NivelesPersecucion::~NivelesPersecucion()
{
    delete morty;
    delete myScene;
    delete ui;
}

void NivelesPersecucion::agregarEnemigo()
{
        Enemigos *enemigo = new Enemigos();
        myScene->addItem(enemigo);

        // Posiciona el enemigo en una ubicación inicial

        enemigo->setPos(rand() % static_cast<int>(ancho), 0); // Posición aleatoria en la parte superior


}
