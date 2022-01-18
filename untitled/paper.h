#ifndef PAPER_H
#define PAPER_H

#include <position.h>

class paper:public position
{
public:
    paper(); // конструктор по умолчанию

    paper(int x0, int y0, int height0, int widht0, int thickness0); // конструктор инициализации
    paper(const paper &other); // конструктор копирования
    const virtual std::type_info& definition();

    [[nodiscard]] int getHeight() const;
    [[nodiscard]] int getWidht() const;
    [[nodiscard]] int getThickness() const;

    void setHeight(int h);
    void setWidht(int w);
    void setThickness(int t);

    virtual ~paper() = default; //деструктор

private:
    int height;
    int widht;
    int thickness;
};

#endif // PAPER_H
