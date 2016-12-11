#include "login.h"
#include "dormitory.h"
#include "administrator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
//    dormitory d;
//    administrator ad;
//    w.show();
//    d.show();
//    ad.show();
        if(w.exec() == QDialog::Accepted){

            if (login::id == "000000")
            {
                administrator ad;
                ad.show();//只能给模态（Qdialog，弹出就不能跳过，只能先选完）和application
                a.exec();
            }
            else
            {
               dormitory d; //主界面
               d.show();
               a.exec();
            }
        }
        else{

        }
        return 0;
//    w.show();
//    return a.exec();
}
