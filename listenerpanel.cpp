#include "listenerpanel.h"
#include "ui_listenerpanel.h"

#include <QMessageBox>
using namespace std;

ListenerPanel::ListenerPanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ListenerPanel)
{
    ui->setupUi(this);
    ui->editInfoGroupBox->hide() ;
}

ListenerPanel::~ListenerPanel()
{
    delete ui;
}

void ListenerPanel::setDatabase(Database* database)
{
    this->database = database ;
}

void ListenerPanel::setPtrToPage(AppPage *page)
{
    this->page = page ;
}

void ListenerPanel::setAccountInfo()
{
    QString fullName = database->userAccount.getFullName();
    QString userName = database->userAccount.getUserName();
    QString bio = database->userAccount.getBiography();

    QString role;
    if (database->userAccount.getRole() == Role::Artist)
    {
        role = "Artist";
    }
    else
    {
        role = "Listener";
    }

    ui->fullNameLabel_3->setText(fullName);
    ui->userNameLabel_3->setText(userName);
    ui->roleLabel_3->setText(role);
    ui->biographyLabel_3->setText(bio);
}


void ListenerPanel::on_OK_clicked()
{
    QString fullName = ui->fullNameLineEdit->text() ;
    QString userName = ui->userNameLineEdit->text() ;
    QString bio = ui->editBiographyLineEdit->text() ;
    if (!fullName.isEmpty())
    {
        database->userAccount.setFullName(fullName) ;
    }
    if(!userName.isEmpty())
    {
        database->userAccount.setUserName(userName) ;
    }
    if(!bio.isEmpty())
    {
        database->userAccount.setBiography(bio) ;
    }
    this->setAccountInfo();
    ui->editInfoGroupBox->hide() ;
    database->saveAll() ;
}


void ListenerPanel::on_editInfoButton_clicked()
{
    if(ui->editInfoGroupBox->isHidden())
    {
        ui->editInfoGroupBox->show() ;
    }
    else
    {
        ui->editInfoGroupBox->hide() ;
    }
}


void ListenerPanel::on_Cancel_clicked()
{
    QString temp = "" ;
    ui->fullNameLineEdit->setText(temp) ;
    ui->userNameLineEdit->setText(temp) ;
    ui->editBiographyLineEdit->setText(temp) ;
    ui->editInfoGroupBox->hide() ;
}


void ListenerPanel::on_logoutButton_clicked()
{
    *this->page = AppPage::Login ;
    emit goToLoginPage();
    this->close();
}


void ListenerPanel::on_deleteAccountButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Account",
                                  "Are you sure you want to delete your account?\nThis action cannot be undone!",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        int userId = database->userAccount.getId();
        bool removed = database->accountRepo.remove(userId);

        if (removed)
        {
            database->saveAll();

            QMessageBox::information(this, "Success", "Account deleted successfully!");

            *this->page = AppPage::Login;
            emit goToLoginPage();
            this->close();
        }
        else
        {
            QMessageBox::warning(this, "Error", "Something went wrong!");
        }
    }
}

