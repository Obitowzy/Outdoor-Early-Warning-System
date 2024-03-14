#define MAX_NUM_OF_DATA 256

#ifndef XMLOPERATION_H
#define XMLOPERATION_H

#include <QObject>
#include <QFile>
#include <QXmlStreamReader>
#include <QDebug>
#include <QStringList>



struct datastorage{

    QString packetHeader;//报文 帧头
    QString opcode;//操作码
    QString o_typecode;//类型，码
    QString t_typecode;//子类型码
    QString description;//条目名描述
    QString data_typem;//通信存储数据类型
    QString data_typea;//实际数据类型
    QString type_switch;//通信存储类型和实际类型之间的系数比
    QString d_length;//数据长度
    QString data_Min;//最小值
    QString data_d;//默认值
    QString data_Max;//最大值
    bool isonodata = false;

};
struct o_typestorage{
   datastorage typestorage[60];
   int typenum;
};

class xmlOperation
{
public:
    xmlOperation();
    void readExcelXML(const QString& filePath);
    //返回数据模型实际有效数据长度↓
    int getdatalength(const datastorage datalist[]);
     //返回数据模型AA 22中大类个数（子页面个数）↓
    int geto_AA22typenum();
    int geto_AA44typenum();
     //返回当前条目 读写权限↓
    QString get_o_typecode(int a);
    int get_RW_YON(const datastorage data);
    void p();


private:
    int rownum=0 ;
    datastorage datalist[MAX_NUM_OF_DATA];
    o_typestorage  type22storagelist[MAX_NUM_OF_DATA];
    o_typestorage  type44storagelist[MAX_NUM_OF_DATA];
};

#endif // XMLOPERATION_H
