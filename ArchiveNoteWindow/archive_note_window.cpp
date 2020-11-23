#include "archive_note_window.h"
#include "ui_archive_note_window.h"

archive_note_window::archive_note_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::archive_note_window)
{
    ui->setupUi(this);
}

archive_note_window::~archive_note_window()
{
    delete ui;
}
