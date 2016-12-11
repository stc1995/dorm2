#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
    static QString id;

private slots:
    void on_user_textChanged(const QString &arg1);

    void on_password_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_ok_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
