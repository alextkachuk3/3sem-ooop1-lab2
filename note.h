#ifndef NOTE_H
#define NOTE_H

#include <QString>

//Note class which conatin note text, count of string and checks archivability
class Note
{
public:
    Note() = default;
    Note(int count_line, int is_archived, QString text);
    int count_line = 0;
    int is_archived = false;
    QString text;
};

#endif // NOTE_H
