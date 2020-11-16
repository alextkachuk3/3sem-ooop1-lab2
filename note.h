#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QVector>
#include <QDateTime>

class Note
{
private:
    QDateTime creation_date;
public:
    Note();
    Note(QString text, bool is_archived, QDateTime creation_date);
    QString text;
    bool is_archived;
    QDateTime get_creation_date();
};

#endif // NOTE_H
