#include <plate.h>

plate::plate():position(){
    R = DEF_DR;
    thickness = DEF_DT;
}

plate::plate(int x0, int y0, int R0, int thickness0):position(x0,y0){
    R = R0;
    thickness = thickness0;
}

const std::type_info &plate::definition(){
    return typeid(plate);
}

int plate::getR() const{
    return R;
}
int plate::getThickness() const{
    return thickness;
}

void plate::setR(int R) {
    plate::R = R;
}
void plate::setThickness(int t) {
    plate::thickness = t;
}
