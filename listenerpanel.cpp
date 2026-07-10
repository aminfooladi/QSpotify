#include "listenerpanel.h"
#include "ui_listenerpanel.h"

ListenerPanel::ListenerPanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ListenerPanel)
{
    ui->setupUi(this);
}

ListenerPanel::~ListenerPanel()
{
    delete ui;
}

void ListenerPanel::setDatabase(Database* database)
{
    this->database = database ;
}

void ListenerPanel::setPtrToPage(AppPage *page)
{
    this->page = page ;
}
