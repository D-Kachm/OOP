#ifndef PRICE_H
#define PRICE_H

#include <iostream>

struct Price {
    int hryvnias;
    short kopiykas;

    Price(int h = 0, short k = 0);
    Price operator+(const Price& other) const;
    Price operator*(int quantity) const;
    void round();
    void display() const;
};

#endif 
