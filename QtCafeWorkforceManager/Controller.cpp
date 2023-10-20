﻿#include "QApplicationGlobal.h"
#include "qcryptographichash.h"
#include <QString>

EUserProfile AuthorizeController::Execute()
{
    QByteArray passwordBytes = Password.toUtf8();
    QByteArray hashedPassword = QCryptographicHash::hash(passwordBytes, QCryptographicHash::Sha256);
    QString hashedPasswordHex = QString(hashedPassword.toHex());

    return QApplicationGlobal::UserDAO.Authorize(Username, hashedPasswordHex);
}



QVector<User> GetUsersController::Execute()
{
    return QApplicationGlobal::UserDAO.GetUsers();
}

void UpdateUserController::Execute()
{
    QByteArray passwordBytes = UpdatedUser.getPassword().toUtf8();
    QByteArray hashedPassword = QCryptographicHash::hash(passwordBytes, QCryptographicHash::Sha256);
    QString hashedPasswordHex = QString(hashedPassword.toHex());
    UpdatedUser.setPassword(hashedPasswordHex);

    QApplicationGlobal::UserDAO.UpdateOrInsert(this->UpdatedUser, this->UsernameBeforeUpdate);
}

void CreateUserController::Execute()
{
    QByteArray passwordBytes = NewUser.getPassword().toUtf8();
    QByteArray hashedPassword = QCryptographicHash::hash(passwordBytes, QCryptographicHash::Sha256);
    QString hashedPasswordHex = QString(hashedPassword.toHex());
    NewUser.setPassword(hashedPasswordHex);

    QApplicationGlobal::UserDAO.Insert(this->NewUser);
}

void DeleteUserController::Execute()
{
    QApplicationGlobal::UserDAO.Delete(this->UsernameToDelete);
}

QVector<User> SearchByEUPController::Execute()
{
    return QApplicationGlobal::UserDAO.SearchByEUP(this->profile);
}
