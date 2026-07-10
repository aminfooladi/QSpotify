#include "artistpanel.h"
#include "ui_artistpanel.h"

ArtistPanel::ArtistPanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ArtistPanel)
{
    ui->setupUi(this);
}

ArtistPanel::~ArtistPanel()
{
    delete ui;
}

void ArtistPanel::setDatabase(Database* database)
{
    this->database = database ;
}

void ArtistPanel::setPtrToPage(AppPage *page)
{
    this->page = page ;
}
