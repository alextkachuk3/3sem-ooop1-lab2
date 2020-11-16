#ifndef NOTES_ON_FILESYSTEM_H
#define NOTES_ON_FILESYSTEM_H

#include <set>
#include "Note.h"
#include <QtCore/QHash>
#include <QtCore/QSet>
#include <QFile>

class Work_with_notes
{
private:
    QVector<QString> notes_dir;
    //QSet<Note> notes_sets;
    std::set<Note> notes_sets;
public:
    Work_with_notes();
    int get_note_count();
    void add_note();
    void edit_note();
    void delete_note();
};

#endif // NOTES_ON_FILESYSTEM_H
