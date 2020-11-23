#include "note_window.h"
#include "ui_note_window.h"


note_window::note_window(QString* get_text) :
    ui(new Ui::note_window)
{
    ui->setupUi(this);
    text_pointer = get_text;
    ui->textEdit->setText(*text_pointer);
}

note_window::~note_window()
{
    delete ui;
}

void note_window::on_save_pushButton_clicked()
{
    *text_pointer = ui->textEdit->toPlainText();
    this->close();
}
