#include "mainwindow.h"
#include <QApplication>
#include "xmloperation.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    xmlOperation x;
//    QString filePath = "D:/QTproject/Outdoor Early Warning System/mainwin/入户报警器数据模型点表（王工专供版2）.xml";
//    x.readExcelXML(filePath);
//    x.p();
    return a.exec();
}
