#include "account.h"
using namespace std ;

Account::Account() : id(0), role(Role::Listener) {}

Account::Account(int id, QString fullName, QString userName,
                 QString biography, QString password, Role role,
                 QString profilePhoto)
    : id(id), fullName(fullName), userName(userName),
    biography(biography), password(password), role(role),
    profilePhoto(profilePhoto) {}

int Account::getId() const { return id; }
void Account::setId(int id) { this->id = id; }

QString Account::getFullName() const { return fullName; }
void Account::setFullName(const QString& fullName) { this->fullName = fullName; }

QString Account::getUserName() const { return userName; }
void Account::setUserName(const QString& userName) { this->userName = userName; }

QString Account::getBiography() const { return biography; }
void Account::setBiography(const QString& biography) { this->biography = biography; }

QString Account::getPassword() const { return password; }
void Account::setPassword(const QString& password) { this->password = password; }

Role Account::getRole() const { return role; }
void Account::setRole(Role role) { this->role = role; }

QString Account::getProfilePhoto() const { return profilePhoto; }
void Account::setProfilePhoto(const QString& profilePhoto) { this->profilePhoto = profilePhoto; }