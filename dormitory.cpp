#include "dormitory.h"
#include "ui_dormitory.h"
#include <mysql.h>
#include <login.h>

dormitory::dormitory(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dormitory)
{
    ui->setupUi(this);
    MySqlInit();
    QString id = SqlQuery("student", "id="+login::id , "id");
    ui->id->setText(id);
    QString name = SqlQuery("student", "id="+login::id , "name");
    ui->name->setText(name);
    QString building = SqlQuery("student", "id="+login::id , "building");
    ui->building->setText(building);
    QString room = SqlQuery("student", "id="+login::id , "room");
    ui->room->setText(room);
}

dormitory::~dormitory()
{
    delete ui;
}

void dormitory::on_pushButton_clicked()
{

    QString start = ui->dateEdit->text();
    QString end = ui->dateEdit_2->text();

    QStringList list_s = start.split("/");
    for(int i = 1; i<list_s.size(); i++){
        if(list_s[i].size()==1)
            list_s[i].prepend("0");
    }
    QString start1 = list_s[0];
    for(int i = 1; i<list_s.size(); i++){
        start1.append("-").append(list_s[i]);
    }

    QStringList list_e = end.split("/");
    for(int i = 1; i<list_e.size(); i++){
        if(list_e[i].size()==1)
            list_e[i].prepend("0");
    }
    QString end1 = list_e[0];
    for(int i = 1; i<list_e.size(); i++){
        end1.append("-").append(list_e[i]);
    }
    start1.prepend("\"").append("\"");
    end1.prepend("\"").append("\"");

    qDebug() << start1;
    qDebug() << end1;

    QSqlTableModel *model = new QSqlTableModel; // 摘抄自帮助文档
    model->setTable("history");
    model->setFilter( "date > "+ start1 + " and " + " date < " + end1 + " and " + " id = " + ui->id->text());
    qDebug() << "date > "+ start1 + " and " + " date < " + end1 + " and " + " id = " + ui->id->text();

    model->select();
    qDebug() << model->lastError();
    ui->tableView->setModel(model);
    ui->tableView->show();

//    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//    QSqlRecord record = model2.record(0);
//    QString column_value= record.value("date").toString();

    //    QTableView *view = new QTableView;
    //    view->setModel(model);
    //    view->show();
}
