#include "note.h"

Note::Note()
{
    this->creation_date = QDateTime::currentDateTime();
}

Note::Note(QString text, bool is_archived, QDateTime creation_date)
{
    this->text = text;
    this->is_archived = is_archived;
    this->creation_date = creation_date;
}

QDateTime Note::get_creation_date()
{
    return this->creation_date;
}

