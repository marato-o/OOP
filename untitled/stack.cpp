#include <stack.h>
#include <iostream>

stack::stack()
{
    size = 0;
    first = NULL;
}

stack::stack(const stack &cop)
{
    size = 0;
    ListElement *newElem1 = new ListElement; // будет указывать на рассматриваемый в заданном стэке элемент
    ListElement *newElem2; // указатель на элемент в новом стэке
    ListElement *newElem3 = new ListElement; // доп переменная

    first = NULL;
    newElem3 = NULL;
    newElem1 = cop.first; // начинаем копирование с первого объекта

    while (newElem1 != NULL){ // до тех пор, пока указатель ссылается на существующую ячейку
        newElem2 = new ListElement;
        newElem2->obj = newElem1->obj;
        newElem2->next = NULL; // возможно следующего элемента не будет

        if (first == NULL){
            first = newElem2;
            newElem3 = newElem2; // запоминаем ссылку на нынешний элемент, чтобы не потерять его
        }
        else{
            newElem3->next = newElem2; // от объекта, который мы запоминали на прошлом шаге, строится ссылка на следующий
            newElem3 = newElem3->next;
        }
        newElem1 = newElem1->next;
        ++size;
    }
}

stack::ListElement::ListElement(){
    next = NULL;
}

stack::ListElement::~ListElement(){
    next = NULL;
    obj.~paper();
}

stack::~stack(){
    /*ListElement *curElem = top;
    while (curElem)
    {
        ListElement *temp = curElem->next;
        curElem = NULL;
        delete(curElem);
        curElem = temp;
    }*/
    clear();
}

void stack::push(paper& addObj){ // добавляем элемент в начало стэка
    ListElement *newElem = new ListElement;
    newElem->obj = addObj;
    newElem->next = first;
    first = newElem; // проталкиваем в самое начало
    ++size;
}


void stack::push_last(const paper& addObj){
    ListElement *newElem = new ListElement; // сначала заполняем содержимое
    newElem->obj = addObj;
    newElem->next = NULL;

    if (first){
        ListElement *Elem = first; // доходим до последнего в стэке элемента
        while (Elem->next != NULL){
            Elem = Elem->next;
        }
        Elem->next = newElem;
        ++size;
    }
    else{
        first = newElem;
        ++size;
    }
}

void stack::clear(){
    ListElement *newElem1;
    ListElement *newElem2;

    newElem1 = first;
    while (newElem1 != NULL){
        newElem2 = newElem1;
        newElem1 = newElem1->next;
        delete newElem2;
    }
    first = NULL;
    size = 0;
}

void stack::pop(){
    if (first == NULL) return; //если стэк пуст
    else if (first->next == NULL){ // если в стэке один элемент
        first = NULL;
        size = 0;
    }
    else
    {
        ListElement *Elem = new ListElement;
        Elem = first; //  Elem указывается на первый элемент в стэке

        /*size_t j = sizeof(ListElement);

        while (j < (size - sizeof(ListElement))){ // идём до предпоследнего элемента в стэке
            Elem = Elem->next;
            j = j + sizeof(ListElement);
        }*/

        int i = 0;
        while (Elem->next != NULL){
            Elem = Elem->next;
            i++;
        }
        Elem = first;
        int j = 0;
        while (j < i - 1){
            Elem = Elem->next;
            j++;
        }

        ListElement *last = new ListElement; // создаём доп указатель
        last->next = NULL;
        last = Elem->next; // указывается на последний элемент в стэке
        delete last;
        Elem->next = NULL;
        --size;
    }
}

int stack::getSize() const{
    return size;
}

stack::iterator::iterator(){
    curElem = NULL;
}

stack::iterator::iterator(ListElement *elem){
    curElem = elem;
}

stack::iterator::~iterator(){}

stack::iterator& stack::iterator::operator=(const iterator& it){
    curElem = it.curElem;
    return *this;
}

stack::iterator stack::iterator::operator++(int){
    iterator temp = *this;
    if (curElem)
        curElem = curElem->next;
    return temp;
}

stack::iterator stack::firstElem() const{
    return iterator(first);
}

stack::iterator stack::lastElem() const{
    ListElement *Elem = first;
    while (Elem->next != NULL){ // пока указатель следующий элемент не указывается на несущ. ячейку
        Elem = Elem->next; // переходим к следующему элементу
    }
    return iterator(Elem);
}

stack::iterator stack::nullElem() const{
    return iterator(NULL);
}

bool stack::iterator::operator!=(const iterator &it){
    return curElem != it.curElem;
}

bool stack::iterator::operator==(const iterator &it){
    return curElem == it.curElem;
}

paper& stack::iterator::operator*() const{
    return curElem->obj;
}

void stack::write(const std::string &filename) const{
    std::ofstream outputFile(filename);
    outputFile << this->getSize() << std::endl;
    for (stack::iterator it = this->firstElem(); it != this->nullElem(); it++)
    {
        outputFile << (*it).getX() << std::endl << (*it).getY() << std::endl
                   << (*it).getHeight() << std::endl
                   << (*it).getWidht() << std::endl
                   << (*it).getThickness() << std::endl;
    }
    outputFile.close();
    outputFile.close();
}

void stack::read(const std::string &filename){
    this->clear();
    std::ifstream inputFile(filename);
    std::string text;
    int x, y, h, w, t;
    int size = 0;
    if (!inputFile.eof())
        inputFile >> size;
    while (!inputFile.eof() && size > 0)
    {
        inputFile >> x;
        inputFile >> y;
        inputFile >> h;
        inputFile >> w;
        inputFile >> t;
        paper list(x, y, h, w, t);
        this->push_last(list);
        --size;
    }
    if (size > 0)
        std::cerr << "Error while reading file" << std::endl;
    inputFile.close();
}

bool compareStacks(const stack& s1, const stack& s2){
    if (s1.getSize() != s2.getSize())
        return 0;
    for (auto it1 = s1.firstElem(), it2 = s2.firstElem(); it1 != s1.nullElem(); it1++, it2++)
    {
        if ((*it1).getX() != (*it2).getX() || (*it1).getY() != (*it2).getY() ||
                (*it1).getHeight() != (*it2).getHeight() || (*it1).getWidht() != (*it2).getWidht() ||
                (*it1).getWidht() != (*it2).getWidht() ||  (*it1). getThickness() != (*it2). getThickness())
            return 0;
    }
    return 1;
}

void printStack(const stack& s) {
    std::cout << "Stack" << std::endl;
    int i = 0;
    for (auto it = s.firstElem(); it != s.nullElem(); it++)
    {
        i++;
        std::cout << "Number " << i << ": " << std::endl
                  << "x, y: " << (*it).getX() <<", "<< (*it).getY() << std::endl
                  << "H: " << (*it).getHeight() << std::endl
                  << "W: " <<(*it).getWidht() << std::endl
                  << "T: " <<(*it).getThickness() << std::endl
                  << std::endl;
    }
}

bool stack::check_balance(){
    if (size < 3) return true;
    else{
        int volume = 0;
        int volume_x = 0;
        int volume_y = 0;
        iterator it = this->firstElem();
        while (it != nullElem()) {
            int xs = (*it).getX();
            int ys = (*it).getY();
            int hs = (*it).getHeight();
            int ws = (*it).getWidht();
            int ts = (*it).getThickness();
            it++;
            volume += hs*ws*ts;
            volume_x += hs*ws*ts*xs;
            volume_y += hs*ws*ts*ys;
        }
        int mean_x = volume_x/volume;
        int mean_y = volume_y/volume;

        int xf = (*firstElem()).getX();
        int yf = (*firstElem()).getY();
        int hf = (*firstElem()).getHeight();
        int wf = (*firstElem()).getWidht();

        if ((mean_x > xf+0.5*wf)||(mean_x < xf - 0.5*wf)||(mean_y > yf+0.5*hf)||(mean_y < yf-0.5*hf)){
            return false;
        }
        else return true;
    }
}

