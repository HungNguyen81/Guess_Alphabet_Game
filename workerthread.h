#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include "mainwindow.h"

class WorkerThread
{
    public:
        WorkerThread();
        void run();
        MainWindow *w;
};

#endif // WORKERTHREAD_H
