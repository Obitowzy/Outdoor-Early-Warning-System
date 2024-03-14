#ifndef CONFIG_INTERFACE_H
#define CONFIG_INTERFACE_H

#include <QWidget>
#include <QLabel>
#include "comm.h"
#include "xmloperation.h"
namespace Ui {
class config_interface;
}

class config_interface : public QWidget
{
    Q_OBJECT


public:
    explicit config_interface(xmlOperation *xmldata,QWidget *parent = nullptr);
    void get_filename(QString &filename);
    ~config_interface();

private:
    Ui::config_interface *ui;
    xmlOperation *xml;
    int re_set_num;//遥设分页数
    int re_adjust_num;//遥调个数
    QString name[13] = {"LORA参数",
                        "串口参数",
                        "水位传感器参数",
                        "雨量传感器参数",
                        "流量传感器参数",
                        "服务器IP参数",
                        "网口参数",
                        "设备信息",
                        "时间参数",
                        "播报参数",
                        "水位告警参数",
                        "雨量告警参数",
                        "白名单号码"};
    QString num[13] = {"0x01",
                        "0x02",
                        "0x03",
                        "0x04",
                        "0x05",
                        "0x06",
                        "0x07",
                        "0x08",
                        "0x09",
                        "0x0A",
                        "0x0B",
                        "0x0C",
                        "0x0D"};

};

#endif // CONFIG_INTERFACE_H
