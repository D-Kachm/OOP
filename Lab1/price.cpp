#include "price.h"
#include <iostream>

Price add(const Price& p1, const Price& p2) {
    Price result;
    result.kopiykas = p1.kopiykas + p2.kopiykas;
    result.hryvnias = p1.hryvnias + p2.hryvnias + result.kopiykas / 100;
    result.kopiykas %= 100;
    return result;
}

Price multiply(const Price& p, int quantity) {
    int total_kop = (p.hryvnias * 100 + p.kopiykas) * quantity;
    Price result;
    result.hryvnias = total_kop / 100;
    result.kopiykas = total_kop % 100;
    return result;
}

void round(Price& p) {
    int remainder = p.kopiykas % 10;
    p.kopiykas -= remainder;
    if (remainder >= 5) p.kopiykas += 10;
    if (p.kopiykas >= 100) {
        p.hryvnias += p.kopiykas / 100;
        p.kopiykas %= 100;
    }
}

void display(const Price& p) {
    std::cout << p.hryvnias << " UAH " << p.kopiykas << " kop";
}
