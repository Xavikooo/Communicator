#include "ServerManager.h"
#include "DatabaseManager.h"

ServerManager::ServerManager(ushort port, QObject *parent)
    : QObject{parent}
{
    setupServer(port);
}

void ServerManager::newClientConnectionRecived()
{
    auto client = _server->nextPendingConnection();
    _clients << client;
    auto id = _clients.length();
    client->setProperty("id", id);
    connect(client, &QTcpSocket::disconnected, this, &ServerManager::onClientDisconnected);
    emit newClientConnected(client);
}

void ServerManager::onClientDisconnected()
{
    auto client = qobject_cast<QTcpSocket *>(sender());
    int id = client->property("id").toInt();
    _clients.removeOne(client);
    emit clientDisconnected(client);
}

void ServerManager::setupServer(ushort port)
{
    _server = new QTcpServer(this);
    connect(_server, &QTcpServer::newConnection, this, &ServerManager::newClientConnectionRecived);
    _server->listen(QHostAddress::Any, port);
}

void ServerManager::newClientConnectionRecived()
{
    auto client = _server->nextPendingConnection();
    _clients << client;

    connect(client, &QTcpSocket::readyRead, this, &ServerManager::handleClientData);
    connect(client, &QTcpSocket::disconnected, this, &ServerManager::onClientDisconnected);

    emit newClientConnected(client);
}

void ServerManager::handleClientData()
{
    auto client = qobject_cast<QTcpSocket *>(sender());
    QByteArray data = client->readAll();
    QStringList credentials = QString::fromUtf8(data).split(",");

    if (credentials.size() == 2) {
        QString username = credentials[0];
        QString password = credentials[1];

        DatabaseManager db;
        if (db.connectToDatabase("localhost", 1433, "ChatDB", "sa", "your_password")) {
            if (db.isUserValid(username, password)) {
                client->write("LOGIN_SUCCESS");
            } else {
                client->write("LOGIN_FAILED");
                client->disconnectFromHost();
            }
        }
    }
}
