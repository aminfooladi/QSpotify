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

private:
    Database * database ;
    AppPage * page ;
    Ui::ListenerPanel *ui;
};

#endif // LISTENERPANEL_H
