QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ArchiveNoteWindow/archive_note_window.cpp \
    Note/note.cpp \
    Note/work_with_notes.cpp \
    NoteWindow/note_window.cpp \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    ArchiveNoteWindow/archive_note_window.h \
    Note/note.h \
    Note/work_with_notes.h \
    NoteWindow/note_window.h \
    mainwindow.h \

FORMS += \
    ArchiveNoteWindow/archive_note_window.ui \
    NoteWindow/note_window.ui \
    mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
