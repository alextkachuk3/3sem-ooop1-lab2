/**
*   @file textnoteeditor.cpp
*	@author Alex Tkachuk
*	@version 1.0
*/
#include "textnoteeditor.h"
#include "ui_textnoteeditor.h"

textNoteEditor::textNoteEditor(QString* get_text, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::textNoteEditor)
{
    ui->setupUi(this);
    text_ptr = get_text;
    ui->textEdit->setText(*text_ptr);
}

textNoteEditor::~textNoteEditor()
{
    delete ui;
}

void textNoteEditor::on_pushButton_save_clicked()
{
    *text_ptr = ui->textEdit->toPlainText();
    this->close();
}
