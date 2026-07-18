#include "addplaylistwindow.h"
#include "ui_addplaylistwindow.h"

AddPlaylistWindow::AddPlaylistWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddPlaylistWindow)
{
    ui->setupUi(this);
}

AddPlaylistWindow::~AddPlaylistWindow()
{
    delete ui;
}
