#include "IntCell.h"

IntCell::IntCell(int initVal) : storedValue{initVal} {}
/**
IntCell::IntCell(int initVal = 0){storedValue = new int{initVal};}
*/

int IntCell::read() const {return storedValue;}
/**
int IntCell::read const(){return *storedValue;}
*/

void IntCell::write(int x){storedValue = x;}
/**
void IntCell::write(int x){*storedValue = x;}
*/
