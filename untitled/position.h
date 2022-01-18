#ifndef POSITION_H
#define POSITION_H

#define DEF_DX 0
#define DEF_DY 0
#define DEF_DH 0
#define DEF_DD 0
#define DEF_DT 0
#define DEF_DR 0

#include <iostream>
#include <typeinfo>

// родительский класс для листов и тарелок

class position
{
public:
    position();
    position(int x0, int y0);
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    const virtual std::type_info& definition();
    void setX(int x);
    void setY(int y);

    virtual ~position() = default; // деструктор класса position

protected:
    int x;
    int y;
};

#endif // POSITION_H

