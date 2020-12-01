#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QVector>
class Note
{
public:
    Note();
    bool is_archived;
    int row_count;
    QVector<QString> text;
};

#endif // NOTE_H

