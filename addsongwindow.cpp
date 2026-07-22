#include "addsongwindow.h"
#include "ui_addsongwindow.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QCoreApplication>
#include <stdexcept>

using namespace std;

AddSongWindow::AddSongWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddSongWindow)
{
    ui->setupUi(this);
    database = nullptr;
    albumId = 0;
    selectedFilePath = "";
}

AddSongWindow::~AddSongWindow()
{
    delete ui;
}

void AddSongWindow::setDatabase(Database* database)
{
    this->database = database;
    ui->label_2->setText(database->userAccount.getFullName());

    if (albumId > 0)
    {
        auto album = database->albumRepo.search(albumId);
        if (album.has_value())
        {
            ui->label->setText(album.value().getName());
        }
    }
    if (albumId == 0)
    {
        ui->label->setText("Singles");
    }
}

void AddSongWindow::setAlbumId(int albumId)
{
    this->albumId = albumId;
}

void AddSongWindow::on_selectFileButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(
        this,
        "Select Audio File",
        "",
        "Audio Files (*.mp3 *.wav *.flac *.m4a *.ogg)"
        );

    if (filePath.isEmpty())
    {
        return;
    }

    QString songsFolder = QCoreApplication::applicationDirPath() + "/songs/";

    QFileInfo fileInfo(filePath);
    QString fileName = fileInfo.fileName();
    QString destPath = songsFolder + fileName;

    if (QFile::copy(filePath, destPath))
    {
        newSong.setFileAddress(destPath);
        ui->filePathLabel->setText(fileName);
    }
    else
    {
        newSong.setFileAddress(filePath);
        ui->filePathLabel->setText(fileName);
    }

    QString baseName = fileInfo.baseName();
    if (ui->titleLineEdit->text().isEmpty())
    {
        ui->titleLineEdit->setText(baseName);
    }
}

void AddSongWindow::on_selectImageButton_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(
        this,
        "Select Song Cover",
        "",
        "Images (*.png *.jpg *.jpeg *.bmp *.gif)"
        );

    if (imagePath.isEmpty())
    {
        return;
    }

    QString songsFolder = QCoreApplication::applicationDirPath() + "/songs/";

    QFileInfo fileInfo(imagePath);
    QString fileName = fileInfo.fileName();
    QString destPath = songsFolder + fileName;

    if (QFile::copy(imagePath, destPath))
    {
        newSong.setCover(destPath);
        ui->imagePathLabel->setText(fileName);
    }
    else
    {
        newSong.setCover(imagePath);
        ui->imagePathLabel->setText(fileName);
    }
}

void AddSongWindow::on_saveButton_clicked()
{
    try
    {
        QString title = ui->titleLineEdit->text().trimmed();
        if (title.isEmpty())
        {
            throw std::runtime_error("Please enter song title!");
        }

        if(this->database->songRepo.serchSongByName(title))
        {
            throw std::runtime_error("A song with this title already exists!");
        }

        QString fileAddress = newSong.getFileAddress();
        if (fileAddress.isEmpty() || fileAddress == "No file selected")
        {
            throw std::runtime_error("Please select an audio file!");
        }

        if(this->database->songRepo.serchSongByFileAddress(fileAddress))
        {
            throw std::runtime_error("A song with this address already exists!");
        }

        newSong.setTitle(title);
        newSong.setReleaseYear(ui->yearSpinBox->value());
        newSong.setGenre(ui->genreLineEdit->text().trimmed());
        newSong.setArtistId(database->userAccount.getId());
        newSong.setAlbumId(this->albumId);

        int songId = database->songRepo.save(newSong);

        if (songId > 0)
        {
            database->saveAll();
            emit goBack(this->albumId);
            this->close();
        }
        else
        {
            throw std::runtime_error("Failed to save song!");
        }
    }
    catch (const std::runtime_error& e)
    {
        ui->erorLabel->setText(e.what());
    }
}

void AddSongWindow::on_cancelButton_clicked()
{
    emit goBack(this->albumId);
    this->close();
}