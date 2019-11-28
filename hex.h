#ifndef ANALYSISHEX_H
#define ANALYSISHEX_H

#include <QByteArray>
#include <QVector>

#define MAX_BUFFER_SIZE 22

class Hex
{
public:
    Hex();
    ~Hex();


    bool analysisHex(QByteArray &hexAllData);
    void DestoryOneRecord();

    unsigned char  getRecordLength();
    unsigned short getLoadOffset();
    unsigned char getRecordType();
    unsigned char* getOneRecordData();              //获取一条记录数据

private:
    QVector<unsigned char> lineData;                //存储待解析的记录
    unsigned char m_cRecordMark;                    //记录标识
    unsigned char m_nRecordLength;                  //记录长度
    unsigned short m_pLoadOffset;                   //装载偏移
    unsigned char m_pRecordType;                    //记录类型
    unsigned char* m_pData;                         //数据字段
    unsigned char m_pChecksum;                      //校验和
};

#endif // ANALYSISHEX_H
