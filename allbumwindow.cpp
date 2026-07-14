#include "allbumwindow.h"
#include "ui_allbumwindow.h"

AllbumWindow::AllbumWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AllbumWindow)
{
    ui->setupUi(this);
}

AllbumWindow::~AllbumWindow()
{
    delete ui;
}
