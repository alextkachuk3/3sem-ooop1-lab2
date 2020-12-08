QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

linux {
    QT       += x11extras
    CONFIG   += link_pkgconfig
    PKGCONFIG += x11
}

win32: SOURCES += win/qglobalshortcut.cpp
linux: SOURCES += x11/qglobalshortcut.cpp

HEADERS  += qglobalshortcut.h \
    archivewindow.h \
    note.h

SOURCES += \
    NoteEditor/textnoteeditor.cpp \
    archivewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    note.cpp

HEADERS += \
    NoteEditor/textnoteeditor.h \
    mainwindow.h \

FORMS += \
    NoteEditor/textnoteeditor.ui \
    archivewindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
