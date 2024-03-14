#include "xmloperation.h"

xmlOperation::xmlOperation()
{

}

void xmlOperation::readExcelXML(const QString& filePath) {
    // 打开XML文件
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件:" << filePath;
        return;
    }

    // 创建XML读取器
    QXmlStreamReader xmlReader(&file);

    // 标志，表示是否在目标工作表中
    bool inTargetWorksheet = false;

    // 遍历XML文件
    int num = 0;
    while (!xmlReader.atEnd() && !xmlReader.hasError()) {
        xmlReader.readNext();

        if (xmlReader.isStartElement()) {
            if (xmlReader.name() == "Worksheet") {

                // 判断是否进入目标工作表
                QXmlStreamAttributes attributes = xmlReader.attributes();
                if (attributes.hasAttribute("ss:Name") && attributes.value("ss:Name") == "Sheet1") {
                    inTargetWorksheet = true;
                } else {
                    inTargetWorksheet = false;
                }
            } else if (inTargetWorksheet && xmlReader.name() == "Cell") {

                // 在目标工作表中，读取<Cell>标签
                xmlReader.readNextStartElement();
                if(num == 13){
                    num = 0;
                    rownum++;
                    qDebug() << "第几排: ↑"<<rownum;

                }


                // 判断是否是<Data>标签
                if (xmlReader.name() == "Data") {
                    // 读取数据
                    QString cellData = xmlReader.readElementText();

                    // 处理非空数据
                    if (!cellData.trimmed().isEmpty()) {

                        num++;
                        if(num == 1)datalist[rownum].packetHeader=cellData;
                        else if (num == 3) datalist[rownum].opcode=cellData;
                        else if (num == 4) datalist[rownum].o_typecode=cellData;
                        else if (num == 5) datalist[rownum].t_typecode=cellData;
                        else if (num == 6) datalist[rownum].description=cellData;
                        else if (num == 7) datalist[rownum].data_typem=cellData;
                        else if (num == 8) datalist[rownum].data_typea=cellData;
                        else if (num == 9) datalist[rownum].type_switch=cellData;
                        else if (num == 10) datalist[rownum].d_length=cellData;
                        else if (num == 11) datalist[rownum].data_Min=cellData;
                        else if (num == 12) datalist[rownum].data_d=cellData;
                        else if (num == 13) {
                            datalist[rownum].data_Max=cellData;
                            datalist[rownum].isonodata=true;
                        }

                        qDebug() << "单元格数据: 第"<<num <<"个: " << cellData;
                    }
                }
            }
        }
    }

    // 关闭文件
    file.close();

    // 处理可能的错误
    if (xmlReader.hasError()) {
        qDebug() << "XML解析错误:" << xmlReader.errorString();
    }
}

void xmlOperation::p(){
    qDebug() <<"数据总排数"<< rownum;
    int a = getdatalength(datalist);
    qDebug() <<"datalist 长度"<< a;
    qDebug() <<"AA22大类个数"<<type22storagelist->typenum;
    qDebug() <<"AA44大类个数"<<type44storagelist->typenum;


}


int xmlOperation::getdatalength(const datastorage *datalist){
    int Length = 0;
    int size = 256;

       for (int i = 1; i < size; ++i) {
           if (datalist[i].isonodata) {
               ++Length;
           }
       }

       return Length;

}
int xmlOperation::geto_AA22typenum(){
    int Length = 0;
    int size = getdatalength(datalist);
    int num = 0;
    QString flag = "0x01";
    QString currentflag;
    for (int i = 1; i <= size; ++i) {
        QString head = datalist[i].packetHeader;
        if (datalist[i].isonodata && datalist[i].packetHeader =="0x22") {
            currentflag = datalist[i].o_typecode;
            if(flag == currentflag){
                type22storagelist[Length].typestorage[num] = datalist[i];
            }else {
                ++Length;
                num = 0;
                flag = currentflag;
                type22storagelist[Length].typestorage[num] = datalist[i];
        }

        }
    }
    type22storagelist->typenum = ++Length;
    return Length;
}

int xmlOperation::geto_AA44typenum(){
    int Length = 0;
    int size = getdatalength(datalist);
    int num = 0;
    QString flag = "0x01";
    QString currentflag;
    for (int i = 1; i <= size; ++i) {
        QString head = datalist[i].packetHeader;
        if (datalist[i].isonodata && datalist[i].packetHeader =="0x44") {
            currentflag = datalist[i].o_typecode;
            if(flag == currentflag){
                type44storagelist[Length].typestorage[num] = datalist[i];
            }else {
                ++Length;
                num = 0;
                flag = currentflag;
                type44storagelist[Length].typestorage[num] = datalist[i];
        }

        }
    }
    type44storagelist->typenum = ++Length;
    return Length;
}

int xmlOperation::get_RW_YON(const datastorage data){
    int r ;
    if(data.opcode == "0x10"){
       r = 1;//只可读
    }
    else if (data.opcode == "0x01") {
       r = 2;//只可写
    }
    else if (data.opcode == "0x11") {
       r = 3;//可读可写
    }
    else if (data.opcode == "0x00") {
       r = 0;//不可读不可写
    }
    else{
       r = -1;
    }
    return  r;
}
QString xmlOperation::get_o_typecode(int a){
    return type22storagelist[a].typestorage->o_typecode;
}
