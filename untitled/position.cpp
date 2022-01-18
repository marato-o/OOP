#include <position.h>

position::position(){
    x = DEF_DX;
    y = DEF_DY;
}

position::position(int x0, int y0){
    x = x0;
    y = y0;
}

const std::type_info &position::definition(){
    return typeid(position);
}

int position::getX() const{
    return x;
}
int position::getY() const{
    return y;
}

void position::setX(int x) {
    position::x = x;
}
void position::setY(int y) {
    position::y = y;
}
