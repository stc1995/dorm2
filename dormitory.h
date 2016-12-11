#ifndef DORMITORY_H
#define DORMITORY_H

#include <QMainWindow>

namespace Ui {
class dormitory;
}

class dormitory : public QMainWindow
{
    Q_OBJECT

public:
    explicit dormitory(QWidget *parent = 0);
    ~dormitory();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dormitory *ui;
};

#endif // DORMITORY_H
