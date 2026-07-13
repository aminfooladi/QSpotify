#ifndef LISTENERPANEL_H
#define LISTENERPANEL_H

#include "database.h"
#include "apppagge.h"

#include <QMainWindow>

namespace Ui {
class ListenerPanel;
}

class ListenerPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListenerPanel(QWidget *parent = nullptr);
    ~ListenerPanel();

    void setDatabase(Database* database) ;
    void setPtrToPage(AppPage* page) ;
    void setAccountInfo() ;
    void lodeAlbums() ;
    void lodeSingles();
    void lodePlaylists();

signals:
    void goToLoginPage() ;

private slots:
    void on_OK_clicked();

    void on_editInfoButton_clicked();

    void on_Cancel_clicked();

    void on_logoutButton_clicked();

    void on_deleteAccountButton_clicked();

private:
    Database * database ;
    AppPage * page ;
    Ui::ListenerPanel *ui;
};

#endif // LISTENERPANEL_H
