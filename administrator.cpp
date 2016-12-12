#include "mysql.h"
#include "administrator.h"
#include "ui_administrator.h"


administrator::administrator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::administrator)
{
    ui->setupUi(this);
    MySqlInit();
}

administrator::~administrator()
{
    delete ui;
}

void administrator::on_pushButton_clicked()//授权
{
    QString id = ui->user->text();
    QString password = ui->password->text();
    QString name = ui->name->text();
    QString building = ui->building->text();
    QString room = ui->room->text();
    QString card = ui->card->text();
    QString college = ui->college->text();
    QString class_2 = ui->class_2->text();

    QString str;
    str.append("student");
    str.append(",").append(id);
    str.append(",").append(name);
    str.append(",").append(password);
    str.append(",").append(building);
    str.append(",").append(room);
    str.append(",").append(card);
    str.append(",").append(college);
    str.append(",").append(class_2);

    qDebug() << str;

    if(SqlInsert(str)){
        qDebug() << "Successfully Insert!";
    }
    else{
        qDebug() << "Unsuccessfully Insert!";
    }

}

void administrator::on_pushButton_2_clicked() //注销
{
    QString id = ui->lineEdit->text();
    QString idcard = ui->lineEdit_2->text();

    QString str;
    str.append("student");
    str.append(",").append(id);
    str.append(",").append(idcard);

    qDebug() << str;

    if(SqlDelete(str)){
        qDebug() << "Successfully delete!";
    }
    else{
        qDebug() << "Unsuccessfully delete!";
    }
}

void administrator::on_pushButton_3_clicked()//修改
{
    QString id = ui->user->text();
    QString password = ui->password->text();
    QString name = ui->name->text();
    QString building = ui->building->text();
    QString room = ui->room->text();
    QString card = ui->card->text();
    QString college = ui->college->text();
    QString class_2 = ui->class_2->text();

    QString str;
    str.append("student");
    str.append(",").append(id);
    str.append(",").append(name);
    str.append(",").append(password);
    str.append(",").append(building);
    str.append(",").append(room);
    str.append(",").append(card);
    str.append(",").append(college);
    str.append(",").append(class_2);

    qDebug() << str;

    if(SqlUpdate(str)){
        qDebug() << "Successfully Update!";
    }
    else{
        qDebug() << "Unsuccessfully Update!";
    }
}



void administrator::on_comboBox_7_currentTextChanged(const QString &arg1) // 左上
{
    if(arg1 == "college"){
        ui->comboBox_5->setCurrentText("major");
        ui->comboBox_8->insertItem(0,"cs");
        ui->comboBox_8->insertItem(1,"info");
        ui->comboBox_8->insertItem(2,"economy");
    }
    else if(arg1 == "building"){
        ui->comboBox_5->setCurrentText("room");
        ui->comboBox_8->insertItem(0,"14");
        ui->comboBox_8->insertItem(1,"15");
        ui->comboBox_8->insertItem(2,"16");
    }
}

void administrator::on_comboBox_5_currentTextChanged(const QString &arg1)  //左下
{
    if(arg1 == "major"){
        if(ui->comboBox_8->currentText() == "cs"){
            ui->comboBox_6->insertItem(0,"cs");
            ui->comboBox_6->insertItem(1,"software");
        }
        else if(ui->comboBox_8->currentText() == "info"){
            ui->comboBox_6->insertItem(0,"commu");
            ui->comboBox_6->insertItem(1,"iot");
        }
        else if(ui->comboBox_7->currentText() == "economy"){
            ui->comboBox_6->insertItem(0,"finance");
            ui->comboBox_6->insertItem(1,"insurance");
        }
    }
    else if(arg1 == "room"){
        if(ui->comboBox_7->currentText() == "14"){
            ui->comboBox_6->insertItem(0,"1401");
            ui->comboBox_6->insertItem(1,"1402");
        }
        else if(ui->comboBox_7->currentText() == "15"){
            ui->comboBox_6->insertItem(0,"1503");
            ui->comboBox_6->insertItem(1,"1504");
        } else if(ui->comboBox_7->currentText() == "16"){
            ui->comboBox_6->insertItem(0,"1605");
            ui->comboBox_6->insertItem(1,"1606");
        }
    }
}

void administrator::on_comboBox_8_currentTextChanged(const QString &arg1)
{
    if(ui->comboBox_5->currentText() == "major"){
        if(arg1 == "cs"){
            ui->comboBox_6->insertItem(0,"cs");
            ui->comboBox_6->insertItem(1,"software");
        }
        else if(arg1 == "info"){
            ui->comboBox_6->insertItem(0,"commu");
            ui->comboBox_6->insertItem(1,"iot");
        } else if(arg1 == "economy"){
            ui->comboBox_6->insertItem(0,"finance");
            ui->comboBox_6->insertItem(1,"insurance");
        }
    }
    else if(ui->comboBox_5->currentText() == "room"){
         qDebug() << "room";
        if(arg1 == "14"){
             qDebug() << "14";
            ui->comboBox_6->insertItem(0,"1401");
            ui->comboBox_6->insertItem(1,"1402");
        }
        else if(arg1 == "15"){
            ui->comboBox_6->insertItem(0,"1503");
            ui->comboBox_6->insertItem(1,"1504");
        } else if(arg1 == "16"){
            ui->comboBox_6->insertItem(0,"1605");
            ui->comboBox_6->insertItem(1,"1606");
        }
    }
}

void administrator::on_pushButton_5_clicked()  //右下查询
{

    QString start = ui->dateEdit_3->text();
    QString end = ui->dateEdit_4->text();

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

    QString str_7;
    QString str_5;
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("history");
    if(ui->comboBox_7->currentText() == "college"){
        str_7 = " and college = \"" + ui->comboBox_8->currentText() + "\"";
        if(ui->comboBox_5->currentText() == "major"){
            str_5 = " and major = \"" + ui->comboBox_6->currentText() + "\"";
        }
    }else if(ui->comboBox_7->currentText() == "building"){
        str_7 = " and building = " + ui->comboBox_8->currentText();
        if(ui->comboBox_5->currentText() == "room"){
             str_5 = " and room = " + ui->comboBox_6->currentText();
        }
    }

    if(ui->comboBox_8->currentText() == ""){
        str_7 = "";
    }
    if(ui->comboBox_6->currentText() == ""){
        str_5 = "";
    }

    model->setFilter(" date > "+ start1 + " and " + " date < " + end1 +  str_7 +  str_5);
    qDebug() << " date > "+ start1 + " and " + " date < " + end1 + str_7 + str_5;
    model->select();
    qDebug() << model->lastError();
    ui->tableView->setModel(model);
    ui->tableView->show();

}


void administrator::on_pushButton_4_clicked()
{
    QString file_full, file_name, file_path;
    QFileInfo fi;
    file_full = QFileDialog::getOpenFileName(this);
    fi = QFileInfo(file_full);
    file_name = fi.fileName();
    file_path = fi.absolutePath();
    qDebug() << file_path+"/"+file_name;

    //读取csv数据到数据表
    QFile file(file_path+"/"+file_name); //打开csv文件
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
        qDebug() << "cvs failure!";
//          std::cerr << "Cannot open file for reading: "
//                    << qPrintable(file.errorString()) << std::endl;
     }
    else{
        qDebug() << "cvs ok!";
    }

    //将csv_utf8转为数据库中的表District保存
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("123.207.165.95");
    db.setPort(3306);
    db.setDatabaseName("abc");
    db.setUserName("root");
    db.setPassword("IOTkeshe2016");

    if(!db.open())
    {
        QMessageBox::critical(0 , "Can not open database",
                              "Unable to establish a database connection.",QMessageBox::Cancel);
        qDebug() << "db failure!";
//        std::cerr<<"stop!";
    }
    else{
        qDebug() << "db ok!";
    }

    QStringList list;
    list.clear();
    QTextStream in(&file);  //QTextStream读取数据

    QSqlQuery query;  //默认打开
//    query.exec("select * from abc.student where id = 66666");

//    while(query.next()){
//        QString str = query.value(0).toString() ;
//        for(int i = 1 ; i < 12; i++){
//            str.append(",").append(query.value(i).toString());
//        }
//        qDebug() << str;
//    }

    while(!in.atEnd())
    {
       QString fileLine = in.readLine();  //从第一行读取至下一行
       list = fileLine.split(",");  // , QString::SkipEmptyParts
       qDebug() << list;

       query.prepare("INSERT INTO student (id,name,password,building,room,idcard,college,class,sex,date,time,admin)"
                     " VALUES (:id,:name,:password,:building,:room,:idcard,:college,:class,:sex,:date,:time,:admin)"); //准备执行SQL查询
       query.bindValue(":id", list.at(0));   //绑定要插入的值
       query.bindValue(":name", list.at(1));
       query.bindValue(":password", list.at(2));
       query.bindValue(":building", list.at(3).toInt());
       query.bindValue(":room", list.at(4).toInt());
       query.bindValue(":idcard", list.at(5));
       query.bindValue(":college", list.at(6));
       query.bindValue(":class", list.at(7));
       query.bindValue(":sex", list.at(8).toInt());
       query.bindValue(":admin", list.at(9));

       query.exec();
       db.commit();
       qDebug() << query.lastError();
    }

}

void administrator::on_pushButton_6_clicked()
{
    QString file_full, file_name, file_path;
    QFileInfo fi;
    file_full = QFileDialog::getOpenFileName(this);
    fi = QFileInfo(file_full);
    file_name = fi.fileName();
    file_path = fi.absolutePath();
    qDebug() << file_path+"/"+file_name;

    //读取csv数据到数据表
    QFile file(file_path+"/"+file_name); //打开csv文件
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
        qDebug() << "cvs failure!";
//          std::cerr << "Cannot open file for reading: "
//                    << qPrintable(file.errorString()) << std::endl;
     }
    else{
        qDebug() << "cvs ok!";
    }

    //将csv_utf8转为数据库中的表District保存
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("123.207.165.95");
    db.setPort(3306);
    db.setDatabaseName("abc");
    db.setUserName("root");
    db.setPassword("IOTkeshe2016");

    if(!db.open())
    {
        QMessageBox::critical(0 , "Can not open database",
                              "Unable to establish a database connection.",QMessageBox::Cancel);
        qDebug() << "db failure!";
//        std::cerr<<"stop!";
    }
    else{
        qDebug() << "db ok!";
    }

    QStringList list;
    list.clear();
    QTextStream in(&file);  //QTextStream读取数据

    QSqlQuery query;  //默认打开
//    query.exec("select * from abc.student where id = 66666");

//    while(query.next()){
//        QString str = query.value(0).toString() ;
//        for(int i = 1 ; i < 12; i++){
//            str.append(",").append(query.value(i).toString());
//        }
//        qDebug() << str;
//    }

    while(!in.atEnd())
    {
       QString fileLine = in.readLine();  //从第一行读取至下一行
       list = fileLine.split(",");  // , QString::SkipEmptyParts
       qDebug() << list;

       query.prepare("DELETE FROM abc.student WHERE id = " + list.at(0)); //准备执行SQL查询

       query.exec();
       db.commit();
       qDebug() << query.lastError();
    }
}
