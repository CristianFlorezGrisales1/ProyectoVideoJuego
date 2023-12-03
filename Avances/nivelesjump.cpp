#include "nivelesjump.h"
#include "ui_nivelesjump.h"

NivelesJump::NivelesJump(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NivelesJump),
    x(0),
    y(0),
    ancho(0),
    alto(0),
    rick(new Rick())
{
    ui->setupUi(this);
    // Obtén las dimensiones de la pantalla principal
    QRect Desktop = QGuiApplication::primaryScreen()->geometry();
    x = Desktop.x();
    y = Desktop.y();
    ancho = Desktop.width() - 100;
    alto = Desktop.height() - 100;

    // Crea una escena gráfica con las dimensiones obtenidas
    scene = new QGraphicsScene(0, 0, ancho, alto);
    ui->graphicsView->setScene(scene);

    // Añade el sprite del personaje principal a la escena
    scene->addItem(rick);
    rick->setPos(200, 700);  // Corrige la sintaxis aquí
}
// Función llamada cuando se presiona una tecla

void NivelesJump::keyPressEvent(QKeyEvent *event)
{
    // Manejo de las teclas de dirección para mover el personaje hacia un aldi u otro
    if (event->key() == Qt::Key_A )
    {
        rick->cambiarDirrecion(200);
    }


   if (event->key() == Qt::Key_D )
    {
        rick->cambiarDirrecion(100);
    }



}

/*void NivelesJump::AgregarPlataforma()
{
    Plataformas *plataforma = new Plataformas();

    scene->addItem(plataforma);

    plataforma->setPos(rand() % static_cast<int>(ancho), 0); // Posición aleatoria en la parte superior
}
}
*/

NivelesJump::~NivelesJump()
{
    delete ui;
}
