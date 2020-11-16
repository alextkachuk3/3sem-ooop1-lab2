#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_add_new_note_clicked()
{
    QListWidgetItem* short_note = new QListWidgetItem("Meow");
    ui->listWidget->addItem(short_note);
}


void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    note_window note_w(index.row());
    note_w.setModal(true);
    note_w.exec();
    qDebug() << index.row();
                if( !index.isValid() ) {
                    return;
            }

            if( QListWidget* listWgt = dynamic_cast< QListWidget* >( sender() ) ) {
                if( QListWidgetItem* item = listWgt->takeItem( index.row() ) ) {
                    delete item;
                }
            }
}
