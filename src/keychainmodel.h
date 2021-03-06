///////////////////////////////////////////////////////////////////////////////
//
// CoinVault
//
// keychainmodel.h
//
// Copyright (c) 2013 Eric Lombrozo
//
// All Rights Reserved.

#ifndef COINVAULT_KEYCHAINMODEL_H
#define COINVAULT_KEYCHAINMODEL_H

#include <QStandardItemModel>

#include <CoinQ_vault.h>

#include <CoinQ_typedefs.h>

class KeychainModel : public QStandardItemModel
{
    Q_OBJECT

public:
    KeychainModel();

    void setVault(CoinQ::Vault::Vault* vault);
    void update();

    void exportKeychain(const QString& keychainName, const QString& fileName, bool exportPrivate) const;
    void importKeychain(const QString& keychainName, const QString& fileName, bool& importPrivate);
    bool exists(const QString& keychainName) const;

    bytes_t getExtendedKey(const QString& keychainName) const;

    // Overridden methods
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex& index) const;

signals:
    void error(const QString& message);

private:
    CoinQ::Vault::Vault* vault;
};

#endif // COINVAULT_ACCOUNTMODEL_H
