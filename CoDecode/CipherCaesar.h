#ifndef CIPHERCAESAR_H
#define CIPHERCAESAR_H

#include <QMap>
#include <string>
#include <QString>


class CipherCaesar
{
public:
    CipherCaesar(int shift);

    void setRosettaCharToInt();
    void setRosettaIntToChar();

    QString encrypt(QString message);
    QString decrypt(QString code);


private:
    int shift = 0;

    QMap<QChar,int> rosettaCharToInt;
    QMap<int,QChar> rosettaIntToChar;
};

#endif // CIPHERCAESAR_H
