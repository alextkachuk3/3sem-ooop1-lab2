#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "NoteWindow/note_window.h"
#include "Note/work_with_notes.h"
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Work_with_notes* app_notes;

private slots:
    void on_add_new_note_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
