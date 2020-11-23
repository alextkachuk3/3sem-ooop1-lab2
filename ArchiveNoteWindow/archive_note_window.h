#ifndef ARCHIVE_NOTE_WINDOW_H
#define ARCHIVE_NOTE_WINDOW_H

#include <QWidget>

namespace Ui {
class archive_note_window;
}

class archive_note_window : public QWidget
{
    Q_OBJECT

public:
    explicit archive_note_window(QWidget *parent = nullptr);
    ~archive_note_window();

private:
    Ui::archive_note_window *ui;
};

#endif // ARCHIVE_NOTE_WINDOW_H
