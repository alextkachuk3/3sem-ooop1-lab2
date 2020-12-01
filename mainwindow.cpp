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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    QMenu * menu = new QMenu(this);
    QAction * deleteNote = new QAction("Delete", this);
    QAction * archiveNote = new QAction("Archive", this);
    connect(deleteNote, SIGNAL(triggered()), this, SLOT(slotDeleteRecord()));
    connect(archiveNote, SIGNAL(triggered()), this, SLOT(slotArchiveRecord()));
    menu->addAction(deleteNote);
    menu->addAction(archiveNote);
    menu->popup(ui->listWidget->viewport()->mapToGlobal(pos));
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
    }
    delete new_text;
    delete nEditor;
}

void MainWindow::slotDeleteRecord()
{
    int row = ui->listWidget->selectionModel()->currentIndex().row();
    ui->listWidget->takeItem(row);
}

void MainWindow::slotArchiveRecord()
{
    int row = ui->listWidget->selectionModel()->currentIndex().row();
    ui->listWidget->takeItem(row);
}
