#include "songwindow.h"
#include "ui_songwindow.h"

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFile>
#include <QSize>
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

    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, [&]() {
                ui->horizontalSlider->setValue(mediaPlayer->position());
            });

    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, [&]() {
                ui->horizontalSlider->setMaximum(mediaPlayer->duration());
            });
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
            pixmap.load(":/songs/images/songDiffult.png");
        }

        ui->coverLabel->setPixmap(pixmap.scaled( ui->coverLabel->size()));

        //QString audioFile = song.getFileAddress();
        QString audioFile = "C:/Users/vihan-rayaneh/Downloads/6936b1d7d23a7-roya-moein(320).mp3" ;
        if (QFile::exists(audioFile))
        {
            QPixmap pixmap(":/songs/images/StopSongIcon.png");
            QIcon icon(pixmap);
            ui->playOrStoppushButton->setIcon(icon);
            ui->playOrStoppushButton->setFixedSize(80, 80);
            ui->playOrStoppushButton->setIconSize(QSize(80, 80));
            mediaPlayer->setSource(QUrl::fromLocalFile(audioFile));
            if(!mediaPlayer->isPlaying()) mediaPlayer->play();
        }
    }
}

void SongWindow::on_horizontalSlider_sliderMoved(int position)
{
    this->mediaPlayer->setPosition(position) ;
}


void SongWindow::on_playOrStoppushButton_clicked()
{
    if(mediaPlayer->isPlaying())
    {
        QPixmap pixmap(":/songs/images/playSongBtnIcon.png");
        QIcon icon(pixmap);
        ui->playOrStoppushButton->setIcon(icon);
        ui->playOrStoppushButton->setFixedSize(80, 80);
        ui->playOrStoppushButton->setIconSize(QSize(80, 80));
        mediaPlayer->pause();
    }
    else
    {
        QPixmap pixmap(":/songs/images/StopSongIcon.png");
        QIcon icon(pixmap);
        ui->playOrStoppushButton->setIcon(icon);
        ui->playOrStoppushButton->setFixedSize(80, 80);
        ui->playOrStoppushButton->setIconSize(QSize(80, 80));
        mediaPlayer->play();
    }
}


void SongWindow::on_lastSongPushButton_clicked()
{
    int newPosition = mediaPlayer->position() - 10000;
    if (newPosition < 0) newPosition = 0;
    mediaPlayer->setPosition(newPosition);
    ui->horizontalSlider->setValue(newPosition);
}

void SongWindow::on_nexSongPushButton_clicked()
{
    int newPosition = mediaPlayer->position() + 10000;
    int duration = mediaPlayer->duration();
    if (newPosition > duration) newPosition = duration;
    mediaPlayer->setPosition(newPosition);
    ui->horizontalSlider->setValue(newPosition);
}


void SongWindow::on_pushButton_clicked()
{
    mediaPlayer->pause();
    emit goBack();
    this->close();
}


void SongWindow::on_pushButton_2_clicked()
{
    mediaPlayer->pause();
    emit gotoEditSong(this->songID);
    this->close();
}

