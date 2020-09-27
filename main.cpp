#include "mainwindow.h"
#include "workerthread.h"
#include <QApplication>
#include <QThread>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    WorkerThread wthread();
//    wthread.w = w.ui;
//    wthread.q = w.queue;
//    wthread.start();
    w.show();
//    wthread.start();
    return a.exec();
}
