#ifndef ALLBUMWINDOW_H
#define ALLBUMWINDOW_H

#include <QMainWindow>

namespace Ui {
class AllbumWindow;
}

class AllbumWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AllbumWindow(QWidget *parent = nullptr);
    ~AllbumWindow();

private:
    Ui::AllbumWindow *ui;
};

#endif // ALLBUMWINDOW_H
