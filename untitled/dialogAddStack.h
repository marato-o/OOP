#ifndef DIALOGADDSTACK_H
#define DIALOGADDSTACK_H

#include <QDialog>
#include <stack.h>

namespace Ui {
class dialogAddStack;
}

class dialogAddStack : public QDialog
{
    Q_OBJECT

public:
    explicit dialogAddStack(QWidget *parent = nullptr);
    ~dialogAddStack();

    stack getObj() const;

private:
    Ui::dialogAddStack *ui;
};

#endif // DIALOGADDSTACK_H
