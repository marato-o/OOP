#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <dialogAddStack.h>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    updateList();

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::updateList(){
    connect(ui->listObj, SIGNAL(clicked(QModelIndex)), this, SLOT(on_listWidget_clicked(QModelIndex)));
    ui->listObj->clear();
    ui->buttonPopObj->setDisabled(true);
    ui->buttonClear->setDisabled(true);
    //for (paper & u: stack){
      //  ui->listObj->addItem(QString::fromStdString(u.getObjectTitle()));
    //}
    if(ui->listObj->count()>0){
        //ui->butSave->setDisabled(false);
        ui->buttonClear->setDisabled(false);
    } else {
        //ui->butSave->setDisabled(true);
        ui->buttonClear->setDisabled(true);
    }

}

void MainWindow::on_buttonAddStack_clicked()
{

}


void MainWindow::on_buttonAddObj_clicked()
{
    dialogAddStack d(this);
    if (d.exec()==QDialog::Accepted){


    }
}


void MainWindow::on_buttonPopObj_clicked()
{

}


void MainWindow::on_buttonClear_clicked()
{

}

