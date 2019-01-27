#include "mainwindow.h"
#include "ui_mainwindow.h"

int clickCount;

int timeCount;

QTimer * p;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Первый урок");

    clickCount = 0;
    timeCount = 0;

    p = new QTimer(this);
    connect(p, SIGNAL(timeout()), SLOT(my_slot()));
    p->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b2_clicked()
{
    close();
}

void MainWindow::on_b1_clicked()
{
    QString s1 = "";
    QString s2 = "";
    s1 = ui->e1->text();
    s2 = ui->e2->text();
    float a = 0.0;
    float b = 0.0;
    a = s1.toFloat();
    b = s2.toFloat();
    float summa = a + b;
    QString s = "";
    s.setNum(summa);
    ui->e3->setText(s);
}

void MainWindow::on_b3_clicked()
{
    clickCount++;
    QString s = "";
    s.setNum(clickCount);
    ui->e4->setText(s);
}

void MainWindow::my_slot()
{
    timeCount++;
    QString s = "";
    s.setNum(timeCount);
    ui->e11->setText(s);
}

void MainWindow::on_b5_clicked()
{
    p->stop();
    ui->b5->setEnabled(false);
}










