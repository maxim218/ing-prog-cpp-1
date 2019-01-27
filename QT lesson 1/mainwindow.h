#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_b2_clicked();

    void on_b1_clicked();

    void on_b3_clicked();

    void on_b5_clicked();

public slots:
    void my_slot();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
