#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QSignalMapper>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    initBtnArray();
    k = 0; i =0; j = 0;
    for(int i = 0; i < 26; i++){
        char_arr[(i+6)%26] = char(i+97);
    }

    ui->setupUi(this);
    func();
//    timer = new QTimer(this);
//    connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::update));
//    timer->start(1000);
    connHandler();

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::event_handler(int x, int y){
    QPushButton *btn = btn_arr[x][y];

    std::random_shuffle(std::begin(char_arr), std::end(char_arr));
    func();

//    btn->setStyleSheet("color: red;");
//    if(queue != NULL){
//        queue->setStyleSheet("color:black");
//    }
//    queue = btn;
}


void MainWindow::initBtnArray(){
    btn_arr[0][0] = ui->btn_00; //1
    btn_arr[0][1] = ui->btn_01;
    btn_arr[0][2] = ui->btn_02;
    btn_arr[0][3] = ui->btn_03;
    btn_arr[0][4] = ui->btn_04;
    btn_arr[1][0] = ui->btn_00;
    btn_arr[1][1] = ui->btn_01;
    btn_arr[1][2] = ui->btn_02;
    btn_arr[1][3] = ui->btn_03;
    btn_arr[1][4] = ui->btn_04;
    btn_arr[2][0] = ui->btn_00;
    btn_arr[2][1] = ui->btn_01;
    btn_arr[2][2] = ui->btn_02;
    btn_arr[2][3] = ui->btn_03;
    btn_arr[2][4] = ui->btn_04;
    btn_arr[3][0] = ui->btn_00;
    btn_arr[3][1] = ui->btn_01;
    btn_arr[3][2] = ui->btn_02;
    btn_arr[3][3] = ui->btn_03;
    btn_arr[3][4] = ui->btn_04;
    btn_arr[4][0] = ui->btn_00;
    btn_arr[4][1] = ui->btn_01;
    btn_arr[4][2] = ui->btn_02;
    btn_arr[4][3] = ui->btn_03;
    btn_arr[4][4] = ui->btn_04; //25
}

void MainWindow::connHandler(){
    QObject::connect(ui->btn_00, SIGNAL(clicked()), this, SLOT(handler_00()));
    QObject::connect(ui->btn_01, SIGNAL(clicked()), this, SLOT(handler_01()));
    QObject::connect(ui->btn_02, SIGNAL(clicked()), this, SLOT(handler_02()));
    QObject::connect(ui->btn_03, SIGNAL(clicked()), this, SLOT(handler_03()));
    QObject::connect(ui->btn_04, SIGNAL(clicked()), this, SLOT(handler_04()));
    QObject::connect(ui->btn_10, SIGNAL(clicked()), this, SLOT(handler_00()));
    QObject::connect(ui->btn_11, SIGNAL(clicked()), this, SLOT(handler_11()));
    QObject::connect(ui->btn_12, SIGNAL(clicked()), this, SLOT(handler_12()));
    QObject::connect(ui->btn_13, SIGNAL(clicked()), this, SLOT(handler_13()));
    QObject::connect(ui->btn_14, SIGNAL(clicked()), this, SLOT(handler_14()));
    QObject::connect(ui->btn_20, SIGNAL(clicked()), this, SLOT(handler_20()));
    QObject::connect(ui->btn_21, SIGNAL(clicked()), this, SLOT(handler_21()));
    QObject::connect(ui->btn_22, SIGNAL(clicked()), this, SLOT(handler_22()));
    QObject::connect(ui->btn_23, SIGNAL(clicked()), this, SLOT(handler_23()));
    QObject::connect(ui->btn_24, SIGNAL(clicked()), this, SLOT(handler_24()));
    QObject::connect(ui->btn_30, SIGNAL(clicked()), this, SLOT(handler_30()));
    QObject::connect(ui->btn_31, SIGNAL(clicked()), this, SLOT(handler_31()));
    QObject::connect(ui->btn_32, SIGNAL(clicked()), this, SLOT(handler_32()));
    QObject::connect(ui->btn_33, SIGNAL(clicked()), this, SLOT(handler_33()));
    QObject::connect(ui->btn_34, SIGNAL(clicked()), this, SLOT(handler_34()));
    QObject::connect(ui->btn_40, SIGNAL(clicked()), this, SLOT(handler_40()));
    QObject::connect(ui->btn_41, SIGNAL(clicked()), this, SLOT(handler_41()));
    QObject::connect(ui->btn_42, SIGNAL(clicked()), this, SLOT(handler_42()));
    QObject::connect(ui->btn_43, SIGNAL(clicked()), this, SLOT(handler_43()));
    QObject::connect(ui->btn_44, SIGNAL(clicked()), this, SLOT(handler_44()));
}

void MainWindow::func(){
    ui->btn_00->setText(QString(char_arr[0]));
    ui->btn_01->setText(QString(char_arr[1]));
    ui->btn_02->setText(QString(char_arr[2]));
    ui->btn_03->setText(QString(char_arr[3]));
    ui->btn_04->setText(QString(char_arr[4]));
    ui->btn_10->setText(QString(char_arr[5]));
    ui->btn_11->setText(QString(char_arr[6]));
    ui->btn_12->setText(QString(char_arr[7]));
    ui->btn_13->setText(QString(char_arr[8]));
    ui->btn_14->setText(QString(char_arr[9]));
    ui->btn_20->setText(QString(char_arr[10]));
    ui->btn_21->setText(QString(char_arr[11]));
    ui->btn_22->setText(QString(char_arr[12]));
    ui->btn_23->setText(QString(char_arr[13]));
    ui->btn_24->setText(QString(char_arr[14]));
    ui->btn_30->setText(QString(char_arr[15]));
    ui->btn_31->setText(QString(char_arr[16]));
    ui->btn_32->setText(QString(char_arr[17]));
    ui->btn_33->setText(QString(char_arr[18]));
    ui->btn_34->setText(QString(char_arr[19]));
    ui->btn_40->setText(QString(char_arr[20]));
    ui->btn_41->setText(QString(char_arr[21]));
    ui->btn_42->setText(QString(char_arr[22]));
    ui->btn_43->setText(QString(char_arr[23]));
    ui->btn_44->setText(QString(char_arr[24]));
}

void MainWindow::handler_00(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(0,0);
}
void MainWindow::handler_01(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(0,1);
}
void MainWindow::handler_02(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(0,2);
}
void MainWindow::handler_03(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(0,3);
}
void MainWindow::handler_04(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(0,4);
}
void MainWindow::handler_10(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(1,0);
}
void MainWindow::handler_11(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(1,1);
}
void MainWindow::handler_12(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(1,2);
}
void MainWindow::handler_13(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(1,3);
}
void MainWindow::handler_14(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(1,4);
}
void MainWindow::handler_20(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(2,0);
}
void MainWindow::handler_21(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(2,1);
}
void MainWindow::handler_22(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(2,2);
}
void MainWindow::handler_23(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(2,3);
}
void MainWindow::handler_24(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(2,4);
}
void MainWindow::handler_30(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(3,0);
}
void MainWindow::handler_31(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(3,1);
}
void MainWindow::handler_32(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(3,2);
}
void MainWindow::handler_33(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(3,3);
}
void MainWindow::handler_34(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(3,4);
}
void MainWindow::handler_40(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
event_handler(4,0);
}
void MainWindow::handler_41(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(4,1);
}
void MainWindow::handler_42(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(4,2);
}
void MainWindow::handler_43(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
event_handler(4,3);
}
void MainWindow::handler_44(){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setStyleSheet("color: orange");
    event_handler(4,4);
}

