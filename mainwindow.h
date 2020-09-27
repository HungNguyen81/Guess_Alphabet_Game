#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include "workerthread.h"
//#include <QQueue>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        Ui::MainWindow *ui;
        void initBtnArray();
        QTimer *timer;
        void func();
        QPushButton *queue;
        QThread *wthread;
        QPushButton ComBtn;


    public slots:
//        void event_handler();
//        void ArrangeBtn();
        void handler_00();
        void handler_01();
        void handler_02();
        void handler_03();
        void handler_04();
        void handler_10();
        void handler_11();
        void handler_12();
        void handler_13();
        void handler_14();
        void handler_20();
        void handler_21();
        void handler_22();
        void handler_23();
        void handler_24();
        void handler_30();
        void handler_31();
        void handler_32();
        void handler_33();
        void handler_34();
        void handler_40();
        void handler_41();
        void handler_42();
        void handler_43();
        void handler_44();
        void changeColor();
        void onTimerChanged(int);

    signals:
        void colorChanged();
    private:
        QPushButton *btn_arr[5][5];
        char char_arr[26];
        int i, k, j;
        void event_handler(int, int);
        void connHandler();



};
#endif // MAINWINDOW_H
