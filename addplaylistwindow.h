#ifndef ADDPLAYLISTWINDOW_H
#define ADDPLAYLISTWINDOW_H

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

private:
    Ui::AddPlaylistWindow *ui;
};

#endif // ADDPLAYLISTWINDOW_H
