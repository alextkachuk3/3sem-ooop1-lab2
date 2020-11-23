#ifndef NOTES_ON_FILESYSTEM_H
#define NOTES_ON_FILESYSTEM_H

#include <set>
#include "Note.h"
#include "note_window.h"
#include <QFile>
#include <QTextStream>
#include <QDir>

class Work_with_notes
{
private:
    QVector<QString> notes_dir;
    std::set<Note> notes_sets;
public:
    Work_with_notes();
    QVector<QString*> get_notes_texts();
    int get_note_count();
    void add_note(QString* text);
    void edit_note();
    void delete_note();
};

#endif // NOTES_ON_FILESYSTEM_H
