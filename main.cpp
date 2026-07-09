#include "loginwindow.h"

#include <QApplication>
using namespace std ;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
    return QApplication::exec();
}
