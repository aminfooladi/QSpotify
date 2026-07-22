#include "editsongwindow.h"
#include "ui_editsongwindow.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include <QSize>
#include <QCoreApplication>
#include <QDir>
#include <stdexcept>

EditSongWindow::EditSongWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EditSongWindow)
{
    ui->setupUi(this);
}

EditSongWindow::~EditSongWindow()
{
    delete ui;
}

void EditSongWindow::setDatabase(Database* database)
{
    this->database = database;
}

void EditSongWindow::setSongId(int songId)
{
    this->songId = songId;
}

void EditSongWindow::loadSongInfo()
{
    auto songOp = database->songRepo.search(songId);
    if (!songOp.has_value())
    {
        ui->errorLabel->setText("Song not found!");
        return;
    }

    editingSong = songOp.value();
    albumId = editingSong.getAlbumId();

    ui->titleLineEdit->setText(editingSong.getTitle());
    ui->yearSpinBox->setValue(editingSong.getReleaseYear());
    ui->genreLineEdit->setText(editingSong.getGenre());

    auto artist = database->accountRepo.search(editingSong.getArtistId());
    if (artist.has_value())
    {
        ui->artistNameLabel->setText(artist.value().getFullName());
    }

    if (albumId > 0)
    {
        auto album = database->albumRepo.search(albumId);
        if (album.has_value())
        {
            ui->albumNameLabel->setText(album.value().getName());
        }
    }
    else
    {
        ui->albumNameLabel->setText("Single");
    }

    QString coverPath = editingSong.getCover();
    if (QFile::exists(coverPath))
    {
        QPixmap pixmap(coverPath);
        ui->coverPreviewLabel->setPixmap(pixmap.scaled(ui->coverPreviewLabel->size()));
    }
    else
    {
        QPixmap pixmap(":/songs/images/songDiffult.png");
        ui->coverPreviewLabel->setPixmap(pixmap.scaled(ui->coverPreviewLabel->size()));
    }

    ui->errorLabel->setText("");
}

void EditSongWindow::on_selectCoverButton_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(
        this,
        "Select Song Cover",
        "",
        "Images (*.png *.jpg *.jpeg *.bmp *.gif)");

    if (imagePath.isEmpty())
    {
        return;
    }

    QString songsFolder = QCoreApplication::applicationDirPath() + "/songs/";

    QDir dir;
    if (!dir.exists(songsFolder))
    {
        dir.mkpath(songsFolder);
    }

    QFileInfo fileInfo(imagePath);
    QString fileName = fileInfo.fileName();
    QString destPath = songsFolder + fileName;

    if (QFile::copy(imagePath, destPath))
    {
        editingSong.setCover(destPath);
        ui->coverPathLabel->setText(fileName);
    }
    else
    {
        editingSong.setCover(imagePath);
        ui->coverPathLabel->setText(fileName);
    }

    if (QFile::exists(editingSong.getCover()))
    {
        QPixmap pixmap(editingSong.getCover());
        ui->coverPreviewLabel->setPixmap(pixmap.scaled(ui->coverPreviewLabel->size()));
    }
}

void EditSongWindow::on_saveButton_clicked()
{
    try
    {
        if(database->userAccount.getId() != database->songRepo.search(this->songId).value().getArtistId())
        {
            throw std::runtime_error("You can not edit this song!");
        }

        QString newTitle = ui->titleLineEdit->text().trimmed();
        if (newTitle.isEmpty())
        {
            throw std::runtime_error("Please enter song title!");
        }

        if (newTitle != editingSong.getTitle())
        {
            int existingId = database->songRepo.serchSongByName(newTitle);
            if (existingId && existingId != this->songId)
            {
                throw std::runtime_error("A song with this title already exists!");
            }
        }

        editingSong.setTitle(newTitle);
        editingSong.setReleaseYear(ui->yearSpinBox->value());
        editingSong.setGenre(ui->genreLineEdit->text().trimmed());

        this->database->songRepo.save(this->editingSong);
        database->saveAll();

        emit goBack(this->albumId, this->songId);
        this->close();
    }
    catch (const std::runtime_error& e)
    {
        ui->errorLabel->setText(e.what());
    }
}

void EditSongWindow::on_cancelButton_clicked()
{
    emit goBack(this->albumId , this->songId);
    this->close();
}