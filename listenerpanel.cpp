#include "listenerpanel.h"
#include "ui_listenerpanel.h"

#include <QMessageBox>
#include <QFile>
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

    this->lodeAlbums();
    this->lodeSingles();
    this->lodePlaylists();
}

void ListenerPanel::lodeAlbums()
{
    vector<Album> albums = database->albumRepo.getAlbums() ;
    ui->albumListWidget->clear() ;
    ui->albumListWidget->setIconSize(QSize(150,170)) ;
    ui->albumListWidget->setGridSize(QSize(180,200)) ;
    ui->albumListWidget->setViewMode(QListWidget::IconMode) ;
    ui->albumListWidget->setResizeMode(QListWidget::Adjust) ;
    ui->albumListWidget->setWrapping(false);

    ui->albumListWidget->setFixedHeight(250);

    for(int i=0 ; i<albums.size() ; i++)
    {
        QString imageAddres = albums[i].getCover() ;
        QPixmap pixmap ;
        if(QFile::exists(imageAddres))
        {
            pixmap.load(imageAddres) ;
        }
        else
        {
            pixmap.load(":/albums/images/albumDiffult.png");

        }

        QIcon icon(pixmap) ;
        QListWidgetItem * item = new QListWidgetItem(icon,albums[i].getName()) ;
        item->setData(Qt::UserRole , albums[i].getId()) ;

        ui->albumListWidget->addItem(item) ;
    }
}

void ListenerPanel::lodeSingles()
{
    vector<Song> allSongs = database->songRepo.getSongs();
    vector<Song> singles;

    for (int i = 0; i < allSongs.size(); i++)
    {
        if (allSongs[i].getAlbumId() == 0)
        {
            singles.push_back(allSongs[i]);
        }
    }

    ui->singlesListWidget->clear();
    ui->singlesListWidget->setIconSize(QSize(150, 170));
    ui->singlesListWidget->setGridSize(QSize(180, 200));
    ui->singlesListWidget->setViewMode(QListWidget::IconMode);
    ui->singlesListWidget->setResizeMode(QListWidget::Adjust);
    ui->singlesListWidget->setWrapping(false);
    ui->singlesListWidget->setFixedHeight(250);

    for (int i = 0; i < singles.size(); i++)
    {
        QString imageAddres = singles[i].getCover();
        QPixmap pixmap;
        if (QFile::exists(imageAddres))
        {
            pixmap.load(imageAddres);
        }
        else
        {
            pixmap.load(":/songs/images/songDiffult.png");
        }

        QIcon icon(pixmap);
        QListWidgetItem *item = new QListWidgetItem(icon, singles[i].getTitle());
        item->setData(Qt::UserRole, singles[i].getId());

        ui->singlesListWidget->addItem(item);
    }
}

void ListenerPanel::lodePlaylists()
{
    vector<Playlist> playlists = database->playlistRepo.getPlaylists(database->userAccount.getId());
    ui->playlistsListWidget->clear();
    ui->playlistsListWidget->setIconSize(QSize(150, 170));
    ui->playlistsListWidget->setGridSize(QSize(180, 200));
    ui->playlistsListWidget->setViewMode(QListWidget::IconMode);
    ui->playlistsListWidget->setResizeMode(QListWidget::Adjust);
    ui->playlistsListWidget->setWrapping(false);
    ui->playlistsListWidget->setFixedHeight(250);

    for (int i = 0; i < playlists.size(); i++)
    {
        QString imageAddres = ":/albums/images/albumDiffult.png";
        QPixmap pixmap;
        pixmap.load(imageAddres);

        QIcon icon(pixmap);
        QListWidgetItem *item = new QListWidgetItem(icon, playlists[i].getName());
        item->setData(Qt::UserRole, playlists[i].getId());

        ui->playlistsListWidget->addItem(item);
    }
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

