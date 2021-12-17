#ifndef NFT_STORAGE_H
#define NFT_STORAGE_H

#include <QObject>

class NFT_Storage
{
public:
    NFT_Storage();
    QString load_media(QString api, QString media);
};

#endif // NFT_STORAGE_H
