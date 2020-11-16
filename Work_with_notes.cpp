#include "Work_with_notes.h"

Work_with_notes::Work_with_notes()
{
    QFile note_dir_file("data\notes_dir.txt");
    note_dir_file.open(QIODevice::ReadWrite);
    QString current_dir;
    while(!note_dir_file.atEnd())
    {
        current_dir = note_dir_file.readLine();
        notes_dir.push_back(current_dir);
    }
    note_dir_file.close();
    QString current_note_text;
    bool current_note_is_archived;
    QString current_note_date_time_string;
    QDateTime current_note_date_time;
    for(const auto& a: notes_dir)
    {
        QFile note_file_text(a + "_text.txt");
        if(!note_file_text.open(QIODevice::ReadOnly))
        {
            continue;
        }

        current_note_text = note_file_text.readAll();
        note_file_text.close();

        QFile note_file_prop(a + "_properties.txt");
        if(!note_file_prop.open(QIODevice::ReadOnly))
        {
            continue;
        }

        current_note_is_archived = note_file_prop.readLine()[0];
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


void Work_with_notes::add_note()
{

}

void Work_with_notes::edit_note()
{

}

void Work_with_notes::delete_note()
{

}
