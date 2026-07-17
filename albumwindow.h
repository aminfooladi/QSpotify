#ifndef ALBUMWINDOW_H
#define ALBUMWINDOW_H

#include "database.h"
#include "apppagge.h"

#include <QMainWindow>

namespace Ui {
class AlbumWindow;
}

class AlbumWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AlbumWindow(QWidget *parent = nullptr);
    ~AlbumWindow();

    void setDatabase(Database* database) ;
    void setPtrToPage(AppPage* page) ;
    void setAlbumId(int albumID) ;
    void setPsgeInfo() ;

signals:
    void goBack();
    void goToSongPage(int songID) ;

private slots:
    void on_backButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::AlbumWindow *ui;
    Database * database ;
    AppPage * page ;
    int albumID ;
};

#endif // ALBUMWINDOW_H
