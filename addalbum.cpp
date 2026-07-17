#include "addalbum.h"
#include "ui_addalbum.h"

AddAlbum::AddAlbum(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddAlbum)
{
    ui->setupUi(this);
}

AddAlbum::~AddAlbum()
{
    delete ui;
}
