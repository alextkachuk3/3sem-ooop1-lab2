#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QVector>

class note
{
public:
    note();
    QString text;
    int media_count;
    QVector<QString> media_dir;
};

#endif // NOTE_H
