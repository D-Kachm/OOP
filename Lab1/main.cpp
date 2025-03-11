#include <iostream>
#include <fstream>
#include "price.h"

int main() {
    std::ifstream file("prices.txt");
    if (!file) {
        std::cerr << "Error opening file!\n";
        return 1;
    }

    Price total(0, 0);
    int hryvnias, quantity;
    short kopiykas;

    while (file >> hryvnias >> kopiykas >> quantity) {
        Price item_price(hryvnias, kopiykas);
        total = total + (item_price * quantity);
    }
    file.close();

    std::cout << "Total price: ";
    total.display();
    std::cout << std::endl;

    total.round();
    std::cout << "Amount to be paid (rounded): ";
    total.display();
    std::cout << std::endl;

    return 0;
}
