#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include "ServerManager.h"

namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

private slots:
    void newClientConnected(QTcpSocket *client);
    void clientDisconnected(QTcpSocket *client);

private:
    Ui::MainPage *ui;
    ServerManager *_server;

private: //metody
    void setupServer();
};



#endif // MAINPAGE_H
