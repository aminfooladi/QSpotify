#include "addsongwindow.h"
#include "ui_addsongwindow.h"

AddSongWindow::AddSongWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddSongWindow)
{
    ui->setupUi(this);
}

AddSongWindow::~AddSongWindow()
{
    delete ui;
}
