#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "mainwindow.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_account->text();
    QString password = ui->lineEdit_password->text();

    // 简单的验证逻辑
    if(username == "admin" && password == "1234")
    {
        accept();  // 登录成功，关闭对话框并返回 QDialog::Accepted
    }
    else
    {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password");
    }
}

void LoginDialog::on_pushButton_cancel_clicked()
{
    reject();  // 取消登录，关闭对话框
}
