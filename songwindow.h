#ifndef SONGWINDOW_H
#define SONGWINDOW_H

#include <QMainWindow>

namespace Ui {
class SongWindow;
}

class SongWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SongWindow(QWidget *parent = nullptr);
    ~SongWindow();

private:
    Ui::SongWindow *ui;
};

#endif // SONGWINDOW_H
