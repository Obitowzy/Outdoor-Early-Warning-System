#include "config_interface.h"
#include "ui_config_interface.h"

config_interface::config_interface(xmlOperation *xmldata,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::config_interface)
{
    ui->setupUi(this);
    //参数预设
    xml = xmldata;
    re_set_num = xml->geto_AA22typenum();
    re_adjust_num = xml->geto_AA44typenum();
    qDebug() << "界面生成读取re_set_num" << re_set_num;
    qDebug() << "界面生成读取re_adjust_num" << re_adjust_num;

    //遥设界面初始化 11
    if(re_set_num>1){
        int flag = 0;
        for (int i = 0; i < re_set_num; ++i) {

            while (xml->get_o_typecode(i) != num[flag]) {
                qDebug() << "大类对比1" << xml->get_o_typecode(i);
                qDebug() << "大类对比2" << num[flag];
                flag++;
                if(flag >=14)return ;
            }

            // 创建一个新的 QWidget
            QWidget *newTab = new QWidget;
            // 可以在这里为新的 tab 添加内容或其他控件
            QLabel *label = new QLabel(QString("%1").arg(name[flag]), newTab);
            label->setAlignment(Qt::AlignCenter);
            // 将新的 tab 添加到 ui->tabWidget
            ui->tabWidget->addTab(newTab, QString("%1").arg(name[flag]));



        }
    }




//    // 创建中央的标签页
//       QWidget *centralTab = new QWidget;
//       QLabel *label = new QLabel("This is the central tab.", centralTab);
//       label->setAlignment(Qt::AlignCenter);

//       // 添加中央标签页到TabWidget
//       ui->tabWidget->addTab(centralTab, "Central Tab");

//       // 创建其他标签页（可选）
//       QWidget *otherTab = new QWidget;
//       QLabel *otherLabel = new QLabel("This is another tab.", otherTab);
//       otherLabel->setAlignment(Qt::AlignCenter);

//       // 添加其他标签页到TabWidget
//       ui->tabWidget->addTab(otherTab, "Other Tab");
}

config_interface::~config_interface()
{
    delete ui;

}
