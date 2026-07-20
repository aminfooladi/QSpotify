#ifndef EDITPLAYLISTWINDOW_H
#define EDITPLAYLISTWINDOW_H

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

private:
    Ui::EditPlaylistWindow *ui;
};

#endif // EDITPLAYLISTWINDOW_H
