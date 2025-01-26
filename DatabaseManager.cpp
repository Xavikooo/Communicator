#include "DatabaseManager.h"

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{
    _db = QSqlDatabase::addDatabase("QODBC");
}

DatabaseManager::~DatabaseManager()
{
    if (_db.isOpen()) {
        _db.close();
    }
}

bool DatabaseManager::connectToDatabase(const QString &hostname, int port,
                                        const QString &databaseName,
                                        const QString &username,
                                        const QString &password)
{
    QString connectionString = QString("DRIVER={SQL Server};SERVER=%1,%2;DATABASE=%3;UID=%4;PWD=%5;")
    .arg(hostname)
        .arg(port)
        .arg(databaseName)
        .arg(username)
        .arg(password);

    _db.setDatabaseName(connectionString);

    if (!_db.open()) {
        qDebug() << "Błąd połączenia z bazą danych:" << _db.lastError().text();
        return false;
    }

    qDebug() << "Połączono z bazą danych!";
    return true;
}

bool DatabaseManager::isUserValid(const QString &login, const QString &password)
{
    if (!_db.isOpen()) {
        qDebug() << "Baza danych nie jest podłączona!";
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Users WHERE username = :login AND password = :password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Błąd zapytania SQL:" << query.lastError().text();
        return false;
    }

    if (query.next() && query.value(0).toInt() > 0) {
        return true;  // Użytkownik istnieje
    }

    return false;
}
