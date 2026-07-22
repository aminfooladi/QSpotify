#include "loginwindow.h"
#include "ui_loginwindow.h"

#include <QMessageBox>
#include <stdexcept>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::setDatabase(Database* database)
{
    this->database = database ;
}

void LoginWindow::setPtrToPage(AppPage *page)
{
    this->page = page ;
}

void LoginWindow::on_loginButton_clicked()
{
    try
    {
        QString userName = ui->usernameLineEdit->text() ;
        QString password = ui->passwordLineEdit->text() ;

        if (userName.isEmpty() && password.isEmpty())
        {
            throw std::runtime_error("Please enter username and password!");
        }

        if (userName.isEmpty())
        {
            throw std::runtime_error("Please enter username!");
        }

        if (password.isEmpty())
        {
            throw std::runtime_error("Please enter password!");
        }

        std::optional<Account> result = database->accountRepo.searchByUserName(userName) ;

        if(!result.has_value())
        {
            throw std::runtime_error("User not found!");
        }

        Account user = result.value() ;

        if(password != user.getPassword())
        {
            throw std::runtime_error("Wrong password!");
        }

        ui->errorLabel->setText("");

        if (user.getRole() == Role::Artist)
        {
            *page = AppPage::ArtistPanel ;
            this->database->userAccount = user ;
            emit loginSuccessful() ;
            this->close();
        }
        else
        {
            *page = AppPage::ListenerPanel ;
            this->database->userAccount = user ;
            emit loginSuccessful() ;
            this->close();
        }
    }
    catch (const std::runtime_error& e)
    {
        ui->errorLabel->setText(e.what());
        ui->usernameLineEdit->setText("");
        ui->passwordLineEdit->setText("");
    }
}


void LoginWindow::on_registerButton_clicked()
{
    *page = AppPage::Register ;
    emit goToRegisterPage() ;
    this->close();
}