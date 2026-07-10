#include "loginwindow.h"
#include "database.h"

#include <QApplication>
using namespace std ;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Database database ;
    database.loadDefaultData();

    LoginWindow w;
    w.setDatabase(&database);
    w.show();

    return QApplication::exec();
}
