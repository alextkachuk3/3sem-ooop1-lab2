#include "note.h"

//Note constructor
Note::Note(int count_line, int is_archived, QString text)
{
    this->count_line=count_line;
    this->is_archived=is_archived;
    this->text=text;
}
