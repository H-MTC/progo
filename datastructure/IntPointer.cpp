#include "IntPointer.h"
using namespace std;
IntPointer::IntPointer(int initVal = 0){storedValue = new int{initVal};}

IntPointer::~IntPointer(){delete storedValue;}

IntPointer::IntPointer(const IntPointer & rhs){storedValue = new int{*rhs.storedValue};}

IntPointer::IntPointer(IntPointer && rhs) : storedValue{rhs.storedValue}{rhs.storedValue = nullptr;}

IntPointer::IntPointer & operator= (const IntPointer & rhs)
{
    if(this != &rhs)
        *storedValue = *rhs.storedValue;
    return *this;
}

IntPointer::IntPointer & operator= (IntPointer && rhs){std::swap(storedValue, rhs.storedValue); return *this;}

int IntPointer::read() const {return *storedValue;}
void IntPointer::write(int x){*storedValue = x;}
