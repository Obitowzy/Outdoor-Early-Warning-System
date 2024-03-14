#include "comm.h"

comm::comm(QObject *parent) : QObject(parent)
{

}

//QByteArray comm::set_packetHeader(QByteArray &packetHeader,int a){
//    packetHeader.clear();
//    switch (a) {
//        case 1:
//                packetHeader = QByteArray::fromHex("AA 11");
//                break;
//        case 2:
//                packetHeader = QByteArray::fromHex("AA 22");
//                break;
//        case 3:
//                packetHeader = QByteArray::fromHex("AA 33");
//                break;
//        case 4:
//                packetHeader = QByteArray::fromHex("AA 44");
//                break;
//        case 5:
//                packetHeader = QByteArray::fromHex("AA 55");
//                break;
//    }
//    return packetHeader;
//}

//QByteArray comm::set_opcode(QByteArray &opcode,int a){
//    opcode.clear();
//    switch (a) {
//        case 0:
//                opcode = QByteArray::fromHex("00");
//                break;
//        case 1:
//                opcode = QByteArray::fromHex("01");
//                break;
//    }
//    return packetHeader;
//}

//QByteArray comm::set_o_typecode(QByteArray &o_typecode ,int num) {
//    o_typecode.clear();
//    // 将int转换为uint8_t
//    uint8_t code = static_cast<uint8_t>(num);
//    // 将uint8_t转换为QByteArray
//    QByteArray byteCode(reinterpret_cast<const char*>(&code), sizeof(code));
//    o_typecode = byteCode;

//    return o_typecode;
//}




//QByteArray comm::calculate_crc16(const QByteArray &data)
//{
//    quint16 crc = 0xFFFF; // 初始值为0xFFFF

//    for (int i = 0; i < data.size(); ++i)
//    {
//        crc ^= static_cast<quint8>(data.at(i)); // 将数据字节与CRC值异或

//        for (int j = 0; j < 8; ++j)
//        {
//            if (crc & 1)
//            {
//                crc = (crc >> 1) ^ 0xA001; // 如果最低位为1，进行位移和异或
//            }
//            else
//            {
//                crc >>= 1; // 否则只进行位移
//            }
//        }
//    }

//    // 构造包含两个字节的结果 QByteArray
//    QByteArray result;
//    result.append(static_cast<char>(crc & 0xFF));
//    result.append(static_cast<char>((crc >> 8) & 0xFF));

//    return result;
//}
