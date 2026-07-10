QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    accountrepository.cpp \
    album.cpp \
    albumrepository.cpp \
    artistpanel.cpp \
    artistrepository.cpp \
    database.cpp \
    listenerpanel.cpp \
    listenerrepository.cpp \
    loginwindow.cpp \
    main.cpp \
    playlist.cpp \
    playlistrepository.cpp \
    registerwindow.cpp \
    song.cpp \
    songrepository.cpp

HEADERS += \
    abstractrepository.h \
    account.h \
    accountrepository.h \
    album.h \
    albumrepository.h \
    apppagge.h \
    artistpanel.h \
    artistrepository.h \
    database.h \
    listenerpanel.h \
    listenerrepository.h \
    loginwindow.h \
    playlist.h \
    playlistrepository.h \
    registerwindow.h \
    song.h \
    songrepository.h

FORMS += \
    artistpanel.ui \
    listenerpanel.ui \
    loginwindow.ui \
    registerwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
