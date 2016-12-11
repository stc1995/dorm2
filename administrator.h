#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QMainWindow>

namespace Ui {
class administrator;
}

class administrator : public QMainWindow
{
    Q_OBJECT

public:
    explicit administrator(QWidget *parent = 0);
    ~administrator();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_7_currentTextChanged(const QString &arg1);

    void on_comboBox_5_currentTextChanged(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_comboBox_8_currentTextChanged(const QString &arg1);

private:
    Ui::administrator *ui;
};

#endif // ADMINISTRATOR_H
