QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    accountrepository.cpp \
    addsongwindow.cpp \
    album.cpp \
    albumrepository.cpp \
    allbumwindow.cpp \
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
    songrepository.cpp \
    songwindow.cpp

HEADERS += \
    abstractrepository.h \
    account.h \
    accountrepository.h \
    addsongwindow.h \
    album.h \
    albumrepository.h \
    allbumwindow.h \
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
    songrepository.h \
    songwindow.h

FORMS += \
    addsongwindow.ui \
    allbumwindow.ui \
    artistpanel.ui \
    listenerpanel.ui \
    loginwindow.ui \
    registerwindow.ui \
    songwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
