#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include "mainwindow.h"
#include <QtCore>


class WorkerThread : public QThread
{
    Q_OBJECT

    public:
        void run();
//        Ui::MainWindow *w;
        QPushButton *q;
};

#endif // WORKERTHREAD_H
