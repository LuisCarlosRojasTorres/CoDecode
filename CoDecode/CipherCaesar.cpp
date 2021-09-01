#include "CipherCaesar.h"

#include <iostream>
#include <QDebug>

CipherCaesar::CipherCaesar(int shift)
    :
      shift(shift)
{
    setRosettaCharToInt();
    setRosettaIntToChar();

    QString test = "Hola Rufo!!";
    std::cout << "Message: " << test.toStdString() << std::endl;
    std::cout << "Code: " << encrypt(test).toStdString() << std::endl;
    std::cout << "DeCode: " << decrypt(encrypt(test)).toStdString() << std::endl;
    std::cout << "OK" << std::endl;

}

void CipherCaesar::setRosettaCharToInt()
{
    rosettaCharToInt['a']=0;
    rosettaCharToInt['b']=1;
    rosettaCharToInt['c']=2;
    rosettaCharToInt['d']=3;
    rosettaCharToInt['e']=4;

    rosettaCharToInt['f']=5;
    rosettaCharToInt['g']=6;
    rosettaCharToInt['h']=7;
    rosettaCharToInt['i']=8;
    rosettaCharToInt['j']=9;

    rosettaCharToInt['k']=10;
    rosettaCharToInt['l']=11;
    rosettaCharToInt['m']=12;
    rosettaCharToInt['n']=13;
    rosettaCharToInt['o']=14;

    rosettaCharToInt['p']=15;
    rosettaCharToInt['q']=16;
    rosettaCharToInt['r']=17;
    rosettaCharToInt['s']=18;
    rosettaCharToInt['t']=19;

    rosettaCharToInt['u']=20;
    rosettaCharToInt['v']=21;
    rosettaCharToInt['w']=22;
    rosettaCharToInt['x']=23;
    rosettaCharToInt['y']=24;

    rosettaCharToInt['z']=25;
}

void CipherCaesar::setRosettaIntToChar()
{
    rosettaIntToChar[0]='a';
    rosettaIntToChar[1]='b';
    rosettaIntToChar[2]='c';
    rosettaIntToChar[3]='d';
    rosettaIntToChar[4]='e';

    rosettaIntToChar[5]='f';
    rosettaIntToChar[6]='g';
    rosettaIntToChar[7]='h';
    rosettaIntToChar[8]='i';
    rosettaIntToChar[9]='j';

    rosettaIntToChar[10]='k';
    rosettaIntToChar[11]='l';
    rosettaIntToChar[12]='m';
    rosettaIntToChar[13]='n';
    rosettaIntToChar[14]='o';

    rosettaIntToChar[15]='p';
    rosettaIntToChar[16]='q';
    rosettaIntToChar[17]='r';
    rosettaIntToChar[18]='s';
    rosettaIntToChar[19]='t';

    rosettaIntToChar[20]='u';
    rosettaIntToChar[21]='v';
    rosettaIntToChar[22]='w';
    rosettaIntToChar[23]='x';
    rosettaIntToChar[24]='y';
    rosettaIntToChar[25]='z';
}

QString CipherCaesar::encrypt(QString message)
{
    message = message.toLower();
    QString ans;

    for(QChar c : message){
        if(rosettaCharToInt.contains(c)){
            ans.append( rosettaIntToChar.value( ( rosettaCharToInt.value(c) + shift ) % 26) );
        }else{
            ans.append(c);
        }
    }
    return ans;
}

QString CipherCaesar::decrypt(QString code)
{
    QString ans;

    for(QChar c : code){
        if(rosettaCharToInt.contains(c)){
            ans.append( rosettaIntToChar.value( ( rosettaCharToInt.value(c) - shift ) % 26) );
        }else{
            ans.append(c);
        }
    }
    return ans;
}
