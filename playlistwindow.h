#ifndef PLAYLISTWINDOW_H
#define PLAYLISTWINDOW_H

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

private:
    Ui::PlaylistWindow *ui;
};

#endif // PLAYLISTWINDOW_H
