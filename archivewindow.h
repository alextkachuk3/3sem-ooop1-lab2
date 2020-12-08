#ifndef ARCHIVEWINDOW_H
#define ARCHIVEWINDOW_H

#include <QDialog>
#include <QVector>
#include <note.h>

namespace Ui {
class ArchiveWindow;
}

class ArchiveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ArchiveWindow(QVector<Note> archived_notes, QWidget *parent = nullptr);
    ~ArchiveWindow();

private:
    Ui::ArchiveWindow *ui;
};

#endif // ARCHIVEWINDOW_H
