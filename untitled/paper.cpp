#include <paper.h>



paper::paper():position(){
    height = DEF_DH;
    widht = DEF_DD;
    thickness = DEF_DT;
}

paper::paper(int x0, int y0, int height0, int widht0, int thickness0):position(x0, y0){
    height = height0;
    widht = widht0;
    thickness = thickness0;
}

paper::paper(const paper &other):position(other.getX(),other.getY()){
    height = other.getHeight();
    widht = other.getWidht();
    thickness = other.getThickness();
}

const std::type_info &paper::definition(){
    return typeid(paper);
}

int paper::getHeight() const{
    return height;
}
int paper::getWidht() const{
    return widht;
}
int paper::getThickness() const{
    return thickness;
}

void paper::setHeight(int h) {
    paper::height = h;
}
void paper::setWidht(int w) {
    paper::widht = w;
}
void paper::setThickness(int t) {
    paper::thickness = t;
}
