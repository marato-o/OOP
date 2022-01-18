#ifndef STACK_H
#define STACK_H

#include <paper.h>
#include <plate.h>
#include <fstream>
#include <math.h>
#include <string>

class stack
{
    struct ListElement;
public:
    stack();
    stack(const stack&);
    ~stack();

    void push(paper& addObj);
    void push_last(const paper& addObj);
    void pop(); // метод удаления последнего в стэке элемента
    void clear(); // очистка стэка

    int getSize() const; // возврат значения размера стэка

    void write(const std::string& filename) const;
    void read(const std::string& filename);
    bool check_balance();

    class iterator
    {
    public:
        iterator();
        iterator(ListElement *elem);
        iterator& operator=(const iterator& it);
        iterator operator++(int);
        bool operator!=(const iterator& it);
        bool operator==(const iterator& it);
        paper& operator*() const;
        ~iterator();
    private:
        ListElement *curElem;
    };

    iterator firstElem() const;
    iterator lastElem() const;
    iterator nullElem() const;

private:
    struct ListElement
    {
        friend class collection;
        friend class Iterator;

        paper obj;
        ListElement *next;
        ListElement();
        ListElement(const position &obj);
        ~ListElement();
    };
    int size; // размер стэка
    ListElement *first;
};

bool compareStacks(const stack& s1, const stack& s2);
void printStack(const stack& s);

#endif // STACK_H
