#include <iostream>
#include <fstream>
#include "price.h"

Price add(const Price& p1, const Price& p2);
Price multiply(const Price& p, int quantity);
void round(Price& p);
void display(const Price& p);

int main() {
    std::ifstream file("prices.txt");
    if (!file) {
        std::cerr << "Error opening file!\n";
        return 1;
    }

    Price total = {0, 0};
    int hryvnias, quantity;
    short kopiykas;

    while (file >> hryvnias >> kopiykas >> quantity) {
        Price item_price = {hryvnias, kopiykas};
        total = add(total, multiply(item_price, quantity));
    }
    file.close();

    std::cout << "Total price: ";
    display(total);
    std::cout << std::endl;

    round(total);
    std::cout << "Amount to be paid (rounded): ";
    display(total);
    std::cout << std::endl;

    return 0;
}
