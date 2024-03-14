#ifndef COMM_H
#define COMM_H

#include <QObject>
#include "xmloperation.h"
class comm : public QObject
{
    Q_OBJECT
public:
    explicit comm(QObject *parent = nullptr);

signals:

public slots:
//    QByteArray calculate_crc16(const QByteArray &data);
//    //注↓ 1:AA 11。2:AA 22。3:AA 33。4:AA 44。5:AA 55。
//    QByteArray set_packetHeader(QByteArray &packetHeader,int a);
//    //注↓ 0:读 1:写
//    QByteArray set_opcode(QByteArray &opcode,int a);
//    //注↓ 直接将读取到的数字转换为16进制
//    QByteArray set_o_typecode(QByteArray &o_typecode,int num);
//    //注↓ 直接将读取到的数字转换为16进制
//    QByteArray set_t_typecode(QByteArray &t_typecode,int num);
//    QByteArray set_d_length(QByteArray &d_length);
//    QByteArray set_data(QByteArray &data);
//    QByteArray set_CRC(QByteArray &CRC);
//    QByteArray set_data_packet(QByteArray &data_packet);
private:
    QByteArray data_packet;//整体报文
    QByteArray packetHeader;//报文 帧头
    QByteArray opcode;//操作码
    QByteArray o_typecode;//类型，码
    QByteArray t_typecode;//子类型码
    QByteArray d_length;//数据长度
    QByteArray data;//具体数据
    QByteArray CRC;//CRC校验码
};

#endif // COMM_H
