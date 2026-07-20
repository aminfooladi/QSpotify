#include "loginwindow.h"
#include "registerwindow.h"
#include "listenerpanel.h"
#include "artistpanel.h"
#include "database.h"
#include "apppagge.h"
#include "addsongwindow.h"
#include "albumwindow.h"
#include "songwindow.h"
#include"addalbum.h"
#include "editalbumwindow.h"
#include "editsongwindow.h"
#include "addplaylistwindow.h"
#include "playlistwindow.h"
#include "editplaylistwindow.h"


#include <QApplication>
#include <QIcon>
using namespace std ;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Database database;
    database.loadAll();

    AppPage page = AppPage::Login;

    LoginWindow login;
    RegisterWindow reg;
    ArtistPanel artist;
    ListenerPanel listener;
    AddSongWindow addSong;
    AddAlbum addAlbum;
    AddPlaylistWindow addPlaylist ;
    EditAlbumWindow* editAlbum = new EditAlbumWindow ;
    EditSongWindow * editSong = new EditSongWindow ;
    EditPlaylistWindow * editPlaylist = new EditPlaylistWindow ;
    AlbumWindow *albumWindow = new AlbumWindow;
    SongWindow *songWindow = new SongWindow ;
    PlaylistWindow* playlistWindow = new PlaylistWindow;

    login.setDatabase(&database);
    login.setPtrToPage(&page);

    reg.setDatabase(&database);
    reg.setPtrToPage(&page);

    artist.setDatabase(&database);
    artist.setPtrToPage(&page);

    listener.setDatabase(&database);
    listener.setPtrToPage(&page);

    addAlbum.setDatabase(&database);
    addAlbum.setPtrToPage(&page);

    addPlaylist.setDatabase(&database);

    albumWindow->setDatabase(&database);
    albumWindow->setPtrToPage(&page);

    songWindow->setDatabase(&database);
    songWindow->setPtrToPage(&page);

    playlistWindow->setDatabase(&database);

    editAlbum->setDatabase(&database);

    editSong->setDatabase(&database);

    editPlaylist->setDatabase(&database);

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
        albumWindow->setPsgeInfo();
        albumWindow->show();
    });

    QObject::connect(&listener , &ListenerPanel::goToAlbumPage , [&](int albumID){
        artist.hide();
        albumWindow->setAlbumId(albumID);
        albumWindow->setPsgeInfo();
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

    QObject::connect(&artist, &ArtistPanel::goToSongPage, [&](int songID){
        artist.hide();
        songWindow->setSongId(songID);
        songWindow->setPageInfo();
        songWindow->show();
    });

    QObject::connect(&listener, &ListenerPanel::goToSongPage, [&](int songID){
        artist.hide();
        songWindow->setSongId(songID);
        songWindow->setPageInfo();
        songWindow->show();
    });

    QObject::connect(songWindow , &SongWindow::goBack , [&](){
        songWindow->hide();

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

    QObject::connect(albumWindow , &AlbumWindow::goToSongPage , [&](int songID){
        albumWindow->hide();
        songWindow->setSongId(songID);
        songWindow->setPageInfo();
        songWindow->show();
    });

    QObject::connect(&artist , &ArtistPanel::goToAddAlbum , [&](){
        artist.hide();
        addAlbum.setPageInfo();
        addAlbum.show();
    });

    QObject::connect(&addAlbum , &AddAlbum::goToArtistPanel , [&](){
        addAlbum.hide();
        artist.setAccountInfo();
        artist.show();
    });

    QObject::connect(albumWindow , &AlbumWindow::goToAddSong , [&](int albumID){
        albumWindow->hide();
        addSong.setAlbumId(albumID);
        addSong.setDatabase(&database);
        addSong.show();
    });

    QObject::connect(&artist , &ArtistPanel::goToAddSong , [&](){
        albumWindow->hide();
        addSong.setAlbumId(0);
        addSong.setDatabase(&database);
        addSong.show();
    });

    QObject::connect(&addSong , &AddSongWindow::goBack , [&](int albumID){
        addSong.hide();

        if(albumID==0)
        {
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
        }
        else
        {
            albumWindow->setAlbumId(albumID);
            albumWindow->setPsgeInfo();
            albumWindow->show();
        }
    });

    QObject::connect(albumWindow , &AlbumWindow::goToEditAlbumWindow , [&](int albumID){
        albumWindow->hide();
        editAlbum->setAlbumId(albumID);
        editAlbum->loadAlbumInfo();
        editAlbum->show();
    });

    QObject::connect(editAlbum , &EditAlbumWindow::albumUpdated , [&](int albumID){
        editAlbum->hide();
        albumWindow->setAlbumId(albumID);
        albumWindow->setPsgeInfo();
        albumWindow->show();
    });

    QObject::connect(editAlbum , &EditAlbumWindow::goBack , [&](int albumID){
        editAlbum->hide();
        albumWindow->setAlbumId(albumID);
        albumWindow->setPsgeInfo();
        albumWindow->show();
    });

    QObject::connect(editSong , &EditSongWindow::goBack , [&](int albumID , int songID){
        editSong->hide();

        if(albumID==0)
        {
            songWindow->setSongId(songID);
            songWindow->setPageInfo();
            songWindow->show();
        }
        else
        {
            albumWindow->setAlbumId(albumID);
            albumWindow->setPsgeInfo();
            albumWindow->show();
        }
    });

    QObject::connect(songWindow , &SongWindow::gotoEditSong , [&](int songID){
        songWindow->hide();
        editSong->setSongId(songID);
        editSong->loadSongInfo();
        editSong->show();
    });

    QObject::connect(albumWindow , &AlbumWindow::goToEditSong , [&](int songID){
        albumWindow->hide();
        editSong->setSongId(songID);
        editSong->loadSongInfo();
        editSong->show();
    });

    QObject::connect(&listener , &ListenerPanel::goToPlaylistPage , [&](int playlistID){
        listener.hide();
        playlistWindow->setPlaylistId(playlistID);
        playlistWindow->setPageInfo();
        playlistWindow->show();
    });

    QObject::connect(&artist , &ArtistPanel::goToPlaylistPage , [&](int playlistID){
        listener.hide();
        playlistWindow->setPlaylistId(playlistID);
        playlistWindow->setPageInfo();
        playlistWindow->show();
    });

    QObject::connect(playlistWindow , &PlaylistWindow::goBack , [&](){
        playlistWindow->hide();

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

    QObject::connect(playlistWindow , &PlaylistWindow::goToEditPlaylistWindow , [&](int playlistID){
        playlistWindow->hide();
        editPlaylist->setPlaylistId(playlistID);
        editPlaylist->setPageInfo();
        editPlaylist->show();
    });

    QObject::connect(playlistWindow , &PlaylistWindow::goToSongPage , [&](int songID){
        playlistWindow->hide();
        songWindow->setSongId(songID);
        songWindow->setPageInfo();
        songWindow->show();
    });

    QObject::connect(editPlaylist , &EditPlaylistWindow::goBack , [&](int playlistID){
        editPlaylist->hide();
        playlistWindow->setPlaylistId(playlistID);
        playlistWindow->setPageInfo();
        playlistWindow->show();
    });

    QObject::connect(&artist , &ArtistPanel::goToAddPlaylist , [&](){
        artist.hide();
        addPlaylist.setDatabase(&database);
        addPlaylist.setPageInfo();
        addPlaylist.show();
    });

    QObject::connect(&listener , &ListenerPanel::goToAddPlaylist , [&](){
        listener.hide();
        addPlaylist.setDatabase(&database);
        addPlaylist.setPageInfo();
        addPlaylist.show();
    });

    QObject::connect(&addPlaylist , &AddPlaylistWindow::goBack , [&](){
        addPlaylist.hide();

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