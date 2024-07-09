#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_cancel_clicked();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGIN_H
