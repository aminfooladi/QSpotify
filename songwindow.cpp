#include "songwindow.h"
#include "ui_songwindow.h"

SongWindow::SongWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SongWindow)
{
    ui->setupUi(this);
}

SongWindow::~SongWindow()
{
    delete ui;
}
