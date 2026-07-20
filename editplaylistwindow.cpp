#include "editplaylistwindow.h"
#include "ui_editplaylistwindow.h"

EditPlaylistWindow::EditPlaylistWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EditPlaylistWindow)
{
    ui->setupUi(this);
}

EditPlaylistWindow::~EditPlaylistWindow()
{
    delete ui;
}
