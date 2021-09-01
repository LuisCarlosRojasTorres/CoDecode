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
    lowerRosettaCharToInt['a']=0;
    lowerRosettaCharToInt['b']=1;
    lowerRosettaCharToInt['c']=2;
    lowerRosettaCharToInt['d']=3;
    lowerRosettaCharToInt['e']=4;

    lowerRosettaCharToInt['f']=5;
    lowerRosettaCharToInt['g']=6;
    lowerRosettaCharToInt['h']=7;
    lowerRosettaCharToInt['i']=8;
    lowerRosettaCharToInt['j']=9;

    lowerRosettaCharToInt['k']=10;
    lowerRosettaCharToInt['l']=11;
    lowerRosettaCharToInt['m']=12;
    lowerRosettaCharToInt['n']=13;
    lowerRosettaCharToInt['o']=14;

    lowerRosettaCharToInt['p']=15;
    lowerRosettaCharToInt['q']=16;
    lowerRosettaCharToInt['r']=17;
    lowerRosettaCharToInt['s']=18;
    lowerRosettaCharToInt['t']=19;

    lowerRosettaCharToInt['u']=20;
    lowerRosettaCharToInt['v']=21;
    lowerRosettaCharToInt['w']=22;
    lowerRosettaCharToInt['x']=23;
    lowerRosettaCharToInt['y']=24;

    lowerRosettaCharToInt['z']=25;

    upperRosettaCharToInt['A']=0;
    upperRosettaCharToInt['B']=1;
    upperRosettaCharToInt['C']=2;
    upperRosettaCharToInt['D']=3;
    upperRosettaCharToInt['E']=4;

    upperRosettaCharToInt['F']=5;
    upperRosettaCharToInt['G']=6;
    upperRosettaCharToInt['H']=7;
    upperRosettaCharToInt['I']=8;
    upperRosettaCharToInt['J']=9;

    upperRosettaCharToInt['K']=10;
    upperRosettaCharToInt['L']=11;
    upperRosettaCharToInt['M']=12;
    upperRosettaCharToInt['N']=13;
    upperRosettaCharToInt['O']=14;

    upperRosettaCharToInt['P']=15;
    upperRosettaCharToInt['Q']=16;
    upperRosettaCharToInt['R']=17;
    upperRosettaCharToInt['S']=18;
    upperRosettaCharToInt['T']=19;

    upperRosettaCharToInt['U']=20;
    upperRosettaCharToInt['V']=21;
    upperRosettaCharToInt['W']=22;
    upperRosettaCharToInt['X']=23;
    upperRosettaCharToInt['Y']=24;

    upperRosettaCharToInt['Z']=25;
}

void CipherCaesar::setRosettaIntToChar()
{
    lowerRosettaIntToChar[0]='a';
    lowerRosettaIntToChar[1]='b';
    lowerRosettaIntToChar[2]='c';
    lowerRosettaIntToChar[3]='d';
    lowerRosettaIntToChar[4]='e';

    lowerRosettaIntToChar[5]='f';
    lowerRosettaIntToChar[6]='g';
    lowerRosettaIntToChar[7]='h';
    lowerRosettaIntToChar[8]='i';
    lowerRosettaIntToChar[9]='j';

    lowerRosettaIntToChar[10]='k';
    lowerRosettaIntToChar[11]='l';
    lowerRosettaIntToChar[12]='m';
    lowerRosettaIntToChar[13]='n';
    lowerRosettaIntToChar[14]='o';

    lowerRosettaIntToChar[15]='p';
    lowerRosettaIntToChar[16]='q';
    lowerRosettaIntToChar[17]='r';
    lowerRosettaIntToChar[18]='s';
    lowerRosettaIntToChar[19]='t';

    lowerRosettaIntToChar[20]='u';
    lowerRosettaIntToChar[21]='v';
    lowerRosettaIntToChar[22]='w';
    lowerRosettaIntToChar[23]='x';
    lowerRosettaIntToChar[24]='y';
    lowerRosettaIntToChar[25]='z';

    upperRosettaIntToChar[0]='A';
    upperRosettaIntToChar[1]='B';
    upperRosettaIntToChar[2]='C';
    upperRosettaIntToChar[3]='D';
    upperRosettaIntToChar[4]='E';

    upperRosettaIntToChar[5]='F';
    upperRosettaIntToChar[6]='G';
    upperRosettaIntToChar[7]='H';
    upperRosettaIntToChar[8]='I';
    upperRosettaIntToChar[9]='J';

    upperRosettaIntToChar[10]='K';
    upperRosettaIntToChar[11]='L';
    upperRosettaIntToChar[12]='M';
    upperRosettaIntToChar[13]='N';
    upperRosettaIntToChar[14]='O';

    upperRosettaIntToChar[15]='P';
    upperRosettaIntToChar[16]='Q';
    upperRosettaIntToChar[17]='R';
    upperRosettaIntToChar[18]='S';
    upperRosettaIntToChar[19]='T';

    upperRosettaIntToChar[20]='U';
    upperRosettaIntToChar[21]='V';
    upperRosettaIntToChar[22]='W';
    upperRosettaIntToChar[23]='X';
    upperRosettaIntToChar[24]='Y';
    upperRosettaIntToChar[25]='Z';
}

QString CipherCaesar::encrypt(QString message)
{
    QString ans;

    for(QChar c : message){
        if(c.isLower()){
            if(lowerRosettaCharToInt.contains(c)){
                ans.append( lowerRosettaIntToChar.value( ( lowerRosettaCharToInt.value(c) + shift ) % 26) );
            }
        }else if(c.isUpper()){
            if(upperRosettaCharToInt.contains(c)){
                ans.append( upperRosettaIntToChar.value( ( upperRosettaCharToInt.value(c) + shift ) % 26) );
            }
        }
        else{
            ans.append(c);
        }
    }
    return ans;
}

QString CipherCaesar::decrypt(QString code)
{
    QString ans;

    for(QChar c : code){
        if(c.isLower()){
            if(lowerRosettaCharToInt.contains(c)){
                ans.append( lowerRosettaIntToChar.value( ( lowerRosettaCharToInt.value(c) - shift ) % 26) );
            }
        }else if(c.isUpper()){
            if(upperRosettaCharToInt.contains(c)){
                ans.append( upperRosettaIntToChar.value( ( upperRosettaCharToInt.value(c) - shift ) % 26) );
            }
        }
        else{
            ans.append(c);
        }
    }
    return ans;
}
