#include "archivewindow.h"
#include "ui_archivewindow.h"

//Archived notes window constructor
ArchiveWindow::ArchiveWindow(QVector<Note> archived_notes, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArchiveWindow)
{
    ui->setupUi(this);
    for(const auto& a: archived_notes)
    {
        ui->listWidget->addItem(a.text);
    }
}

//Archived notes window destructor
ArchiveWindow::~ArchiveWindow()
{
    delete ui;
}
