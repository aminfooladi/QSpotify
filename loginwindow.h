#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "database.h"
#include "apppagge.h"

#include <QMainWindow>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

    void setDatabase(Database* database) ;
    void setPtrToPage(AppPage* page) ;

private slots:
    void on_loginButton_clicked();

private:
    Database * database ;
    AppPage * page ;
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
