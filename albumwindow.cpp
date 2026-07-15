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
        for (int i = 0; i < songs.size(); i++)
        {
            QTableWidgetItem *numItem = new QTableWidgetItem(QString::number(i + 1));
            numItem->setTextAlignment(Qt::AlignCenter);
            ui->songsTable->setItem(i, 0, numItem);

            QTableWidgetItem *titleItem = new QTableWidgetItem(songs[i].getTitle());
            ui->songsTable->setItem(i, 1, titleItem);
        }
    }
}

void AlbumWindow::on_backButton_clicked()
{
    emit goBack();
    this->close();
}

