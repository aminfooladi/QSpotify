#ifndef EDITALBUMWINDOW_H
#define EDITALBUMWINDOW_H

#include "database.h"

#include <QMainWindow>

namespace Ui {
class EditAlbumWindow;
}

class EditAlbumWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditAlbumWindow(QWidget *parent = nullptr);
    ~EditAlbumWindow();

    void setDatabase(Database* database);
    void setAlbumId(int albumId);
    void loadAlbumInfo();

signals:
    void goBack(int albumID);
    void albumUpdated(int albumID);
    void goToPanel();

private slots:
    void on_selectCoverButton_clicked();

    void on_saveButton_clicked();

    void on_cancelButton_clicked();

    void on_deleteAlbumPushButton_clicked();

private:
    Ui::EditAlbumWindow *ui;
    Database* database;
    int albumId;
    Album editingAlbum;
    QString newCoverPath;

};

#endif // EDITALBUMWINDOW_H
