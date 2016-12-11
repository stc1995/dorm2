#ifndef MYSQL_H
#define MYSQL_H

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

void MySqlInit();
bool SqlInsert(QString str);
bool SqlUpdate(QString str);
bool SqlDelete(QString str);
QString SqlQuery(QString table, QString str, QString column);

#endif // MYSQL_H
