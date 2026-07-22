#include "registerwindow.h"
#include "ui_registerwindow.h"

#include <QMessageBox>
#include <stdexcept>

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
    try
    {
        QString fullName = ui->fullNameLineEdit->text().trimmed();
        QString userName = ui->userNameLineEdit->text().trimmed();
        QString password = ui->passwordLineEdit->text();
        QString biography = ui->biographyLineEdit->text().trimmed();

        bool isArtist = ui->artistButton->isChecked();
        bool isListener = ui->listenerButton->isChecked();

        if (fullName.isEmpty())
        {
            throw std::runtime_error("Please enter your full name!");
        }

        if (userName.isEmpty())
        {
            throw std::runtime_error("Please enter a username!");
        }

        std::optional<Account> user = database->accountRepo.searchByUserName(userName);
        if (user.has_value())
        {
            throw std::runtime_error("This username is already taken!");
        }

        if (password.isEmpty())
        {
            throw std::runtime_error("Please enter a password!");
        }

        bool hasUpper = false;
        bool hasLower = false;
        bool hasNumber = false;
        bool hasSpecial = false;

        for (int i = 0; i < password.size(); i++)
        {
            if (password[i] <= 'Z' && password[i] >= 'A' )
            {
                hasUpper = true;
            }
            else if (password[i] <= 'z' && password[i] >= 'a' )
            {
                hasLower = true;
            }
            else if (password[i] <= '9' && password[i] >= '0' )
            {
                hasNumber = true;
            }
            else if (password[i] == '@' || password[i] == '$' || password[i] == '%' || password[i] == '#' )
            {
                hasSpecial = true;
            }
        }

        if (password.length() < 6)
        {
            ui->progressBar->setValue(60);
            ui->progressBar->setStyleSheet("QProgressBar::chunk { background: rgb(231, 76, 60); }");
            throw std::runtime_error("Weak password! Password must be at least 6 characters!");
        }
        else if (password.length() >= 12 && hasUpper && hasLower && hasNumber && hasSpecial)
        {
            ui->errorLabel->setText("Strong password!");
            ui->progressBar->setValue(80);
            ui->progressBar->setStyleSheet("QProgressBar::chunk { background: rgb(243, 156, 18); }");
        }
        else if (password.length() >= 6 && hasUpper && hasLower && hasNumber && hasSpecial)
        {
            ui->errorLabel->setText("Medium password!");
            ui->progressBar->setValue(100);
            ui->progressBar->setStyleSheet("QProgressBar::chunk { background: rgb(29, 185, 84); }");
        }
        else
        {
            throw std::runtime_error("Weak password! Use uppercase, lowercase, numbers, and special characters!");
        }

        if (!isArtist && !isListener)
        {
            throw std::runtime_error("Please choose your role (Artist or Listener)!");
        }

        Role role;
        if (isArtist)
        {
            role = Role::Artist;
        }
        else
        {
            role = Role::Listener;
        }

        Account newAccount(0, fullName, userName, biography, password, role);

        int newId = database->accountRepo.save(newAccount);

        if (newId > 0)
        {
            ui->errorLabel->setText("");
            QMessageBox::information(this, "Success", "Account created successfully!");
            database->saveAll() ;
            *page = AppPage::Login;
            emit goToLoginPage();
            this->close();
        }
        else
        {
            throw std::runtime_error("Something went wrong!");
        }
    }
    catch (const std::runtime_error& e)
    {
        ui->errorLabel->setText(e.what());
    }
}

void RegisterWindow::on_backToLoginButton_clicked()
{
    *page = AppPage::Login ;
    emit goToLoginPage() ;
    this->close();
}

void RegisterWindow::on_passwordLineEdit_textChanged(const QString &arg1)
{
    bool hasUpper = false;
    bool hasLower = false;
    bool hasNumber = false;
    bool hasSpecial = false;
    QString password = arg1 ;
    for (int i = 0; i < password.size(); i++)
    {
        if (password[i] <= 'Z' && password[i] >= 'A' )
        {
            hasUpper = true;
        }
        else if (password[i] <= 'z' && password[i] >= 'a' )
        {
            hasLower = true;
        }
        else if (password[i] <= '9' && password[i] >= '0' )
        {
            hasNumber = true;
        }
        else if (password[i] == '@' || password[i] == '$' || password[i] == '%' || password[i] == '#' )
        {
            hasSpecial = true;
        }
    }

    if (password.length() < 2)
    {
        ui->progressBar->setValue(20);
        ui->progressBar->setStyleSheet("QProgressBar::chunk { background: rgb(231, 76, 60); }");
    }
    else if (password.length() < 4 && password.length() > 2)
    {
        ui->progressBar->setValue(40);
        ui->progressBar->setStyleSheet("QProgressBar::chunk { background: rgb(231, 76, 60); }");
    }
    else if (password.length() < 6 && password.length() > 4)
    {
        ui->progressBar->setValue(60);
        ui->progressBar->setStyleSheet("QProgressBar::chunk { background: rgb(231, 76, 60); }");
    }
    else if (password.length() >= 6 && hasUpper && hasLower && hasNumber && hasSpecial && password.length() < 12 )
    {
        ui->progressBar->setValue(80);
        ui->progressBar->setStyleSheet("QProgressBar::chunk { background: rgb(243, 156, 18); }");
    }
    else if (password.length() >= 12 && hasUpper && hasLower && hasNumber && hasSpecial)
    {
        ui->progressBar->setValue(100);
        ui->progressBar->setStyleSheet("QProgressBar::chunk { background: rgb(29, 185, 84); }");
    }
}