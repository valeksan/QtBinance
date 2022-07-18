#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIcon icon(":/images/binance_logo.png");
    setWindowIcon(icon);

    QString path(QDir::currentPath() + QDir::separator() + "key.ini");
    QSettings settings(path, QSettings::IniFormat);
    QString api_key = settings.value("api_key", "").toString();
    QString secret_key = settings.value("secret_key", "").toString();

    if (api_key.isEmpty()) {
        settings.setValue("api_key", "");
        settings.setValue("secret_key", "");
    }

    client = new binanceClient(api_key.toLocal8Bit(), secret_key.toLocal8Bit());

    client->getAllPrices();
}

MainWindow::~MainWindow()
{
    delete ui;
}
