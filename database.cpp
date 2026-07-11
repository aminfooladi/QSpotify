#include "database.h"
#include <fstream>
#include <iostream>
using namespace std;

Database::Database() {}

void Database::loadDefaultData()
{
    Account artist1(1, "Ali", "ali", "bio", "1234", Role::Artist);
    Account listener1(3, "Amin", "amin", "bio", "1234", Role::Listener);

    accountRepo.save(artist1);
    accountRepo.save(listener1);
}

void Database::saveAll()
{
    ofstream file("data.txt");

    if (!file.is_open()) { return; }

    vector<Account> accounts = accountRepo.getAccounts();
    file << accounts.size() << endl;
    for (int i = 0; i < accounts.size(); i++)
    {
        file << accounts[i].getId() << ","
             << accounts[i].getFullName().toStdString() << ","
             << accounts[i].getUserName().toStdString() << ","
             << accounts[i].getBiography().toStdString() << ","
             << accounts[i].getPassword().toStdString() << ",";

        if (accounts[i].getRole() == Role::Artist)
        {
            file << "Artist";
        }
        else
        {
            file << "Listener";
        }
        file << endl;
    }

    vector<Song> songs = songRepo.getSongs();
    file << songs.size() << endl;
    for (int i = 0; i < songs.size(); i++)
    {
        file << songs[i].getId() << ","
             << songs[i].getTitle().toStdString() << ","
             << songs[i].getReleaseYear() << ","
             << songs[i].getGenre().toStdString() << ","
             << songs[i].getFileAddress().toStdString() << ","
             << songs[i].getArtistId() << ","
             << songs[i].getAlbumId() << ","
             << songs[i].getCover().toStdString() << endl;
    }

    vector<Album> albums = albumRepo.getAlbums();
    file << albums.size() << endl;
    for (int i = 0; i < albums.size(); i++)
    {
        file << albums[i].getId() << ","
             << albums[i].getName().toStdString() << ","
             << albums[i].getArtistId() << ","
             << albums[i].getCover().toStdString() << endl;
    }

    vector<Playlist> playlists = playlistRepo.getAllPlaylists();
    file << playlists.size() << endl;
    for (int i = 0; i < playlists.size(); i++)
    {
        file << playlists[i].getId() << ","
             << playlists[i].getName().toStdString() << ","
             << playlists[i].getListenerId() << ",";

        vector<int> songIds = playlists[i].getSongIDs();
        file << songIds.size() << ",";
        for (int j = 0; j < songIds.size(); j++)
        {
            file << songIds[j];
            if (j < songIds.size() - 1) file << ";";
        }
        file << endl;
    }

    file.close();
}

void Database::loadAll()
{
    ifstream file("data.txt");

    if (!file.is_open())
    {
        loadDefaultData();
        return;
    }

    int count;

    file >> count;
    for (int i = 0; i < count; i++)
    {
        int id;
        string fullName, userName, biography, password, roleStr;

        file >> id;
        file.ignore();
        getline(file, fullName, ',');
        getline(file, userName, ',');
        getline(file, biography, ',');
        getline(file, password, ',');
        getline(file, roleStr);

        Role role;
        if (roleStr == "Artist")
        {
            role = Role::Artist;
        }
        else
        {
            role = Role::Listener;
        }

        Account account(id,
                        QString::fromStdString(fullName),
                        QString::fromStdString(userName),
                        QString::fromStdString(biography),
                        QString::fromStdString(password),
                        role );
        accountRepo.save(account);
    }

    file >> count;
    for (int i = 0; i < count; i++)
    {
        int id, releaseYear, artistId, albumId;
        string title, genre, fileAddress, cover;

        file >> id;
        file.ignore();
        getline(file, title, ',');
        getline(file, genre, ',');
        file >> releaseYear;
        file.ignore();
        getline(file, fileAddress, ',');
        file >> artistId;
        file.ignore();
        file >> albumId;
        file.ignore();
        getline(file, cover);

        Song song(id,
                  QString::fromStdString(title),
                  releaseYear,
                  QString::fromStdString(genre),
                  QString::fromStdString(fileAddress),
                  artistId,
                  albumId,
                  QString::fromStdString(cover));

        songRepo.save(song);
    }

    file >> count;
    for (int i = 0; i < count; i++)
    {
        int id, artistId;
        string name, cover;

        file >> id;
        file.ignore();
        getline(file, name, ',');
        file >> artistId;
        file.ignore();
        getline(file, cover);

        Album album(id,
                    QString::fromStdString(name),
                    artistId,
                    QString::fromStdString(cover));

        albumRepo.save(album);
    }

    file >> count;
    for (int i = 0; i < count; i++)
    {
        int id, listenerId, songCount;
        string name;

        file >> id;
        file.ignore();
        getline(file, name, ',');
        file >> listenerId;
        file.ignore();
        file >> songCount;
        file.ignore();

        Playlist playlist(id, QString::fromStdString(name), listenerId);

        for (int j = 0; j < songCount; j++)
        {
            int songId;
            file >> songId;
            playlist.setSongID(songId);
            if (j < songCount - 1)
            {
                char semicalem;
                file >> semicalem;
            }
        }
        playlistRepo.save(playlist);
    }

    file.close();
}