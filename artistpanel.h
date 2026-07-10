#ifndef ARTISTPANEL_H
#define ARTISTPANEL_H

#include "database.h"
#include "apppagge.h"

#include <QMainWindow>

namespace Ui {
class ArtistPanel;
}

class ArtistPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ArtistPanel(QWidget *parent = nullptr);
    ~ArtistPanel();

    void setDatabase(Database* database) ;
    void setPtrToPage(AppPage* page) ;

private:
    Database * database ;
    AppPage * page ;
    Ui::ArtistPanel *ui;
};

#endif // ARTISTPANEL_H
