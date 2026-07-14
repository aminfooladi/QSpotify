#include "loginwindow.h"
#include "registerwindow.h"
#include "listenerpanel.h"
#include "artistpanel.h"
#include "database.h"
#include "apppagge.h"
#include "addsongwindow.h"
#include "albumwindow.h"

#include <QApplication>
#include <QIcon>
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
    AddSongWindow addSong;

    AlbumWindow *albumWindow = new AlbumWindow();

    login.setDatabase(&database);
    login.setPtrToPage(&page);

    reg.setDatabase(&database);
    reg.setPtrToPage(&page);

    artist.setDatabase(&database);
    artist.setPtrToPage(&page);

    listener.setDatabase(&database);
    listener.setPtrToPage(&page);

    albumWindow->setDatabase(&database);
    albumWindow->setPtrToPage(&page);

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
            artist.setAccountInfo();
            artist.show();
            break;
        case AppPage::ListenerPanel:
            listener.setAccountInfo();
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

    QObject::connect(&listener , &ListenerPanel::goToLoginPage , [&](){
        listener.hide();
        login.show();
    });

    QObject::connect(&artist , &ArtistPanel::goToLoginPage , [&](){
        artist.hide();
        login.show();
    });

    QObject::connect(&artist , &ArtistPanel::goToAlbumPage , [&](int albumID){
        artist.hide();
        albumWindow->setAlbumId(albumID);
        albumWindow->setAccountInfo();
        albumWindow->show();
    });

    QObject::connect(&listener , &ListenerPanel::goToAlbumPage , [&](int albumID){
        artist.hide();
        albumWindow->setAlbumId(albumID);
        albumWindow->setAccountInfo();
        albumWindow->show();
    });

    QObject::connect(albumWindow , &AlbumWindow::goBack , [&](){
        albumWindow->hide();

        switch (page)
        {
        case AppPage::Login:
            login.show();
            break;
        case AppPage::Register:
            reg.show();
            break;
        case AppPage::ArtistPanel:
            artist.setAccountInfo();
            artist.show();
            break;
        case AppPage::ListenerPanel:
            listener.setAccountInfo();
            listener.show();
            break;
        }
    });

    login.show();

    return a.exec();
}