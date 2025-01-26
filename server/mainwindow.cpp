#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString XDD = ui->lineEdit_Login->text();
    QString Password = ui->lineEdit_Password->text();
    if (XDD == "Admin" && Password == "ehh")
    {
        QMessageBox::information(this,"Admin","Zalogowano");
        this->hide();
        MainPage *mainpage = new MainPage();
        mainpage->show();
    }
    else
    {
        QMessageBox::warning(this,"aplikacja", "Sprobuj ponownie");
    }
}





void MainWindow::on_pushButton_Exit_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"aplikacja","czy aby napewno chcesz wyjsc?",QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes){
        QApplication::quit();
    }
}

