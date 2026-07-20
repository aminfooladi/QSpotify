QT += widgets multimedia

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    accountrepository.cpp \
    addalbum.cpp \
    addplaylistwindow.cpp \
    addsongwindow.cpp \
    album.cpp \
    albumrepository.cpp \
    albumwindow.cpp \
    artistpanel.cpp \
    artistrepository.cpp \
    database.cpp \
    editalbumwindow.cpp \
    editplaylistwindow.cpp \
    editsongwindow.cpp \
    listenerpanel.cpp \
    listenerrepository.cpp \
    loginwindow.cpp \
    main.cpp \
    playlist.cpp \
    playlistrepository.cpp \
    playlistwindow.cpp \
    registerwindow.cpp \
    song.cpp \
    songrepository.cpp \
    songwindow.cpp

HEADERS += \
    abstractrepository.h \
    account.h \
    accountrepository.h \
    addalbum.h \
    addplaylistwindow.h \
    addsongwindow.h \
    album.h \
    albumrepository.h \
    albumwindow.h \
    apppagge.h \
    artistpanel.h \
    artistrepository.h \
    database.h \
    editalbumwindow.h \
    editplaylistwindow.h \
    editsongwindow.h \
    listenerpanel.h \
    listenerrepository.h \
    loginwindow.h \
    playlist.h \
    playlistrepository.h \
    playlistwindow.h \
    registerwindow.h \
    song.h \
    songrepository.h \
    songwindow.h

FORMS += \
    addalbum.ui \
    addplaylistwindow.ui \
    addsongwindow.ui \
    albumwindow.ui \
    artistpanel.ui \
    editalbumwindow.ui \
    editplaylistwindow.ui \
    editsongwindow.ui \
    listenerpanel.ui \
    loginwindow.ui \
    playlistwindow.ui \
    registerwindow.ui \
    songwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
