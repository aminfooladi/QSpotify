#include "editalbumwindow.h"
#include "ui_editalbumwindow.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include <QSize>
EditAlbumWindow::EditAlbumWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EditAlbumWindow)
{
    ui->setupUi(this);
}

EditAlbumWindow::~EditAlbumWindow()
{
    delete ui;
}

void EditAlbumWindow::setDatabase(Database* database)
{
    this->database = database;
}

void EditAlbumWindow::setAlbumId(int albumId)
{
    this->albumId = albumId;
}

void EditAlbumWindow::loadAlbumInfo()
{
    auto albumOp = database->albumRepo.search(albumId);
    if (!albumOp.has_value())
    {
        ui->errorLabel->setText("Album not found!");
        return;
    }

    editingAlbum = albumOp.value();
    ui->nameLineEdit->setText(editingAlbum.getName());

    QString coverPath = editingAlbum.getCover();
    if (QFile::exists(coverPath))
    {
        QPixmap pixmap(coverPath);
        ui->coverPreviewLabel->setPixmap(pixmap.scaled(ui->coverPreviewLabel->size()));
    }
    else
    {
        QPixmap pixmap(":/albums/images/albumDiffult.png");
        ui->coverPreviewLabel->setPixmap(pixmap.scaled(ui->coverPreviewLabel->size()));
    }
}

void EditAlbumWindow::on_selectCoverButton_clicked()
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
        editingAlbum.setCover(destPath);
        ui->coverPathLabel->setText(fileName);
    }
    else
    {
        editingAlbum.setCover(imagePath);
        ui->coverPathLabel->setText(fileName);
    }

    if (QFile::exists(editingAlbum.getCover()))
    {
        QPixmap pixmap(editingAlbum.getCover());
        ui->coverPreviewLabel->setPixmap(pixmap.scaled(ui->coverPreviewLabel->size()));
    }

}


void EditAlbumWindow::on_saveButton_clicked()
{
    QString newName = ui->nameLineEdit->text().trimmed();
    if (newName.isEmpty())
    {
        ui->errorLabel->setText("Please enter album name!");
        return;
    }
    if(database->albumRepo.searchByName(newName))
    {
        ui->errorLabel->setText("An album with this name already exists!");
        return;
    }
    editingAlbum.setName(newName);
    this->database->albumRepo.save(this->editingAlbum);
    database->saveAll();
    emit albumUpdated(this->albumId);
    this->close();
    return ;
}


void EditAlbumWindow::on_cancelButton_clicked()
{
    emit goBack(this->albumId);
    this->close();
    return ;
}

