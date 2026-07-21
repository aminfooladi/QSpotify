#ifndef ARTISTPANEL_H
#define ARTISTPANEL_H

#include "database.h"
#include "apppagge.h"

#include <QMainWindow>
#include <QListWidgetItem>
#include <QListWidget>

namespace Ui {
class ArtistPanel;
}

class ArtistPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ArtistPanel(QWidget *parent = nullptr);
    ~ArtistPanel();

    void setDatabase(Database* database) ;
    void setPtrToPage(AppPage* page) ;
    void setAccountInfo() ;
    void lodeAlbums() ;
    void lodeSingles();
    void lodePlaylists();
    void loadMyAlbums();
    void loadMySingles();

signals:
    void goToLoginPage() ;
    void goToAlbumPage(int albumId);
    void goToSongPage(int songId);
    void goToAddAlbum();
    void goToAddSong() ;
    void goToAddPlaylist();
    void goToPlaylistPage(int playlistId);

private slots:
    void on_editInfoButton_clicked();

    void on_Cancel_clicked();

    void on_logoutButton_clicked();

    void on_OK_clicked();

    void on_deleteAccountButton_clicked();

    void on_myAlbumsListWidget_itemClicked(QListWidgetItem *item);

    void on_playlistsListWidget_itemClicked(QListWidgetItem *item);

    void on_albumListWidget_itemClicked(QListWidgetItem *item);

    void on_singlesListWidget_itemClicked(QListWidgetItem *item);

    void on_mySinglesListWidget_itemClicked(QListWidgetItem *item);

    void on_plaaylistRadioButton_clicked();

    void on_albumRadioButton_clicked();

    void on_songRadioButton_clicked();

    void on_searchLineEdit_textChanged(const QString &arg1);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Database * database ;
    AppPage * page ;
    Ui::ArtistPanel *ui;
};

#endif // ARTISTPANEL_H
