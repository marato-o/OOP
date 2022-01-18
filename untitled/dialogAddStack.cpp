#include "dialogAddStack.h"
#include "ui_dialogAddStack.h"

dialogAddStack::dialogAddStack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogAddStack)
{
    ui->setupUi(this);
}

dialogAddStack::~dialogAddStack()
{
    delete ui;
}
