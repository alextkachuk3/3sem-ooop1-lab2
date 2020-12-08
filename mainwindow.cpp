/**
*   @file mainwindow.cpp
*	@author Alex Tkachuk
*	@version 1.0
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotEditRecord()));
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotCustomMenuRequested(QPoint)));


    shortcutFirst = new QGlobalShortcut(this);
    connect(shortcutFirst, &QGlobalShortcut::activated, this, &MainWindow::slotOpenGK);
    shortcutFirst->setShortcut(QKeySequence("Ctrl+O"));
    shortcutSecond = new QGlobalShortcut(this);
    connect(shortcutSecond, &QGlobalShortcut::activated, this, &MainWindow::slotNewNoteGK);
    shortcutSecond->setShortcut(QKeySequence("Ctrl+N"));

    QFile note_file(QDir::homePath() + "/notes/notes.txt");
    note_file.open(QIODevice::ReadOnly| QIODevice::Text);

    int cur_count_line = 0;
    int cur_is_archived = false;
    QString cur_line;
    QString cur_text;

    while(!note_file.atEnd())
    {
        cur_count_line = note_file.readLine().toInt();

        cur_is_archived = note_file.readLine().toInt();
        for(int i = 0; i<cur_count_line; i++)
            {
                cur_line = note_file.readLine();
                cur_text += cur_line;
            }
        cur_text.resize(cur_text.size() - 1);
        Note new_note;
        new_note.count_line = cur_count_line;
        new_note.is_archived = cur_is_archived;
        new_note.text = cur_text;
        if(cur_is_archived)
        {
            archived.push_back(new_note);
        }
        else
        {
            notes.push_back(new_note);
            ui->listWidget->addItem(cur_text);
            ui->listWidget->item(ui->listWidget->count() - 1)->setBackground(QColor(qrand()%255,qrand()%255,qrand()%255));
        }
        cur_text.clear();
    }
    note_file.close();
}

MainWindow::~MainWindow()
{
    QFile note_file(QDir::homePath() + "/notes/notes.txt");
    note_file.open(QIODevice::WriteOnly| QIODevice::Text);
    for(const auto& a: notes)
    {
        note_file.write(QString::number(a.count_line).toUtf8() + '\n');
        note_file.write(QString::number(a.is_archived).toUtf8() + '\n');
        note_file.write(a.text.toUtf8() +'\n');
    }
    for(const auto& a: archived)
    {
        note_file.write(QString::number(a.count_line).toUtf8() + '\n');
        note_file.write(QString::number(a.is_archived).toUtf8() + '\n');
        note_file.write(a.text.toUtf8() + '\n');
    }
    delete ui;
}

void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    QMenu * menu = new QMenu(this);
    QAction * archiveNote = new QAction("Archive", this);
    connect(archiveNote, SIGNAL(triggered()), this, SLOT(slotArchiveRecord()));
    menu->addAction(archiveNote);
    menu->popup(ui->listWidget->viewport()->mapToGlobal(pos));
}

void MainWindow::slotOpenGK()
{
    showNormal();
}

void MainWindow::slotNewNoteGK()
{
    ui->pushButton->click();
}

void MainWindow::on_pushButton_clicked()
{
    QString* new_text = new QString;
    auto nEditor = new textNoteEditor(new_text);
    nEditor->setModal(true);
    nEditor->exec();
    if(new_text->length())
    {
        ui->listWidget->addItem(*new_text);
        ui->listWidget->item(ui->listWidget->count() - 1)->setBackground(QColor(qrand()%255,qrand()%255,qrand()%255));
        int line_count = 1;
        for(const auto &a :*new_text)
        {
            if(a=='\n')
            {
                line_count++;
            }
        }


            Note new_note;
            new_note.count_line = line_count;
            new_note.is_archived = 0;
            new_note.text = *new_text;
            notes.push_back(new_note);
    }

    delete new_text;
    delete nEditor;

}

void MainWindow::slotArchiveRecord()
{
    int row = ui->listWidget->selectionModel()->currentIndex().row();
    ui->listWidget->takeItem(row);
    Note to_archive = notes[row];
    notes.remove(row);
    to_archive.is_archived = true;
    archived.push_back(to_archive);
}

void MainWindow::on_pushButton_archive_clicked()
{
    auto Archive_Window = new ArchiveWindow(archived);
    Archive_Window->setModal(true);
    Archive_Window->exec();
}
