#include "loginwindow.h"
#include "ui_loginwindow.h"

#include <QMessageBox>

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
    QString userName = ui->usernameLineEdit->text() ;
    QString password = ui->passwordLineEdit->text() ;

    if (userName.isEmpty() && password.isEmpty())
    {
        ui->errorLabel->setText("Please enter username and password!");
        return;
    }

    if (userName.isEmpty())
    {
        ui->errorLabel->setText("Please enter username!");
        return;
    }

    if (password.isEmpty())
    {
        ui->errorLabel->setText("Please enter password!");
        return;
    }

    std::optional<Account> result = database->accountRepo.searchByUserName(userName) ;

    if(result)
    {
        Account user = result.value() ;
        if(password==user.getPassword())
        {
            ui->errorLabel->setText("");

            if (user.getRole() == Role::Artist)
            {
                QMessageBox::information(this, "Success", "Welcome Artist!");
                *page = AppPage::ArtistPanel ;
                emit loginSuccessful() ;
                this->close();
            }
            else
            {
                QMessageBox::information(this, "Success", "Welcome Listener!");
                *page = AppPage::ListenerPanel ;
                emit loginSuccessful() ;
                this->close();
            }
            return;
        }
        else
        {
            ui->errorLabel->setText("Wrong password!");
            return;
        }
    }
    else
    {
        ui->errorLabel->setText("User not found!");
        ui->usernameLineEdit->setText("") ;
        ui->passwordLineEdit->setText("") ;
    }

}


void LoginWindow::on_registerButton_clicked()
{
    *page = AppPage::Register ;
    emit goToRegisterPage() ;
    this->close();
}

