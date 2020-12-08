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

void textNoteEditor::on_textEdit_textChanged()
{
    if (ui->textEdit->toPlainText().length() > 800)
    {
        QString text = ui->textEdit->toPlainText();
        text.chop(text.length() - 800);
        ui->textEdit->setPlainText(text);
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.setPosition(ui->textEdit->document()->characterCount() - 1);
        ui->textEdit->setTextCursor(cursor);
    }
}
