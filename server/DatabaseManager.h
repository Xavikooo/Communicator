#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QDebug>

class DatabaseManager : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseManager(QObject *parent = nullptr);
    ~DatabaseManager();

    bool connectToDatabase(const QString &hostname, int port, const QString &databaseName,
                           const QString &username, const QString &password);
    bool isUserValid(const QString &login, const QString &password);

private:
    QSqlDatabase _db;
};

#endif // DATABASEMANAGER_H
