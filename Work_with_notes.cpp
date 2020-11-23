#include "Work_with_notes.h"

Work_with_notes::Work_with_notes()
{
    QFile note_dir_file(QDir::homePath() + "/notes/dir_notes.txt");
    note_dir_file.open(QIODevice::ReadWrite);
    QString current_dir;
    while(!note_dir_file.atEnd())
    {
        current_dir = note_dir_file.readLine();
        notes_dir.push_back(current_dir);
    }
    note_dir_file.close();

    for(const auto& a: notes_dir)
    {
        QString* current_note_text = new QString;
        bool* current_note_is_archived = new bool;
        QDateTime current_note_date_time;

        QFile note_file_text(a + "_text.txt");
        if(!note_file_text.open(QIODevice::ReadOnly))
        {
            delete current_note_text;
            delete current_note_is_archived;
            continue;
        }

        *current_note_text = note_file_text.readAll();
        note_file_text.close();

        QFile note_file_prop(a + "_properties.txt");
        if(!note_file_prop.open(QIODevice::ReadOnly))
        {
            continue;
        }

        *current_note_is_archived = note_file_prop.readLine()[0];
        current_note_date_time = QDateTime::fromString(note_file_prop.readLine(), "yyyy-MM-dd HH.mm.ss");
        note_file_prop.close();
        Note new_note(current_note_text, current_note_is_archived, current_note_date_time);
        this->notes_sets.insert(new_note);
    }
}

int Work_with_notes::get_note_count()
{
    return this->notes_sets.size();
}

QVector<QString*> Work_with_notes::get_notes_texts()
{
    QVector<QString*> result;
    for(const auto &a : notes_sets)
    {
        result.push_back(a.text);
    }
    return result;
}

void Work_with_notes::add_note(QString* new_text)
{
    QString genDir;
    genDir.resize(25);
    for (int i = 0; i < genDir.size() ; ++i)
    {
            genDir[i] = QChar('A' + char(qrand() % ('Z' - 'A')));
    }
    genDir+="\n";
    if(!QDir(QDir::homePath() + "/notes").exists())
    {
        QDir().mkdir(QDir::homePath() + "/notes");
    }
    QFile note_dir_file(QDir::homePath() + "/notes/dir_notes.txt");
    note_dir_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    QTextStream writeStream(&note_dir_file);
    writeStream << genDir;
    note_dir_file.close();
    note_window note_w(new_text);
    note_w.setModal(true);
    note_w.exec();
}

void Work_with_notes::edit_note()
{

}

void Work_with_notes::delete_note()
{

}
