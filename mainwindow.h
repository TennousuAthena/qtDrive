#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateTime();
    void on_pushButton_sos_clicked();
    void updateTimers();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTime workRemain;
    QTime totalWork;
    QTime totalRest;
    QTime currentRest;
    QTime nextRest;

    void startTimers();
};

#endif // MAINWINDOW_H
