#include <mainwindow.h>
#include <qapplication.h>
#include <qpushbutton.h>
#include <iostream>
#include <test.h>
#include <paper.h>
#include <plate.h>

#include <QApplication>

int main(int argc, char *argv[])
{

    paperConstructorTest();
    paperTest();

    stackConstructorTest();
    pushPopTest();
    pushLustTest();
    stackClearTest();
    compareStacksTest();
    writeReadTest();
    printStackTest();

    plateConstructorTest();
    plateTest();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
