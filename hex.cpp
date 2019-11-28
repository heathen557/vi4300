#include "hex.h"
#include <qDebug>

Hex::Hex()
{
    m_cRecordMark = 0;
    m_nRecordLength = 0;
    m_pLoadOffset = 0;
    m_pRecordType = 0;
    m_pData = 0;
    m_pChecksum = 0;
    lineData.clear();
}

Hex::~Hex(){}
unsigned char  Hex::getRecordLength()
{
     return m_nRecordLength;
}
unsigned short Hex::getLoadOffset()
{
    return m_pLoadOffset;
}
unsigned char Hex::getRecordType()
{
    return m_pRecordType;
}

unsigned char* Hex::getOneRecordData()
{
    return m_pData;
}

void Hex::DestoryOneRecord(void)
{
    m_cRecordMark = 0;
    m_nRecordLength = 0;
    m_pLoadOffset = 0;
    m_pRecordType = 0;
    m_pData = 0;
    m_pChecksum = 0;
    lineData.clear();
}

bool Hex::analysisHex(QByteArray &hexAllData)
{
    unsigned char ch, ch1;
    //数据格式不对
    if(hexAllData.at(0) != ':')
        return false;

    lineData.append(':');

    //将ASCII转化为数字和字符
    for(int i = 1; i < hexAllData.size(); i+=2)
    {
        //到行尾，跳出
        if(hexAllData[i] == '\r')
            break;

        if('0' <= hexAllData[i] && hexAllData[i] <= '9')
            ch = hexAllData[i] - '0';
        else if('A' <= hexAllData[i] && hexAllData[i] <= 'F')
            ch = hexAllData[i] - 0x37;

        if('0' <= hexAllData[i+1] && hexAllData[i+1] <= '9')
            ch1 = hexAllData[i+1] - '0';
        else if('A' <= hexAllData[i+1] && hexAllData[i+1] <= 'F')
            ch1 = hexAllData[i+1] - 0x37;

         lineData.append(ch << 4 | ch1);
    }

    /*数据长度*/
    m_nRecordLength = lineData[1];

    /*计算校验和*/
    for(unsigned char j = 1; j < m_nRecordLength + 5; j++)
       m_pChecksum +=  lineData[j];

    /*校验正确*/
    if(lineData[m_nRecordLength+5] == (unsigned char)(0x100 - m_pChecksum)&0xFF)
    {
        /*数据偏移*/
        m_pLoadOffset = lineData[2]* 256 + lineData[3];

        /*数据类型*/
        m_pRecordType = lineData[4];

        /*数据指针*/
        m_pData = &lineData[5];

        return true;
    }
    else
    {
        DestoryOneRecord();
    }
    return false;
}
