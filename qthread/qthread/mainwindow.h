#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QThread>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    class RunScriptThread: public QThread
    {
    private:
        QLabel* lbNotification;
        QString text;
    public:
        RunScriptThread(QLabel* lb);
        void setText(QString txt);
        void run();
    };

private slots:
    void on_btRun_clicked();

private:
    Ui::MainWindow *ui;
    RunScriptThread* exeThread;
};
#endif // MAINWINDOW_H
