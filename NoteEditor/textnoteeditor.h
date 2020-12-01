/**
*   @file textnoteeditor.h
*	@author Alex Tkachuk
*	@version 1.0
*/
#ifndef TEXTNOTEEDITOR_H
#define TEXTNOTEEDITOR_H

#include <QDialog>

namespace Ui {
class textNoteEditor;
}

class textNoteEditor : public QDialog
{
    Q_OBJECT

public:
    explicit textNoteEditor(QString* get_text, QWidget *parent = nullptr);
    ~textNoteEditor();

private slots:
    void on_pushButton_save_clicked();

private:
    Ui::textNoteEditor *ui;
    QString *text_ptr;
};

#endif // TEXTNOTEEDITOR_H
