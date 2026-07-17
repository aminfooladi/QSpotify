#ifndef ADDALBUM_H
#define ADDALBUM_H

#include <QMainWindow>

namespace Ui {
class AddAlbum;
}

class AddAlbum : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddAlbum(QWidget *parent = nullptr);
    ~AddAlbum();

private:
    Ui::AddAlbum *ui;
};

#endif // ADDALBUM_H
