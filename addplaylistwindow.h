#ifndef ADDPLAYLISTWINDOW_H
#define ADDPLAYLISTWINDOW_H

#include "database.h"

#include <QListWidgetItem>
#include <QMainWindow>

namespace Ui {
class AddPlaylistWindow;
}

class AddPlaylistWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddPlaylistWindow(QWidget *parent = nullptr);
    ~AddPlaylistWindow();

    void setDatabase(Database* database);
    void setPageInfo();
    void setPageInfo(std::vector<int> selectedSongIds , Playlist playlist);

signals:
    void goBack();

private slots:
    void on_availableSongsList_itemDoubleClicked(QListWidgetItem *item);
    void on_saveButton_clicked();
    void on_cancelButton_clicked();
    void onRemoveSong(int row);
    void loadAvailableSongs();
    void loadSongsTable();
    void addSongToPlaylist(int songId);
    void removeSongFromPlaylist(int row);

private:
    Ui::AddPlaylistWindow *ui;
    Database* database;
    Playlist newPlaylist;
    std::vector<int> selectedSongIds;
    std::vector<Song> allSongs;

};

#endif