#ifndef PLATE_H
#define PLATE_H

#include <position.h>

class plate:public position
{
public:
    plate();
    plate(int x, int y, int R, int thickness);
    plate(const plate &other) = default;
    const virtual std::type_info& definition();

    [[nodiscard]] int getR() const;
    [[nodiscard]] int getThickness() const;

    void setR(int R);
    void setThickness(int t);

    virtual ~plate() = default; // деструктор класса plate
private:
    int R;
    int thickness;
};

#endif // PLATE_H
