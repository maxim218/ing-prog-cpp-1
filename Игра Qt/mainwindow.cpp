#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsView>

QGraphicsScene * my_s;

class DrawManager {
public:
    void clearFon() {
        my_s->clear();
        QPen pen(Qt::red);
        pen.setWidth(600);
        my_s->addLine(0, 0, 300, 300, pen);
    }

    void drawRect(int xx, int yy, int color) {
        int size = 30;
        QPen pen(Qt::white);
        pen.setWidth(2);
        if(color == 2) {
            pen.setColor(Qt::yellow);
        }
        if(color == 3) {
            pen.setColor(Qt::blue);
        }
        my_s->addRect(xx, yy, size, size, pen);
    }
};

int heroX;
int heroY;

DrawManager drawManager;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Игра 2D");

    my_s = new QGraphicsScene;
    ui->graphicsView->setScene(my_s);
    my_s->setSceneRect(0, 0, 300, 300);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    drawManager.clearFon();

    heroX = 150;
    heroY = 80;

    drawManager.drawRect(heroX, heroY, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
