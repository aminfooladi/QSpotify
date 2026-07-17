#include "editalbumwindow.h"
#include "ui_editalbumwindow.h"

EditAlbumWindow::EditAlbumWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EditAlbumWindow)
{
    ui->setupUi(this);
}

EditAlbumWindow::~EditAlbumWindow()
{
    delete ui;
}
