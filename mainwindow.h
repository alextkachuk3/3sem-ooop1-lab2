/**
*   @file main.cpp
*	@author Alex Tkachuk
*	@version 1.0
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QFile>
#include <QDir>
#include "NoteEditor/textnoteeditor.h"
#include "qglobalshortcut.h"
#include "QTextStream"
#include "note.h"
#include "archivewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Main window of the program
 *
 * Program allow to create notes.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void slotOpenGK();
    void slotNewNoteGK();

private slots:
    void on_listWidget_customContextMenuRequested(const QPoint &pos);
    void on_pushButton_clicked();
    void slotArchiveRecord();
    void slotEditRecord();
    void on_pushButton_archive_clicked();


private:
    Ui::MainWindow *ui;
    QGlobalShortcut *shortcutFirst;
    QGlobalShortcut *shortcutSecond;
    QVector<Note> notes;
    QVector<Note> archived;
};
#endif // MAINWINDOW_H
