#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <paper.h>
#include <stack.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_buttonAddStack_clicked();

    void on_buttonAddObj_clicked();

    void on_buttonPopObj_clicked();

    void on_buttonClear_clicked();

private:
    Ui::MainWindow *ui;
    void updateList();
    stack stack;
};
#endif // MAINWINDOW_H
