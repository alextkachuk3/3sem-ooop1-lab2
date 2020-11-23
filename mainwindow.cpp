#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , app_notes(new Work_with_notes)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(const auto a: app_notes->get_notes_texts())
    {
        ui->listWidget->addItem(*a);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete app_notes;
}


void MainWindow::on_add_new_note_clicked()
{
    QString* new_text = new QString;
    this->app_notes->add_note(new_text);
    ui->listWidget->addItem(*new_text);
}
