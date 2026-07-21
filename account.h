#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

enum class Role
{
    Artist,
    Listener
};

class Account
{
private:
    int id;
    QString fullName;
    QString userName;
    QString biography;
    QString password;
    Role role;
    QString profilePhoto;
    std::vector <int> likedSongIDs;

public:
    Account();
    Account(int id, QString fullName, QString userName,
            QString biography, QString password, Role role,
            QString profilePhoto = "");

    int getId() const;
    void setId(int id);

    QString getFullName() const;
    void setFullName(const QString& fullName);

    QString getUserName() const;
    void setUserName(const QString& userName);

    QString getBiography() const;
    void setBiography(const QString& biography);

    QString getPassword() const;
    void setPassword(const QString& password);

    Role getRole() const;
    void setRole(Role role);

    QString getProfilePhoto() const;
    void setProfilePhoto(const QString& profilePhoto);

    std::vector <int> getLikedSongIDs();
    void setLikedSongIDs( std::vector<int> likedSongIDs );
};

#endif // ACCOUNT_H