#include "dormitory.h"
#include "login.h"
#include "administrator.h"
#include "ui_login.h"
#include "mysql.h"
#include "QMessageBox.h"

QString login::id = "";

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    MySqlInit();
}

login::~login()
{
    delete ui;
}

void login::on_user_textChanged(const QString &arg1)
{
    if(!QString(ui->password->text()).isEmpty()){
        ui->ok->setEnabled(!arg1.isEmpty());
    }
    else
    {
        ui->ok->setDisabled(true);
    }
}

void login::on_password_textChanged(const QString &arg1)
{
    if(!QString(ui->user->text()).isEmpty()){
        ui->ok->setEnabled(!arg1.isEmpty());
    }
    else
    {
        ui->ok->setDisabled(true);
    }
}

void login::on_pushButton_2_clicked()
{
    close();
}

void login::on_ok_clicked()
{
//    login *a=new login;
//    a->show();
    login::id = ui->user->text();
    QString password = ui->password->text();

    QString str = QString("id = " + id);
    qDebug() << str;
    QString pwd = SqlQuery("student", str, "password");
    qDebug() << pwd;
    if(pwd!=NULL && pwd==password || id == "000000" && password == "000000"){

//        if (login::id == "000000")
//            {
//                administrator m;
//                m.exec();//只能给模态（Qdialog，弹出就不能跳过，只能先选完）和application
//            }
//        else
//            {
//               dormitory w; //主界面
//               w.exec();
//           }
        login::id = ui->user->text();
        accept();
    }
    else{
        QMessageBox::warning(this, tr("Warning"), tr("Incorrect username or password!"), QMessageBox::Yes, QMessageBox::Yes);
        this->ui->user->clear();
        this->ui->password->clear();
        this->ui->user->setFocus();
    }
}
