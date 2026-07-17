#ifndef EDITALBUMWINDOW_H
#define EDITALBUMWINDOW_H

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

private:
    Ui::EditAlbumWindow *ui;
};

#endif // EDITALBUMWINDOW_H
