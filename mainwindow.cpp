#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    score = 0;          // Điểm ban đầu của người chơi là 0
    isStart = false;    // Biến isStart để kiểm tra trạng thái Started của game

//    ui->lbl_score->setNum(score);  // Dòng này gây ra crash
//    initBtnArray();     // Khởi tạo mảng các button, mảng này không dùng đến
    k = 0; i =0; j = 0;
    for(int i = 0; i < 26; i++){
        char_arr[(i+6)%26] = char(i+97);
    }

    ui->setupUi(this);
    connect(ui->btn_start, SIGNAL(clicked()), this, SLOT(startGame()));
    func();             // gán text cho buttons
    connHandler();      // kết nối tất cả buttons với slots tương ứng

    srand((int) time(0));
    int ran = rand()%25;
    ComBtn.setText(QString(char_arr[ran]));
    ui->lbl_com->setNum(int(char_arr[ran])-96);   // Lấy kí tự ngẫu nhiên từ mảng
                                                  // và chuyển sang mã ASCII (số nguyên)
}
MainWindow::~MainWindow()
{
    delete ui;   // Trả lại bộ nhớ đã cấp cho chương trình
}

void MainWindow::startGame(){
    t = 60;             // thời gian đếm ngược (giây), sau mỗi 1000ms timer gửi tín hiệu 1 lần,
                        // ta sẽ xử lí tín hiệu này để giảm t đi 1 đến khi t < 0 thì dừng timer
                        // t < 0 là vì t = 0 thì màn LCD_TIMER vẫn chưa in ra t.
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerChanged()));
    timer->start(1000);                 // Bắt đầu gửi tín hiệu tới SLOT sau mỗi 1000ms
}

void MainWindow::onTimerChanged(){      // SLOT nhận tín hiệu từ Timer
    ui->lcd_timer->display(t);
    t--;
    if(t < 0) {
        timer->stop();                  // Dừng timer khi thời gian đếm ngược = 0
        isStart = false;                // Trạng thái đang chơi của game đặt về False
    }
    else isStart = true;                // isStart được kiểm tra mỗi khi nhấn phím btn_##
}

void MainWindow::shuffle_arr(){         // Trộn các kí tự trong mảng char_arr
    std::random_shuffle(std::begin(char_arr), std::end(char_arr));
    func();                             //set text cho buttons sau mỗi lần trộn mảng
}

void MainWindow::executing(QPushButton *btn){
    if(QString::compare(btn->text(),ComBtn.text()) == 0){
        score += 5;
        srand((int) time(0));
        int r = rand()%25;
        shuffle_arr();
        ComBtn.setText(QString(char_arr[r]));
        ui->lbl_com->setNum((int(char_arr[r])) - 96);  // gợi ý người chơi STT của chữ cái
                                                       // cần đoán trong bảng chữ cái
    }
    ui->lbl_score->setNum(score);
}

//-------------------CÁC HÀM XỬ LÍ TÍN HIỆU NHẬN ĐƯỢC TỪ PUSH-BUTTON-----------------
void MainWindow::handler_00(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_01(){ // Mới chỉ xử lý sự kiện tính điểm cho btn_01
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_02(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_03(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_04(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_10(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_11(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_12(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_13(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_14(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_20(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_21(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_22(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_23(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_24(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_30(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_31(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_32(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_33(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_34(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_40(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_41(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_42(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_43(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
void MainWindow::handler_44(){
    if(isStart){
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        btn->setStyleSheet("QPushButton::focus{color: orange;}");
        executing(btn);
    }
}
//-----------------------------------------------------------------------------------
//void MainWindow::initBtnArray(){
//    btn_arr[0][0] = ui->btn_00; //1
//    btn_arr[0][1] = ui->btn_01;
//    btn_arr[0][2] = ui->btn_02;
//    btn_arr[0][3] = ui->btn_03;
//    btn_arr[0][4] = ui->btn_04;
//    btn_arr[1][0] = ui->btn_00;
//    btn_arr[1][1] = ui->btn_01;
//    btn_arr[1][2] = ui->btn_02;
//    btn_arr[1][3] = ui->btn_03;
//    btn_arr[1][4] = ui->btn_04;
//    btn_arr[2][0] = ui->btn_00;
//    btn_arr[2][1] = ui->btn_01;
//    btn_arr[2][2] = ui->btn_02;
//    btn_arr[2][3] = ui->btn_03;
//    btn_arr[2][4] = ui->btn_04;
//    btn_arr[3][0] = ui->btn_00;
//    btn_arr[3][1] = ui->btn_01;
//    btn_arr[3][2] = ui->btn_02;
//    btn_arr[3][3] = ui->btn_03;
//    btn_arr[3][4] = ui->btn_04;
//    btn_arr[4][0] = ui->btn_00;
//    btn_arr[4][1] = ui->btn_01;
//    btn_arr[4][2] = ui->btn_02;
//    btn_arr[4][3] = ui->btn_03;
//    btn_arr[4][4] = ui->btn_04; //25
//}


//---------- HÀM TẠO KẾT NỐI GIỮA PUSH-BUTTON VÀ HÀM XỬ LÍ (slot) TƯƠNG ỨNG-------------
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

//-------------------HÀM HIỂN THỊ TEXT CỦA CÁC PUSH-BUTTON---------------------------
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

