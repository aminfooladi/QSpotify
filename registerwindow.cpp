#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::setDatabase(Database* database)
{
    this->database = database ;
}

void RegisterWindow::setPtrToPage(AppPage *page)
{
    this->page = page ;
}

void RegisterWindow::on_registerButton_clicked()
{

}


void RegisterWindow::on_backToLoginButton_clicked()
{

}

