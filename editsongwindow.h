#ifndef EDITSONGWINDOW_H
#define EDITSONGWINDOW_H

#include "database.h"

#include <QMainWindow>

namespace Ui {
class EditSongWindow;
}

class EditSongWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditSongWindow(QWidget *parent = nullptr);
    ~EditSongWindow();

    void setDatabase(Database* database);
    void setAlbumId(int albumId);
    void setSongId(int songId) ;
    void loadSongInfo();

signals:
    void goBack(int albumID , int songID);

private slots:
    void on_selectCoverButton_clicked();

    void on_saveButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::EditSongWindow *ui;
    Database* database;
    int albumId;
    int songId;
    Song editingSong;
    QString newCoverPath;
};

#endif // EDITSONGWINDOW_H
