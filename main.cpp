#include "loginwindow.h"
#include "registerwindow.h"
#include "listenerpanel.h"
#include "artistpanel.h"
#include "database.h"
#include "apppagge.h"

#include <QApplication>
using namespace std ;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Database database;
    database.loadDefaultData();

    AppPage page = AppPage::Login;

    LoginWindow login;
    RegisterWindow reg;
    ArtistPanel artist;
    ListenerPanel listener;

    login.setDatabase(&database);
    login.setPtrToPage(&page);

    reg.setDatabase(&database);
    reg.setPtrToPage(&page);

    artist.setDatabase(&database);
    artist.setPtrToPage(&page);

    listener.setDatabase(&database);
    listener.setPtrToPage(&page);

    QObject::connect(&login, &LoginWindow::loginSuccessful, [&]() {

        login.hide();

        switch (page)
        {
        case AppPage::Login:
            login.show();
            break;
        case AppPage::Register:
            reg.show();
            break;
        case AppPage::ArtistPanel:
            artist.show();
            break;
        case AppPage::ListenerPanel:
            listener.show();
            break;
        }
    });

    QObject::connect(&login, &LoginWindow::goToRegisterPage , [&](){
        login.hide();
        reg.show();
    });

    QObject::connect(&reg , &RegisterWindow::goToLoginPage , [&](){
        reg.hide();
        login.show();
    });

    login.show();

    return a.exec();
}