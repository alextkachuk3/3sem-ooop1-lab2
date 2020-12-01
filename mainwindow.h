/**
*   @file main.cpp
*	@author Alex Tkachuk
*	@version 1.0
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "NoteEditor/textnoteeditor.h"
#include "qglobalshortcut.h"

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
    //QVector<Note*> main_notes;
    //QVector<Note*> archive_notes;
    void on_pushButton_clicked();
    void slotDeleteRecord();
    void slotArchiveRecord();


private:
    Ui::MainWindow *ui;
    QGlobalShortcut *shortcutFirst;
    QGlobalShortcut *shortcutSecond;
};
#endif // MAINWINDOW_H
