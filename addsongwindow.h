#ifndef ADDSONGWINDOW_H
#define ADDSONGWINDOW_H
#include "database.h"

#include <QMediaPlayer>
#include <QMainWindow>

namespace Ui {
class AddSongWindow;
}

class AddSongWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddSongWindow(QWidget *parent = nullptr);
    ~AddSongWindow();

    void setDatabase(Database* database);
    void setAlbumId(int albumId);
signals:
    void goBack(int albumID);
private slots:
    void on_selectFileButton_clicked();

    void on_selectImageButton_clicked();

    void on_saveButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::AddSongWindow *ui;
    Database* database;
    int albumId;
    QString selectedFilePath;
    QMediaPlayer* mediaPlayer;
    Song newSong;
};

#endif // ADDSONGWINDOW_H
