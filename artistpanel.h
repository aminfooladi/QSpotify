#ifndef ARTISTPANEL_H
#define ARTISTPANEL_H

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

private:
    Ui::ArtistPanel *ui;
};

#endif // ARTISTPANEL_H
