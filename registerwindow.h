#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H
#include "database.h"
#include "apppagge.h"


#include <QMainWindow>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

    void setDatabase(Database* database) ;
    void setPtrToPage(AppPage* page) ;

private:
    Database * database ;
    AppPage * page ;
    Ui::RegisterWindow *ui;
};

#endif // REGISTERWINDOW_H
