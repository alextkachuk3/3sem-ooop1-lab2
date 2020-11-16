#ifndef NOTE_WINDOW_H
#define NOTE_WINDOW_H

#include <QDialog>
#include "Work_with_notes.h"


namespace Ui {
class note_window;
}

class note_window : public QDialog
{
    Q_OBJECT

public:
    explicit note_window(QWidget *parent = nullptr);
    explicit note_window(const int& note_index, QWidget *parent = nullptr);
    ~note_window();

private:
    Ui::note_window *ui;
};

#endif // NOTE_WINDOW_H
