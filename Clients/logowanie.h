#ifndef LOGOWANIE_H
#define LOGOWANIE_H

#include <QObject>
#include <QString>

class Logowanie : public QObject
{
    Q_OBJECT

public:
    explicit Logowanie(QObject *parent = nullptr);

    void setUsername(const QString &username);
    void setPassword(const QString &password);

    QString getUsername() const;
    QString getPassword() const;

    bool verifyCredentials();

signals:
    void loginSuccess();
    void loginFailed();

private:
    QString _username;
    QString _password;
};

#endif // LOGOWANIE_H
