#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QGridLayout>
#include <QMessageBox>
#include "xmloperation.h"
#include "config_interface.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void es_connection();

signals:

private slots:
    void Refresh_ConfigOpt();
    //界面切换槽函数
    void Switch_interface();
    void main_interface();
    //数据类槽函数
    void load_data();
private:
    Ui::MainWindow *ui;
    int num;
    bool loadfile = false;
    QString file;//配置文件路径
    QString justFileName;//配置文件名

    QGridLayout *gridLayout;
    config_interface *configInterfaceWidget;
    xmlOperation *xml;
    QAction *configswitch;
};

#endif // MAINWINDOW_H
