#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "note.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_listWidget_customContextMenuRequested(const QPoint &pos);
    //QVector<Note*> main_notes;
    //QVector<Note*> archive_notes;
    void on_pushButton_clicked();
    void slotDeleteRecord();
    void slotArchiveRecord();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
