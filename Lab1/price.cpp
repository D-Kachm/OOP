#include "price.h"

Price::Price(int h, short k) : hryvnias(h), kopiykas(k) {}

Price Price::operator+(const Price& other) const {
    int total_kop = (hryvnias + other.hryvnias) * 100 + (kopiykas + other.kopiykas);
    return Price(total_kop / 100, total_kop % 100);
}

Price Price::operator*(int quantity) const {
    int total_kop = (hryvnias * 100 + kopiykas) * quantity;
    return Price(total_kop / 100, total_kop % 100);
}

void Price::round() {
    int remainder = kopiykas % 10;
    if (remainder < 5) {
        kopiykas -= remainder;
    } else {
        kopiykas += (10 - remainder);
    }
    if (kopiykas >= 100) {
        hryvnias += kopiykas / 100;
        kopiykas %= 100;
    }
}

void Price::display() const {
    std::cout << hryvnias << " UAH " << kopiykas << " kop";
}
