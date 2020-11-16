#ifndef NOTES_ON_FILESYSTEM_H
#define NOTES_ON_FILESYSTEM_H

#include "note.h"
#include <QSet>

class work_with_notes
{
private:
    int note_count;
    QVector<QString> notes_dir;
    QSet<Note> notes_sets;
public:
    work_with_notes();
    int get_note_count();
    void add_note();
    void read_notes();
    void edit_note();
    void delite_note();
};

#endif // NOTES_ON_FILESYSTEM_H
