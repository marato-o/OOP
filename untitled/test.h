#ifndef TEST_H
#define TEST_H

#include <paper.h>
#include <stack.h>
#include <plate.h>
#include <assert.h>

#define DEF_N 0

#define DEF_X1 0
#define DEF_Y1 2
#define DEF_H1 5
#define DEF_W1 4
#define DEF_T1 1
#define DEF_R 3

#define DEF_X2 1
#define DEF_Y2 11
#define DEF_H2 1
#define DEF_W2 5
#define DEF_T2 2

#define OUT_PATH "/Users/Marat/Projects/qt_projects/file.txt"

void paperConstructorTest();
void paperTest();

void stackConstructorTest();
void pushPopTest();
void pushLustTest();
void stackClearTest();
void printStackTest();
void compareStacksTest();
void writeReadTest();

void plateConstructorTest();
void plateTest();

#endif // TEST_H

