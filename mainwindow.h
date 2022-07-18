#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "binanceclient.h"

#include <QMainWindow>
#include <QThread>
#include <QMutex>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    binanceClient* client;

public slots:
    //...

};

#endif // MAINWINDOW_H
