#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>

QGraphicsScene * my_s;

class SceneController {
public:
    void clearFon() {
        my_s->clear();
        QPen pen(Qt::blue);
        pen.setWidth(1000);
        my_s->addLine(0, 0, 300, 300, pen);
    }

    void drawHero(int xx, int yy) {
        int size = 50;
        QPen pen(Qt::green);
        pen.setWidth(2);
        my_s->addLine(xx, yy, xx + size, yy, pen);
        my_s->addLine(xx + size, yy, xx + size, yy + size, pen);
        my_s->addLine(xx + size, yy + size, xx, yy + size, pen);
        my_s->addLine(xx, yy + size, xx, yy, pen);
    }
};

SceneController sceneController;
int heroX;
int heroY;
QTimer * p;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Рисование");

    my_s = new QGraphicsScene;
    ui->graphicsView->setScene(my_s);
    my_s->setSceneRect(0, 0, 300, 300);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    heroX = 70;
    heroY = 140;

    sceneController.clearFon();
    sceneController.drawHero(heroX, heroY);

    p = new QTimer(this);
    connect(p, SIGNAL(timeout()), SLOT(my_slot()));
    p->start(50);
}

int speed = 4;

bool pause = false;

void MainWindow::my_slot() {
    if(pause == false) {
        heroX += speed;
        sceneController.clearFon();
        sceneController.drawHero(heroX, heroY);

        if(heroX + 50 + speed >= 300) {
            speed = speed * (-1);
        }

        if(heroX + speed <= 0) {
            speed = speed * (-1);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    pause = !pause;
    if(pause == true) ui->pushButton->setText("Play");
    if(pause == false) ui->pushButton->setText("Stop");
}



