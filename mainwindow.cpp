#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer(this))
    , workRemain(QTime(8, 0))
    , totalWork(QTime(2, 0))
    , totalRest(QTime(0, 0))
    , currentRest(QTime(1, 0))
    , nextRest(QTime(11, 10))
{
    ui->setupUi(this);

    // 初始化定时器，每秒更新一次时间和倒计时
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimers);
    timer->start(1000);

    // 设置初始时间
    updateTime();
    startTimers();

    // 连接 SOS 按钮点击事件
    connect(ui->pushButton_sos, &QPushButton::clicked, this, &MainWindow::on_pushButton_sos_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    QString timeString = currentTime.toString("hh:mm:ss");
    ui->label_time->setText(timeString);
}

void MainWindow::updateTimers()
{
    // 更新倒计时时间
    workRemain = workRemain.addSecs(-1);
    totalWork = totalWork.addSecs(-1);
    currentRest = currentRest.addSecs(-1);

    // 更新标签显示
    ui->label_work_remain_time->setText(workRemain.toString("hh:mm:ss"));
    ui->label_total_work_time->setText(totalWork.toString("hh:mm:ss"));
    ui->label_current_rest_time->setText(currentRest.toString("hh:mm:ss"));

}

void MainWindow::on_pushButton_sos_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("SOS");
    msgBox.setText("SOS信息已发送");
    msgBox.setStyleSheet("QLabel{ color: black; }");
    msgBox.exec();
}

void MainWindow::startTimers()
{
    ui->label_work_remain_time->setText(workRemain.toString("hh:mm:ss"));
    ui->label_total_work_time->setText(totalWork.toString("hh:mm:ss"));
    ui->label_current_rest_time->setText(currentRest.toString("hh:mm:ss"));
    ui->label_next_rest_time->setText(nextRest.toString("hh:mm:ss"));
    ui->label_last_rest_time->setText("10:10"); // 假设这是一个静态时间
}
