#include "loginwindow.h"
#include "database.h"

#include <QApplication>
using namespace std ;

enum class AppPage
{
    Login,
    Register,
    ArtistPanel,
    ListenerPanel
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Database database ;
    database.loadDefaultData();

    AppPage page = AppPage::Login ;
    switch (page)
    {
    case AppPage::Login:
    {
        LoginWindow login ;
        login.setDatabase(&database);
        login.show();
        break;
    }
    case AppPage::Register:
    {

    }
    default:
        break;
    }

    return QApplication::exec();
}
