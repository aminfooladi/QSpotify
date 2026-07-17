#include "albumwindow.h"
#include "ui_albumwindow.h"

#include <QFile>
using namespace std;

AlbumWindow::AlbumWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AlbumWindow)
{
    ui->setupUi(this);
}

AlbumWindow::~AlbumWindow()
{
    delete ui;
}

void AlbumWindow::setDatabase(Database *database)
{
    this->database = database ;
}

void AlbumWindow::setPtrToPage(AppPage *page)
{
    this->page = page ;
}

void AlbumWindow::setAlbumId(int albumID)
{
    this->albumID = albumID ;
}

void AlbumWindow::setPsgeInfo()
{
    optional<Album> albumOp = this->database->albumRepo.search(this->albumID) ;
    if(albumOp.has_value())
    {
        Album album = albumOp.value();
        vector<Song> songs = database->songRepo.getByAlbum(this->albumID);
        ui->albumNameLabel->setText(album.getName()) ;
        ui->artistNameLabel->setText(database->accountRepo.search(album.getArtistId()).value().getFullName());
        QString coverPath = album.getCover();
        QPixmap pixmap;

        if (QFile::exists(coverPath))
        {
            pixmap.load(coverPath);
        }
        else
        {
            pixmap.load(":/albums/images/albumDiffult.png");
        }

        ui->coverLabel->setPixmap(pixmap.scaled( ui->coverLabel->size()));
        ui->songsTable->setRowCount(songs.size());

        ui->songsTable->verticalHeader()->setDefaultSectionSize(40);
        ui->songsTable->verticalHeader()->setVisible(false);

        ui->songsTable->setColumnWidth(0, 250);
        ui->songsTable->setColumnWidth(1, 150);
        ui->songsTable->setColumnWidth(2, 80);
        ui->songsTable->setColumnWidth(3, 80);
        ui->songsTable->setColumnWidth(4, 80);

        ui->songsTable->setShowGrid(false);

        for (int i = 0; i < songs.size(); i++)
        {
            ui->songsTable->setItem(i, 0, new QTableWidgetItem(songs[i].getTitle()));

            QString info = QString::number(songs[i].getReleaseYear()) + " | " + songs[i].getGenre();
            ui->songsTable->setItem(i, 1, new QTableWidgetItem(info));

            QPushButton* playBtn = new QPushButton("▶ Play");
            playBtn->setFixedSize(60, 20);

            playBtn->setStyleSheet(
                "background: transparent;"
                "border: 1px solid rgb(0, 85, 0);"
                "border-radius: 10px;"
                "color: rgb(0, 85, 0);");


            ui->songsTable->setCellWidget(i, 2, playBtn);

            connect(playBtn, &QPushButton::clicked, this, [this, i, songs]() {
                emit goToSongPage(songs[i].getId());
                this->close();
            });

            QPushButton* editBtn = new QPushButton("✎ Edit");
            editBtn->setFixedSize(60, 20);
            ui->songsTable->setCellWidget(i, 3, editBtn);

            editBtn->setStyleSheet(
                "background: transparent;"
                "border: 1px solid rgb(89, 89, 89);"
                "border-radius: 10px;"
                "color: rgb(89, 89, 89);");

            QPushButton* deleteBtn = new QPushButton("✕ Delete");
            deleteBtn->setFixedSize(60, 20);
            ui->songsTable->setCellWidget(i, 4, deleteBtn);

            deleteBtn->setStyleSheet(
                "background: transparent;"
                "border: 1px solid rgb(181, 0, 3);"
                "border-radius: 10px;"
                "color: rgb(181, 0, 3);");

        }
    }
}

void AlbumWindow::on_backButton_clicked()
{
    emit goBack();
    this->close();
}

void AlbumWindow::on_addSongpushButton_clicked()
{
    emit goToAddSong(this->albumID);
    this->close();
    return;
}


void AlbumWindow::on_editAlbumpushButton_clicked()
{
    emit goToEditAlbumWindow(this->albumID);
    this->close();
    return;
}

