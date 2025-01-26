#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Logowanie.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    ui->centralwidget->setEnabled(false);
}

void MainWindow::on_actionPolacz_triggered()
{
    Logowanie *logowanie = new Logowanie(this);

    logowanie->setUsername("admin");  // Możesz pobrać z interfejsu użytkownika
    logowanie->setPassword("password123");

    connect(logowanie, &Logowanie::loginSuccess, [this]() {
        ui->statusbar->showMessage("dobrze");
        _client = new ClientManager();
        _client->connectToServer();
    });

    connect(logowanie, &Logowanie::loginFailed, [this]() {
        ui->statusbar->showMessage("zle");
    });

    if (!logowanie->verifyCredentials()) {
        delete logowanie;
    }

    _client = new ClientManager();
    connect(_client, &ClientManager::connected, [this](){
        ui->centralwidget->setEnabled(true);
    });

    connect(_client, &ClientManager::disconnected, [this](){
        ui->centralwidget->setEnabled(false);
    });

    connect(_client, &ClientManager::dataReceived, this, &MainWindow::dataReceived);


    _client->connectToServer();
}

void MainWindow::dataReceived(QByteArray data)
{
    ui->lstMessages->addItem(data);
}

void MainWindow::on_btnSend_clicked()
{
    auto message = ui->lnMessage->text().trimmed();
    _client->sendMessage(message);
    ui->lstMessages->addItem(message);
    ui->lnMessage->setText("");
}


