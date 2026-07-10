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
