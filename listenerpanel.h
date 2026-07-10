#ifndef LISTENERPANEL_H
#define LISTENERPANEL_H

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

private:
    Ui::ListenerPanel *ui;
};

#endif // LISTENERPANEL_H
