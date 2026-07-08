QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractrepository.cpp \
    account.cpp \
    accountrepository.cpp \
    album.cpp \
    albumrepository.cpp \
    artistrepository.cpp \
    listenerrepository.cpp \
    main.cpp \
    mainwindow.cpp \
    playlist.cpp \
    playlistrepository.cpp \
    song.cpp \
    songrepository.cpp

HEADERS += \
    abstractrepository.h \
    account.h \
    accountrepository.h \
    album.h \
    albumrepository.h \
    artistrepository.h \
    listenerrepository.h \
    mainwindow.h \
    playlist.h \
    playlistrepository.h \
    song.h \
    songrepository.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
