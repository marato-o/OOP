#include <iostream>
#include <test.h>

void paperConstructorTest()
{
    std::cerr << "Paper check..." << std::endl;
    paper paper0;

    assert(paper0.getX() == DEF_N);
    assert(paper0.getY() == DEF_N);
    assert(paper0.getHeight() == DEF_N);
    assert(paper0.getWidht() == DEF_N);
    assert(paper0.getThickness() == DEF_N);


    //Проверка работы инициализационного конструктора
    paper paper1(DEF_X1, DEF_Y1, DEF_H1, DEF_W1, DEF_T1);
    assert(paper1.getX() == DEF_X1);
    assert(paper1.getY() == DEF_Y1);
    assert(paper1.getHeight() == DEF_H1);
    assert(paper1.getWidht() == DEF_W1);
    assert(paper1.getThickness() == DEF_T1);

    // Проверка констуктора копирования
    paper paper2{paper1};
    assert(paper2.getX() == paper1.getX());
    assert(paper2.getY() == paper1.getY());
    assert(paper2.getHeight() == paper1.getHeight());
    assert(paper2.getWidht() == paper1.getWidht());
    assert(paper2.getThickness() == paper1.getThickness());


    std::cerr << "No errors for constructors in paper class" << std::endl;

}

void paperTest(void)
{
    paper paper3;
    paper3.setX(DEF_X2);
    paper3.setY(DEF_Y2);
    paper3.setHeight(DEF_H2);
    paper3.setWidht(DEF_W2);
    paper3.setThickness(DEF_T2);

    assert(paper3.getX() == DEF_X2);
    assert(paper3.getY() == DEF_Y2);
    assert(paper3.getHeight() == DEF_H2);
    assert(paper3.getWidht() == DEF_W2);
    assert(paper3.getThickness() == DEF_T2);

    std::cerr << "No errors for setters and getters in paper class" << std::endl << std::endl;
}

void stackConstructorTest(){
    std::cerr << "Stack check..." << std::endl;
    stack pile;
    assert(pile.getSize() == 0 && pile.firstElem() == NULL);
    std::cerr << "No errors for initialization constructor" << std::endl;

    paper list1(DEF_X1, DEF_Y1, DEF_H1, DEF_W1, DEF_T1);
    paper list2(DEF_X2, DEF_Y2, DEF_H2, DEF_W2, DEF_T2);
    pile.push(list1);
    pile.push(list2);

    stack pile_new(pile);
    assert(compareStacks(pile, pile_new));
    std::cerr << "No errors for copying constructor" << std::endl;
}

void pushPopTest(){
    stack s1;
    stack s2;
    paper list1(DEF_X2, DEF_Y2, DEF_H2, DEF_W2, DEF_T2);
    s1.push(list1);
    s1.pop();
    assert(compareStacks(s1,s2) && s1.getSize() == 0);
    std::cerr << "No errors for push and pop methods" << std::endl;
}

void pushLustTest(){
    stack pile1;
    stack pile2;

    paper list1(DEF_X1, DEF_Y1, DEF_H1, DEF_W1, DEF_T1);
    pile1.push_last(list1);
    pile2.push(list1);
    assert(compareStacks(pile1,pile2) && pile1.getSize() == 1);
    std::cerr << "No errors for push_last method" << std::endl;
}

void stackClearTest(){
    stack pile1;
    stack pile2;
    paper list1(DEF_X1, DEF_Y1, DEF_H1, DEF_W1, DEF_T1);
    paper list2(DEF_X2, DEF_Y2, DEF_H2, DEF_W2, DEF_T2);
    pile1.push(list1);
    pile1.push(list2);
    pile1.clear();
    assert(compareStacks(pile1,pile2) && pile1.getSize() == 0);
    std::cerr << "No errors for clear method" << std::endl ;
}

void compareStacksTest(){
    stack pile1, pile2;
    paper list1(DEF_X1, DEF_Y1, DEF_H1, DEF_W1, DEF_T1);
    paper list2(DEF_X2, DEF_Y2, DEF_H2, DEF_W2, DEF_T2);
    pile1.push(list1);
    pile2.push(list2);
    assert(!compareStacks(pile1,pile2));
    std::cerr << "No errors for compare_stacks method" << std::endl;
}

void writeReadTest(){
    stack pile1, pile2;
    paper list1(DEF_X1, DEF_Y1, DEF_H1, DEF_W1, DEF_T1);
    paper list2(DEF_X2, DEF_Y2, DEF_H2, DEF_W2, DEF_T2);
    pile1.push(list1);
    pile1.push(list2);

    pile1.write(OUT_PATH);
    pile2.read(OUT_PATH);
    assert(compareStacks(pile1, pile2));
    std::cerr << "No errors for file methods" << std::endl << std::endl;
}

void printStackTest(){
    stack pile1;
    paper list1(DEF_X1, DEF_Y1, DEF_H1, DEF_W1, DEF_T1);
    paper list2(DEF_X2, DEF_Y2, DEF_H2, DEF_W2, DEF_T2);
    pile1.push(list1);
    pile1.push(list2);
    printStack(pile1);
}

void plateConstructorTest()
{
    std::cerr << "Plate check..." << std::endl;
    plate plate0;
    assert(plate0.getX() == DEF_N);
    assert(plate0.getY() == DEF_N);
    assert(plate0.getR() == DEF_N);
    assert(plate0.getThickness() == DEF_N);

    plate plate1(DEF_X1, DEF_Y1, DEF_R, DEF_T1);
    assert(plate1.getX() == DEF_X1);
    assert(plate1.getY() == DEF_Y1);
    assert(plate1.getR() == DEF_R);
    assert(plate1.getThickness() == DEF_T1);

    // Проверка констуктора копирования
    plate plate2(plate1);
    assert(plate2.getX() == DEF_X1);
    assert(plate2.getY() == DEF_Y1);
    assert(plate2.getR() == DEF_R);
    assert(plate2.getThickness() == DEF_T1);

    std::cerr << "No errors for constructors in plate class" << std::endl;
}

void plateTest()
{
    plate plate3;
    plate3.setX(DEF_X2);
    plate3.setY(DEF_Y2);
    plate3.setR(DEF_R);
    plate3.setThickness(DEF_T2);

    assert(plate3.getX() == DEF_X2);
    assert(plate3.getY() == DEF_Y2);
    assert(plate3.getR() == DEF_R);
    assert(plate3.getThickness() == DEF_T2);

    std::cerr << "No errors for setters and getters in plate class" << std::endl << std::endl;
}



