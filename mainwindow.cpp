#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    xml = new xmlOperation();
//    ui->pre_entryWidget->hide();
    configInterfaceWidget = new config_interface(xml,ui->centralWidget);
    ui->gridLayout->addWidget(configInterfaceWidget);
    ui->gridLayout->setContentsMargins(0, 0, 0, 0);
    configswitch = new QAction("配置文件选择", ui->menu_1);
    ui->menu_1->addAction(configswitch);
    configInterfaceWidget->hide();
    es_connection();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::es_connection(){
    connect(ui->config_c, &QPushButton::clicked, this, &MainWindow::Refresh_ConfigOpt);
//    connect(ui->config_c, &QPushButton::clicked, this, &MainWindow::load_data);
    connect(ui->in, &QPushButton::clicked, this, &MainWindow::Switch_interface);
    connect(configswitch, &QAction::triggered, this, &MainWindow::main_interface);
//    connect(ui->in, &QPushButton::clicked, this, &MainWindow::load_data);

}

void MainWindow::Refresh_ConfigOpt(){
    // 打开文件选择对话框，限制文件类型为XML文件
    file = QFileDialog::getOpenFileName(this, tr("Select XML File"), "", tr("XML Files (*.xml);;All Files (*)"));
    QFileInfo fileInfo(file);
    QString justFileName = fileInfo.fileName();
    if (!file.isEmpty())
    {
        // 在这里可以处理所选的XML文件，例如打印文件路径
        qDebug() << "Selected XML File:" << file;

    }
    if (!fileInfo.exists()) {
        qDebug() << "文件:" << file<<"不存在";
        return;
    }
    ui->config2->setText(justFileName);
    loadfile = true;
    load_data();
}

void MainWindow::Switch_interface(){
    if(loadfile){
        if(ui->pre_entryWidget->isVisible()){
            ui->pre_entryWidget->hide();
            // Check if configInterfaceWidget needs reinitialization
            if (!configInterfaceWidget->isVisible()) {
                // Reinitialize configInterfaceWidget
                configInterfaceWidget = new config_interface(xml, ui->centralWidget);
                ui->gridLayout->addWidget(configInterfaceWidget);
                ui->gridLayout->setContentsMargins(0, 0, 0, 0);
            }

            configInterfaceWidget->show();
        } else {
            ui->pre_entryWidget->show();
            configInterfaceWidget->hide();
        }
    }else {
         QMessageBox::critical(nullptr, "错误", "请先选择配置文件");
    }

}


void MainWindow::load_data(){
    xml->readExcelXML(file);

    xml->geto_AA22typenum();
    xml->geto_AA44typenum();
    xml->p();
}

void MainWindow::main_interface(){
    ui->pre_entryWidget->show();
    configInterfaceWidget->hide();
}
