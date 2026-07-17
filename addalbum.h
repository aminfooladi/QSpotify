#ifndef ADDALBUM_H
#define ADDALBUM_H

#include "database.h"
#include "apppagge.h"

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

    void setDatabase(Database* database) ;
    void setPtrToPage(AppPage* page) ;
    void setPageInfo();

signals:
    void goToArtistPanel() ;

private slots:
    void on_selectFileButton_clicked();

    void on_savePushButton_clicked();

    void on_cancelPushButton_clicked();

private:
    Ui::AddAlbum *ui;
    Database * database ;
    AppPage * page ;
    QString albumType;
    Album newAlbum ;
};

#endif // ADDALBUM_H
