#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QProcess>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    exeThread = new RunScriptThread(ui->lbQThread);
    connect(exeThread, &QThread::finished, [=](){
        qDebug() << "Thread finished";
    });
}

MainWindow::RunScriptThread::RunScriptThread(QLabel* lb)
{
    lbNotification = lb;
}

void MainWindow::RunScriptThread::setText(QString txt)
{
    text = txt;
}

void MainWindow::RunScriptThread::run()
{
    qDebug() << "Thread is running...";

    for(int i = 0; i < 5; i++)
    {
        lbNotification->setText(QString("Process %1").arg(i));
        qDebug() << "Process " << i;
        QProcess* exe = new QProcess();
        exe->start("execute.sh");
        exe->waitForFinished(-1);
        delete(exe);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete exeThread;
}

void MainWindow::on_btRun_clicked()
{
    exeThread->start();
}

