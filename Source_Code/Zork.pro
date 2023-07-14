QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Character.cpp \
    MainLobby.cpp \
    Room.cpp \
    accusationcheck.cpp \
    animateobject.cpp \
    interface.cpp \
    item.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp

HEADERS += \
    Array.h \
    Character.h \
    MainLobby.h \
    Room.h \
    accusationcheck.h \
    animateobject.h \
    interface.h \
    item.h \
    main.h \
    mainwindow.h \
    map.h

FORMS += \
    accusationcheck.ui \
    mainwindow.ui \
    map.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Text/Examinations/Character Dialogue/Butler Dialogue.txt \
    Text/Examinations/Character Dialogue/Gardener Dialogue.txt \
    Text/Examinations/SoupExamination.txt \
    Text/SoupLongDescription.txt \
    Zork_first_version/Text/TestText.txt

RESOURCES += \
    Text.qrc \
    Text.qrc
