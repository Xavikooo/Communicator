#include "Logowanie.h"

Logowanie::Logowanie(QObject *parent)
    : QObject(parent), _username(""), _password("")
{
}

void Logowanie::setUsername(const QString &username)
{
    _username = username;
}

void Logowanie::setPassword(const QString &password)
{
    _password = password;
}

QString Logowanie::getUsername() const
{
    return _username;
}

QString Logowanie::getPassword() const
{
    return _password;
}

bool Logowanie::verifyCredentials()
{
    // Przykładowa walidacja - zamień na rzeczywiste sprawdzenie np. z bazy danych
    if (_username == "admin" && _password == "password123") {
        emit loginSuccess();
        return true;
    } else {
        emit loginFailed();
        return false;
    }
}
