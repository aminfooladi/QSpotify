#ifndef EDITPLAYLISTWINDOW_H
#define EDITPLAYLISTWINDOW_H

#include "database.h"

#include <QListWidgetItem>
#include <QMainWindow>

namespace Ui {
class EditPlaylistWindow;
}

class EditPlaylistWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditPlaylistWindow(QWidget *parent = nullptr);
    ~EditPlaylistWindow();

    void setDatabase(Database* database);
    void setPlaylistId(int playlistId);
    void setPageInfo();

signals:
    void goBack(int playlistID);

private slots:
    void on_availableSongsList_itemDoubleClicked(QListWidgetItem *item);
    void on_saveButton_clicked();
    void on_cancelButton_clicked();
    void onRemoveSong(int row);

private:
    Ui::EditPlaylistWindow *ui;
    Database* database;
    int playlistId;
    Playlist editingPlaylist;
    std::vector<int> selectedSongIds;
    std::vector<Song> allSongs;

    void loadAvailableSongs();
    void loadSongsTable();
    void addSongToPlaylist(int songId);
    void removeSongFromPlaylist(int row);
};

#endif // EDITPLAYLISTWINDOW_H