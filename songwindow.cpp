#include "songwindow.h"
#include "ui_songwindow.h"

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFile>
#include <QIcon>
using namespace std;
SongWindow::SongWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SongWindow)
{
    ui->setupUi(this);
    this->mediaPlayer = new QMediaPlayer ;
    this->audioOutput = new QAudioOutput ;
    this->mediaPlayer->setAudioOutput(audioOutput) ;
}

SongWindow::~SongWindow()
{
    delete ui;
}

void SongWindow::setDatabase(Database *database)
{
    this->database = database ;
}

void SongWindow::setPtrToPage(AppPage *page)
{
    this->page = page;
}

void SongWindow::setSongId(int songID)
{
    this->songID = songID;
}

void SongWindow::setPageInfo()
{
    optional<Song> songOp = database->songRepo.search(songID);
    if(songOp.has_value())
    {
        Song song = songOp.value();
        ui->songArtistLabel->setText(database->accountRepo.search(song.getArtistId()).value().getFullName()) ;
        ui->songGenreLabel->setText(song.getGenre()) ;
        ui->songNameLabel->setText(song.getTitle());
        ui->songYearLabel->setText(QString::number(song.getReleaseYear()));

        QString coverPath = song.getCover();
        QPixmap pixmap;

        if (QFile::exists(coverPath))
        {
            pixmap.load(coverPath);
        }
        else
        {
            pixmap.load(":/albums/images/songDiffult.png");
        }

        ui->coverLabel->setPixmap(pixmap.scaled( ui->coverLabel->size()));

        QString audioFile = song.getFileAddress();
        if (QFile::exists(audioFile))
        {
            mediaPlayer->setSource(QUrl::fromLocalFile(audioFile));
        }
    }
}
