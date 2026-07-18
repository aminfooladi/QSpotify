#include "database.h"

#include <fstream>
#include <iostream>
#include <QDebug>
using namespace std;

Database::Database() {}

void Database::loadDefaultData()
{
    // ===== کاربران =====
    Account artist1(1, "Ali Rezaei", "ali", "I love music and playing guitar", "1234", Role::Artist);
    Account artist2(2, "Mohsen", "mohsen", "Pop singer", "1234", Role::Artist);
    Account artist3(3, "Sara", "sara", "Rock singer", "1234", Role::Artist);
    Account listener1(4, "Amin", "amin", "Music lover", "1234", Role::Listener);
    Account listener2(5, "Reza", "reza", "Listening to music everyday", "1234", Role::Listener);
    Account listener3(6, "Narges", "narges", "Classic music fan", "1234", Role::Listener);

    accountRepo.save(artist1);
    accountRepo.save(artist2);
    accountRepo.save(artist3);
    accountRepo.save(listener1);
    accountRepo.save(listener2);
    accountRepo.save(listener3);

    // ===== آلبوم‌ها =====
    // آلبوم‌های Ali (artist1)
    Album album1(1, "Shahr-e-Ghahreman", 1, "album1.jpg");
    Album album2(2, "Khaterat", 1, "album2.jpg");
    Album album3(3, "Bahar", 1, "album3.jpg");

    // آلبوم‌های Mohsen (artist2)
    Album album4(4, "Gole Sorkh", 2, "album4.jpg");
    Album album5(5, "Asheghaneh", 2, "album5.jpg");

    // آلبوم‌های Sara (artist3)
    Album album6(6, "Rock Night", 3, "album6.jpg");
    Album album7(7, "Electric Dreams", 3, "album7.jpg");

    albumRepo.save(album1);
    albumRepo.save(album2);
    albumRepo.save(album3);
    albumRepo.save(album4);
    albumRepo.save(album5);
    albumRepo.save(album6);
    albumRepo.save(album7);

    // ===== آهنگ‌ها =====
    // Ali - آلبوم Shahr-e-Ghahreman
    Song song1(1, "Shahr-e-Ghahreman", 1400, "Rock", "song1.mp3", 1, 1);
    Song song2(2, "Gole Sorkh", 1400, "Pop", "song2.mp3", 1, 1);
    Song song3(3, "Biya To", 1400, "Pop", "song3.mp3", 1, 1);
    Song song4(4, "Darya", 1400, "Pop", "song4.mp3", 1, 1);

    // Ali - آلبوم Khaterat
    Song song5(5, "Khaterat", 1401, "Pop", "song5.mp3", 1, 2);
    Song song6(6, "Geryeh", 1401, "Pop", "song6.mp3", 1, 2);
    Song song7(7, "Yadet Bashe", 1401, "Rock", "song7.mp3", 1, 2);

    // Ali - آلبوم Bahar
    Song song8(8, "Bahar", 1402, "Pop", "song8.mp3", 1, 3);
    Song song9(9, "To Beman", 1402, "Pop", "song9.mp3", 1, 3);

    // Ali - Singles (بدون آلبوم)
    Song song10(10, "Tanha", 1402, "Pop", "song10.mp3", 1, 0);
    Song song11(11, "Khoone", 1402, "Acoustic", "song11.mp3", 1, 0);
    Song song12(12, "Man o To", 1402, "Pop", "song12.mp3", 1, 0);

    // Mohsen - آلبوم Gole Sorkh
    Song song13(13, "Gole Sorkh", 1400, "Classic", "song13.mp3", 2, 4);
    Song song14(14, "Bagh-e-Shab", 1400, "Classic", "song14.mp3", 2, 4);
    Song song15(15, "Gol-e-Yas", 1400, "Classic", "song15.mp3", 2, 4);

    // Mohsen - آلبوم Asheghaneh
    Song song16(16, "Asheghaneh", 1401, "Traditional", "song16.mp3", 2, 5);
    Song song17(17, "Mah-e-Tamam", 1401, "Traditional", "song17.mp3", 2, 5);

    // Mohsen - Singles (بدون آلبوم)
    Song song18(18, "Delam", 1402, "Acoustic", "song18.mp3", 2, 0);
    Song song19(19, "Bahar", 1402, "Traditional", "song19.mp3", 2, 0);

    // Sara - آلبوم Rock Night
    Song song20(20, "Rock Night", 1401, "Rock", "song20.mp3", 3, 6);
    Song song21(21, "Heavy Metal", 1401, "Rock", "song21.mp3", 3, 6);
    Song song22(22, "Guitar Solo", 1401, "Rock", "song22.mp3", 3, 6);

    // Sara - آلبوم Electric Dreams
    Song song23(23, "Electric Dreams", 1402, "Electronic", "song23.mp3", 3, 7);
    Song song24(24, "Synth Wave", 1402, "Electronic", "song24.mp3", 3, 7);
    Song song25(25, "Neon Lights", 1402, "Electronic", "song25.mp3", 3, 7);

    // Sara - Singles (بدون آلبوم)
    Song song26(26, "Alone", 1402, "Acoustic", "song26.mp3", 3, 0);
    Song song27(27, "Dreams", 1402, "Electronic", "song27.mp3", 3, 0);

    songRepo.save(song1);
    songRepo.save(song2);
    songRepo.save(song3);
    songRepo.save(song4);
    songRepo.save(song5);
    songRepo.save(song6);
    songRepo.save(song7);
    songRepo.save(song8);
    songRepo.save(song9);
    songRepo.save(song10);
    songRepo.save(song11);
    songRepo.save(song12);
    songRepo.save(song13);
    songRepo.save(song14);
    songRepo.save(song15);
    songRepo.save(song16);
    songRepo.save(song17);
    songRepo.save(song18);
    songRepo.save(song19);
    songRepo.save(song20);
    songRepo.save(song21);
    songRepo.save(song22);
    songRepo.save(song23);
    songRepo.save(song24);
    songRepo.save(song25);
    songRepo.save(song26);
    songRepo.save(song27);

    // ===== لیست‌های پخش =====
    Playlist playlist1(1, "My Favorites", 4);  // Amin
    Playlist playlist2(2, "Workout", 4);       // Amin
    Playlist playlist3(3, "Chill", 5);         // Reza
    Playlist playlist4(4, "Classic Collection", 6); // Narges
    Playlist playlist5(5, "Drive", 5);         // Reza

    playlistRepo.save(playlist1);
    playlistRepo.save(playlist2);
    playlistRepo.save(playlist3);
    playlistRepo.save(playlist4);
    playlistRepo.save(playlist5);
}

void Database::saveAll()
{
    ofstream file("C:/Users/vihan-rayaneh/OneDrive/Desktop/Project Spotify/QSpotify/data.txt");

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
    ifstream file("C:/Users/vihan-rayaneh/OneDrive/Desktop/Project Spotify/QSpotify/data.txt");

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
            role = Role::Artist;
        else
            role = Role::Listener;

        Account account(id,
                        QString::fromStdString(fullName),
                        QString::fromStdString(userName),
                        QString::fromStdString(biography),
                        QString::fromStdString(password),
                        role);
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
        file >> releaseYear;
        file.ignore();
        getline(file, genre, ',');
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
                char semicolon;
                file >> semicolon;
            }
        }
        playlistRepo.save(playlist);
    }

    file.close();
}