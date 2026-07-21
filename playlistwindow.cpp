#include "playlistwindow.h"
#include "ui_playlistwindow.h"

#include <QFile>
using namespace std;

PlaylistWindow::PlaylistWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PlaylistWindow)
{
    ui->setupUi(this);
}

PlaylistWindow::~PlaylistWindow()
{
    delete ui;
}

void PlaylistWindow::setDatabase(Database *database)
{
    this->database = database ;
}

void PlaylistWindow::setPlaylistId(int playlistID)
{
    this->playlistID = playlistID ;
}

void PlaylistWindow::setPageInfo()
{
    optional<Playlist> playlistOp = this->database->playlistRepo.search(this->playlistID) ;
    if(playlistOp.has_value())
    {
        Playlist playlist = playlistOp.value();
        vector<Song> songs ;
        vector<int> songsIDs = playlist.getSongIDs();
        for(int i=0 ; i<songsIDs.size() ; i++ )
        {
            songs.push_back(database->songRepo.search(songsIDs[i]).value()) ;
        }
        ui->playlistNameLabel->setText(playlist.getName()) ;
        ui->listenerNameLabel->setText(database->accountRepo.search(playlist.getListenerId()).value().getFullName());
        QString coverPath = playlist.getCover();
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

            QPushButton* deleteBtn = new QPushButton("✕ Delete");
            deleteBtn->setFixedSize(60, 20);
            ui->songsTable->setCellWidget(i, 3, deleteBtn);



            deleteBtn->setStyleSheet(
                "background: transparent;"
                "border: 1px solid rgb(181, 0, 3);"
                "border-radius: 10px;"
                "color: rgb(181, 0, 3);");

            connect(deleteBtn, &QPushButton::clicked, this, [this, playlistID = this->playlistID , songId = songs[i].getId()]() {
                this->database->playlistRepo.removeSong(playlistID, songId);
                this->setPageInfo();
            });
        }
    }
}

void PlaylistWindow::on_backButton_clicked()
{
    emit goBack();
    this->close();
}

void PlaylistWindow::on_editPlaylistpushButton_clicked()
{
    emit goToEditPlaylistWindow(this->playlistID);
    this->close();
    return;
}