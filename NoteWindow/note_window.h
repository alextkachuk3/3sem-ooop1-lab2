#ifndef NOTE_WINDOW_H
#define NOTE_WINDOW_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class note_window;
}

class note_window : public QDialog
{
    Q_OBJECT

public:
    explicit note_window(QString* get_text);
    ~note_window();

private slots:


    void on_save_pushButton_clicked();

private:
    Ui::note_window *ui;
    QString* text_pointer;
};

#endif // NOTE_WINDOW_H
