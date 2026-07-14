#include "addsongwindow.h"
#include "ui_addsongwindow.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QFile>
#include <QDir>

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

    ui->filePathLabel->setText(QFileInfo(filePath).fileName());

    QString fileName = QFileInfo(filePath).baseName();

    if (ui->titleLineEdit->text().isEmpty())
    {
        ui->titleLineEdit->setText(fileName);
    }
}
void AddSongWindow::on_selectImageButton_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(
        this,
        "");

    if (imagePath.isEmpty())
    {
        return;
    }

    ui->filePathLabel->setText(QFileInfo(imagePath).fileName());

    QString fileName = QFileInfo(imagePath).baseName();

    if (ui->titleLineEdit->text().isEmpty())
    {
        ui->titleLineEdit->setText(fileName);
    }
}


void AddSongWindow::on_saveButton_clicked()
{
    vector<Song> songs = database->songRepo.getByArtist(database->userAccount.getId()) ;
    QString title = ui->titleLineEdit->text();
    int releaseYear = ui->yearSpinBox->value();
    QString genre = ui->genreLineEdit->text();
    QString fileAddress = ui->filePathLabel->text();
    int artistId = database->userAccount.getId();
    int albumId ;
    QString cover = ui->imagePathLabel->text();


}

