#include "addalbum.h"
#include "ui_addalbum.h"


#include <QFileDialog>
#include <stdexcept>
using namespace std;

AddAlbum::AddAlbum(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddAlbum)
{
    ui->setupUi(this);
}

AddAlbum::~AddAlbum()
{
    delete ui;
}

void AddAlbum::setDatabase(Database *database)
{
    this->database = database;
}

void AddAlbum::setPtrToPage(AppPage *page)
{
    this->page = page ;
}

void AddAlbum::setPageInfo()
{
    ui->lineEdit->setText("");
    ui->label_2->setText("");
    ui->erorLabel->setText("");
    ui->filePathLabel->setText("No file selected");
    ui->label_2->setText(this->database->userAccount.getFullName());
}

void AddAlbum::on_selectFileButton_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(
        this,
        "Select Album Cover",
        "",
        "Images (*.png *.jpg *.jpeg *.bmp *.gif)"
        );

    if (imagePath.isEmpty())
    {
        return;
    }

    QString albumsFolder = QCoreApplication::applicationDirPath() + "/albums/";

    QFileInfo fileInfo(imagePath);
    QString fileName = fileInfo.fileName();
    QString destPath = albumsFolder + fileName;

    if (QFile::copy(imagePath, destPath))
    {
        newAlbum.setCover(destPath);
        ui->filePathLabel->setText(fileName);
    }
    else
    {
        newAlbum.setCover(imagePath);
        ui->filePathLabel->setText(fileName);
    }
}

void AddAlbum::on_savePushButton_clicked()
{
    try
    {
        QString albumName = ui->lineEdit->text();
        if(albumName == "")
        {
            throw std::runtime_error("Please enter album name!");
        }

        if(database->albumRepo.searchByName(albumName))
        {
            throw std::runtime_error("An album with this name already exists!");
        }

        this->newAlbum.setName(albumName) ;
        newAlbum.setArtistId(database->userAccount.getId());

        if (database->albumRepo.save(this->newAlbum))
        {
            database->saveAll();
            emit goToArtistPanel();
            this->close();
        }
        else
        {
            throw std::runtime_error("Failed to save album!");
        }
    }
    catch (const std::runtime_error& e)
    {
        ui->erorLabel->setText(e.what());
    }
}


void AddAlbum::on_cancelPushButton_clicked()
{
    emit goToArtistPanel();
    this->close();
}