#include "addplaylistwindow.h"
#include "ui_addplaylistwindow.h"

#include <QMessageBox>
#include <stdexcept>

using namespace std;

AddPlaylistWindow::AddPlaylistWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddPlaylistWindow)
{
    ui->setupUi(this);
    database = nullptr;
}

AddPlaylistWindow::~AddPlaylistWindow()
{
    delete ui;
}

void AddPlaylistWindow::setDatabase(Database *database)
{
    this->database = database;
}

void AddPlaylistWindow::setPageInfo()
{
    ui->nameLineEdit->clear();
    selectedSongIds.clear();
    newPlaylist = Playlist();

    loadAvailableSongs();
    loadSongsTable();
    ui->errorLabel->setText("");
}

void AddPlaylistWindow::setPageInfo(vector<int> selectedSongIds, Playlist playlist)
{
    ui->nameLineEdit->clear();
    this->selectedSongIds.clear();
    newPlaylist = Playlist();

    newPlaylist = playlist ;
    this->selectedSongIds = selectedSongIds;

    loadAvailableSongs();
    loadSongsTable();
    ui->errorLabel->setText("");
}

void AddPlaylistWindow::loadAvailableSongs()
{
    allSongs = database->songRepo.getSongs();
    ui->availableSongsList->clear();

    for (int i = 0; i < allSongs.size(); i++)
    {
        Song song = allSongs[i];
        bool alreadyAdded = false;

        for (int j = 0; j < selectedSongIds.size(); j++)
        {
            if (selectedSongIds[j] == song.getId())
            {
                alreadyAdded = true;
            }
        }

        if (alreadyAdded)
        {
            continue;
        }

        QString text = song.getTitle();
        optional<Account> artist = database->accountRepo.search(song.getArtistId());

        if (artist.has_value())
        {
            text += " - " + artist.value().getFullName();
        }

        QListWidgetItem* item = new QListWidgetItem(text);
        item->setData(Qt::UserRole, song.getId());
        ui->availableSongsList->addItem(item);
    }
}

void AddPlaylistWindow::on_availableSongsList_itemDoubleClicked(QListWidgetItem *item)
{
    int songId = item->data(Qt::UserRole).toInt();
    addSongToPlaylist(songId);
}

void AddPlaylistWindow::addSongToPlaylist(int songId)
{
    for (int i = 0; i < selectedSongIds.size(); i++)
    {
        if (selectedSongIds[i] == songId)
        {
            ui->errorLabel->setText("Song already in playlist!");
            return;
        }
    }

    selectedSongIds.push_back(songId);
    loadSongsTable();
    loadAvailableSongs();
    ui->errorLabel->setText("");
}

void AddPlaylistWindow::removeSongFromPlaylist(int row)
{
    if (row < 0 || row >= selectedSongIds.size())
    {
        return;
    }

    selectedSongIds.erase(selectedSongIds.begin() + row);

    loadSongsTable();
    loadAvailableSongs();
}

void AddPlaylistWindow::loadSongsTable()
{
    ui->songsTable->setRowCount(selectedSongIds.size());
    ui->songsTable->setColumnWidth(0, 235);
    ui->songsTable->setColumnWidth(1, 85);

    for (int i = 0; i < selectedSongIds.size(); i++)
    {
        optional<Song> song = database->songRepo.search(selectedSongIds[i]);

        QTableWidgetItem* titleItem = new QTableWidgetItem(song.value().getTitle());
        ui->songsTable->setItem(i, 0, titleItem);

        QPushButton* removeBtn = new QPushButton("✕ Remove");
        removeBtn->setFixedSize(60, 20);
        removeBtn->setStyleSheet(
            "background: transparent;"
            "border: 1px solid rgb(181, 0, 3);"
            "border-radius: 10px;"
            "color: rgb(181, 0, 3);");

        connect(removeBtn, &QPushButton::clicked, this, [this, i](){
                    onRemoveSong(i);
                });

        ui->songsTable->setCellWidget(i, 1, removeBtn);
    }
}

void AddPlaylistWindow::onRemoveSong(int row)
{
    removeSongFromPlaylist(row);
}

void AddPlaylistWindow::on_saveButton_clicked()
{
    try
    {
        QString name = ui->nameLineEdit->text().trimmed();

        if (name.isEmpty())
        {
            throw std::runtime_error("Please enter playlist name!");
        }

        if (database->playlistRepo.searchByName(name))
        {
            throw std::runtime_error("A playlist with this name already exists!");
        }

        if (selectedSongIds.empty())
        {
            throw std::runtime_error("Please add at least one song!");
        }

        newPlaylist.setName(name);
        newPlaylist.setListenerId(database->userAccount.getId());
        newPlaylist.setSongIDs(selectedSongIds);

        int result = database->playlistRepo.save(newPlaylist);

        if (result > 0)
        {
            database->saveAll();
            ui->errorLabel->setText("");
            emit goBack();
            this->close();
        }
        else
        {
            throw std::runtime_error("Failed to save playlist!");
        }
    }
    catch (const std::runtime_error& e)
    {
        ui->errorLabel->setText(e.what());
    }
}

void AddPlaylistWindow::on_cancelButton_clicked()
{
    emit goBack();
    this->close();
}