#ifndef PLAYLISTWINDOW_H
#define PLAYLISTWINDOW_H

#include "database.h"

#include <QMainWindow>

namespace Ui {
class PlaylistWindow;
}

class PlaylistWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlaylistWindow(QWidget *parent = nullptr);
    ~PlaylistWindow();

    void setDatabase(Database* database) ;
    void setPlaylistId(int playlistID) ;
    void setPageInfo() ;

signals:
    void goBack();
    void goToSongPage(int songID) ;
    void goToEditPlaylistWindow(int playlistID);

private slots:
    void on_backButton_clicked();

    void on_editPlaylistpushButton_clicked();

private:
    Ui::PlaylistWindow *ui;
    Database * database ;
    int playlistID ;
};

#endif // PLAYLISTWINDOW_H