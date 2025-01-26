#include "mainpage.h"
#include "ClientChatWidget.h"
#include "ui_mainpage.h"

MainPage::MainPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPage)
{
    ui->setupUi(this);
    setupServer();
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::newClientConnected(QTcpSocket *client)
{
    auto id = client->property("id").toInt();
    ui->lstClients->addItem(QString("New client added: %1").arg(id));
    auto chatWidget = new ClientChatWidget(client);
    ui->tbChats->addTab(chatWidget, QString("Client(%1").arg(id));

}

void MainPage::clientDisconnected(QTcpSocket *client)
{
    auto id = client->property("id").toInt();
    ui->lstClients->addItem(QString("Client disconnected: %1").arg(id));
}

void MainPage::setupServer()
    {
        _server = new ServerManager();
        connect(_server, &ServerManager::newClientConnected, this, &MainPage::newClientConnected);
        connect(_server, &ServerManager::clientDisconnected, this, &MainPage::clientDisconnected);
    }
