#include "note_window.h"
#include "ui_note_window.h"


note_window::note_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::note_window)
{
    ui->setupUi(this);
}

note_window::note_window(const int& note_index, QWidget *parent) :
QDialog(parent),
ui(new Ui::note_window)
{
ui->setupUi(this);
//ui->textEdit->append("daer\n meow");
//ui->textEdit->append("lil\n lol");
}

note_window::~note_window()
{
    delete ui;
}
