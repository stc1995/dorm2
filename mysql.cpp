#include "mysql.h"


QStringList list_column = {"id","name","password","building","room","idcard","college","class"};

void MySqlInit(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("123.207.165.95");
    db.setPort(3306);
    db.setDatabaseName("abc");
    db.setUserName("root");
    db.setPassword("IOTkeshe2016");

    if(db.open()){
        qDebug() << "database is established!" ;
    }
    else{
        qDebug() << "build error!" ;
    }
}


bool SqlInsert(QString str){

    QStringList list1 = str.split(",");
    qDebug() << list1;

    QSqlTableModel model;
    model.setTable(list1[0]);
    int row = 0;
    model.insertRows(row,1);
    for(int i = 1; i<list1.size(); i++){
        if(i<=3 || i>=6){
            model.setData(model.index(row,i-1), list1[i]);
        }
        else{
            model.setData(model.index(row,i-1), list1[i].toInt());
        }
    }

    if(model.submitAll()){
        qDebug() << "Successfully Insert!";
        return true;
    }
    else{
        qDebug() << model.lastError();
        return false;
    }
}

bool SqlUpdate(QString str){
    QStringList list1 = str.split(",");
    qDebug() << list1;

    QSqlTableModel model;
    model.setTable(list1[0]);
    model.setFilter("id = " + list1[1]);
    model.select();
    for(int j = 0; j < model.rowCount() ; j++)
    {
        QSqlRecord record = model.record(j);
        for(int i = 2; i<list1.size(); i++){
            if(list1[i] != NULL){
                if(i<=3 || i>=6){
                    record.setValue(list_column[i-1], list1[i]);
                }
                else{
                    record.setValue(list_column[i-1], list1[i].toInt());
                }
            }
        }
        model.setRecord(j, record);
    }

    if(model.submitAll()){
        qDebug() << "Successfully Insert!";
        return true;
    }
    else{
        qDebug() << model.lastError();
        return false;
    }
}

bool SqlDelete(QString str){

    QStringList list1 = str.split(",");
    qDebug() << list1;

    QSqlTableModel model;
    model.setTable(list1[0]);
    model.setFilter("id = \"" + list1[1] + "\"");
    model.setFilter("idcard = \"" + list1[2] + "\"");
    model.select();

    for(int j = 0; j < model.rowCount() ; j++)
    {
            model.removeRow(j);
    }

    if(model.submitAll()){
        qDebug() << "Successfully Delete!";
        return true;
    }
    else{
        qDebug() << model.lastError();
        return false;
    }
}


QString SqlQuery(QString table, QString str, QString column){
    qDebug() << table;

    QSqlTableModel model;
    model.setTable(table);

    qDebug() << str;
    qDebug() << column;
    model.setFilter(str);
    model.select();
    QSqlRecord record = model.record(0);
    QString column_value= record.value(column).toString();
    return column_value;
}




