#ifndef NOTE_H
#define NOTE_H

#include <QString>

class Note
{
public:
    Note();
    int count_line = 0;
    int is_archived = false;
    QString text;
};

#endif // NOTE_H
